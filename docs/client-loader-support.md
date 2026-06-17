# Client Loader Support Matrix

Status on 2026-06-16: native Linux ELF and Windows/Proton client probe support
are both scaffolded and smoke-tested as read-only runtime probes, with an
additional opt-in loader-owned hook dispatch self-test. Confidence: high.

Observed on 2026-06-16: the staged Windows `version.dll` loaded inside the real
Proton client process
`TargetGame-Win64-Shipping.exe` and logged module images to
`/tmp/ue4ssl-win-client-probe-loader.log`. That launch did not inherit scan
environment, so it recorded `0` scan starts. The Windows sidecar fallback was
added after that observation; the next normal Steam launch with the staged
`ue4ssl-win.env` should scan without requiring launch environment
inheritance. Confidence: high for load, moderate until the next real scan log.

Follow-up on 2026-06-16: a later Steam launch started
`TargetGame-Win64-Shipping.exe`, but process maps showed Proton's builtin
`version.dll` was loaded instead of the staged game-directory proxy. For that
case use `scripts/proton-dll-override-control.sh --set` to write a per-app
`version=native,builtin` Wine override before the next client restart.
Confidence: high.

Final client canary on 2026-06-16: after setting the per-app Wine DLL override,
the real Proton client loaded the staged `VERSION.dll`, read
`ue4ssl-win.env`, and completed a full preset scan with
`strings=45`. See `docs/windows-client-loader-canary-2026-06-16.md`.
Confidence: high.

This is not UE4SS yet. Both client paths are loader/probe foundations for
runtime discovery with loader-owned hook, Lua dispatch, reflection, and
ProcessEvent-shaped self-tests. They do not yet marshal live Unreal
`FProperty` values, dispatch UE4SS Lua callbacks from a live game
`ProcessEvent` hook, or patch game memory. The persistent ProcessEvent hook
scaffold exists, but it currently only validates install/restore, logs bounded
calls when requested, and forwards to the original function. Confidence: high.

## Target Selection

Use the loader that matches the process format:

| Client process | Loader artifact | Launch path | File mutation |
| --- | --- | --- | --- |
| Native Linux ELF | `libue4ssl_linux_client_loader.so` | `LD_PRELOAD` through `scripts/launch-linux-client-probe.sh` | None |
| Windows PE under Proton/Wine | `ue4ssl_windows_proxy_loader.dll` staged as `version.dll` | `scripts/launch-proton-client-probe.sh --stage-to-game-dir -- %command%` | Adds/removes `version.dll` beside the game exe with manifest tracking |

Do not use the Linux `.so` for a Proton client. It cannot load into a Windows PE
process. Do not use the Windows DLL for a native Linux ELF client.

The installed target profile client on this host is Windows PE:

```text
~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe
```

The shipping executable imports `VERSION.dll`, including
`GetFileVersionInfoSizeW`, `GetFileVersionInfoW`, and `VerQueryValueW`, so the
`version.dll` proxy is a real Proton load point. Confidence: high.

## Parity

Both client loaders now provide:

| Capability | Linux ELF | Windows/Proton |
| --- | --- | --- |
| Read-only process load proof | Constructor log | `DllMain` worker-thread log |
| Module/image logging | `UE4SSL_CLIENT_LOG_MODULES=true` | `UE4SSL_WIN_LOG_MODULES=true` |
| String scan | `UE4SSL_CLIENT_SCAN_STRINGS` | `UE4SSL_WIN_SCAN_STRINGS` |
| Byte signature scan | `UE4SSL_CLIENT_SCAN_SIGNATURES` | `UE4SSL_WIN_SCAN_SIGNATURES` |
| Signature file scan | `UE4SSL_CLIENT_SCAN_SIGNATURES_FILE` | `UE4SSL_WIN_SCAN_SIGNATURES_FILE` |
| Explicit UE anchor validation | `UE4SSL_CLIENT_UE_ANCHORS` | `UE4SSL_WIN_UE_ANCHORS` |
| Signature-resolved UE anchors | `UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES`, `UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES_FILE` | `UE4SSL_WIN_UE_ANCHOR_SIGNATURES`, `UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE` |
| Read-only UE pointer probe | `UE4SSL_CLIENT_UE_POINTER_PROBE` | `UE4SSL_WIN_UE_POINTER_PROBE` |
| Read-only UE layout probe | `UE4SSL_CLIENT_UE_LAYOUT_PROBE` | `UE4SSL_WIN_UE_LAYOUT_PROBE` |
| Read-only UObject candidate probe | `UE4SSL_CLIENT_UE_UOBJECT_PROBE` | `UE4SSL_WIN_UE_UOBJECT_PROBE` |
| Read-only UE reflection probe | `UE4SSL_CLIENT_UE_REFLECTION_PROBE` | `UE4SSL_WIN_UE_REFLECTION_PROBE` |
| Bounded UE reflection field walk | `UE4SSL_CLIENT_UE_REFLECTION_FIELD_WALK` | `UE4SSL_WIN_UE_REFLECTION_FIELD_WALK` |
| Bounded FProperty descriptor probe | `UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_PROBE` | `UE4SSL_WIN_UE_REFLECTION_PROPERTY_PROBE` |
| Bounded container child property scan | `UE4SSL_CLIENT_UE_REFLECTION_CONTAINER_CHILD_SCAN_START`/`END` | `UE4SSL_WIN_UE_REFLECTION_CONTAINER_CHILD_SCAN_START`/`END` |
| Bounded reflected property value probe | `UE4SSL_CLIENT_UE_REFLECTION_VALUE_PROBE` | `UE4SSL_WIN_UE_REFLECTION_VALUE_PROBE` |
| Bounded object-array walk | `UE4SSL_CLIENT_UE_OBJECT_ARRAY_PROBE` | `UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE` |
| Bounded FName decoder | `UE4SSL_CLIENT_UE_FNAME_PROBE` | `UE4SSL_WIN_UE_FNAME_PROBE` |
| Guarded hook dispatch self-test | `UE4SSL_CLIENT_HOOK_SELF_TEST` | `UE4SSL_WIN_HOOK_SELF_TEST` |
| Guarded ProcessEvent target hook probe | `UE4SSL_CLIENT_UE_PROCESS_EVENT_HOOK_PROBE` | `UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE` |
| Persistent ProcessEvent hook scaffold | `UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK` | `UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK` |
| Live ProcessEvent Lua callback bridge | `UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH` | `UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH` |
| Native mod dispatch self-test | `UE4SSL_CLIENT_MOD_SELF_TEST` | `UE4SSL_WIN_MOD_SELF_TEST` |
| Lua runtime execution self-test | `UE4SSL_CLIENT_LUA_SELF_TEST`, `UE4SSL_CLIENT_LUA_LIBRARY` | `UE4SSL_WIN_LUA_SELF_TEST`, `UE4SSL_WIN_LUA_DLL` |
| Typed Lua reflection/property self-test | `UE4SSL_CLIENT_LUA_REFLECTION_SELF_TEST` | `UE4SSL_WIN_LUA_REFLECTION_SELF_TEST` |
| Lua ProcessEvent-shaped hook self-test | `UE4SSL_CLIENT_LUA_PROCESS_EVENT_SELF_TEST` | `UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST` |
| Lua mod entrypoints | `UE4SSL_CLIENT_LUA_MODS_ENABLED`, `UE4SSL_CLIENT_LUA_MOD_ROOT` | `UE4SSL_WIN_LUA_MODS_ENABLED`, `UE4SSL_WIN_LUA_MOD_ROOT` |
| Post-canary xref/anchor analysis | `summarize-linux-loader-xrefs.py`, `summarize-linux-loader-anchors.py` | `summarize-client-loader-xrefs.py` |
| Built-in presets | `core,ue,client,cheat,brt,deep-desert` | `core,ue,client,cheat,brt,deep-desert` |
| Hit coordinates | runtime address, image offset, file offset | runtime address, module RVA, region base |
| Scan size guard | `UE4SSL_CLIENT_SCAN_MAX_MAPPING_BYTES` | `UE4SSL_WIN_SCAN_MAX_REGION_BYTES` |
| Hit-count guard | `UE4SSL_CLIENT_SCAN_MAX_HITS_PER_NEEDLE` | `UE4SSL_WIN_SCAN_MAX_HITS_PER_NEEDLE` |
| Path filters | `UE4SSL_CLIENT_SCAN_PATH_FILTER` | `UE4SSL_WIN_SCAN_PATH_FILTER` |
| Launch-env fallback | not needed for `LD_PRELOAD` | `ue4ssl-win.env` sidecar beside proxy DLL |
| Proton builtin override | not applicable | `scripts/proton-dll-override-control.sh --set` |
| Read-only default | yes | yes, `MEM_IMAGE` only |
| Smoke script | `scripts/smoke-linux-client-loader.sh` | `scripts/smoke-windows-client-loader.sh` |
| Real Lua runtime smoke | included in default smoke through `liblua5.4.so` | `make smoke-windows-client-loader-lua` stages pinned LuaBinaries 5.4.8 when no DLL is set |
| Full local parity smoke | `make smoke-linux-client-loader` | `make smoke-windows-client-loader-full` |
| Package script | `scripts/package-linux-client-loader.sh` | `scripts/package-windows-client-loader.sh` |

