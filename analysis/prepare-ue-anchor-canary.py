#!/usr/bin/env python3
import argparse
import importlib.util
import json
import subprocess
import sys
from pathlib import Path


PLATFORMS = ("server", "linux-client", "windows")


def import_script(script_name, module_name):
    script = Path(__file__).resolve().parent / script_name
    spec = importlib.util.spec_from_file_location(module_name, script)
    module = importlib.util.module_from_spec(spec)
    if spec.loader is None:
        raise RuntimeError(f"unable to import {script}")
    spec.loader.exec_module(module)
    return module


def platform_config(platform):
    if platform == "windows":
        return {
            "manifestScript": "export-client-pe-signature-manifest.py",
            "manifestModule": "export_client_pe_signature_manifest",
            "loader": "win-client",
            "anchorPlatform": "windows",
            "manifestName": "client-pe-signature-manifest.json",
            "anchorSignatureName": "client-anchor-signatures.txt",
            "anchorEnvName": "ue-anchors.env",
            "readinessLogArg": "--client-log",
        }
    if platform == "linux-client":
        return {
            "manifestScript": "export-elf-signature-manifest.py",
            "manifestModule": "export_elf_signature_manifest",
            "targetLoader": "linux-client",
            "loader": "linux-client",
            "anchorPlatform": "linux",
            "manifestName": "client-elf-signature-manifest.json",
            "anchorSignatureName": "client-anchor-signatures.txt",
            "anchorEnvName": "ue-anchors.env",
            "readinessLogArg": "--client-log",
        }
    return {
        "manifestScript": "export-elf-signature-manifest.py",
        "manifestModule": "export_elf_signature_manifest",
        "targetLoader": "server",
        "loader": "server",
        "anchorPlatform": "server",
        "manifestName": "server-elf-signature-manifest.json",
        "anchorSignatureName": "server-anchor-signatures.txt",
        "anchorEnvName": "ue-server-anchors.env",
        "readinessLogArg": "--server-log",
    }


def load_json(path):
    with path.open("r", encoding="utf-8", errors="replace") as handle:
        return json.load(handle)


def build_manifest(args, config):
    exporter = import_script(config["manifestScript"], config["manifestModule"])
    if args.validation_json:
        validation = load_json(args.validation_json)
    else:
        categories = args.category or ["ue"]
        names = args.name or []
        if args.platform == "windows":
            validation = exporter.build_validation(
                args.binary,
                args.loader_log,
                args.xref_json,
                args.loader or [config["loader"]],
                args.pid,
                args.exe_substring,
                categories,
                names,
                args.signature_prefix,
                args.signature_suffix,
                args.scope,
                args.max_matches,
            )
        else:
            validation = exporter.build_validation(
                args.binary,
                args.loader_log,
                args.xref_json,
                args.exe_substring[0] if args.exe_substring else (
                    "TargetGame" if args.platform == "linux-client" else "TargetGameServer"
                ),
                int(args.pid[0]) if args.pid else None,
                categories,
                names,
                args.signature_prefix,
                args.signature_suffix,
                args.scope,
                args.max_matches,
            )
    entries = exporter.build_entries(validation, promotable_only=not args.include_non_promotable)
    if args.platform == "windows":
        manifest = exporter.make_manifest(
            args.binary,
            validation,
            entries,
            args.loader_log,
            args.xref_json,
            args.max_patterns_per_scan,
            args.max_env_value_chars,
        )
    else:
        manifest = exporter.make_manifest(
            args.binary,
            validation,
            entries,
            args.loader_log,
            args.xref_json,
            args.max_patterns_per_scan,
            args.max_env_value_chars,
            config["targetLoader"],
        )
    return exporter, manifest


def build_anchor_env(args, config):
    anchor_exporter = import_script("export-ue-anchor-env.py", "export_ue_anchor_env")
    return anchor_exporter, anchor_exporter.build_export(
        args.loader_log,
        args.loader or [config["loader"]],
        args.pid,
        args.exe_substring,
        args.anchor_name or list(anchor_exporter.DEFAULT_ANCHORS),
        config["anchorPlatform"],
    )


def run_readiness(args, config, validation_path):
    readiness = Path(__file__).resolve().parent / "ue4ss-port-readiness.py"
    command = [
        sys.executable,
        str(readiness),
        config["readinessLogArg"],
        str(args.loader_log),
        "--loader",
        config["loader"],
        "--signature-validation-json",
        str(validation_path),
        "--format",
        "markdown",
    ]
    return subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True).stdout


