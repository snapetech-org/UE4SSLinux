#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
build_script="$repo_root/scripts/build-linux-server-loader.sh"
build_dir="${UE4SSL_LINUX_SERVER_LOADER_BUILD_DIR:-$repo_root/build/linux-server-loader}"
loader="$build_dir/libue4ssl_linux_server_loader.so"
dist_root="${UE4SSL_LINUX_SERVER_LOADER_DIST_DIR:-$repo_root/dist/linux-server-loader}"
default_version="$(git -C "$repo_root" rev-parse --short HEAD 2>/dev/null || date -u +%Y%m%dT%H%M%SZ)"
if ! git -C "$repo_root" diff --quiet --ignore-submodules -- 2>/dev/null ||
   ! git -C "$repo_root" diff --cached --quiet --ignore-submodules -- 2>/dev/null; then
  default_version="${default_version}-dirty"
fi
version="${UE4SSL_LINUX_SERVER_LOADER_VERSION:-$default_version}"
platform="linux-x86_64"
package_name="ue4ssl-linux-server-loader-${version}-${platform}"
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
  "$stage/analysis" \
  "$stage/docs" \
  "$stage/profiles/dune" \
  "$stage/profiles/palworld" \
  "$stage/examples" \
  "$stage/abi"

cp "$loader" "$stage/lib/libue4ssl_linux_server_loader.so"
cp "$repo_root/runtime/linux-elf/ue4ssl_linux_server_loader.c" "$stage/src/ue4ssl_linux_server_loader.c"
cp "$repo_root/runtime/linux-elf/CMakeLists.txt" "$stage/src/CMakeLists.txt"
cp "$repo_root/analysis/summarize-linux-loader-scan.py" "$stage/analysis/summarize-linux-loader-scan.py"
cp "$repo_root/analysis/summarize-linux-loader-xrefs.py" "$stage/analysis/summarize-linux-loader-xrefs.py"
cp "$repo_root/analysis/summarize-linux-loader-anchors.py" "$stage/analysis/summarize-linux-loader-anchors.py"
cp "$repo_root/analysis/validate-elf-signatures.py" "$stage/analysis/validate-elf-signatures.py"
cp "$repo_root/analysis/export-elf-signature-manifest.py" "$stage/analysis/export-elf-signature-manifest.py"
cp "$repo_root/analysis/summarize-client-loader-scan.py" "$stage/analysis/summarize-client-loader-scan.py"
cp "$repo_root/analysis/export-ue-anchor-env.py" "$stage/analysis/export-ue-anchor-env.py"
cp "$repo_root/analysis/prepare-ue-anchor-canary.py" "$stage/analysis/prepare-ue-anchor-canary.py"
cp "$repo_root/analysis/plan-ue4ss-canary-env.py" "$stage/analysis/plan-ue4ss-canary-env.py"
cp "$repo_root/analysis/resolve-profile.py" "$stage/analysis/resolve-profile.py"
cp "$repo_root/scripts/smoke-linux-server-loader.sh" "$stage/examples/smoke-linux-server-loader.sh"
cp "$repo_root/docs/ue4ss-linux-loader-evaluation.md" "$stage/docs/ue4ss-linux-loader-evaluation.md"
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
if [ -f "$repo_root/docs/linux-server-loader-canary-2026-06-16.md" ]; then
  cp "$repo_root/docs/linux-server-loader-canary-2026-06-16.md" "$stage/docs/linux-server-loader-canary-2026-06-16.md"
fi
if [ -f "$repo_root/docs/current-build-runtime-surface-1988751.md" ]; then
  cp "$repo_root/docs/current-build-runtime-surface-1988751.md" "$stage/docs/current-build-runtime-surface-1988751.md"
fi

cat > "$stage/build-linux-server-loader.sh" <<'EOF'
#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source_dir="${UE4SSL_LINUX_SERVER_LOADER_SOURCE_DIR:-$script_dir/src}"
build_dir="${UE4SSL_LINUX_SERVER_LOADER_BUILD_DIR:-$script_dir/build}"
build_type="${CMAKE_BUILD_TYPE:-RelWithDebInfo}"

if ! command -v cmake >/dev/null 2>&1; then
  echo "cmake is required to build the Linux server loader" >&2
  exit 1
fi

generator=()
if command -v ninja >/dev/null 2>&1; then
  generator=(-G Ninja)
fi