The Windows path has an extra proxy-forwarding smoke because it must preserve
the `version.dll` API surface expected by the game. The Linux path has no
equivalent forwarding layer because `LD_PRELOAD` does not replace a game DLL.

## Native Linux ELF Runbook

Build:

```bash
scripts/build-linux-client-loader.sh
```

Smoke:

```bash
scripts/smoke-linux-client-loader.sh
```

Launch a native ELF client:

```bash
scripts/launch-linux-client-probe.sh -- /path/to/TargetGame-Linux-Shipping
```

Default log:

```text
/tmp/ue4ssl-client-loader.log
```

Useful environment:

```dotenv
UE4SSL_CLIENT_LOG=/tmp/ue4ssl-client-loader.log
UE4SSL_CLIENT_FORCE=true
UE4SSL_CLIENT_LOG_MODULES=true
UE4SSL_CLIENT_SCAN_ENABLED=true
UE4SSL_CLIENT_SCAN_PRESETS=core,ue,client,cheat,brt,deep-desert
UE4SSL_CLIENT_SCAN_STRINGS=ProcessEvent;FNamePool;GUObjectArray;CheatManager
UE4SSL_CLIENT_SCAN_SIGNATURES=name=48 8b ?? ?? 48 85 c0
UE4SSL_CLIENT_SCAN_SIGNATURES_FILE=/path/to/client-signatures.txt
UE4SSL_CLIENT_UE_ANCHORS=FNamePool=0x0;GUObjectArray=0x0;GWorld=0x0;ProcessEvent=0x0
UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES=
UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES_FILE=/path/to/client-anchor-signatures.txt
UE4SSL_CLIENT_UE_POINTER_PROBE=false
UE4SSL_CLIENT_UE_LAYOUT_PROBE=false
UE4SSL_CLIENT_UE_UOBJECT_PROBE=false
UE4SSL_CLIENT_UE_REFLECTION_PROBE=false
UE4SSL_CLIENT_UE_REFLECTION_FIELD_WALK=false
UE4SSL_CLIENT_UE_REFLECTION_FIELD_NEXT_OFFSET=0x28
UE4SSL_CLIENT_UE_REFLECTION_MAX_FIELDS=16
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_PROBE=false
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET=0x30
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET=0x34
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_FLAGS_OFFSET=0x38
UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET=0x44
UE4SSL_CLIENT_UE_REFLECTION_FUNCTION_FLAGS_OFFSET=0x58
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
UE4SSL_CLIENT_GAME_DIR=
UE4SSL_CLIENT_UNREAL_VERSION_MAJOR=5
UE4SSL_CLIENT_UNREAL_VERSION_MINOR=0
UE4SSL_CLIENT_SCAN_MAX_HITS_PER_NEEDLE=16
UE4SSL_CLIENT_SCAN_MAX_MAPPING_BYTES=268435456
```

The Linux launch wrapper refuses Windows/PE targets and reports that the Proton
DLL path is required.

## Windows/Proton Runbook

Build:

```bash
scripts/build-windows-client-loader.sh
```

Smoke:

```bash
scripts/smoke-windows-client-loader.sh
```

The default Windows smoke proves loader, scan, proxy forwarding, hook, mod,
object-array, FName, and Lua missing-DLL behavior. It does not prove a real
Windows Lua runtime. Run the parity smoke to stage a pinned LuaBinaries 5.4.8
`lua54.dll` under `build/` and execute the real Lua path:

```bash
make smoke-windows-client-loader-lua
```

before treating Windows/Proton Lua dispatch parity as fully validated.
Confidence: high.

Recommended Steam launch option for the installed target profile client:

```bash
scripts/launch-proton-client-probe.sh --stage-to-game-dir -- %command%
```

This stages:

```text
~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/version.dll
~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/ue4ssl-win.env
```

and records:

```text
build/windows-client-loader/game-dir-stage-manifest.txt
```

Default log:

```text
/tmp/ue4ssl-win-client-probe-loader.log
```

Useful environment:

```dotenv
UE4SSL_WIN_LOG=Z:\tmp\ue4ssl-win-loader.log
UE4SSL_WIN_LOG_MODULES=true
UE4SSL_WIN_SCAN_ENABLED=true
UE4SSL_WIN_SCAN_PRESETS=core,ue,client,cheat,brt,deep-desert
UE4SSL_WIN_SCAN_STRINGS=ProcessEvent;FNamePool;GUObjectArray;CheatManager
UE4SSL_WIN_SCAN_SIGNATURES=name=48 8b ?? ?? 48 85 c0
UE4SSL_WIN_SCAN_SIGNATURES_FILE=Z:\path\to\client-signatures.txt
UE4SSL_WIN_UE_ANCHORS=FNamePool=0x0;GUObjectArray=0x0;GWorld=0x0;ProcessEvent=0x0
UE4SSL_WIN_UE_ANCHOR_SIGNATURES=
UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE=Z:\path\to\client-anchor-signatures.txt
UE4SSL_WIN_UE_POINTER_PROBE=false
UE4SSL_WIN_UE_LAYOUT_PROBE=false
UE4SSL_WIN_UE_UOBJECT_PROBE=false
UE4SSL_WIN_UE_REFLECTION_PROBE=false
UE4SSL_WIN_UE_REFLECTION_FIELD_WALK=false
UE4SSL_WIN_UE_REFLECTION_FIELD_NEXT_OFFSET=0x28
UE4SSL_WIN_UE_REFLECTION_MAX_FIELDS=16
UE4SSL_WIN_UE_REFLECTION_PROPERTY_PROBE=false
UE4SSL_WIN_UE_REFLECTION_PROPERTY_ARRAY_DIM_OFFSET=0x30
UE4SSL_WIN_UE_REFLECTION_PROPERTY_ELEMENT_SIZE_OFFSET=0x34
UE4SSL_WIN_UE_REFLECTION_PROPERTY_FLAGS_OFFSET=0x38
UE4SSL_WIN_UE_REFLECTION_PROPERTY_OFFSET_INTERNAL_OFFSET=0x44
UE4SSL_WIN_UE_REFLECTION_FUNCTION_FLAGS_OFFSET=0x58
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
UE4SSL_WIN_GAME_DIR=
UE4SSL_WIN_UNREAL_VERSION_MAJOR=5
UE4SSL_WIN_UNREAL_VERSION_MINOR=0
UE4SSL_WIN_SCAN_MAX_HITS_PER_NEEDLE=16
UE4SSL_WIN_SCAN_MAX_REGION_BYTES=268435456
UE4SSL_WIN_SCAN_PRIVATE=false
```

