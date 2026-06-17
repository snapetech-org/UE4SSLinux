#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
build_script="$repo_root/scripts/build-linux-client-loader.sh"
build_dir="${UE4SSL_LINUX_CLIENT_LOADER_BUILD_DIR:-$repo_root/build/linux-client-loader}"
loader="$build_dir/libue4ssl_linux_client_loader.so"
dist_root="${UE4SSL_LINUX_CLIENT_LOADER_DIST_DIR:-$repo_root/dist/linux-client-loader}"
default_version="$(git -C "$repo_root" rev-parse --short HEAD 2>/dev/null || date -u +%Y%m%dT%H%M%SZ)"
if ! git -C "$repo_root" diff --quiet --ignore-submodules -- 2>/dev/null ||
   ! git -C "$repo_root" diff --cached --quiet --ignore-submodules -- 2>/dev/null; then
  default_version="${default_version}-dirty"
fi
version="${UE4SSL_LINUX_CLIENT_LOADER_VERSION:-$default_version}"
platform="linux-x86_64"
package_name="ue4ssl-linux-client-loader-${version}-${platform}"
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

cp "$loader" "$stage/lib/libue4ssl_linux_client_loader.so"
cp "$repo_root/runtime/linux-elf/ue4ssl_linux_client_loader.c" "$stage/src/ue4ssl_linux_client_loader.c"
cp "$repo_root/runtime/linux-elf/CMakeLists.txt" "$stage/src/CMakeLists.txt"
cp "$repo_root/scripts/build-linux-client-loader.sh" "$stage/build-linux-client-loader.sh"
cp "$repo_root/scripts/launch-linux-client-probe.sh" "$stage/examples/launch-native-client.sh"
cp "$repo_root/scripts/smoke-linux-client-loader.sh" "$stage/examples/smoke-linux-client-loader.sh"
cp "$repo_root/analysis/summarize-client-loader-scan.py" "$stage/analysis/summarize-client-loader-scan.py"
cp "$repo_root/analysis/summarize-linux-loader-xrefs.py" "$stage/analysis/summarize-linux-loader-xrefs.py"
cp "$repo_root/analysis/summarize-linux-loader-anchors.py" "$stage/analysis/summarize-linux-loader-anchors.py"
cp "$repo_root/analysis/validate-elf-signatures.py" "$stage/analysis/validate-elf-signatures.py"
cp "$repo_root/analysis/export-elf-signature-manifest.py" "$stage/analysis/export-elf-signature-manifest.py"
cp "$repo_root/analysis/summarize-client-ue-anchors.py" "$stage/analysis/summarize-client-ue-anchors.py"
cp "$repo_root/analysis/ue4ss-port-readiness.py" "$stage/analysis/ue4ss-port-readiness.py"
cp "$repo_root/analysis/export-ue-anchor-env.py" "$stage/analysis/export-ue-anchor-env.py"
cp "$repo_root/analysis/prepare-ue-anchor-canary.py" "$stage/analysis/prepare-ue-anchor-canary.py"
cp "$repo_root/analysis/plan-ue4ss-canary-env.py" "$stage/analysis/plan-ue4ss-canary-env.py"
cp "$repo_root/analysis/resolve-profile.py" "$stage/analysis/resolve-profile.py"
cp "$repo_root/tests/test_client_loader_scan_summary.py" "$stage/tests/test_client_loader_scan_summary.py"
cp "$repo_root/tests/test_linux_loader_xrefs.py" "$stage/tests/test_linux_loader_xrefs.py"
cp "$repo_root/tests/test_linux_loader_anchors.py" "$stage/tests/test_linux_loader_anchors.py"
cp "$repo_root/tests/test_elf_signatures.py" "$stage/tests/test_elf_signatures.py"
cp "$repo_root/tests/test_elf_signature_manifest.py" "$stage/tests/test_elf_signature_manifest.py"
cp "$repo_root/tests/test_client_ue_anchors.py" "$stage/tests/test_client_ue_anchors.py"
cp "$repo_root/tests/test_ue4ss_port_readiness.py" "$stage/tests/test_ue4ss_port_readiness.py"
cp "$repo_root/tests/test_export_ue_anchor_env.py" "$stage/tests/test_export_ue_anchor_env.py"
cp "$repo_root/tests/test_prepare_ue_anchor_canary.py" "$stage/tests/test_prepare_ue_anchor_canary.py"
cp "$repo_root/tests/test_plan_ue4ss_canary_env.py" "$stage/tests/test_plan_ue4ss_canary_env.py"
cp "$repo_root/tests/test_resolve_profile.py" "$stage/tests/test_resolve_profile.py"
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
cp "$repo_root/docs/linux-client-loader.md" "$stage/docs/linux-client-loader.md"

