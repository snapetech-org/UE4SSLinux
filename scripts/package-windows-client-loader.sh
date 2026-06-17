#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
build_script="$repo_root/scripts/build-windows-client-loader.sh"
build_dir="${UE4SSL_WINDOWS_LOADER_BUILD_DIR:-$repo_root/build/windows-client-loader}"
loader="$build_dir/ue4ssl_windows_proxy_loader.dll"
dist_root="${UE4SSL_WINDOWS_LOADER_DIST_DIR:-$repo_root/dist/windows-client-loader}"
default_version="$(git -C "$repo_root" rev-parse --short HEAD 2>/dev/null || date -u +%Y%m%dT%H%M%SZ)"
if ! git -C "$repo_root" diff --quiet --ignore-submodules -- 2>/dev/null ||
   ! git -C "$repo_root" diff --cached --quiet --ignore-submodules -- 2>/dev/null; then
  default_version="${default_version}-dirty"
fi
version="${UE4SSL_WINDOWS_LOADER_VERSION:-$default_version}"
platform="windows-x86_64"
package_name="ue4ssl-windows-proxy-loader-${version}-${platform}"
stage="$dist_root/$package_name"
archive="$dist_root/${package_name}.tar.gz"

"$build_script" >/dev/null

if [ ! -f "$loader" ]; then
  echo "missing built loader: $loader" >&2
  exit 1
fi

rm -rf "$stage" "$archive"
mkdir -p \
  "$stage/lib" \
  "$stage/src" \
  "$stage/docs" \
  "$stage/profiles/dune" \
  "$stage/profiles/palworld" \
  "$stage/examples" \
  "$stage/analysis" \
  "$stage/tests" \
  "$stage/abi"

cp "$loader" "$stage/lib/ue4ssl_windows_proxy_loader.dll"
cp "$loader" "$stage/lib/version.dll"
cp "$repo_root/runtime/windows-proxy/ue4ssl_windows_proxy_loader.c" "$stage/src/ue4ssl_windows_proxy_loader.c"
cp "$repo_root/scripts/build-windows-client-loader.sh" "$stage/build-windows-client-loader.sh"
cp "$repo_root/scripts/launch-proton-client-probe.sh" "$stage/examples/launch-proton-client-probe.sh"
cp "$repo_root/scripts/proton-dll-override-control.sh" "$stage/examples/proton-dll-override-control.sh"
cp "$repo_root/analysis/stage-windows-lua-runtime.sh" "$stage/examples/stage-windows-lua-runtime.sh"
cp "$repo_root/scripts/smoke-windows-client-loader.sh" "$stage/examples/smoke-windows-client-loader.sh"
cp "$repo_root/scripts/smoke-windows-client-loader-lua.sh" "$stage/examples/smoke-windows-client-loader-lua.sh"
cp "$repo_root/analysis/summarize-client-loader-scan.py" "$stage/analysis/summarize-client-loader-scan.py"
cp "$repo_root/analysis/summarize-client-loader-xrefs.py" "$stage/analysis/summarize-client-loader-xrefs.py"
cp "$repo_root/analysis/validate-client-pe-signatures.py" "$stage/analysis/validate-client-pe-signatures.py"
cp "$repo_root/analysis/export-client-pe-signature-manifest.py" "$stage/analysis/export-client-pe-signature-manifest.py"
cp "$repo_root/analysis/summarize-client-ue-anchors.py" "$stage/analysis/summarize-client-ue-anchors.py"
cp "$repo_root/analysis/ue4ss-port-readiness.py" "$stage/analysis/ue4ss-port-readiness.py"
cp "$repo_root/analysis/export-ue-anchor-env.py" "$stage/analysis/export-ue-anchor-env.py"
cp "$repo_root/analysis/prepare-ue-anchor-canary.py" "$stage/analysis/prepare-ue-anchor-canary.py"
cp "$repo_root/analysis/plan-ue4ss-canary-env.py" "$stage/analysis/plan-ue4ss-canary-env.py"
cp "$repo_root/analysis/resolve-profile.py" "$stage/analysis/resolve-profile.py"
cp "$repo_root/analysis/proton-proxy-candidates.py" "$stage/analysis/proton-proxy-candidates.py"
cp "$repo_root/tests/test_client_loader_scan_summary.py" "$stage/tests/test_client_loader_scan_summary.py"
cp "$repo_root/tests/test_client_loader_xrefs.py" "$stage/tests/test_client_loader_xrefs.py"
cp "$repo_root/tests/test_client_pe_signatures.py" "$stage/tests/test_client_pe_signatures.py"
cp "$repo_root/tests/test_client_pe_signature_manifest.py" "$stage/tests/test_client_pe_signature_manifest.py"
cp "$repo_root/tests/test_client_ue_anchors.py" "$stage/tests/test_client_ue_anchors.py"
cp "$repo_root/tests/test_ue4ss_port_readiness.py" "$stage/tests/test_ue4ss_port_readiness.py"
cp "$repo_root/tests/test_export_ue_anchor_env.py" "$stage/tests/test_export_ue_anchor_env.py"
cp "$repo_root/tests/test_prepare_ue_anchor_canary.py" "$stage/tests/test_prepare_ue_anchor_canary.py"
cp "$repo_root/tests/test_plan_ue4ss_canary_env.py" "$stage/tests/test_plan_ue4ss_canary_env.py"
cp "$repo_root/tests/test_resolve_profile.py" "$stage/tests/test_resolve_profile.py"
cp "$repo_root/tests/test_proton_proxy_candidates.py" "$stage/tests/test_proton_proxy_candidates.py"
cp "$repo_root/docs/client-loader-support.md" "$stage/docs/client-loader-support.md"
cp "$repo_root/docs/install.md" "$stage/docs/install.md"
cp "$repo_root/docs/target-profiles.md" "$stage/docs/target-profiles.md"
cp "$repo_root/docs/safety-model.md" "$stage/docs/safety-model.md"
cp "$repo_root/docs/test-plan.md" "$stage/docs/test-plan.md"
cp "$repo_root/docs/feature-parity.md" "$stage/docs/feature-parity.md"
cp "$repo_root/docs/roadmap.md" "$stage/docs/roadmap.md"
cp "$repo_root/profiles/dune/profile.json" "$stage/profiles/dune/profile.json"
cp "$repo_root/profiles/dune/README.md" "$stage/profiles/dune/README.md"
cp "$repo_root/profiles/dune/compat-env.sh" "$stage/profiles/dune/compat-env.sh"
cp "$repo_root/profiles/palworld/profile.json" "$stage/profiles/palworld/profile.json"
cp "$repo_root/profiles/palworld/README.md" "$stage/profiles/palworld/README.md"
cp "$repo_root/docs/windows-client-loader.md" "$stage/docs/windows-client-loader.md"
cp "$repo_root/docs/windows-client-loader-canary-2026-06-16.md" "$stage/docs/windows-client-loader-canary-2026-06-16.md"
cp "$repo_root/docs/windows-client-loader-xrefs-2026-06-16.md" "$stage/docs/windows-client-loader-xrefs-2026-06-16.md"