The same keys are valid in `ue4ssl-win.env`. The launch wrapper
writes the sidecar automatically during staging, and process environment values
override sidecar values if both are present. This covers normal Steam launches
where the proxy DLL loads but the wrapper environment was not inherited.

Remove the staged proxy if it still matches the current probe:

```bash
scripts/launch-proton-client-probe.sh --unstage-game-dir
```

The wrapper backs up an unrelated preexisting `version.dll` before replacing it.
Manifest-owned probe DLLs are restaged without accumulating backups.

If `/proc/<pid>/maps` shows Proton's builtin `version.dll` instead of the staged
game-directory proxy, set the per-app Wine DLL override:

```bash
scripts/proton-dll-override-control.sh --set
scripts/proton-dll-override-control.sh --query
```

Unset it with:

```bash
scripts/proton-dll-override-control.sh --unset
```

## Packaging

Build both client packages:

```bash
make package-client-loaders
```

Outputs:

```text
dist/linux-client-loader/
dist/windows-client-loader/
```

Each package includes source, build helper, launch helper, smoke helper, docs,
ABI/header reports, and `SHA256SUMS`.

## Analysis Tools

Summarize a Linux or Windows client probe log:

```bash
analysis/summarize-client-loader-scan.py /tmp/ue4ssl-win-client-probe-loader.log
```

Summarize UE anchor readiness from the same log:

```bash
analysis/summarize-client-ue-anchors.py /tmp/ue4ssl-win-client-probe-loader.log
```

For a native Linux ELF client, map runtime scan hits back into the ELF file and
rank simple code xrefs:

```bash
analysis/summarize-linux-loader-xrefs.py \
  /path/to/TargetGame-Linux-Shipping \
  --loader-log /tmp/ue4ssl-client-loader.log \
  --exe-substring TargetGame \
  --category cheat \
  --category brt
```

Validate Linux ELF seed uniqueness and export a line-based runtime signature
file:

```bash
analysis/validate-elf-signatures.py \
  /path/to/TargetGame-Linux-Shipping \
  --loader-log /tmp/ue4ssl-client-loader.log \
  --exe-substring TargetGame \
  --category cheat \
  --category brt

analysis/export-elf-signature-manifest.py \
  /path/to/TargetGame-Linux-Shipping \
  --loader-log /tmp/ue4ssl-client-loader.log \
  --target-loader linux-client \
  --exe-substring TargetGame \
  --category cheat \
  --category brt \
  --format signatures

analysis/export-elf-signature-manifest.py \
  /path/to/TargetGame-Linux-Shipping \
  --loader-log /tmp/ue4ssl-client-loader.log \
  --target-loader linux-client \
  --exe-substring TargetGame \
  --category ue \
  --format anchor-signatures
```

For full native Linux manifests, prefer the `signatures` output and point
`UE4SSL_CLIENT_SCAN_SIGNATURES_FILE` at it. The JSON output is the
cross-build revalidation artifact. Use `anchor-signatures` for validated UE
anchor rows and point `UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES_FILE` at that
file during the next read-only canary. Confidence: high for synthetic ELF
validator coverage.

For a full second-pass native Linux canary bundle, generate all anchor inputs
and the readiness report together:

```bash
analysis/prepare-ue-anchor-canary.py \
  --platform linux-client \
  --binary /path/to/TargetGame-Linux-Shipping \
  --loader-log /tmp/ue4ssl-client-loader.log \
  --output-dir build/linux-client-loader/client-anchor-canary

analysis/plan-ue4ss-canary-env.py \
  --platform linux-client \
  --client-log /tmp/ue4ssl-client-loader.log \
  --max-stage read-only \
  > build/linux-client-loader/next-canary.env
```

For the Windows/Proton client, map runtime scan hits back into the PE file and
rank simple code xrefs:

```bash
analysis/summarize-client-loader-xrefs.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --category deep-desert \
  --show-context \
  --show-seeds
```

This is the bridge from read-only runtime canary to static signature work. It
uses loader `rva` values, PE section headers, and x86-64 RIP-relative/call/jump
patterns; it does not patch or inject anything further. The `--show-seeds`
output wildcards the relative displacement inside each xref instruction and is
a seed for later cross-build validation, not a final signature. Confidence:
high.

Validate Windows/Proton seed uniqueness:

```bash
analysis/validate-client-pe-signatures.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt
```

Only `unique-expected` seeds should move into build-check manifests. Everything
else remains useful context but is not durable enough to gate patch/hook work.
Confidence: high.

Export the validated Windows/Proton manifest or runtime scan chunks:

```bash
analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --format json

analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --format env

analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --format signatures

analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category ue \
  --format anchor-signatures
```

For full Windows/Proton manifests, prefer the `signatures` output and point
`UE4SSL_WIN_SCAN_SIGNATURES_FILE` at it. The env output is chunked
for sidecar/env value limits; use one chunk per client launch and do not
concatenate all chunks into a single sidecar value. Use `anchor-signatures` for
validated UE anchor rows and point
`UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE` at that file during the next
read-only Proton canary. Confidence: high.

Revalidate an exported Windows/Proton manifest after a client update:

```bash
analysis/validate-client-pe-signatures.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --manifest-json build/windows-client-loader/client-pe-signature-manifest.json \
  --ignore-expected-offsets
```

Use exact-offset validation without `--ignore-expected-offsets` for same-build
proof. Use offset-ignored validation for a new build to separate moved unique
signatures from missing or ambiguous signatures before runtime canary work.
Confidence: high.

Rank Proton proxy fallback DLLs from the target profile PE import table:

```bash
analysis/proton-proxy-candidates.py ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe
```

Current ranking on this host puts `version.dll` first because the executable
imports it directly, it has a small forwarding surface, and the existing
`version.dll` is manifest-owned by our probe. Fallbacks if `version.dll` fails
are `dxgi.dll`, `winmm.dll`, `xinput1_3.dll`, `d3d9.dll`, `d3d11.dll`, and
`dsound.dll`, in that order from the current import-table evidence. Confidence:
moderate until a real target profile launch log proves `version.dll` loads early enough.

## Interpreting Logs

First validate load:

```text
event=loaded
event=module
```

Then validate scan setup:

```text
event=scan-start
event=scan-hit
event=scan-finish
```

If explicit UE anchors are configured, validate them separately:

```text
event=ue-anchor-start
event=ue-anchor name=<anchor> status=mapped
event=ue-anchor-finish
event=ue-pointer name=<anchor> status=target-mapped
event=ue-layout name=<anchor> status=target-readable
event=ue-layout-slot name=<anchor> status=target-mapped
event=ue-uobject name=<anchor> status=candidate
event=hook-dispatch-self-test status=passed
event=ue-process-event-hook status=passed
event=ue-process-event-dispatch-self-test status=armed
event=ue-process-event-live-hook status=installed
event=mod-dispatch-self-test status=passed
event=lua-dispatch-self-test status=passed
```

`status=unmapped` is a blocker for that anchor and does not count toward
object-discovery readiness. `ue-pointer status=target-mapped` is the next gate:
it means the anchor can be read as a pointer-sized value and the value lands in
mapped memory. `ue-layout-slot status=target-mapped` is the next bounded layout
signal. `ue-uobject status=candidate classMapped=true` means the pointed-to
target has readable `UObjectBase`-shaped fields and its `ClassPrivate` value is
mapped. It still does not prove the full Unreal layout is correct.

`UE4SSL_CLIENT_UE_ANCHOR_SIGNATURES` and
`UE4SSL_WIN_UE_ANCHOR_SIGNATURES` use the same `name=aa bb ??`
syntax as normal scan signatures, but only unique runtime matches are promoted
to UE anchors. Missing and ambiguous matches log
`event=ue-anchor-signature status=missing|ambiguous` and are ignored for deeper
pointer/layout/UObject probes. Add `@hit+N`, `@riprel32+N`, `@callrel32`, or
`@ptr+N` to the signature name when the match is an instruction or pointer
slot rather than the anchor address itself, for example
`GWorld@riprel32+3=48 8b 0d ?? ?? ?? ??`. Confidence: high.