def write_summary(path, platform, manifest, anchor_export, files):
    lines = ["# UE Anchor Canary Prep", ""]
    lines.append(f"- Platform: `{platform}`")
    lines.append(f"- Manifest entries: `{manifest['entryCount']}`")
    lines.append(f"- Anchor env entries: `{anchor_export['entryCount']}`")
    if anchor_export["missing"]:
        lines.append(f"- Missing anchors: `{', '.join(anchor_export['missing'])}`")
    lines.append("")
    lines.append("## Outputs")
    lines.append("")
    for label, output in files.items():
        lines.append(f"- {label}: `{output}`")
    lines.append("")
    path.write_text("\n".join(lines), encoding="utf-8")


def main(argv=None):
    parser = argparse.ArgumentParser(
        description="Prepare second-pass UE anchor canary artifacts from a UE4SSLinux loader log and binary."
    )
    parser.add_argument("--platform", choices=PLATFORMS, required=True)
    parser.add_argument("--binary", type=Path, required=True)
    parser.add_argument("--loader-log", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--validation-json", type=Path)
    parser.add_argument("--xref-json", type=Path)
    parser.add_argument("--loader", action="append", default=[])
    parser.add_argument("--pid", action="append", default=[])
    parser.add_argument("--exe-substring", action="append", default=[])
    parser.add_argument("--category", action="append", default=[])
    parser.add_argument("--name", action="append", default=[])
    parser.add_argument("--anchor-name", action="append", default=[])
    parser.add_argument("--signature-prefix", type=int, default=8)
    parser.add_argument("--signature-suffix", type=int, default=16)
    parser.add_argument("--scope", choices=("executable", "all"), default="executable")
    parser.add_argument("--max-matches", type=int, default=16)
    parser.add_argument("--include-non-promotable", action="store_true")
    parser.add_argument("--max-patterns-per-scan", type=int, default=256)
    parser.add_argument("--max-env-value-chars", type=int, default=1800)
    parser.add_argument("--skip-readiness", action="store_true")
    parser.add_argument("--format", choices=("json", "markdown"), default="markdown")
    args = parser.parse_args(argv)

    config = platform_config(args.platform)
    args.output_dir.mkdir(parents=True, exist_ok=True)

    exporter, manifest = build_manifest(args, config)
    manifest_path = args.output_dir / config["manifestName"]
    validation_path = args.output_dir / "signature-validation.json"
    anchor_signature_path = args.output_dir / config["anchorSignatureName"]
    manifest_path.write_text(json.dumps(manifest, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    validation_path.write_text(json.dumps(manifest["validation"], indent=2, sort_keys=True) + "\n", encoding="utf-8")
    anchor_signature_path.write_text(exporter.anchor_signatures_text(manifest), encoding="utf-8")

    anchor_exporter, anchor_export = build_anchor_env(args, config)
    anchor_env_path = args.output_dir / config["anchorEnvName"]
    anchor_env_path.write_text(anchor_exporter.env_text(anchor_export), encoding="utf-8")

    files = {
        "manifest": manifest_path,
        "signatureValidation": validation_path,
        "anchorSignatures": anchor_signature_path,
        "anchorEnv": anchor_env_path,
    }
    if not args.skip_readiness:
        readiness_path = args.output_dir / "ue4ss-readiness.md"
        readiness_path.write_text(run_readiness(args, config, validation_path), encoding="utf-8")
        files["readiness"] = readiness_path

    summary_path = args.output_dir / "README.md"
    write_summary(summary_path, args.platform, manifest, anchor_export, files)
    files["summary"] = summary_path

    result = {
        "schemaVersion": "ue4sslinux-ue-anchor-canary-prep/v1",
        "platform": args.platform,
        "manifestEntryCount": manifest["entryCount"],
        "anchorEnvEntryCount": anchor_export["entryCount"],
        "missingAnchors": anchor_export["missing"],
        "outputs": {key: str(value) for key, value in files.items()},
    }
    if args.format == "json":
        json.dump(result, sys.stdout, indent=2, sort_keys=True)
        sys.stdout.write("\n")
    else:
        sys.stdout.write(summary_path.read_text(encoding="utf-8"))


if __name__ == "__main__":
    main()