chmod 0755 "$stage/build-windows-client-loader.sh"
chmod 0755 "$stage/examples/launch-proton-client-probe.sh"
chmod 0755 "$stage/examples/proton-dll-override-control.sh"
chmod 0755 "$stage/examples/stage-windows-lua-runtime.sh"
chmod 0755 "$stage/examples/smoke-windows-client-loader.sh"
chmod 0755 "$stage/examples/smoke-windows-client-loader-lua.sh"
chmod 0755 "$stage/analysis/summarize-client-loader-scan.py"
chmod 0755 "$stage/analysis/summarize-client-loader-xrefs.py"
chmod 0755 "$stage/analysis/validate-client-pe-signatures.py"
chmod 0755 "$stage/analysis/export-client-pe-signature-manifest.py"
chmod 0755 "$stage/analysis/summarize-client-ue-anchors.py"
chmod 0755 "$stage/analysis/ue4ss-port-readiness.py"
chmod 0755 "$stage/analysis/export-ue-anchor-env.py"
chmod 0755 "$stage/analysis/prepare-ue-anchor-canary.py"
chmod 0755 "$stage/analysis/plan-ue4ss-canary-env.py"
chmod 0755 "$stage/analysis/resolve-profile.py"
chmod 0755 "$stage/analysis/proton-proxy-candidates.py"
chmod 0644 "$stage/lib/ue4ssl_windows_proxy_loader.dll" "$stage/lib/version.dll"

cat > "$stage/examples/env.scan.example" <<'EOF'
# Windows/Proton client proxy DLL probe.
UE4SSL_WIN_PROXY_DLL=version.dll
UE4SSL_WIN_LOG=Z:\tmp\ue4ssl-win-loader.log
UE4SSL_WIN_SNAPSHOT_DELAY_SECONDS=2