`hook-dispatch-self-test status=passed` proves only the platform hook
substrate: write an absolute jump into loader-owned code, dispatch to a
replacement function, run a pre-callback, call the original bytes through a
generated trampoline, run a post-callback, restore the original bytes, and keep
executing. It is not a `ProcessEvent` hook and it is deliberately disabled by
default. Confidence: high.

`mod-dispatch-self-test status=passed` proves the native mod lifecycle and
callback registry: load a mod entry, register pre/post hook callbacks, dispatch
around an original-call context, and unload the mod entry. This is the layer a
Lua runtime will attach to; it is not Lua execution yet. Confidence: high.

`lua-dispatch-self-test status=passed` proves a Lua VM was loaded dynamically,
a script was compiled/executed through the Lua C API, Lua called the
loader-provided `RegisterHook` function, native code recorded the hook name,
native code stored the Lua pre/post callbacks, native code invoked both
callbacks, `UnregisterHook` removed a temporary hook pair, and the script
result was read back. `RegisterHook` returns UE4SS-shaped `preId, postId`
values. ProcessEvent routing self-tests intentionally keep a non-target hook
registered ahead of the target hook, so the target hook's first id is `4` in
those logs. Native Linux can use system
`liblua`; Windows/Proton needs a staged Lua DLL named by
`UE4SSL_WIN_LUA_DLL` or available under a common DLL name. Use
`scripts/stage-windows-lua-runtime.sh` or `make smoke-windows-client-loader-lua`
to stage the pinned local test DLL. A complete
pass includes `callbackStatus=0 preCalls=1 postCalls=1 preResult=11
postResult=31` and the API surface counters
`staticFindObjectCalls=1 findFirstOfCalls=1 staticConstructObjectCalls=1
notifyOnNewObjectCalls=1 executeInGameThreadCallbacks=1`. The object API check
now also requires `staticFindObjectHits=1 findFirstOfHits=1
findAllOfHits=1 loadAssetHits=1 staticConstructObjectHits=1`, proving the
lookup calls returned loader object-handle tables, class enumeration works
through both `FindObjects` and `FindAllOf`, `LoadAsset` resolves an already
known handle, and synthetic construction returned a handle instead of `nil`.
`LoadAsset` is loader-owned here too: it is a registry lookup by path/name, not
package loading. `StaticConstructObject` is loader-owned here: it creates a
bounded `/RuntimeProbe/Constructed/<Name>` registry handle and does not
allocate a live Unreal object. It preserves `ClassAddress` when the class
argument is a known object or `UClass` handle. If
`NotifyOnNewObject(filter, callback)` has a
matching loader-owned class/path/name filter, synthetic construction dispatches
every matching callback with the constructed handle and logs
`notifyOnNewObjectCallbacks`, `notifyOnNewObjectResult`,
`notifyOnNewObjectIsNumber`, and `notifyOnNewObjectStatus`. This is still not a
live Unreal construction hook. Live target profile object handles still require validated
GUObjectArray/FNamePool anchors from the target build. Class-mapped
`ue-uobject` probe candidates are added as `/RuntimeProbe/<AnchorName>` handles
and logged with `event=lua-object-registry source=ue-uobject status=added`.
When FName decoding succeeds, the same object is also exposed as
`/RuntimeProbe/<DecodedName>` with `source=ue-uobject-fname`; later object-array
aliases for the same decoded name/address are logged as `status=skipped` so the
registry remains stable.
Confidence: high for Linux on this host, moderate for Windows until a real Lua
DLL is staged.

Set `UE4SSL_CLIENT_UE_FNAME_PROBE=true` or
`UE4SSL_WIN_UE_FNAME_PROBE=true` after a valid `FNamePool`/`GName`
anchor is configured. The bounded decoder reads UE-style block entries and logs
`event=ue-fname status=decoded` for UObject/object-array candidates whose
`NamePrivate` fields resolve. Confidence: high for the self-test fixture,
moderate for live target profile until same-build FNamePool anchors are validated.

Set `UE4SSL_CLIENT_UE_REFLECTION_PROBE=true` or
`UE4SSL_WIN_UE_REFLECTION_PROBE=true` after pointer, UObject, and
FName probes are stable. The probe reads the candidate object's class pointer,
logs `event=ue-reflection status=class-mapped`, and classifies configured
UClass/field slots with `event=ue-reflection-slot`. Slot offsets are
environment-configurable and default to the synthetic self-test layout. This is
read-only metadata telemetry; it does not marshal live `FProperty` values.
Confidence: high for the self-test fixture, moderate for live target profile until
offsets are validated against the current build.

Set `UE4SSL_CLIENT_UE_REFLECTION_FIELD_WALK=true` or
`UE4SSL_WIN_UE_REFLECTION_FIELD_WALK=true` only after the class/slot
probe is stable. The loader walks bounded `children`, `childProperties`,
`propertyLink`, and `functionLink` chains from the configured UClass offsets,
logs `event=ue-reflection-field status=candidate`, and decodes field names
through the FName reader when enabled. `*_UE_REFLECTION_FIELD_NEXT_OFFSET`
defaults to `0x28`, and `*_UE_REFLECTION_MAX_FIELDS` defaults to `16` with a
hard clamp. This proves candidate `FField`/`UField` chain visibility, not live
property marshaling. Confidence: high for the self-test fixture, moderate for
live target profile until current-build offsets are validated.

Set `UE4SSL_CLIENT_UE_REFLECTION_PROPERTY_PROBE=true` or
`UE4SSL_WIN_UE_REFLECTION_PROPERTY_PROBE=true` after field walking
is stable. This implies the bounded field walk and reads property-shaped
descriptor fields from `childProperties` and `propertyLink`: `ArrayDim`,
`ElementSize`, `PropertyFlags`, and `Offset_Internal`. It logs
`event=ue-reflection-property status=candidate`. Offsets default to UE4-style
values but must be validated per Funcom build before live marshaling.
For each bounded `functionLink` candidate, the same probe also reads the
configured `FunctionFlags` slot plus function-level `childProperties` and
`propertyLink` roots, then emits `event=ue-function-param-root` plus
`event=ue-function-param` descriptor lines when param metadata is readable.
Readable descriptors and readable `FunctionFlags` values are promoted into
the bounded live `UFunction` param registry, and
`GetFunctionParamDescriptors(function)`/`GetFunctionParams(function)` returns
them when Lua passes the matching live function handle. This is equal for native
Linux and Windows/Proton. When the `functionLink` FName decodes, the descriptor
log also carries `functionName` and `functionPath`, and Lua
`ctx.Function.PathName`/`GetFunctionParams(ctx.Function)` use that
`/RuntimeProbe/<owner>.<function>:Function` identity. This is a runtime-probe
identity, not a resolved Unreal package path yet. When the FName decoder can
read the parameter field's class object, the registry also carries
`fieldClassName`/`ClassName`, so Lua can
distinguish scalar, bool, and object-pointer params. This is not full live
`FProperty` marshaling for strings, names, arrays, structs, or complex out-param
lifetimes.
Confidence: high for the self-test fixture, moderate for live target profile until
current-build offsets are validated.