cmake -S "$source_dir" -B "$build_dir" "${generator[@]}" -DCMAKE_BUILD_TYPE="$build_type"
build_args=(--build "$build_dir" --target ue4ssl_linux_server_loader)
if [ -n "${UE4SSL_LINUX_SERVER_LOADER_JOBS:-}" ]; then
  build_args+=(--parallel "$UE4SSL_LINUX_SERVER_LOADER_JOBS")
fi
cmake "${build_args[@]}"

loader="$build_dir/libue4ssl_linux_server_loader.so"
if [ ! -f "$loader" ]; then
  loader="$(find "$build_dir" -name libue4ssl_linux_server_loader.so -type f -print -quit)"
fi

if [ -z "$loader" ] || [ ! -f "$loader" ]; then
  echo "built target but did not find libue4ssl_linux_server_loader.so under $build_dir" >&2
  exit 1
fi

printf 'built Linux server probe loader: %s\n' "$loader"
EOF

chmod 0755 "$stage/build-linux-server-loader.sh"
chmod 0755 "$stage/analysis/summarize-linux-loader-scan.py"
chmod 0755 "$stage/analysis/summarize-linux-loader-xrefs.py"
chmod 0755 "$stage/analysis/summarize-linux-loader-anchors.py"
chmod 0755 "$stage/analysis/validate-elf-signatures.py"
chmod 0755 "$stage/analysis/export-elf-signature-manifest.py"
chmod 0755 "$stage/analysis/summarize-client-loader-scan.py"
chmod 0755 "$stage/analysis/export-ue-anchor-env.py"
chmod 0755 "$stage/analysis/prepare-ue-anchor-canary.py"
chmod 0755 "$stage/analysis/plan-ue4ss-canary-env.py"
chmod 0755 "$stage/analysis/resolve-profile.py"
chmod 0755 "$stage/examples/smoke-linux-server-loader.sh"
chmod 0755 "$stage/lib/libue4ssl_linux_server_loader.so"

cat > "$stage/examples/env.scan.example" <<'EOF'
# Opt-in runtime loader. Keep disabled until a deliberate canary restart.
UE4SSL_ENABLE_LINUX_SERVER_PRELOAD=true
UE4SSL_LINUX_SERVER_PRELOAD=/workspace/build/linux-server-loader/libue4ssl_linux_server_loader.so
UE4SSL_LINUX_SERVER_PRELOAD_PARTITIONS=7
UE4SSL_SERVER_LOG=/tmp/ue4ssl-server-loader.log
UE4SSL_SERVER_SNAPSHOT_DELAY_SECONDS=0

# Read-only runtime anchor scan.
UE4SSL_SERVER_SCAN_ENABLED=true
UE4SSL_SERVER_SCAN_PRESETS=building,brt,deep-desert,gm,cheat,core
UE4SSL_SERVER_SCAN_STRINGS=DeepDesert;ServerRequestBaseBackup;BaseBackupTool;BuildingSettings;CheatManager;PrintAllowedCommands;PartitionIndex;BuildableMapRegion;FuncomLiveServices;FarmHealth
UE4SSL_SERVER_SCAN_SIGNATURES=brt-action-guard=48 85 c0 74 0a 41 b6 01 41 80 7f 55 01 75 03
UE4SSL_SERVER_SCAN_SIGNATURES_FILE=
UE4SSL_SERVER_SCAN_MAX_HITS_PER_NEEDLE=16
UE4SSL_SERVER_SCAN_LOG_MAPPINGS=true
UE4SSL_SERVER_SCAN_MAX_MAPPING_BYTES=536870912