chmod 0755 "$stage/build-linux-client-loader.sh"
chmod 0755 "$stage/examples/launch-native-client.sh"
chmod 0755 "$stage/examples/smoke-linux-client-loader.sh"
chmod 0755 "$stage/analysis/summarize-client-loader-scan.py"
chmod 0755 "$stage/analysis/summarize-linux-loader-xrefs.py"
chmod 0755 "$stage/analysis/summarize-linux-loader-anchors.py"
chmod 0755 "$stage/analysis/validate-elf-signatures.py"
chmod 0755 "$stage/analysis/export-elf-signature-manifest.py"
chmod 0755 "$stage/analysis/summarize-client-ue-anchors.py"
chmod 0755 "$stage/analysis/ue4ss-port-readiness.py"
chmod 0755 "$stage/analysis/export-ue-anchor-env.py"
chmod 0755 "$stage/analysis/prepare-ue-anchor-canary.py"
chmod 0755 "$stage/analysis/plan-ue4ss-canary-env.py"
chmod 0755 "$stage/analysis/resolve-profile.py"
chmod 0755 "$stage/lib/libue4ssl_linux_client_loader.so"

cat > "$stage/examples/env.scan.example" <<'EOF'
# Native Linux ELF client preload. This does not modify installed game files.
UE4SSL_LINUX_CLIENT_PRELOAD=/abs/path/libue4ssl_linux_client_loader.so
UE4SSL_CLIENT_LOG=/tmp/ue4ssl-client-loader.log
UE4SSL_CLIENT_FORCE=true
UE4SSL_CLIENT_LOG_MODULES=true
UE4SSL_CLIENT_SNAPSHOT_DELAY_SECONDS=0