Set `UE4SSL_CLIENT_UE_REFLECTION_VALUE_PROBE=true` or
`UE4SSL_WIN_UE_REFLECTION_VALUE_PROBE=true` after descriptor offsets
are stable. This implies the descriptor probe and reads up to
`*_UE_REFLECTION_VALUE_MAX_BYTES` raw bytes from the owning object at
`Offset_Internal`, logging `event=ue-reflection-value status=read` with
`fieldName`, `raw`, and `rawLe`. Successful reads are also registered as
read-only Lua raw property candidates keyed by decoded field names such as
`SelfTestUObjectName_0` when the FName reader is available, with positional
fallback keys such as `propertyLink[0]`; Lua `GetPropertyValue` re-reads
1/2/4/8-byte scalar candidates from the owning object through the same guarded
memory checks. The self-test queries `/RuntimeProbe/SelfTestUObject` by decoded
field name first and falls back to the positional raw path when needed. If
`*_LUA_REFLECTION_RAW_SET_ENABLED=true`, `SetPropertyValue` can write bounded
1/2/4/8-byte scalar candidates only when the destination range is writable; keep
it false for read-only canaries. The smoke fixture enables it only against
loader-owned memory and expects `namedPropertyHits=2 rawPropertySetHits=1
rawPropertySetValue=17`.
This proves bounded container-byte visibility and Lua-visible live raw scalar
get/set; it is not typed `FProperty` marshaling. Confidence: high for the
self-test fixture, moderate for live target profile until current-build offsets are
validated.

For container params, the reflection probe also performs a bounded pointer-slot
scan across `FArrayProperty`, `FSetProperty`, and `FMapProperty` descriptors.
Decoded candidates emit `event=ue-function-param-container-child` with role
`inner`, `element`, `key`, or `value`, plus child property/class names when the
FName resolver can decode them. The scan window defaults to `0x48..0xa0` and is
controlled by `*_UE_REFLECTION_CONTAINER_CHILD_SCAN_START` and
`*_UE_REFLECTION_CONTAINER_CHILD_SCAN_END`. The readiness key is
`ueFunctionParamContainerChildren`; it proves metadata needed for future typed
container element unmarshaling, not the element unmarshaling itself. Promoted
live param descriptors expose the decoded children to Lua as `ContainerChildren`
plus UE4SS-style accessors/fields: arrays use `GetInner()` and `Inner*`, sets
use `GetElementProperty()`/`GetElementProp()` and `Element*`, and maps use
`GetKeyProperty()`/`GetKeyProp()` plus `GetValueProperty()`/`GetValueProp()` and
`Key*`/`Value*`.

The Lua object-registry surface now includes `StaticFindObject`,
`FindObject`, `FindFirstOf`, `GetKnownObjects`, `FindObjects`, `FindAllOf`,
`ForEachUObject`, `IsA`, and `LoadAsset` on native Linux and Windows/Proton
clients. `GetKnownObjects()`, `FindObjects()`, and `FindAllOf()` return tables
keyed by runtime `PathName` plus `Count`; `ForEachUObject(callback[, class])`
iterates the same bounded registry; and `IsA(object, class)` checks the handle
class or base `UObject`. `LoadAsset(pathOrName)` currently returns an existing
registry handle and returns `nil` for unknown paths; it is not package loading
or async asset streaming. The backing registry currently contains loader
self-test handles, class-mapped `ue-uobject` candidates, bounded object-array
candidates, and loader-owned synthetic objects. It is an API-compatible staging
point for a real `GUObjectArray` backend, not full global UObject enumeration
yet.

Every returned object/function handle now carries UE4SS-style methods:
`GetFullName`, `GetName`, `GetPathName`, `GetAddress`, `IsValid`, `GetClass`,
`GetOuter`, `GetWorld`, `GetFName`, `type`, `IsClass`, `IsAnyClass`, `IsA`,
`HasAllFlags`, `HasAnyFlags`, `HasAnyInternalFlags`, `GetPropertyValue`,
`SetPropertyValue`, `CallFunction`, `ProcessConsoleExec`, `ULocalPlayerExec`,
`GetFunctionFlags`, `SetFunctionFlags`, `GetSuperStruct`, `ForEachFunction`,
`ForEachProperty`, `GetCDO`, `IsChildOf`, and `GetLevel`. These methods are
equal across native Linux, Linux server, and Windows/Proton loaders. Handles
also expose `ClassAddress`, `OuterAddress`, `SuperAddress`, `ObjectFlags`,
`InternalIndex`, `HasObjectMetadata`, `InternalFlags`, `HasInternalFlags`,
`FunctionFlags`, and `HasFunctionFlags` when scan metadata is available.
`GetClass` returns a `UClass` handle named from the
registry `ClassName`; its `Address` is the live scanned `ClassPrivate` pointer
when available and zero for purely synthetic registry entries. `GetOuter`
resolves the loader-owned outer for synthetic objects created by
`StaticConstructObject` and otherwise returns `nil`; `GetSuperStruct` prefers a
scanned `SuperAddress` and otherwise returns a synthetic `UObject` class for
non-`UObject` synthetic `UClass` handles or `nil`; `GetWorld` returns the
handle itself for registered world-like handles, resolves loader-owned
`OuterAddress` chains to a registered world, and can fall back to a registered
`GWorld`/`UWorld`-like handle for common world-context classes. It is not a
live engine `UObject::GetWorld` call yet. `GetCDO` returns a loader-owned
`Default__<Class>` handle for `UClass` handles with `RF_ClassDefaultObject`
set; it is not the live engine class-default object yet. `GetLevel` returns a
registered level-like handle for level objects and loader-owned outer chains;
it is not a live `AActor::GetLevel` call yet;
`IsChildOf` is truthful for loader-owned self/base-class checks and walks the
bounded scan-derived `SuperAddress` chain when both class handles carry live
addresses; it is not full `GUObjectArray`-backed hierarchy enumeration yet.
`ProcessConsoleExec` dispatches loader-owned
`RegisterProcessConsoleExecPreHook` callbacks, then
`RegisterConsoleCommandHandler`/`RegisterConsoleCommandGlobalHandler`
callbacks, then `RegisterProcessConsoleExecPostHook` callbacks. Console exec
hooks receive `(context, rawCommand, command, args, handled)` and may return
boolean true to mark the command handled. It does not hook live engine console
routing yet;
`ULocalPlayerExec` dispatches loader-owned
`RegisterULocalPlayerExecPreHook` callbacks and
`RegisterULocalPlayerExecPostHook` callbacks with the same
`(context, rawCommand, command, args, handled)` shape. It is a distinct
loader-owned dispatcher and does not hook live `ULocalPlayer::Exec` yet;
`CallFunction` dispatches loader-owned
`RegisterCallFunctionByNameWithArgumentsPreHook` callbacks before its bounded
self-test function shim and `RegisterCallFunctionByNameWithArgumentsPostHook`
callbacks after it. Call-function hooks receive
`(context, functionName, args, handled, result)` and may return
`replacement, true` to short-circuit or replace the result. It does not hook the
live engine `UObject::CallFunctionByNameWithArguments` path yet;
`lua-mod-finish` reports per-family hook counts and call/handled totals for
loader-owned console exec, local-player exec, and call-function hooks, so
canary logs can prove those paths without inspecting mod source;
`HasAllFlags`/`HasAnyFlags` use promoted `ObjectFlags` for scanned UObject
candidates and keep conservative zero-flag behavior for synthetic-only handles;
`HasAnyInternalFlags` uses promoted `InternalFlags` when the object-array item
flags word is readable and returns false for handles without decoded internal
flag metadata;
`GetFunctionFlags` returns promoted `FunctionFlags` for scanned UFunction
handles when readable and `0` otherwise; `SetFunctionFlags` mutates
loader-owned Lua handle metadata and syncs matching loader registry entries,
but it does not write live UFunction memory.
`ForEachFunction` is no longer a pure no-op: on loader-owned self-test
object/class handles it iterates unique promoted `UFunction` handles from the
same bounded registry as `GetKnownFunctions`. It is still not a complete live
`UStruct` function-chain traversal. Loader logs expose this as
`forEachFunctionCalls` and `forEachFunctionCallbacks` on Lua dispatch/mod-finish
events; the readiness report gates it as `luaFunctionIteration`.
`NotifyOnNewObject` is also bounded: it stores up to 32 class/path/name filter
registrations, then dispatches every match only when loader-owned
`StaticConstructObject` creates a matching synthetic handle. The readiness
report gates this as
`luaObjectNotify`.
Synthetic constructed-object outer preservation is gated as
`luaSyntheticOuter`.
`GetWorld`, `GetCDO`, and `GetLevel` compatibility are gated as
`luaWorldContext`, `luaClassDefaultObject`, and `luaLevel`.