# Explicit read-only UE anchor probes. Fill these with runtime addresses from
# symbol/signature work or prior canary logs before enabling the deeper probes.
UE4SSL_SERVER_UE_ANCHORS=
UE4SSL_SERVER_UE_ANCHOR_SIGNATURES=
UE4SSL_SERVER_UE_ANCHOR_SIGNATURES_FILE=
UE4SSL_SERVER_UE_POINTER_PROBE=false
UE4SSL_SERVER_UE_LAYOUT_PROBE=false
UE4SSL_SERVER_UE_LAYOUT_SLOTS=8
UE4SSL_SERVER_UE_UOBJECT_PROBE=false
UE4SSL_SERVER_UE_REFLECTION_PROBE=false
UE4SSL_SERVER_UE_REFLECTION_NEXT_OFFSET=0x28
UE4SSL_SERVER_UE_REFLECTION_SUPER_OFFSET=0x30
UE4SSL_SERVER_UE_REFLECTION_CHILDREN_OFFSET=0x38
UE4SSL_SERVER_UE_REFLECTION_CHILD_PROPERTIES_OFFSET=0x40
UE4SSL_SERVER_UE_REFLECTION_PROPERTY_LINK_OFFSET=0x48
UE4SSL_SERVER_UE_REFLECTION_FUNCTION_LINK_OFFSET=0x50
UE4SSL_SERVER_UE_REFLECTION_FIELD_WALK=false
UE4SSL_SERVER_UE_REFLECTION_FIELD_NEXT_OFFSET=0x28
UE4SSL_SERVER_UE_REFLECTION_MAX_FIELDS=16
UE4SSL_SERVER_UE_REFLECTION_PROPERTY_PROBE=false
UE4SSL_SERVER_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET=0x30
UE4SSL_SERVER_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET=0x34
UE4SSL_SERVER_UE_REFLECTION_PROPERTY_FLAGS_OFFSET=0x38
UE4SSL_SERVER_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET=0x44
UE4SSL_SERVER_UE_REFLECTION_CONTAINER_CHILD_SCAN_START=0x48
UE4SSL_SERVER_UE_REFLECTION_CONTAINER_CHILD_SCAN_END=0xa0
UE4SSL_SERVER_UE_REFLECTION_VALUE_PROBE=false
UE4SSL_SERVER_UE_REFLECTION_VALUE_MAX_BYTES=16
UE4SSL_SERVER_UE_OBJECT_ARRAY_PROBE=false
UE4SSL_SERVER_UE_OBJECT_ARRAY_MAX_OBJECTS=128
UE4SSL_SERVER_UE_OBJECT_ARRAY_OFFSET=0
UE4SSL_SERVER_UE_OBJECT_ARRAY_ITEM_SIZE=24
UE4SSL_SERVER_UE_OBJECT_ARRAY_OBJECT_OFFSET=0
UE4SSL_SERVER_UE_OBJECT_ARRAY_CHUNK_SIZE=65536
UE4SSL_SERVER_UE_FNAME_PROBE=false
UE4SSL_SERVER_UE_FNAME_POOL=
UE4SSL_SERVER_UE_FNAME_POOL_ADDR=
UE4SSL_SERVER_UE_FNAME_POOL_OFFSET=0
UE4SSL_SERVER_UE_FNAME_BLOCKS_OFFSET=0x10
UE4SSL_SERVER_UE_FNAME_STRIDE=2
UE4SSL_SERVER_UE_FNAME_MAX_LENGTH=128
UE4SSL_SERVER_UE_SELF_TEST_ANCHOR=false

# Loader-owned UE4SS-style dispatch self-tests. Keep disabled in normal live operation.
UE4SSL_SERVER_HOOK_SELF_TEST=false
UE4SSL_SERVER_MOD_SELF_TEST=false
UE4SSL_SERVER_LUA_SELF_TEST=false
UE4SSL_SERVER_LUA_LIBRARY=
UE4SSL_SERVER_LUA_SELF_TEST_SCRIPT=
UE4SSL_SERVER_LUA_REFLECTION_SELF_TEST=false
UE4SSL_SERVER_LUA_REFLECTION_RAW_SET_ENABLED=false
UE4SSL_SERVER_LUA_REFLECTION_SELF_TEST_SCRIPT=
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_PROBE=false
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_ADDRESS=
UE4SSL_SERVER_UE_PROCESS_EVENT_ADDRESS=
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_SELF_TEST_TARGET=false
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_INSTALL=false
UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_CALL_SELF_TEST=false
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK=false
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_ADDRESS=
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_SELF_TEST_TARGET=false
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_CALL_SELF_TEST=false
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS=false
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT=8
UE4SSL_SERVER_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=false
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=false
UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_LUA_SCRIPT=
UE4SSL_SERVER_LUA_PROCESS_EVENT_SELF_TEST=false
UE4SSL_SERVER_LUA_PROCESS_EVENT_SELF_TEST_SCRIPT=
UE4SSL_SERVER_LUA_MODS_ENABLED=false
UE4SSL_SERVER_LUA_MOD_SCRIPTS=
UE4SSL_SERVER_LUA_MOD_DISPATCH_SELF_TEST=false
EOF

cat > "$stage/examples/smoke-cached-funcom-image.sh" <<'EOF'
#!/usr/bin/env bash
set -euo pipefail

image="${1:-registry.funcom.com/funcom/self-hosting/seabass-server:1988751-0-shipping}"
loader="${2:-$(pwd)/lib/libue4ssl_linux_server_loader.so}"
log=/tmp/ue4ssl-loader-image-scan.log