# Read-only runtime anchor scan.
UE4SSL_WIN_SCAN_ENABLED=true
UE4SSL_WIN_LOG_MODULES=true
UE4SSL_WIN_SCAN_PRESETS=core,ue,client,cheat,brt,deep-desert
UE4SSL_WIN_SCAN_STRINGS=ProcessEvent;FNamePool;GUObjectArray;CheatManager
UE4SSL_WIN_SCAN_SIGNATURES=
UE4SSL_WIN_SCAN_SIGNATURES_FILE=
UE4SSL_WIN_UE_ANCHORS=
UE4SSL_WIN_UE_ANCHOR_SIGNATURES=
UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE=
UE4SSL_WIN_UE_POINTER_PROBE=false
UE4SSL_WIN_UE_LAYOUT_PROBE=false
UE4SSL_WIN_UE_UOBJECT_PROBE=false
UE4SSL_WIN_UE_REFLECTION_PROBE=false
UE4SSL_WIN_UE_REFLECTION_NEXT_OFFSET=0x28
UE4SSL_WIN_UE_REFLECTION_SUPER_OFFSET=0x30
UE4SSL_WIN_UE_REFLECTION_CHILDREN_OFFSET=0x38
UE4SSL_WIN_UE_REFLECTION_CHILD_PROPERTIES_OFFSET=0x40
UE4SSL_WIN_UE_REFLECTION_PROPERTY_LINK_OFFSET=0x48
UE4SSL_WIN_UE_REFLECTION_FUNCTION_LINK_OFFSET=0x50
UE4SSL_WIN_UE_REFLECTION_FIELD_WALK=false
UE4SSL_WIN_UE_REFLECTION_FIELD_NEXT_OFFSET=0x28
UE4SSL_WIN_UE_REFLECTION_MAX_FIELDS=16
UE4SSL_WIN_UE_REFLECTION_PROPERTY_PROBE=false
UE4SSL_WIN_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET=0x30
UE4SSL_WIN_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET=0x34
UE4SSL_WIN_UE_REFLECTION_PROPERTY_FLAGS_OFFSET=0x38
UE4SSL_WIN_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET=0x44
UE4SSL_WIN_UE_REFLECTION_CONTAINER_CHILD_SCAN_START=0x48
UE4SSL_WIN_UE_REFLECTION_CONTAINER_CHILD_SCAN_END=0xa0
UE4SSL_WIN_UE_REFLECTION_VALUE_PROBE=false
UE4SSL_WIN_UE_REFLECTION_VALUE_MAX_BYTES=16
UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE=false
UE4SSL_WIN_UE_OBJECT_ARRAY_MAX_OBJECTS=128
UE4SSL_WIN_UE_FNAME_PROBE=false
UE4SSL_WIN_UE_FNAME_POOL=
UE4SSL_WIN_UE_FNAME_BLOCKS_OFFSET=0x10
UE4SSL_WIN_UE_FNAME_STRIDE=2
UE4SSL_WIN_UE_FNAME_MAX_LENGTH=128
UE4SSL_WIN_UE_LAYOUT_SLOTS=8
UE4SSL_WIN_HOOK_SELF_TEST=false
UE4SSL_WIN_MOD_SELF_TEST=false
UE4SSL_WIN_LUA_SELF_TEST=false
UE4SSL_WIN_LUA_DLL=
UE4SSL_WIN_LUA_SELF_TEST_SCRIPT=
UE4SSL_WIN_LUA_REFLECTION_SELF_TEST=false
UE4SSL_WIN_LUA_REFLECTION_RAW_SET_ENABLED=false
UE4SSL_WIN_LUA_REFLECTION_SELF_TEST_SCRIPT=
UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE=false
UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_ADDRESS=
UE4SSL_WIN_UE_PROCESS_EVENT_ADDRESS=
UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_SELF_TEST_TARGET=false
UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_INSTALL=false
UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_CALL_SELF_TEST=false
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK=false
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_ADDRESS=
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_SELF_TEST_TARGET=false
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_SELF_TEST=false
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS=false
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT=8
UE4SSL_WIN_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=false
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=false
UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_SCRIPT=
UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST=false
UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST_SCRIPT=
UE4SSL_WIN_LUA_MODS_ENABLED=false
UE4SSL_WIN_LUA_MOD_SCRIPTS=
UE4SSL_WIN_LUA_MOD_ROOT=
UE4SSL_WIN_LUA_MOD_DISPATCH_SELF_TEST=false
UE4SSL_WIN_SCAN_MAX_HITS_PER_NEEDLE=16
UE4SSL_WIN_SCAN_MAX_REGION_BYTES=268435456