# Read-only runtime anchor scan.
UE4SSL_CLIENT_SCAN_ENABLED=true
UE4SSL_CLIENT_SCAN_PRESETS=core,ue,client,cheat,brt,deep-desert
UE4SSL_CLIENT_SCAN_STRINGS=ProcessEvent;FNamePool;GUObjectArray;CheatManager
UE4SSL_CLIENT_SCAN_SIGNATURES=
UE4SSL_CLIENT_SCAN_SIGNATURES_FILE=
UE4SSL_CLIENT_UE_ANCHORS=
UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES=
UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES_FILE=
UE4SSL_CLIENT_UE_POINTER_PROBE=false
UE4SSL_CLIENT_UE_LAYOUT_PROBE=false
UE4SSL_CLIENT_UE_UOBJECT_PROBE=false
UE4SSL_CLIENT_UE_REFLECTION_PROBE=false
UE4SSL_CLIENT_UE_REFLECTION_NEXT_OFFSET=0x28
UE4SSL_CLIENT_UE_REFLECTION_SUPER_OFFSET=0x30
UE4SSL_CLIENT_UE_REFLECTION_CHILDREN_OFFSET=0x38
UE4SSL_CLIENT_UE_REFLECTION_CHILD_PROPERTIES_OFFSET=0x40
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_LINK_OFFSET=0x48
UE4SSL_CLIENT_UE_REFLECTION_FUNCTION_LINK_OFFSET=0x50
UE4SSL_CLIENT_UE_REFLECTION_FIELD_WALK=false
UE4SSL_CLIENT_UE_REFLECTION_FIELD_NEXT_OFFSET=0x28
UE4SSL_CLIENT_UE_REFLECTION_MAX_FIELDS=16
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_PROBE=false
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET=0x30
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET=0x34
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_FLAGS_OFFSET=0x38
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET=0x44
UE4SSL_CLIENT_UE_REFLECTION_CONTAINER_CHILD_SCAN_START=0x48
UE4SSL_CLIENT_UE_REFLECTION_CONTAINER_CHILD_SCAN_END=0xa0
UE4SSL_CLIENT_UE_REFLECTION_VALUE_PROBE=false
UE4SSL_CLIENT_UE_REFLECTION_VALUE_MAX_BYTES=16
UE4SSL_CLIENT_UE_OBJECT_ARRAY_PROBE=false
UE4SSL_CLIENT_UE_OBJECT_ARRAY_MAX_OBJECTS=128
UE4SSL_CLIENT_UE_FNAME_PROBE=false
UE4SSL_CLIENT_UE_FNAME_POOL=
UE4SSL_CLIENT_UE_FNAME_BLOCKS_OFFSET=0x10
UE4SSL_CLIENT_UE_FNAME_STRIDE=2
UE4SSL_CLIENT_UE_FNAME_MAX_LENGTH=128
UE4SSL_CLIENT_UE_LAYOUT_SLOTS=8
UE4SSL_CLIENT_HOOK_SELF_TEST=false
UE4SSL_CLIENT_MOD_SELF_TEST=false
UE4SSL_CLIENT_LUA_SELF_TEST=false
UE4SSL_CLIENT_LUA_LIBRARY=
UE4SSL_CLIENT_LUA_SELF_TEST_SCRIPT=
UE4SSL_CLIENT_LUA_REFLECTION_SELF_TEST=false
UE4SSL_CLIENT_LUA_REFLECTION_RAW_SET_ENABLED=false
UE4SSL_CLIENT_LUA_REFLECTION_SELF_TEST_SCRIPT=
UE4SSL_CLIENT_UE_PROCESS_EVENT_HOOK_PROBE=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_HOOK_ADDRESS=
UE4SSL_CLIENT_UE_PROCESS_EVENT_ADDRESS=
UE4SSL_CLIENT_UE_PROCESS_EVENT_HOOK_SELF_TEST_TARGET=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_HOOK_INSTALL=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_HOOK_CALL_SELF_TEST=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK_ADDRESS=
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK_SELF_TEST_TARGET=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK_CALL_SELF_TEST=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT=8
UE4SSL_CLIENT_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=false
UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_LUA_SCRIPT=
UE4SSL_CLIENT_LUA_PROCESS_EVENT_SELF_TEST=false
UE4SSL_CLIENT_LUA_PROCESS_EVENT_SELF_TEST_SCRIPT=
UE4SSL_CLIENT_LUA_MODS_ENABLED=false
UE4SSL_CLIENT_LUA_MOD_SCRIPTS=
UE4SSL_CLIENT_LUA_MOD_ROOT=
UE4SSL_CLIENT_LUA_MOD_DISPATCH_SELF_TEST=false
UE4SSL_CLIENT_SCAN_MAX_HITS_PER_NEEDLE=16
UE4SSL_CLIENT_SCAN_MAX_MAPPING_BYTES=268435456
EOF

cat > "$stage/README.md" <<EOF
# target profile Linux Client Loader

Package: ${package_name}
Built: $(date -u +%Y-%m-%dT%H:%M:%SZ)
Source commit: $(git -C "$repo_root" rev-parse HEAD 2>/dev/null || printf unknown)
Platform: ${platform}

This is a native Linux client-process preload/probe for this repo. It is not
upstream UE4SS yet. It collects read-only runtime anchors from an ELF client
process and refuses Windows/PE Proton targets in the launch wrapper.

## Contents

- lib/libue4ssl_linux_client_loader.so: runtime preload library.
- src/: source used for this package.
- build-linux-client-loader.sh: local rebuild helper.
- examples/launch-native-client.sh: launch wrapper for a native ELF client.
- examples/smoke-linux-client-loader.sh: local smoke test.
- examples/env.scan.example: scan environment settings.
- analysis/: log summarizer, ELF xref, nearby-anchor, and UE readiness tools.
- tests/: unit tests for the packaged analysis tools.
- docs/client-loader-support.md: shared Linux/Windows support matrix.
- abi/: dependency and symbol-version report.
- SHA256SUMS: checksums for package contents.