docker run --rm --pull never --network none \
  -v "$(dirname "$loader"):/probe:ro" \
  --entrypoint /bin/sh \
  "$image" \
  -lc "rm -f '$log'; UE4SSL_SERVER_LOG='$log' UE4SSL_SERVER_SNAPSHOT_DELAY_SECONDS=0 UE4SSL_SERVER_SCAN_ENABLED=true UE4SSL_SERVER_SCAN_PRESETS= UE4SSL_SERVER_SCAN_STRINGS='Usage:' UE4SSL_SERVER_SCAN_SIGNATURES='elf=7f 45 4c 46' UE4SSL_SERVER_SCAN_MAX_HITS_PER_NEEDLE=4 LD_PRELOAD=/probe/$(basename "$loader") /usr/bin/true; cat '$log'"
EOF
chmod 0755 "$stage/examples/smoke-cached-funcom-image.sh"

cat > "$stage/README.md" <<EOF
# target profile Linux Server Loader

Package: ${package_name}
Built: $(date -u +%Y-%m-%dT%H:%M:%SZ)
Source commit: $(git -C "$repo_root" rev-parse HEAD 2>/dev/null || printf unknown)
Platform: ${platform}

This is a native Linux server-process loader/probe for this target profile self-host repo.
It is not upstream UE4SS and does not install client mods. It is loaded into a
Linux dedicated-server process with LD_PRELOAD through scripts/run_server_safe.sh.
It supports read-only runtime scans, explicit UE anchor validation,
pointer/layout/UObject/object-array/FName probes, Lua object-handle registration
for UE candidates, and loader-owned hook/mod/Lua/ProcessEvent-shaped self-tests.

## Contents

- lib/libue4ssl_linux_server_loader.so: runtime preload library.
- src/: source used for this package.
- build-linux-server-loader.sh: local rebuild helper.
- scripts/: scan, xref, ELF signature, anchor export, and anchor report helpers.
- examples/env.scan.example: opt-in environment settings.
- examples/smoke-linux-server-loader.sh: local loader-owned dispatch/Lua smoke test.
- examples/smoke-cached-funcom-image.sh: one-off Docker smoke test for a cached image.
- abi/: dependency and symbol-version report.
- SHA256SUMS: checksums for package contents.

## Safe Smoke Test

Local smoke without live Compose or game containers:

\`\`\`bash
examples/smoke-linux-server-loader.sh
\`\`\`

On a host with the Funcom server image cached:

\`\`\`bash
cd ${package_name}
examples/smoke-cached-funcom-image.sh registry.funcom.com/funcom/self-hosting/seabass-server:1988751-0-shipping
\`\`\`

The smoke test uses \`--pull never --network none\` and exits after \`/usr/bin/true\`.
It does not touch live Compose containers.

## Live Canary Shape

For a live canary, copy \`lib/libue4ssl_linux_server_loader.so\` into a path mounted
readable in the target game container, set the variables from
\`examples/env.scan.example\`, then restart exactly one chosen map through the
repo restart/recovery scripts so post-start hooks still run.

Keep \`UE4SSL_SERVER_SCAN_ENABLED=false\` for normal operation after collecting
anchors.

## Reports

\`\`\`bash
analysis/summarize-linux-loader-scan.py /path/to/loader.log
analysis/export-ue-anchor-env.py /path/to/loader.log --loader server --platform server > ue-server-anchors.env
analysis/summarize-linux-loader-xrefs.py /path/to/TargetGameServer-Linux-Shipping --loader-log /path/to/loader.log --category brt
analysis/summarize-linux-loader-anchors.py /path/to/TargetGameServer-Linux-Shipping --loader-log /path/to/loader.log --category brt
analysis/validate-elf-signatures.py /path/to/TargetGameServer-Linux-Shipping --loader-log /path/to/loader.log --category brt
analysis/export-elf-signature-manifest.py /path/to/TargetGameServer-Linux-Shipping --loader-log /path/to/loader.log --target-loader server --format signatures > server-signatures.txt
analysis/export-elf-signature-manifest.py /path/to/TargetGameServer-Linux-Shipping --loader-log /path/to/loader.log --target-loader server --category ue --format anchor-signatures > server-anchor-signatures.txt
analysis/prepare-ue-anchor-canary.py --platform server --binary /path/to/TargetGameServer-Linux-Shipping --loader-log /path/to/loader.log --output-dir build/server-anchor-canary
analysis/plan-ue4ss-canary-env.py --platform server --server-log /path/to/loader.log --max-stage read-only > next-canary.env
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

printf 'packaged Linux server loader: %s\n' "$archive"
printf 'package checksum: %s\n' "${archive}.sha256"