# Proton/Wine load controls.
WINEDLLOVERRIDES=version=n,b
WINEPATH=Z:\absolute\path\to\stage
WINEDLLPATH=/absolute/path/to/stage

# The launch wrapper also writes these same probe keys to
# ue4ssl-win.env beside version.dll for normal Steam launches where
# wrapper environment variables are not inherited.
EOF

cat > "$stage/README.md" <<EOF
# target profile Windows Client Loader

Package: ${package_name}
Built: $(date -u +%Y-%m-%dT%H:%M:%SZ)
Source commit: $(git -C "$repo_root" rev-parse HEAD 2>/dev/null || printf unknown)
Platform: ${platform}

This is a Windows PE client-process proxy/probe for target profile under Wine/Proton. It
is not upstream UE4SS yet. It can be staged as a native override DLL, defaults
to \`version.dll\`, logs from inside the Windows process, and scans committed
image mappings for configured anchors. The target profile shipping executable imports
\`VERSION.dll\`, making \`version.dll\` a real proxy load point.

## Contents

- lib/ue4ssl_windows_proxy_loader.dll: runtime proxy/probe DLL.
- lib/version.dll: same DLL under the recommended proxy name.
- src/: source used for this package.
- build-windows-client-loader.sh: local rebuild helper.
- examples/launch-proton-client-probe.sh: Proton/Steam launch wrapper.
- examples/proton-dll-override-control.sh: registry override helper for Steam launches that do not inherit environment.
- examples/smoke-windows-client-loader.sh: local Wine smoke test.
- examples/stage-windows-lua-runtime.sh: staged LuaBinaries 5.4.8 helper for parity smoke tests.
- examples/smoke-windows-client-loader-lua.sh: real Lua DLL smoke test.
- examples/env.scan.example: scan environment settings.
- analysis/: log summarizer, PE xref summarizer, PE signature validator, manifest/env exporter, UE anchor readiness, and proxy candidate tools.
- tests/: unit tests for the packaged analysis tools.
- docs/client-loader-support.md: shared Linux/Windows support matrix.
- docs/windows-client-loader-canary-2026-06-16.md: real Proton client canary result.
- docs/windows-client-loader-xrefs-2026-06-16.md: real Proton client static xref follow-up.
- abi/: PE header and export reports when local tools are available.
- SHA256SUMS: checksums for package contents.

## Steam Launch Option

\`\`\`bash
$repo_root/scripts/launch-proton-client-probe.sh --stage-to-game-dir -- %command%
\`\`\`

The wrapper can stage the DLL outside the Steam game directory for experiments,
but target profile's Proton path should use \`--stage-to-game-dir\` so \`version.dll\` is
beside the game executable. The script backs up any existing DLL with the same
name before replacing it. It also writes \`ue4ssl-win.env\` beside
the proxy DLL so a normal Steam launch can still enable scan mode even when the
wrapper environment is not inherited.

If the real game process still loads Proton's builtin \`version.dll\`, set the
per-app Wine override:

\`\`\`bash
examples/proton-dll-override-control.sh --set
examples/proton-dll-override-control.sh --query
\`\`\`

Default log:

\`\`\`text
/tmp/ue4ssl-win-client-probe-loader.log
\`\`\`

## Smoke Test

\`\`\`bash
examples/smoke-windows-client-loader.sh
\`\`\`

The default smoke validates the missing-Lua-DLL path. To prove real Windows Lua
dispatch parity, stage the pinned LuaBinaries 5.4.8 runtime and run the Lua
smoke:

\`\`\`bash
examples/stage-windows-lua-runtime.sh
UE4SSL_WIN_LUA_DLL="$(pwd)/build/windows-lua-runtime/lua54.dll" examples/smoke-windows-client-loader-lua.sh
\`\`\`

## Analysis

\`\`\`bash
analysis/summarize-client-loader-scan.py /tmp/ue4ssl-win-client-probe-loader.log
analysis/summarize-client-loader-xrefs.py /path/to/TargetGame-Win64-Shipping.exe --loader-log /tmp/ue4ssl-win-client-probe-loader.log --category cheat --show-context --show-seeds
analysis/validate-client-pe-signatures.py /path/to/TargetGame-Win64-Shipping.exe --loader-log /tmp/ue4ssl-win-client-probe-loader.log --category cheat
analysis/export-client-pe-signature-manifest.py /path/to/TargetGame-Win64-Shipping.exe --loader-log /tmp/ue4ssl-win-client-probe-loader.log --category cheat --format env
analysis/export-client-pe-signature-manifest.py /path/to/TargetGame-Win64-Shipping.exe --loader-log /tmp/ue4ssl-win-client-probe-loader.log --category cheat --format signatures > client-signatures.txt
analysis/export-client-pe-signature-manifest.py /path/to/TargetGame-Win64-Shipping.exe --loader-log /tmp/ue4ssl-win-client-probe-loader.log --category ue --format anchor-signatures > client-anchor-signatures.txt
analysis/validate-client-pe-signatures.py /path/to/TargetGame-Win64-Shipping.exe --manifest-json client-pe-signature-manifest.json --ignore-expected-offsets
analysis/export-ue-anchor-env.py /tmp/ue4ssl-win-client-probe-loader.log --loader win-client --platform windows > ue-anchors.env
analysis/prepare-ue-anchor-canary.py --platform windows --binary /path/to/TargetGame-Win64-Shipping.exe --loader-log /tmp/ue4ssl-win-client-probe-loader.log --output-dir build/windows-client-anchor-canary
analysis/plan-ue4ss-canary-env.py --platform windows --client-log /tmp/ue4ssl-win-client-probe-loader.log --loader win-client --max-stage read-only > next-canary.env
analysis/ue4ss-port-readiness.py --client-log /tmp/ue4ssl-win-client-probe-loader.log --loader win-client --signature-validation-json client-pe-signature-validation.json
analysis/summarize-client-ue-anchors.py /tmp/ue4ssl-win-client-probe-loader.log
analysis/proton-proxy-candidates.py /path/to/TargetGame-Win64-Shipping.exe
python3 _m unittest tests/test_client_loader_scan_summary.py tests/test_client_loader_xrefs.py tests/test_client_pe_signatures.py tests/test_client_pe_signature_manifest.py tests/test_client_ue_anchors.py tests/test_ue4ss_port_readiness.py tests/test_export_ue_anchor_env.py tests/test_prepare_ue_anchor_canary.py tests/test_plan_ue4ss_canary_env.py tests/test_proton_proxy_candidates.py
\`\`\`

\`export-ue-anchor-env.py\` exports core discovery anchors plus reflection
anchors by default, including anchors from resolved \`ue-anchor-signature\`
records. Unresolved and ambiguous signature anchors remain missing.
\`prepare-ue-anchor-canary.py\` combines the validated UE signature manifest,
loader-consumable anchor signature file, second-pass anchor env, validation
summary, and readiness report in one output directory.
\`plan-ue4ss-canary-env.py\` reads readiness evidence and emits the next guarded
canary env. It defaults to read-only discovery/reflection and only emits
ProcessEvent hook or live Lua dispatch flags when \`--max-stage\` allows them.
\`live-hook\` and \`lua-dispatch\` plans also enable bounded live ProcessEvent
call logging so \`ue-process-event-live-context\` and
\`ue-process-event-live-param\` readiness evidence is collected.

For a full one-launch signature canary, point
\`UE4SSL_WIN_SCAN_SIGNATURES_FILE\` at the generated
\`client-signatures.txt\`. Use \`--format env\` only when a file path is
inconvenient; env output is chunked. Use \`--manifest-json\` with
\`--ignore-expected-offsets\` to revalidate exported manifests against later
client builds before canary scanning.
EOF

file "$loader" > "$stage/abi/file.txt"
if command -v llvm-objdump >/dev/null 2>&1; then
  llvm-objdump -p "$loader" > "$stage/abi/pe-headers.txt"
fi
if command -v llvm-nm >/dev/null 2>&1; then
  llvm-nm -g "$loader" > "$stage/abi/exports-symbols.txt" || true
fi

(
  cd "$stage"
  find . -type f ! -name SHA256SUMS -print | sort | sed 's#^\./##' | xargs sha256sum > SHA256SUMS
)

tar -C "$dist_root" -czf "$archive" "$package_name"
sha256sum "$archive" > "${archive}.sha256"

printf 'packaged Windows client loader: %s\n' "$archive"
printf 'package checksum: %s\n' "${archive}.sha256"
