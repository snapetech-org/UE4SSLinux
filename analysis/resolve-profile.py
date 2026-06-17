#!/usr/bin/env python3
import argparse
import json
import sys
from pathlib import Path


SCHEMA = "ue4sslinux-profile-resolution/v1"
PROFILE_SCHEMA = "ue4sslinux-profile/v1"
PLATFORMS = ("linux-client", "linux-server", "windows")


def repo_root():
    return Path(__file__).resolve().parents[1]


def load_profile(name, profiles_dir=None):
    base = profiles_dir or repo_root() / "profiles"
    path = base / name / "profile.json"
    if not path.exists():
        raise FileNotFoundError(f"missing profile: {path}")
    with path.open("r", encoding="utf-8") as handle:
        profile = json.load(handle)
    if profile.get("schemaVersion") != PROFILE_SCHEMA:
        raise ValueError(f"{path} has unsupported schemaVersion: {profile.get('schemaVersion')}")
    return path, profile


def platform_key(platform):
    return {
        "linux-client": "linuxClient",
        "linux-server": "linuxServer",
        "windows": "windows",
    }[platform]


def env_prefix(platform):
    return {
        "linux-client": "UE4SSL_CLIENT",
        "linux-server": "UE4SSL_SERVER",
        "windows": "UE4SSL_WIN",
    }[platform]


def resolve(name, platform, profiles_dir=None):
    path, profile = load_profile(name, profiles_dir)
    key = platform_key(platform)
    prefix = env_prefix(platform)
    proxy_candidates = profile.get("windowsProxyDllCandidates", [])
    return {
        "schemaVersion": SCHEMA,
        "profile": profile.get("name", name),
        "displayName": profile.get("displayName", name),
        "profilePath": str(path),
        "platform": platform,
        "envPrefix": prefix,
        "processFilters": list(profile.get("processFilters", {}).get(key, [])),
        "scanPresets": list(profile.get("scanPresets", [])),
        "ueVersionHint": profile.get("ueVersionHint", ""),
        "safeLaunchMode": profile.get("safeLaunchMode", ""),
        "defaultWindowsProxyDll": profile.get("defaultWindowsProxyDll", ""),
        "windowsProxyDllCandidates": list(proxy_candidates),
        "caveats": list(profile.get("caveats", [])),
    }


def shell_quote(value):
    return "'" + str(value).replace("'", "'\"'\"'") + "'"


def env_text(resolution):
    prefix = resolution["envPrefix"]
    lines = [
        f"# {resolution['displayName']} profile for {resolution['platform']}",
        f"UE4SSL_PROFILE={shell_quote(resolution['profile'])}",
        f"{prefix}_SCAN_PRESETS={shell_quote(';'.join(resolution['scanPresets']))}",
    ]
    if resolution["processFilters"]:
        lines.append(f"{prefix}_SCAN_PATH_FILTER={shell_quote(';'.join(resolution['processFilters']))}")
    if resolution["platform"] == "windows" and resolution["defaultWindowsProxyDll"]:
        lines.append(f"UE4SSL_WIN_PROXY_DLL={shell_quote(resolution['defaultWindowsProxyDll'])}")
    if resolution["ueVersionHint"]:
        lines.append(f"{prefix}_UNREAL_VERSION_HINT={shell_quote(resolution['ueVersionHint'])}")
    if resolution["safeLaunchMode"]:
        lines.append(f"{prefix}_SAFE_LAUNCH_MODE={shell_quote(resolution['safeLaunchMode'])}")
    return "\n".join(lines) + "\n"


def main(argv=None):
    parser = argparse.ArgumentParser(description="Resolve a UE4SSLinux target profile for a platform.")
    parser.add_argument("profile")
    parser.add_argument("--platform", choices=PLATFORMS, required=True)
    parser.add_argument("--profiles-dir", type=Path)
    parser.add_argument("--format", choices=("json", "env"), default="json")
    args = parser.parse_args(argv)

    try:
        resolution = resolve(args.profile, args.platform, args.profiles_dir)
    except (FileNotFoundError, ValueError) as exc:
        parser.error(str(exc))
    if args.format == "env":
        sys.stdout.write(env_text(resolution))
    else:
        json.dump(resolution, sys.stdout, indent=2, sort_keys=True)
        sys.stdout.write("\n")


if __name__ == "__main__":
    main()