`Reflection()` returns a loader-owned `UObjectReflection` table for known
handles. `Reflection():GetProperty(name)` resolves self-test properties,
promoted `UFunction` param descriptors, and scalar live reflection candidates
into UE4SS-style property descriptor tables. Descriptor methods include
`GetFullName`, `GetFName`, `IsA`, `GetClass`, `ContainerPtrToValuePtr`,
`ImportText`, `ExportText`, `ExportTextItem`, `GetOffset_Internal`,
`GetOffsetInternal`, `GetElementSize`, `GetSize`, `GetArrayDim`,
`GetPropertyFlags`, `HasAnyPropertyFlags`, `GetPropertyClass`, bool mask helpers, `GetStruct`, `GetInner`,
and `type`. The self-test descriptor set includes integer, bool, float, double,
`FName`, string, `FText`, object, and bounded array properties; readiness reports the
float/double proof as `luaReflectionNumericPropertyValues=true` and the
name/text proof as `luaReflectionNameTextPropertyValues=true`, and the
`FArrayProperty:GetInner()` proof as `luaReflectionArrayInnerProperty=true`,
and the `FEnumProperty:GetEnum()` / `GetUnderlyingProperty()` proof as
`luaReflectionEnumProperty=true`, and the `FSetProperty` element plus
`FMapProperty` key/value proof as `luaReflectionContainerProperties=true`.
`GetInner()` returns the bounded fixture's synthetic `FIntProperty` inner
descriptor. `GetEnum()` returns the bounded fixture's synthetic `UEnum` handle,
and `GetUnderlyingProperty()` returns its synthetic `FByteProperty` descriptor.
`GetElementProperty()` / `GetElementProp()` return the bounded fixture's
synthetic set element descriptor, while `GetKeyProperty()` / `GetKeyProp()` and
`GetValueProperty()` / `GetValueProp()` return synthetic map key/value
descriptors. `ImportText()` accepts text for loader-owned integer, bool,
float, double, string, `FName`, and `FText` descriptors and is reported as
`luaReflectionImportText=true`. `ExportText()` and `ExportTextItem()` export
text from the same loader-owned descriptor set and are reported as
`luaReflectionExportText=true`. `GetOffset_Internal()`, `GetOffsetInternal()`,
`GetElementSize()`, `GetSize()`, `GetArrayDim()`, `GetPropertyFlags()`,
and `HasAnyPropertyFlags()` expose bounded descriptor metadata and are reported
as `luaReflectionPropertyMetadata=true`. `GetValue()` and `SetValue()` provide
bounded descriptor-level value access for loader-owned descriptors and are
reported as `luaReflectionDescriptorValues=true`.
`ForEachProperty`
iterates the same known descriptor sets and stops when the callback returns
true. This is a bounded descriptor shim, not complete live `FProperty`
traversal, live arbitrary typed value marshaling, live enum value marshaling, or
arbitrary container storage marshaling.

The Lua global compatibility surface also includes `FName`, `FText`,
`ExecuteAsync`, `ExecuteWithDelay`, `LoopAsync`, `RegisterKeyBind`,
`IsKeyBindRegistered`, `RegisterConsoleCommandHandler`,
`RegisterConsoleCommandGlobalHandler`, `RegisterProcessConsoleExecPreHook`,
`RegisterProcessConsoleExecPostHook`, `RegisterCustomEvent`,
`RegisterCustomProperty`, `RegisterCallFunctionByNameWithArgumentsPreHook`,
`RegisterCallFunctionByNameWithArgumentsPostHook`,
`RegisterULocalPlayerExecPreHook`, `RegisterULocalPlayerExecPostHook`,
`UE4SSLProbeDispatchCustomEvent`, `UE4SSLProbeLoadMap`, `UE4SSLProbeBeginPlay`,
`UE4SSLProbeInitGameState`, `IterateGameDirectories`, and common lifecycle hook
registration names. The
loaders also seed `UE4SS`,
`UnrealVersion`, `ModRef`, `EObjectFlags`, `EInternalObjectFlags`,
`PropertyTypes`, `Key`, `ModifierKey`, and `ModifierKeys`. `ModRef`
implements loader-local shared variables for nil, string, integer, bool, and
known object handles. These are deterministic loader shims today: async/delay
callbacks run immediately, no-hook Lua mods load successfully, and loader-owned
custom-event/lifecycle shims dispatch registered Lua refs. No real engine event
is dispatched until the matching
Unreal callsite is resolved and hooked. `FName` returns a table with `ToString()`
and `GetComparisonIndex()` methods, matching the ProcessEvent decoded-name value
shape.
Confidence: high for the loader registry, moderate for live target profile object-array
candidates until current-build anchors are confirmed.

Set `UE4SSL_CLIENT_LUA_PROCESS_EVENT_SELF_TEST=true` or
`UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST=true` after the plain Lua
self-test passes. It installs an inline hook on a loader-owned
`ProcessEvent(UFunction*, void*)` stand-in, dispatches the Lua pre/post
callbacks registered by `RegisterHook`, calls the original bytes through the
trampoline, restores the hook, and logs `event=lua-process-event-self-test`.
The default script also exercises guarded `GetParamValue`/`SetParamValue`
access against the loader-owned params block and logs
`paramDescriptorHits=2 paramDescriptorLookupHits=13
functionParamDescriptorHits=2 paramGetHits=21 paramSetHits=7`. The `Params`
table includes descriptor metadata under
`Properties` with `Name`, `Type`, `ClassName`, `OffsetInternal`, `ElementSize`,
`PropertyFlags`, `Size`, `ArrayDim`, `IsParm`, `IsOutParm`, and
`IsReturnParm`, and Lua can retrieve descriptor handles through
`GetParamDescriptor`. `Params.<Name>` and `Params.Values.<Name>` also expose
loader-owned `RemoteUnrealParam`-style wrappers with `get()`, `Get()`, `set()`,
`Set()`, and `type() == "RemoteUnrealParam"`. `GetParamValue` returns booleans for `FBoolProperty`
descriptors, object-handle tables for object/class/interface pointer
descriptors, decoded `FName` tables when an `FNamePool` resolver is cached,
bounded read-only `FStrProperty` strings, guarded `FVector` tables for
`FStructProperty` descriptors with `X/Y/Z` and `x/y/z` fields, and
`FStructProperty:GetStruct()` returns a synthetic `/Script/CoreUObject.Vector`
`UScriptStruct` handle for that bounded vector shape. It also covers guarded signed/unsigned integer
scalars, and guarded `float`/`double` values for scalar descriptors;
`SetParamValue` accepts the matching Lua boolean/object/table/address/integer, vector table,
and numeric forms. Lua can
also call
`GetFunctionParamDescriptors(ctx.Function)` or the shorter `GetFunctionParams`
alias to retrieve a function-scoped descriptor table with `PropertyCount` and
`Properties`. Mods can resolve the promoted runtime function registry with
`FindFunction(pathOrName)`, `FindFirstFunction()`, and `GetKnownFunctions()`;
`GetKnownFunctions()` returns a table keyed by runtime `PathName` plus `Count`,
and compatible owner/class handles can enumerate those promoted functions with
`ForEachFunction(callback)`.
These APIs only expose UFunctions already discovered by the bounded
`functionLink` descriptor probe. This proves the ProcessEvent-shaped Lua bridge and
function-param descriptor bounded self-test params access. The default routing
self-test registers one nonmatching hook and one matching hook, so `hooks=2`
with `preCalls=1 postCalls=1` proves known-path `RegisterHook` filtering
through `ctx.functionPath`. This is not full live `FProperty` marshaling.
Confidence: high for native Linux with Lua present and for local Windows/Wine
Lua smoke, moderate until the same DLL path is tested with live target profile under
Proton.