## Native Client Launch

\`\`\`bash
examples/launch-native-client.sh -- /path/to/TargetGame-Linux-Shipping
\`\`\`

The wrapper uses \`LD_PRELOAD\` and does not edit Steam or game files. If the
target is a Windows/PE executable under Proton, it exits and reports that a
Windows DLL/proxy/injection path is required instead.

Large signature manifests should be passed with
\`UE4SSL_CLIENT_SCAN_SIGNATURES_FILE=/path/to/client-signatures.txt\`.
Validated UE anchor signatures should be passed separately with
\`UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES_FILE=/path/to/client-anchor-signatures.txt\`.

## Smoke Test

\`\`\`bash
examples/smoke-linux-client-loader.sh
\`\`\`

## Analysis

\`\`\`bash
analysis/summarize-client-loader-scan.py /tmp/ue4ssl-client-loader.log
analysis/summarize-linux-loader-xrefs.py /path/to/TargetGame-Linux-Shipping --loader-log /tmp/ue4ssl-client-loader.log --exe-substring TargetGame --category cheat
analysis/summarize-linux-loader-anchors.py /path/to/TargetGame-Linux-Shipping --loader-log /tmp/ue4ssl-client-loader.log --exe-substring TargetGame --category cheat
analysis/validate-elf-signatures.py /path/to/TargetGame-Linux-Shipping --loader-log /tmp/ue4ssl-client-loader.log --exe-substring TargetGame --category cheat
analysis/export-elf-signature-manifest.py /path/to/TargetGame-Linux-Shipping --loader-log /tmp/ue4ssl-client-loader.log --target-loader linux-client --exe-substring TargetGame --format signatures > client-signatures.txt
analysis/export-elf-signature-manifest.py /path/to/TargetGame-Linux-Shipping --loader-log /tmp/ue4ssl-client-loader.log --target-loader linux-client --exe-substring TargetGame --category ue --format anchor-signatures > client-anchor-signatures.txt
analysis/summarize-client-ue-anchors.py /tmp/ue4ssl-client-loader.log
analysis/export-ue-anchor-env.py /tmp/ue4ssl-client-loader.log --loader linux-client --platform linux > ue-anchors.env
analysis/prepare-ue-anchor-canary.py --platform linux-client --binary /path/to/TargetGame-Linux-Shipping --loader-log /tmp/ue4ssl-client-loader.log --output-dir build/linux-client-anchor-canary
analysis/plan-ue4ss-canary-env.py --platform linux-client --client-log /tmp/ue4ssl-client-loader.log --max-stage read-only > next-canary.env
analysis/ue4ss-port-readiness.py --client-log /tmp/ue4ssl-client-loader.log --loader linux-client
python3 _m unittest tests/test_client_loader_scan_summary.py tests/test_linux_loader_xrefs.py tests/test_linux_loader_anchors.py tests/test_elf_signatures.py tests/test_elf_signature_manifest.py tests/test_client_ue_anchors.py tests/test_ue4ss_port_readiness.py tests/test_export_ue_anchor_env.py tests/test_prepare_ue_anchor_canary.py tests/test_plan_ue4ss_canary_env.py
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
EOF

readelf -d "$loader" > "$stage/abi/readelf-dynamic.txt"
objdump -T "$loader" | grep -E 'GLIBC|GLIBCXX|CXXABI|GCC_' | sort -u > "$stage/abi/symbol-versions.txt" || true
file "$loader" > "$stage/abi/file.txt"

(
  cd "$stage"
  find . -type f ! -name SHA256SUMS -print | sort | sed 's#^\./##' | xargs sha256sum > SHA256SUMS
)

tar -C "$dist_root" -czf "$archive" "$package_name"
sha256sum "$archive" > "${archive}.sha256"

printf 'packaged Linux client loader: %s\n' "$archive"
printf 'package checksum: %s\n' "${archive}.sha256"