Set `UE4SSL_CLIENT_UE_PROCESS_EVENT_HOOK_PROBE=true` or
`UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE=true` after a unique
`ProcessEvent` anchor exists. The probe resolves the hook target from
`*_UE_PROCESS_EVENT_HOOK_ADDRESS`, `*_UE_PROCESS_EVENT_ADDRESS`, explicit UE
anchors, or signature-resolved UE anchors. With `*_HOOK_INSTALL=false` it only
validates that the target is mapped and executable. With
`*_HOOK_INSTALL=true` it installs an inline hook and immediately restores it;
`*_HOOK_SELF_TEST_TARGET=true` confines that install/restore pass to
loader-owned code for smoke tests. This is a guarded hookability probe, not a
persistent live ProcessEvent dispatch loop. Confidence: high.

Set `UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_HOOK=true` or
`UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK=true` only after the guarded
hook probe passes on the same resolved target. The live hook scaffold resolves
the target from `*_UE_PROCESS_EVENT_LIVE_HOOK_ADDRESS`, the hook-probe address,
the generic ProcessEvent address, explicit UE anchors, or signature-resolved UE
anchors. It installs once, leaves the hook active for the process lifetime,
calls the original through the trampoline, optionally logs bounded call
entries/returns, and restores on loader unload/process detach. It does not yet
decode live `UObject`/`UFunction` arguments or marshal live `FProperty`
payloads. Confidence: high.

Set `UE4SSL_CLIENT_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=true` or
`UE4SSL_WIN_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=true` with the live
hook scaffold in a smoke/lab run to arm a native ProcessEvent pre/post callback
registry. A passing self-test proves the persistent hook runs native callbacks
before and after the original function. It is the spine for live Lua routing,
not the Lua routing itself. Confidence: high.

Set `UE4SSL_CLIENT_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=true` or
`UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=true` with the live
hook scaffold after the native dispatch self-test passes. The loader creates a
persistent Lua VM for the live hook, executes a script that calls
`RegisterHook`, stores the Lua pre/post refs, and invokes those callbacks from
the persistent ProcessEvent hook around the original call. The callback receives
a table with raw `object`, `function`, and `params` addresses plus `stage`,
`call`, `originalCalled`, `preCallbacks`, and `postCallbacks`; when the loader
can resolve the raw addresses, the same table also includes UE4SS-shaped
`Object` and `Function` handle tables plus a `Params` context table. A pass logs
`event=ue-process-event-live-lua-dispatch status=armed` and the hook install
line reports `luaDispatch=true luaObjectHandleHits=2
luaFunctionHandleHits=2 luaParamsHandleHits=2 luaParamDescriptorHits=2
luaParamDescriptorLookupHits=12 luaFunctionParamDescriptorHits=2
luaParamGetHits=18 luaParamSetHits=6`. `GetFunctionParamDescriptors`/
`GetFunctionParams` first return live registry descriptors when `ctx.Function`
matches a scanned `UFunction`, and fall back to the self-test `Value`,
`OriginalResult`, and `Touched` fields for loader-owned callbacks.
`GetParamValue` and `SetParamValue` accept descriptor tables from either source,
but they are guarded to the active callback's params block, mapped page
permissions, descriptor type, and scalar/bool/object/name/string width. This
proves live ProcessEvent-to-Lua callback routing with handle-backed
object/function context, a stable params address table, and bounded
scalar/bool/object-pointer plus in-place `FName`/`FString` params get/set
plumbing. When the synthetic function path is known, dispatch filters
registered hooks by `ctx.functionPath`; unresolved live `UFunction` paths remain
permissive until real path/name discovery is proven. Bounded live samples now
emit `event=ue-process-event-live-param` for descriptor-backed scalar, bool,
object-pointer, `FName`, `FString`, and vector reads from the active params
block. For arrays it emits `status=container` and Lua `GetParamValue` returns
an `FScriptArray` table with `Data`, `Num`, `Max`, `BytesHex`, address, offset,
class, type, and size metadata. If the array data pointer is readable, the
table also includes `DataSampleAddress`, `DataSampleReadSize`, and
`DataSampleBytesHex`, and the log value includes `dataSampleHex=...`.
`FScriptArray` tables expose `GetNum()`, `NumElements()`, `GetData()`,
`GetDataSampleBytes()`, `GetRawElement(index, byteCount)`, and
`GetElement(index)`. `GetElement` uses promoted `Inner*` metadata when present
to decode bounded scalar, object, and `FName` elements; unsupported element
classes return a raw element table with `BytesHex`. For sets and maps it
emits header-only `FScriptSetHeader` and `FScriptMapHeader` tables with the same
metadata. Container descriptor discovery separately emits
`event=ue-function-param-container-child` when a live `FArrayProperty`,
`FSetProperty`, or `FMapProperty` param has decoded inner/key/value child
metadata; `GetFunctionParams(function).Properties.<Param>` and
`RemoteUnrealParam.Descriptor` expose that metadata through `ContainerChildren`
and the same child-property getter methods. Set/map element iteration and typed
complex array elements are still future work. Unsupported complex values,
including non-vector structs, still emit
`status=raw value=rawHex=...` and Lua returns a `RawUnrealParam` table. This
still does not perform typed container element unmarshaling or complete live
`FProperty` object marshaling. Windows/Proton
additionally requires a staged Lua DLL or the event reports
`status=library-missing`.
When bounded call logging is enabled, the hook also emits
`event=ue-process-event-live-context`. `status=resolved` proves that a sampled
live call had a nonzero params pointer, a Lua-visible object handle for the raw
object pointer, a resolved `UFunction` path, and promoted function-param
descriptors for the raw function pointer. A readable
`ue-process-event-live-param` line is the readiness gate between raw hook
dispatch and live Lua/mod routing with descriptor-backed payload access. The
readiness report also tracks `ueProcessEventLiveContainerParamValues`; `false`
means no sampled live array/set/map param produced a typed header table yet.
It also tracks `ueProcessEventLiveContainerDataSamples`; `false` means no
sampled live array header had a readable data pointer for bounded storage bytes.
Confidence: high.
Confidence: high for native Linux and local Windows/Wine Lua smoke, moderate
until a live target profile Proton Lua canary passes.

`lua-mod-script status=passed` proves the loader can discover and execute a Lua
entrypoint from either an explicit script list or a UE4SS-style
`Mods/<ModName>/Scripts/main.lua` root. `lua-mod-dispatch-self-test
status=passed` proves callbacks registered by that loaded mod entrypoint can be
invoked from native code. `RegisterHook` is a bounded multi-callback registry
on the Linux server, native Linux client, and Windows/Proton client loaders, so
multiple loaded scripts can register callbacks without overwriting each other.
This is still a loader-level dispatch proof; it is not yet a live `ProcessEvent`
bridge. Confidence: high.

If a Lua mod entrypoint fails to load or execute, `event=lua-mod-script` logs a
sanitized `error=` field on all three loaders. Script reads remain capped at 256
KiB, and the loader does not print arbitrary binary data from the Lua stack.

Export explicit anchor env from a first scan:

```bash
analysis/export-ue-anchor-env.py /tmp/ue4ssl-win-client-probe-loader.log \
  --loader win-client \
  --platform windows \
  > build/windows-client-loader/ue-anchors.env

analysis/prepare-ue-anchor-canary.py \
  --platform windows \
  --binary /path/to/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --output-dir build/windows-client-loader/client-anchor-canary

analysis/plan-ue4ss-canary-env.py \
  --platform windows \
  --client-log /tmp/ue4ssl-win-client-probe-loader.log \
  --loader win-client \
  --max-stage read-only \
  > build/windows-client-loader/next-canary.env
```

By default this exports core discovery anchors plus reflection anchors
(`UObject`, `UFunction`, `UClass`, `FProperty`) from scan hits, mapped explicit
anchors, or resolved `ue-anchor-signature` records. Missing or ambiguous
signature anchors stay out of the env file.
The canary-prep helper writes the PE manifest, anchor-signature sidecar, anchor
env, validation summary, and readiness report into one directory for the next
Proton/Windows launch.
The canary env planner reads readiness evidence and emits the next guarded env:
read-only object/reflection discovery by default, guarded ProcessEvent
install/restore only with `--max-stage hook-probe`, persistent hook scaffolding
only with `--max-stage live-hook`, and live Lua/mod dispatch only with
`--max-stage lua-dispatch`. `live-hook` and `lua-dispatch` plans also enable
bounded live ProcessEvent call logging so `ue-process-event-live-context`
readiness evidence is collected in the same canary.

Source that env for a second read-only launch, then run the readiness gate.
Confidence: high.

For Windows, also validate forwarding:

```text
event=forward-smoke function=GetFileVersionInfoSizeW result=<nonzero>
```

If the client starts but no profile-specific scan hits appear, do not assume the
loader failed. Check `event=module` first to verify the game executable and
expected modules are present in the log, then narrow `SCAN_PATH_FILTER` or add
more precise signatures.

For UE readiness, the minimum useful read-only discovery set is at least one
anchor in each of:

- names: `FNamePool` or `GName`
- objects: `GUObjectArray` or `GObjectArray`
- world: `GWorld`
- dispatch: `ProcessEvent` or `StaticFindObject`

Run the shared port gate after a canary:

```bash
analysis/ue4ss-port-readiness.py \
  --client-log /tmp/ue4ssl-win-client-probe-loader.log \
  --loader win-client \
  --signature-validation-json build/windows-client-loader/client-pe-signature-validation.json
```

For a native Linux client, use `--client-log /tmp/ue4ssl-client-loader.log`
and `--loader linux-client`. For a Linux server canary, use
`--server-log /tmp/ue4ssl-server-loader.log`.

The gate is intentionally strict. `objectDiscovery=false` means stay in
scan/xref mode or rerun with pointer, layout, UObject candidate, and
object-array internal-flag probes.
`reflection=false` now also covers `ueFunctionFlags=false`; readable
`FunctionFlags` must be promoted before `GetFunctionFlags()` is treated as
live-compatible. It also covers `ueFunctionParamContainerChildren=false`, which
means no bounded container-param scan has decoded inner/key/value child property
metadata yet.
`hookDispatch=false` means prove the guarded self-test before touching a game
function. `modDispatch=false` means prove the native mod lifecycle before Lua
binding work. `luaRuntime=false` means Lua execution, Lua callback dispatch, and
UE4SS-style Lua API surface calls have not all been proven.
`luaObjectApi=false` means `FindObject`, `GetKnownObjects`, `FindObjects`,
`FindAllOf`, `ForEachUObject`, `IsA`, and `LoadAsset` have not passed in both
the built-in Lua self-test and a loaded Lua mod. `luaDecodedObjectAliases=false` means decoded UObject
FNames have not been promoted into Lua-visible `/RuntimeProbe/<DecodedName>`
aliases. `luaMods=false` means Lua mod entrypoint loading and callback dispatch
have not both passed.
`luaProcessConsoleExecHooks=false` means a Lua mod has not yet proven
`RegisterProcessConsoleExecPreHook`/`PostHook` dispatch around loader-owned
`ProcessConsoleExec`.
`luaLocalPlayerExecHooks=false` means a Lua mod has not yet proven
`RegisterULocalPlayerExecPreHook`/`PostHook` dispatch around loader-owned
`ULocalPlayerExec`.
`luaCallFunctionHooks=false` means a Lua mod has not yet proven
`RegisterCallFunctionByNameWithArgumentsPreHook`/`PostHook` dispatch around
loader-owned `CallFunction`.
`luaLifecycleHooks=false` means a Lua mod has not yet proven `RegisterCustomEvent`
plus `RegisterLoadMap*`, `RegisterBeginPlay*`, and `RegisterInitGameState*`
dispatch around loader-owned lifecycle shims.
`ueProcessEventHookProbe=false` means no mapped/executable ProcessEvent target
has survived the guarded install/restore probe. `ueProcessEventLiveHook=false`
means the opt-in persistent hook scaffold has not been installed on a resolved
target. `ueProcessEventDispatch=false` means the native pre/original/post
callback spine has not been armed. `ueProcessEventLiveLuaDispatch=false` means
the live hook has not invoked Lua `RegisterHook` callbacks.
`ueProcessEventLiveContext=false` means sampled live hook calls have not yet
resolved raw object/function/params into a Lua-visible object handle, function
path, params pointer, and function-param descriptor set.
`ueProcessEventLiveParamValues=false` means sampled live hook calls have not yet
read at least one descriptor-backed param value from the active params block.
`ueProcessEventLiveRawParamValues=false` means sampled live hook calls have not
yet read a complex param payload/header as bounded raw bytes.
`ueProcessEventLiveContainerParamValues=false` means sampled live hook calls
have not yet read an array/set/map param as a typed container header table.
`ueProcessEventLiveContainerDataSamples=false` means sampled live array headers
have not yet yielded bounded readable storage bytes from their data pointer.
`ueProcessEventLuaContextHandles=false` means those callbacks have not received
resolved `Object`, `Function`, and `Params` context tables.
`ueProcessEventLuaParamAccessors=false` means Lua
`GetFunctionParamDescriptors`/`GetFunctionParams` plus descriptor-handle
`GetParamDescriptor`, `GetParamValue`, and `SetParamValue` access has not
passed in both the synthetic ProcessEvent self-test and the live hook path.
`ueProcessEventLuaScalarParamAccessors=false` means that path has not yet proven
the widened signed/unsigned integer and `float`/`double` scalar get/set fixture.
`ueProcessEventLuaNameStringParamAccessors=false` means that path has not yet
proven guarded in-place `FName`/`FString` param get/set from both the synthetic
ProcessEvent self-test and the live hook path.
`ueProcessEventLuaStructParamAccessors=false` means that path has not yet proven
bounded `FVector`-shaped `FStructProperty` param get/set from both paths.
`ueFunctionIdentities=false` means decoded `functionLink` names have not yet
produced Lua-visible runtime UFunction paths.
`ueProcessEventLuaHookRouting=false` means multiple `RegisterHook` entries have
not yet proven that only the matching known `ctx.functionPath` callback fires.
`luaObjectNotify=false` means a Lua mod has not yet proven
`NotifyOnNewObject` callback dispatch for a newly constructed loader-owned
object handle.
`luaSyntheticOuter=false` means a Lua mod has not yet proven
`StaticConstructObject` preserved and resolved a loader-owned outer handle.
`hooks=false` means do not route live ProcessEvent into Lua/mod callbacks.
`luaDispatch=false` means do not expose UE4SS Lua APIs yet. Confidence: high.

## Next UE4SS-Port Step

The next shared implementation step is read-only Unreal discovery against the
confirmed live process surfaces:

1. locate `FNamePool`;
2. locate `GUObjectArray`;
3. locate `GWorld`;
4. locate `ProcessEvent`;
5. validate FName/object/class/property layout reads without hooks;
6. use the guarded ProcessEvent hook probe on the resolved target;
7. install the persistent ProcessEvent hook scaffold on the resolved target;
8. enable the live ProcessEvent Lua callback bridge;
9. require resolved `Object`/`Function` handles and a `Params` table in live Lua callbacks;
10. prove Lua `GetFunctionParamDescriptors`/`GetFunctionParams` plus descriptor-handle `GetParamDescriptor` and `GetParamValue`/`SetParamValue` access from ProcessEvent callbacks;
11. prove on a live native-Linux or Proton canary that `ctx.Function` from a real ProcessEvent call has a nonempty runtime `PathName`, hits the promoted `ue-function-param` registry, and that guarded class-aware `GetParamValue` works on the active params pointer;
12. only then attach live UE property marshaling.
