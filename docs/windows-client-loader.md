# Windows Client Loader

Status on 2026-06-16: Windows/Proton client proxy support is scaffolded as a
read-only runtime probe. Confidence: high.

Observed on 2026-06-16: staged `version.dll` loaded in the real
`TargetGame-Win64-Shipping.exe` Proton process and logged module images. The
launch did not inherit scan environment, so the sidecar config path below now
covers normal Steam launches where only the staged DLL is guaranteed to load.
Confidence: high for proxy load, moderate for the next real scan until a fresh
client launch log shows `event=scan-start`.

Follow-up observed on 2026-06-16: a later Steam launch with no launch-wrapper
environment started the full game process, but `/proc/<pid>/maps` showed
Proton's builtin `version.dll` from
`/usr/share/steam/compatibilitytools.d/proton-ge-custom/files/lib/wine/x86_64-windows/version.dll`.
The staged game-directory DLL was bypassed. For that case, set the per-app Wine
DLL override documented below. Confidence: high.

Final canary on 2026-06-16: with the per-app Wine DLL override set, the real
Proton client loaded the staged `VERSION.dll`, read
`ue4ssl-win.env`, and completed a full preset scan with
`strings=45`. See `docs/windows-client-loader-canary-2026-06-16.md`.
Confidence: high.

The installed target profile client on this host is a Windows PE executable:

```text
TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe
```

That means the native Linux `.so` loader cannot inject into the actual client
when Steam runs it through Proton. This path uses a Windows PE DLL instead.
The shipping executable imports `VERSION.dll` directly, specifically
`GetFileVersionInfoSizeW`, `GetFileVersionInfoW`, and `VerQueryValueW`, so the
`version.dll` proxy is a valid load point. Confidence: high.

The cross-client support matrix and shared runbook live in
`docs/client-loader-support.md`.

## What Exists

- `runtime/windows-proxy/ue4ssl_windows_proxy_loader.c`
- `scripts/build-windows-client-loader.sh`
- `scripts/launch-proton-client-probe.sh`
- `scripts/proton-dll-override-control.sh`
- `scripts/package-windows-client-loader.sh`
- `scripts/smoke-windows-client-loader.sh`
- `scripts/smoke-windows-client-loader-lua.sh`

The DLL:

- imports only `kernel32`;
- starts a worker thread from `DllMain`;
- logs from inside the Windows process;
- reads `ue4ssl-win.env` beside the proxy DLL as a fallback when
  Steam/Proton launch environment is unavailable;
- scans committed image mappings with `VirtualQuery`;
- logs loaded image modules before scanning;
- reports runtime address, module RVA, region base, protection, and module path;
- exports common `version.dll` APIs and forwards them to the real system
  `version.dll` so it can be staged as a `version.dll` proxy.

This is not full UE4SS yet. It has loader-owned hook, Lua dispatch, reflection,
and ProcessEvent-shaped self-tests, but it does not yet marshal live Unreal
`FProperty` values or patch game memory. The persistent ProcessEvent hook
scaffold exists, and the separate live-Lua gate can route `RegisterHook`
pre/post callbacks from that hook. It still does not decode live UE arguments
or marshal real `FProperty` payloads. Confidence: high.

## Build

```bash
scripts/build-windows-client-loader.sh
```

Default output:

```text
build/windows-client-loader/ue4ssl_windows_proxy_loader.dll
```

The build script supports either `x86_64-w64-mingw32-gcc` or the local fallback
available on this host: `clang` + `ld.lld` + Wine x86_64 Windows import
libraries.

## Steam / Proton Launch

Smoke test:

```bash
scripts/smoke-windows-client-loader.sh
```

The default smoke intentionally pins `UE4SSL_WIN_LUA_DLL` to a
missing DLL and verifies the `library-missing` path. The real Lua parity smoke
stages a pinned LuaBinaries 5.4.8 `lua54.dll` under `build/` when
`UE4SSL_WIN_LUA_DLL` is not already set:

```bash
make smoke-windows-client-loader-lua
```

Run `make smoke-windows-client-loader-full` to execute both the proxy/missing-DLL
smoke and the real Lua smoke.

That smoke must pass before claiming Windows/Proton has the same real Lua
runtime coverage as the Linux `liblua5.4.so` smoke. Confidence: high.

Recommended Steam launch option for target profile:

```bash
scripts/launch-proton-client-probe.sh --stage-to-game-dir -- %command%
```

The wrapper can stage the built DLL as `version.dll` in a repo-contained overlay
directory:

```text
build/windows-client-loader/proton-stage/version.dll
```

Then it exports:

```dotenv
WINEDLLOVERRIDES=version=n,b
WINEPATH=<Windows path to stage dir>
WINEDLLPATH=<POSIX path to stage dir>
UE4SSL_WIN_LOG=Z:\tmp\ue4ssl-win-loader.log
UE4SSL_WIN_SCAN_ENABLED=true
UE4SSL_WIN_LOG_MODULES=true
UE4SSL_WIN_SCAN_PRESETS=core,ue,client,cheat,brt,deep-desert
```

For the installed target profile Proton client, use the explicit game-directory staging
mode so the proxy DLL is beside the game executable:

```bash
scripts/launch-proton-client-probe.sh --stage-to-game-dir
```

That copies the proxy DLL beside the game executable. If a DLL with the same
name already exists and differs, the script backs it up first. It also writes a
sidecar config beside the DLL:

```text
TargetGame/Binaries/Win64/ue4ssl-win.env
```

The sidecar makes normal Steam launches canary-capable even if the Steam launch
option or inherited environment is missing. Environment variables still override
sidecar values. The script records both staged files in:

```text
build/windows-client-loader/game-dir-stage-manifest.txt
```

Remove a staged game-dir copy only when it still matches our current loader:

```bash
scripts/launch-proton-client-probe.sh --unstage-game-dir
```

That also removes the sidecar only if the manifest proves it is ours.

## Scan Variables

```dotenv
UE4SSL_WIN_SCAN_ENABLED=true
UE4SSL_WIN_LOG_MODULES=true
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

Default scans cover `MEM_IMAGE` regions only. Set
`UE4SSL_WIN_SCAN_PRIVATE=true` only for targeted lab runs; it can be
much noisier and slower.

The same keys can be placed in `ue4ssl-win.env` next to
`version.dll`. The launch wrapper writes this file automatically when staging.

`UE4SSL_WIN_UE_ANCHORS` validates explicit runtime addresses through
`VirtualQuery` and logs mapped/unmapped status, protections, RVA, allocation
base, and module path. Mapped anchors are folded into readiness summaries as
validated UE surfaces. Use real addresses from a validated signature or xref
pass, not the zero placeholders above. Confidence: high.

`UE4SSL_WIN_UE_ANCHOR_SIGNATURES` and
`UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE` resolve `name=aa bb ??`
patterns in filtered committed image regions and promote only unique matches to
UE anchors. These keys can be set in the environment or in the
`ue4ssl-win.env` sidecar beside `version.dll`. Missing or ambiguous
signatures are logged and skipped. Use `Name@hit+N`, `Name@riprel32+N`,
`Name@callrel32`, or `Name@ptr+N` when a signature match must be transformed
into the anchor address. Confidence: high.
`analysis/export-client-pe-signature-manifest.py --format anchor-signatures`
emits that loader-consumable file from validated promotable UE signature rows;
point `UE4SSL_WIN_UE_ANCHOR_SIGNATURES_FILE` at it for the next
read-only Proton canary.

Set `UE4SSL_WIN_UE_POINTER_PROBE=true` for the second read-only
canary after explicit anchors are configured. It reads one pointer-sized value
from each readable anchor address and validates the target with `VirtualQuery`.
`target-mapped` is required by the readiness gate before object layout readers.
Confidence: high.

Set `UE4SSL_WIN_UE_LAYOUT_PROBE=true` after pointer targets are
mapped. It reads up to `UE4SSL_WIN_UE_LAYOUT_SLOTS` pointer-sized
fields from the mapped target and logs whether each slot is null, unmapped, or
points to mapped memory. This is layout evidence only; it does not install hooks
or interpret Unreal objects yet. Confidence: high.

Set `UE4SSL_WIN_UE_UOBJECT_PROBE=true` only after pointer targets are
mapped. It reads the standard `UObjectBase`-shaped fields from the pointed-to
target: vtable, object flags, internal index, `ClassPrivate`, the `FName` pair,
and `OuterPrivate`. A `status=candidate` line with `classMapped=true` is a
read-only object candidate, not proof that full UE reflection or UE4SS Lua
dispatch is ready. Confidence: high.

Set `UE4SSL_WIN_HOOK_SELF_TEST=true` only for a lab/smoke run after
the read-only gates are understood. It temporarily installs an inline jump on a
loader-owned self-test function with `VirtualProtect`, verifies dispatch to a
replacement function, executes one pre-callback, calls the original bytes
through a generated trampoline, executes one post-callback, flushes the
instruction cache, then restores the original bytes. It does not hook
`ProcessEvent` or any game function. Confidence: high.

Set `UE4SSL_WIN_MOD_SELF_TEST=true` to exercise the native
mod-dispatch scaffold. It registers one loader-owned mod entry, runs load,
pre-hook, post-hook, and unload callbacks around the same hook dispatch context,
and logs `event=mod-dispatch-self-test`. This is the ABI spine for later Lua
binding; it does not execute Lua scripts yet. Confidence: high.

Set `UE4SSL_WIN_LUA_SELF_TEST=true` to execute a real Lua VM
self-test through a dynamically loaded Windows Lua DLL. Use
`UE4SSL_WIN_LUA_DLL` to point at a staged DLL such as `lua54.dll`;
otherwise the loader tries common names. Without a staged DLL it logs
`status=library-missing`, which is expected. A pass logs
`event=lua-dispatch-self-test ... result=42` plus
`callbackStatus=0 preCalls=1 postCalls=1 preResult=11 postResult=31`. The
default script calls a loader-provided
`RegisterHook('/Script/UE4SSLProbe.SelfTest:Function', pre, post)` function, so a
pass proves Lua-to-native hook registration, native-to-Lua callback dispatch,
and script result handling. `RegisterHook` returns UE4SS-shaped `preId, postId`
values, and `UnregisterHook(name, preId, postId)` removes a registered pair.
The loader also registers UE4SS-style globals
`UnregisterHook`, `StaticFindObject`, `FindObject`, `FindFirstOf`, `GetKnownObjects`,
`FindObjects`, `FindAllOf`, `ForEachUObject`, `IsA`, `LoadAsset`,
`StaticConstructObject`, `NotifyOnNewObject`, `ExecuteInGameThread`,
`ExecuteAsync`, `ExecuteWithDelay`, `LoopAsync`, `FName`, `FText`,
`RegisterKeyBind`, `IsKeyBindRegistered`, `RegisterConsoleCommandHandler`,
`RegisterConsoleCommandGlobalHandler`, `RegisterProcessConsoleExecPreHook`,
`RegisterProcessConsoleExecPostHook`, `RegisterCustomEvent`,
`RegisterCustomProperty`, `RegisterCallFunctionByNameWithArgumentsPreHook`,
`RegisterCallFunctionByNameWithArgumentsPostHook`,
`RegisterULocalPlayerExecPreHook`, `RegisterULocalPlayerExecPostHook`,
`UE4SSLProbeDispatchCustomEvent`, `UE4SSLProbeLoadMap`, `UE4SSLProbeBeginPlay`,
`UE4SSLProbeInitGameState`, `IterateGameDirectories`, and common lifecycle hook
registration shims. `RegisterCustomEvent`,
`RegisterLoadMapPreHook`/`PostHook`, `RegisterBeginPlayPreHook`/`PostHook`, and
`RegisterInitGameStatePreHook`/`PostHook` now store Lua refs and dispatch through
loader-owned shims with `(context, eventName, payload, handled)`. They are not
attached to live UE lifecycle functions until those call targets are discovered
and hooked in the running Proton/Windows client. It also
seeds UE4SS-style `UE4SS`,
`UnrealVersion`, `ModRef`, `EObjectFlags`, `EInternalObjectFlags`,
`PropertyTypes`, `Key`, `ModifierKey`, and `ModifierKeys` tables. `ModRef`
supports loader-local `SetSharedVariable`/`GetSharedVariable` for nil, string,
integer, bool, and known object handles.
`StaticFindObject`, `FindObject`, `FindFirstOf`, `FindObjects`, and
`FindAllOf` return bounded object-handle tables from the loader's object
registry; `GetKnownObjects()` returns a table keyed by runtime `PathName` plus
`Count`; `ForEachUObject(callback[, class])` iterates that same registry; and
`IsA(object, class)` checks the handle class or the base `UObject`.
`LoadAsset(pathOrName)` resolves an already-registered object handle by path or
name and returns `nil` when the object is not in the registry; it does not load
packages yet. `StaticConstructObject` creates a loader-owned
synthetic `/RuntimeProbe/Constructed/<Name>` handle. It does not allocate or
initialize a live Unreal object yet, but it preserves `ClassAddress` when the
class argument is a known object or `UClass` handle.
`NotifyOnNewObject(filter, callback)` is bounded to that synthetic path: it
stores up to 32 class/path/name filter registrations and dispatches every
matching callback when `StaticConstructObject` creates a loader-owned handle.
Returned object/function handle tables
also expose UE4SS-style methods: `GetFullName`, `GetName`, `GetPathName`,
`GetAddress`, `IsValid`, `GetClass`, `GetOuter`, `GetWorld`, `GetFName`,
`type`, `IsClass`, `IsAnyClass`, `IsA`, `HasAllFlags`, `HasAnyFlags`,
`HasAnyInternalFlags`, `GetPropertyValue`, `SetPropertyValue`, and
`CallFunction`, plus UE4SS method stubs/compat methods `ProcessConsoleExec`,
`ULocalPlayerExec`,
`GetFunctionFlags`, `SetFunctionFlags`, `GetSuperStruct`, `ForEachFunction`,
`ForEachProperty`, `GetCDO`, `IsChildOf`, and `GetLevel`. `ForEachFunction`
iterates unique promoted `UFunction` handles for loader-owned self-test
object/class handles through the same bounded registry used by
`GetKnownFunctions`; it is not full live `UStruct` function-chain traversal
yet. Handles also expose `ClassAddress`, `OuterAddress`, and `SuperAddress`
when scan metadata is available. `GetClass` returns a `UClass` handle whose
`Address` is the live scanned `ClassPrivate` pointer when available and zero
for purely synthetic registry entries;
`GetOuter` resolves the loader-owned outer for synthetic objects created by
`StaticConstructObject` and otherwise returns `nil`;
`GetSuperStruct` prefers a scanned `SuperAddress` and otherwise returns a
synthetic `UObject` class for non-`UObject` synthetic `UClass` handles or
`nil`;
`GetWorld` returns the handle itself for registered world-like handles,
resolves loader-owned `OuterAddress` chains to a registered world, and can fall
back to a registered `GWorld`/`UWorld`-like handle for common world-context
classes. It is not a live engine `UObject::GetWorld` call yet.
`GetCDO` returns a loader-owned `Default__<Class>` handle for `UClass` handles
with `RF_ClassDefaultObject` set; it is not the live engine class-default
object yet. `GetLevel` returns a registered level-like handle for level objects
and loader-owned outer chains; it is not a live `AActor::GetLevel` call yet,
`IsChildOf` is truthful for loader-owned self/base-class checks and walks the
bounded scan-derived `SuperAddress` chain when both class handles carry live
addresses; it is not full `GUObjectArray`-backed hierarchy enumeration yet.
`ProcessConsoleExec` dispatches loader-owned
`RegisterProcessConsoleExecPreHook` callbacks, then
`RegisterConsoleCommandHandler`/`RegisterConsoleCommandGlobalHandler`
callbacks, then `RegisterProcessConsoleExecPostHook` callbacks. Console exec
hooks receive `(context, rawCommand, command, args, handled)` and may return
boolean true to mark the command handled. It does not hook live engine console
routing yet,
`ULocalPlayerExec` dispatches loader-owned
`RegisterULocalPlayerExecPreHook` callbacks and
`RegisterULocalPlayerExecPostHook` callbacks with the same
`(context, rawCommand, command, args, handled)` shape. It is a distinct
loader-owned dispatcher and does not hook live `ULocalPlayer::Exec` yet,
`CallFunction` dispatches loader-owned
`RegisterCallFunctionByNameWithArgumentsPreHook` callbacks before its bounded
self-test function shim and `RegisterCallFunctionByNameWithArgumentsPostHook`
callbacks after it. Call-function hooks receive
`(context, functionName, args, handled, result)` and may return
`replacement, true` to short-circuit or replace the result. It does not hook the
live engine `UObject::CallFunctionByNameWithArguments` path yet,
scanned UObject handles also expose `ObjectFlags`, `InternalIndex`,
`HasObjectMetadata`, and, when the object-array item flags word is readable,
`InternalFlags`/`HasInternalFlags`; scanned UFunction handles also expose
`FunctionFlags` and `HasFunctionFlags`; `HasAllFlags`/`HasAnyFlags` use the
promoted `ObjectFlags`, and `GetFunctionFlags` returns promoted
`FunctionFlags` when readable.
`SetFunctionFlags` mutates loader-owned Lua handle metadata and syncs matching
loader registry entries, but it does not write live UFunction memory.
`HasAnyInternalFlags` uses promoted `InternalFlags` and returns false for
handles without decoded internal flag metadata. The self-test seeds a
`/Script/UE4SSLProbe.SelfTestObject` handle and requires both lookup paths plus
object enumeration, `IsA`, and synthetic construction to succeed. Class-mapped
`ue-uobject` probe candidates are also ingested as
`/RuntimeProbe/<AnchorName>` handles and logged as `event=lua-object-registry`.
When the FName decoder is available, decoded object names are additionally
registered as `/RuntimeProbe/<DecodedName>` aliases with
`source=ue-uobject-fname`; object-array aliases for the same address/name are
reported as `status=skipped` instead of creating duplicate handles.
`Reflection()` returns a loader-owned `UObjectReflection` table for known
handles. `Reflection():GetProperty(name)` resolves self-test properties,
promoted `UFunction` param descriptors, and scalar live reflection candidates
into UE4SS-style property descriptor tables. Descriptor methods include
`GetFullName`, `GetFName`, `IsA`, `GetClass`, `ContainerPtrToValuePtr`,
`ImportText`, `ExportText`, `ExportTextItem`, `GetOffset_Internal`,
`GetOffsetInternal`, `GetElementSize`, `GetSize`, `GetArrayDim`,
`GetPropertyFlags`, `HasAnyPropertyFlags`, `GetPropertyClass`, bool mask helpers, `GetStruct`, `GetInner`,
and `type`. `ForEachProperty` iterates those known descriptor sets. This is a
bounded descriptor shim, not complete live `FProperty` traversal or marshaling.
The async/delay/loop helpers invoke callbacks immediately in the probe
environment, and registration shims allocate ids without live engine event
dispatch until the corresponding Unreal callsites are hooked. `FName`/`FText`
construct loader-visible value tables compatible with the existing ProcessEvent
param value shape; `FName` values expose `ToString()` and
`GetComparisonIndex()` methods. Lua mods do not need to register a hook to be
considered loaded; a clean no-hook compatibility script passes in the real-Lua
smoke path when `UE4SSL_WIN_LUA_DLL` points at a Lua DLL.
Set `UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE=true` to attempt a bounded
FChunkedFixedUObjectArray walk from configured anchors; it tries both direct and
indirect anchor interpretations and logs `event=ue-object-array` plus
`source=ue-object-array` registry handles for class-mapped items. Set
`UE4SSL_WIN_UE_FNAME_PROBE=true` with a valid `FNamePool`/`GName`
anchor or explicit `UE4SSL_WIN_UE_FNAME_POOL` address to decode
candidate `NamePrivate` values. Successful decodes log
`event=ue-fname status=decoded`. Confidence: high for the dynamic ABI path and
local Wine Lua smoke, moderate until the same DLL path is tested with live target profile
under Proton.

Set `UE4SSL_WIN_UE_REFLECTION_PROBE=true` after the UObject and
FName probes are stable. It reads the candidate object's class pointer and emits
`event=ue-reflection` plus `event=ue-reflection-slot` for configured UClass and
field/function slots. The default offsets match the synthetic self-test layout;
override them from current-build analysis before treating live output as
actionable. This is read-only metadata discovery, not live `FProperty`
marshaling. Confidence: high for the self-test fixture.

Set `UE4SSL_WIN_UE_REFLECTION_FIELD_WALK=true` after the class/slot
probe is stable. It walks bounded `children`, `childProperties`,
`propertyLink`, and `functionLink` chains, using
`UE4SSL_WIN_UE_REFLECTION_FIELD_NEXT_OFFSET` and
`UE4SSL_WIN_UE_REFLECTION_MAX_FIELDS`, and logs
`event=ue-reflection-field status=candidate`. This keeps Proton/Windows support
equal to native Linux for the read-only field/function discovery gate.
Confidence: high for the self-test fixture, moderate for live target profile until
offsets are canary-validated.

Set `UE4SSL_WIN_UE_REFLECTION_PROPERTY_PROBE=true` after field
walking is stable. It implies the bounded field walk and reads property-shaped
descriptor fields from `childProperties` and `propertyLink`: `ArrayDim`,
`ElementSize`, `PropertyFlags`, and `Offset_Internal`. Successful reads log
`event=ue-reflection-property status=candidate`. This keeps Windows/Proton at
the same read-only descriptor gate as native Linux. Confidence: high for the
self-test fixture, moderate for live target profile until offsets are canary-validated.
For each bounded `functionLink` candidate, the same probe also reads
function-level `FunctionFlags`, `childProperties`, and `propertyLink` roots and emits
`event=ue-function-param-root` plus `event=ue-function-param` descriptor lines
when param metadata is readable. Readable descriptors and readable
`FunctionFlags` values are promoted into the bounded live `UFunction` param
registry, and
`GetFunctionParamDescriptors(function)`/`GetFunctionParams(function)` returns
them when Lua passes the matching live function handle. When the `functionLink`
FName decodes, `event=ue-function-param` also carries `functionName` and
`functionPath`, and Lua `ctx.Function.PathName`/`GetFunctionParams(ctx.Function)`
use that `/RuntimeProbe/<owner>.<function>:Function` identity. This is a
runtime-probe identity, not a resolved Unreal package path yet. This keeps
Windows/Proton equal to native Linux for descriptor visibility with decoded
`fieldClassName`/`ClassName` when the FName decoder can read the parameter
field's class object. Lua can distinguish scalar, bool, and object-pointer
params from that metadata, but this is not full live `FProperty` marshaling for
strings, names, arrays, structs, or complex out-param lifetimes.

Set `UE4SSL_WIN_UE_REFLECTION_VALUE_PROBE=true` after descriptor
offsets are stable. It implies descriptor probing and reads up to
`UE4SSL_WIN_UE_REFLECTION_VALUE_MAX_BYTES` raw bytes from the owning
object at `Offset_Internal`, logging `event=ue-reflection-value status=read`
with `raw` and `rawLe`. This keeps Windows/Proton equal to native Linux for
bounded value telemetry; it is not typed property marshaling or Lua-visible
get/set. Confidence: high for the self-test fixture, moderate for live target profile
until offsets are canary-validated.

Set `UE4SSL_WIN_LUA_PROCESS_EVENT_SELF_TEST=true` after the plain Lua
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
Confidence: high for the hook ABI path and local Wine Lua smoke, moderate until
the same DLL path is tested with live target profile under Proton.

Set `UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE=true` after a unique
`ProcessEvent` target has been resolved from explicit anchors or
`UE4SSL_WIN_UE_ANCHOR_SIGNATURES`. The loader first validates the
target with `VirtualQuery`. With
`UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_INSTALL=true`, it installs an
inline hook with `VirtualProtect`, flushes the instruction cache, and
immediately restores the original bytes. Use
`UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_SELF_TEST_TARGET=true` to constrain
that install/restore path to loader-owned code in smoke tests. This proves
target hookability, not a persistent live ProcessEvent dispatcher. Confidence:
high.

Set `UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK=true` only after the
guarded hook probe passes on the same target. The scaffold resolves the target
from `UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_ADDRESS`, the hook-probe
address, the generic ProcessEvent address, explicit anchors, or
signature-resolved anchors. It validates the target with `VirtualQuery`,
installs once with `VirtualProtect`, leaves the hook active for the process
lifetime, calls the original through the trampoline, optionally logs bounded
calls, and restores on process detach. When bounded call logging is enabled,
`event=ue-process-event-live-context status=resolved` proves sampled raw
`Object`/`Function`/`Params` pointers resolved to a Lua-visible object handle, a
`UFunction` path, a nonzero params pointer, and promoted function param
descriptors. The same bounded sample emits `event=ue-process-event-live-param`
for descriptor-backed scalar, bool, object-pointer, `FName`, `FString`, and
vector reads from the active params block. For arrays it emits
`status=container` and Lua `GetParamValue` returns an `FScriptArray` table with
`Data`, `Num`, `Max`, `BytesHex`, address, offset, class, type, and size
metadata. If the array data pointer is readable, the table also includes
`DataSampleAddress`, `DataSampleReadSize`, and `DataSampleBytesHex`, and the log
value includes `dataSampleHex=...`. `FScriptArray` tables expose
`GetNum()`, `NumElements()`, `GetData()`, `GetDataSampleBytes()`,
`GetRawElement(index, byteCount)`, and `GetElement(index)`. `GetElement` uses
promoted `Inner*` metadata when present to decode bounded scalar, object, and
`FName` elements; unsupported element classes return a raw element table with
`BytesHex`. For sets and maps it emits header-only
`FScriptSetHeader` and `FScriptMapHeader` tables with the same metadata.
Container descriptor discovery separately emits
`event=ue-function-param-container-child` for decoded `FArrayProperty`,
`FSetProperty`, or `FMapProperty` inner/key/value child metadata; the bounded
scan window defaults to `0x48..0xa0` via
`UE4SSL_WIN_UE_REFLECTION_CONTAINER_CHILD_SCAN_START` and
`UE4SSL_WIN_UE_REFLECTION_CONTAINER_CHILD_SCAN_END`. Promoted live
param descriptors expose those children to Lua as `ContainerChildren` plus
`GetInner()`, `GetElementProperty()`, `GetKeyProperty()`, and
`GetValueProperty()` where applicable.
Unsupported complex values, including non-vector structs, still emit
`status=raw value=rawHex=...` and Lua returns a `RawUnrealParam` table. This
still does not perform typed container element unmarshaling or complete live
`FProperty` object marshaling.
Confidence: high.

Set `UE4SSL_WIN_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=true` with the
live hook scaffold in a smoke/lab run to arm native ProcessEvent pre/post
callbacks. The persistent hook invokes those callbacks around the original
function and logs the callback counts. This proves the native dispatch spine
before Lua is attached. Confidence: high.

Set `UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=true` with the
live hook scaffold after native dispatch passes and after
`UE4SSL_WIN_LUA_DLL` points at a real Windows Lua 5.4 DLL. Run
`scripts/stage-windows-lua-runtime.sh` or `make smoke-windows-client-loader-lua`
to stage the pinned test DLL. The loader
creates a persistent Lua VM for the live hook, executes
`UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_SCRIPT` or the default
`RegisterHook` script, stores the Lua pre/post refs, and invokes those callbacks
from the live ProcessEvent hook around the original call. The callback receives
a table with raw `object`, `function`, and `params` addresses plus `stage`,
`call`, `originalCalled`, `preCallbacks`, and `postCallbacks`; when the loader
can resolve those addresses, it also includes UE4SS-shaped `Object` and
`Function` handle tables plus a `Params` context table. A pass logs
`event=ue-process-event-live-lua-dispatch status=armed` and the live hook line
reports `luaDispatch=true luaObjectHandleHits=2 luaFunctionHandleHits=2
luaParamsHandleHits=2 luaParamDescriptorHits=2
luaParamDescriptorLookupHits=12 luaFunctionParamDescriptorHits=2
luaParamGetHits=18 luaParamSetHits=6`; without a staged Lua DLL it reports
`status=library-missing`. `GetFunctionParamDescriptors`/`GetFunctionParams`
first return live registry descriptors when `ctx.Function` matches a scanned
`UFunction`, and fall back to the self-test `Value`, `OriginalResult`, and
`Touched` fields for loader-owned callbacks. `GetParamValue` and
`SetParamValue` accept descriptor tables from either source, but they are
guarded to the active callback's params block, `VirtualQuery` page permissions,
descriptor type, and scalar/bool/object/name/string width. This proves live
ProcessEvent-to-Lua callback routing with handle-backed object/function context,
a stable params address table, and bounded scalar/bool/object-pointer plus
in-place `FName`/`FString` params get/set plumbing, not full live `FProperty`
marshaling. When the synthetic function path is known, dispatch filters
registered hooks by `ctx.functionPath`; unresolved live `UFunction` paths remain
permissive until real path/name discovery is proven. Confidence: high for the
hook path, moderate for Proton until the real-DLL smoke passes.

Set `UE4SSL_WIN_LUA_REFLECTION_SELF_TEST=true` after the plain Lua
self-test passes. It exposes UE4SS-shaped `GetPropertyValue`,
`SetPropertyValue`, and `CallFunction` globals to Lua and exercises them against
the loader-owned `/Script/UE4SSLProbe.SelfTestObject` handle. For the raw
property read only, the default self-test prefers the registered
`/RuntimeProbe/SelfTestUObject` candidate and falls back to the synthetic handle
when no runtime candidate was discovered. In the smoke fixture the scan logs
`fieldName=SelfTestUObjectName_0 rawLe=0x7`, then the loader mutates its own
`SelfTestUObject` scalar to prove Lua is doing a guarded live re-read through a
decoded property alias. If
`UE4SSL_WIN_LUA_REFLECTION_RAW_SET_ENABLED=true`, the self-test also
writes `17` back to that loader-owned candidate and re-reads it, logging
`rawPropertySetHits=1 rawPropertySetValue=17`. Keep this flag false for live
read-only canaries. A read-only pass logs `rawPropertyValue=13`; a raw-set pass
logs `event=lua-reflection-self-test ... result=42 getPropertyHits=20
rawPropertyHits=2 rawPropertyValue=17 namedPropertyHits=2 rawPropertySetHits=1
rawPropertySetValue=17 arrayInnerPropertyHits=1 enumPropertyHits=1
enumUnderlyingPropertyHits=1 setElementPropertyHits=1 mapKeyPropertyHits=1
mapValuePropertyHits=1 importTextHits=1 setPropertyHits=9 probeFloat=13.750
probeDouble=-47.500 probeName=ArrakisName probeText=WaterDebt
callFunctionHits=2`. Without that
registry, the raw lookup returns nil and the self-test still covers the
synthetic fields.
This proves integer, boolean, float, double, `FName`, string, `FText`,
object-handle, function-call, bounded `FArrayProperty:GetInner()` metadata, and
bounded `FEnumProperty:GetEnum()` / `GetUnderlyingProperty()` metadata, and
bounded `FSetProperty` element plus `FMapProperty` key/value metadata, and
bounded `FProperty:ImportText()` text-to-value writes for loader-owned scalar
and string-like descriptors, bounded `FProperty:ExportText()` value-to-text
exports for the same loader-owned descriptors, bounded property metadata
accessors for offset, size, array dimension, and property flags, and
gated raw candidate get/set through the Lua reflection dispatch surface, not
live typed `FProperty` marshaling, live enum value marshaling, or arbitrary
container storage marshaling from target profile objects. Confidence: high for parity
with the Linux path in local Wine smoke, moderate until tested with live target profile
under Proton.

Set `UE4SSL_WIN_LUA_MODS_ENABLED=true` to load Lua mod entrypoints
from `UE4SSL_WIN_LUA_MOD_SCRIPTS` (semicolon-separated files) and
`UE4SSL_WIN_LUA_MOD_ROOT`. The root scanner accepts direct `*.lua`
files and the UE4SS-style `Mods\<ModName>\Scripts\main.lua` layout. Set
`UE4SSL_WIN_LUA_MOD_DISPATCH_SELF_TEST=true` to invoke callbacks
registered by the loaded mod script and log
`event=lua-mod-dispatch-self-test ... status=passed`. Without a staged Lua DLL,
the mod loader exits with `event=lua-mod-finish ... status=library-missing`,
which is expected. Script reads are capped at 256 KiB and the loader accepts at
most 32 entrypoints and 32 hook registrations per run. `RegisterHook` uses the
same bounded multi-callback registry as the Linux paths, so separate mod scripts
do not overwrite each other's pre/post callbacks. If a script fails to load or
execute, `event=lua-mod-script` includes a sanitized `error=` field. Confidence:
high for parity with the Linux path, moderate until tested with a real Windows
Lua DLL under Proton.

## Proton DLL Override

If a real Steam launch loads Proton's builtin `version.dll` instead of the
staged native proxy, set an app-specific Wine override:

```bash
scripts/proton-dll-override-control.sh --set
scripts/proton-dll-override-control.sh --query
```

This writes:

```text
HKCU\Software\Wine\AppDefaults\TargetGame-Win64-Shipping.exe\DllOverrides
version=native,builtin
```

The script backs up `user.reg`, `system.reg`, and `userdef.reg` first and writes
a manifest under:

```text
build/windows-client-loader/proton-dll-override-manifest.txt
```

Remove the override:

```bash
scripts/proton-dll-override-control.sh --unset
```

The helper refuses set/unset while target profile client processes are running unless
`UE4SSL_PROTON_OVERRIDE_ALLOW_RUNNING=true` is set.

## Analysis

Summarize a real client log:

```bash
analysis/summarize-client-loader-scan.py /tmp/ue4ssl-win-client-probe-loader.log
analysis/summarize-client-ue-anchors.py /tmp/ue4ssl-win-client-probe-loader.log
```

Latest canary summary:

```bash
analysis/summarize-client-loader-scan.py /tmp/ue4ssl-win-client-probe-loader.log --loader win-client
analysis/summarize-client-ue-anchors.py /tmp/ue4ssl-win-client-probe-loader.log --loader win-client
```

Find static PE xrefs from real runtime scan hits back into the shipping exe:

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

The xref tool maps loader `rva` hits back to file offsets, scans executable PE
sections for simple x86-64 RIP-relative/call/jump references, and also checks
the start of the containing ASCII string when the scan hit is a substring.
That matters for Unreal-style text surfaces where compiled code references the
full string literal, not necessarily the matched needle offset. Confidence:
high for string/code-neighborhood triage, moderate for final hook addresses
until object and function signatures are validated. With `--show-seeds`, the
tool prints wildcarded seed windows around each xref; those are candidate
signature inputs, not validated cross-build patch signatures.

Validate those seed windows before promoting them:

```bash
analysis/validate-client-pe-signatures.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --format json \
  > build/windows-client-loader/client-pe-signature-validation.json
```

`unique-expected` means the seed occurs once in executable PE sections and still
lands at the xref address that generated it. `ambiguous`, `missing`, or
`unique-unexpected` means do not promote that seed to a build-check signature.
Confidence: high.

Export a JSON manifest or runtime scan chunks:

```bash
analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --format json \
  --output build/windows-client-loader/client-pe-signature-manifest.json

analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --format env \
  --output build/windows-client-loader/client-pe-signature-env-chunks.env

analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category cheat \
  --category brt \
  --format signatures \
  --output build/windows-client-loader/client-pe-signatures.txt

analysis/export-client-pe-signature-manifest.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --loader-log /tmp/ue4ssl-win-client-probe-loader.log \
  --category ue \
  --format anchor-signatures \
  --output build/windows-client-loader/client-anchor-signatures.txt
```

Validate an existing manifest against a later client build before reusing it:

```bash
analysis/validate-client-pe-signatures.py \
  ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe \
  --manifest-json build/windows-client-loader/client-pe-signature-manifest.json \
  --ignore-expected-offsets \
  --format json \
  > build/windows-client-loader/client-pe-signature-revalidation.json
```

Without `--ignore-expected-offsets`, the validator enforces same-build exact
file offsets and only `unique-expected` rows are promotable. With
`--ignore-expected-offsets`, a signature that moved but still occurs exactly
once is promotable for canary scanning; `missing` or `ambiguous` still means do
not rely on that signature. Confidence: high.

The Windows loader now accepts up to 256 signature patterns. For full manifests,
prefer `UE4SSL_WIN_SCAN_SIGNATURES_FILE` so the whole validated set
can run in one launch. The `env` export remains useful when a file path is
inconvenient; it splits runtime signatures into conservative chunks because the
sidecar config value is capped lower than a full manifest. Set exactly one
generated `UE4SSL_WIN_SCAN_SIGNATURES` chunk per launch when using
env chunks. Confidence: high.

Gate UE4SS-port readiness after the scan and validation steps:

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

analysis/ue4ss-port-readiness.py \
  --client-log /tmp/ue4ssl-win-client-probe-loader.log \
  --loader win-client \
  --signature-validation-json build/windows-client-loader/client-pe-signature-validation.json
```

`export-ue-anchor-env.py` exports core discovery anchors plus reflection anchors
by default. It accepts anchors found by string/signature scan, mapped explicit
anchor validation, or resolved `ue-anchor-signature` records; unresolved and
ambiguous signatures remain missing.
`prepare-ue-anchor-canary.py` combines the validated PE UE signature manifest,
loader-consumable anchor signature file, second-pass anchor env, validation
summary, and readiness report for the next Proton/Windows canary. Confidence:
high.
`plan-ue4ss-canary-env.py` emits the next guarded Proton/Windows env from
readiness evidence. It defaults to read-only object/reflection discovery; use
`--max-stage hook-probe`, `live-hook`, or `lua-dispatch` only for the matching
lab canary phase. `live-hook` and `lua-dispatch` plans also enable bounded live
ProcessEvent call logging so `ue-process-event-live-context` readiness evidence
is collected in the same canary. Confidence: high.

This gate must report `objectDiscovery=true` and `ueObjectInternalFlags=true`
before ProcessEvent hook work, `reflection=true` before live property work, including
`ueReflectionFieldWalk=true`, `ueReflectionPropertyDescriptors=true`,
`ueFunctionParamDescriptors=true`, `ueFunctionParamContainerChildren=true`,
`ueFunctionIdentities=true`,
`ueFunctionFlags=true`, and `ueReflectionPropertyValues=true`. It
must report `ueProcessEventHookProbe=true`, `ueProcessEventLiveHook=true`,
`ueProcessEventDispatch=true`, `ueProcessEventLiveLuaDispatch=true`, and
`ueProcessEventLiveContext=true`, `ueProcessEventLiveParamValues=true`,
`ueProcessEventLiveRawParamValues=true`, `ueProcessEventLuaContextHandles=true`,
`ueProcessEventLuaParamAccessors=true`,
`ueProcessEventLuaScalarParamAccessors=true`,
`ueProcessEventLuaNameStringParamAccessors=true`,
`ueProcessEventLuaStructParamAccessors=true`, and
`ueProcessEventLuaHookRouting=true` before routing real ProcessEvent calls
into Lua/mod callbacks, and `luaDispatch=true` plus `luaObjectApi=true`,
`luaProcessConsoleExecHooks=true`, `luaLocalPlayerExecHooks=true`,
`luaCallFunctionHooks=true`, `luaLifecycleHooks=true`, `luaObjectNotify=true`,
`luaSyntheticOuter=true`, `luaDecodedObjectAliases=true`,
`luaReflectionNumericPropertyValues=true`, and
`luaReflectionNameTextPropertyValues=true`, and
`luaReflectionArrayInnerProperty=true`, `luaReflectionEnumProperty=true`, and
`luaReflectionContainerProperties=true`, `luaReflectionImportText=true`, and
`luaReflectionExportText=true`, `luaReflectionPropertyMetadata=true`, and
`luaReflectionDescriptorValues=true`
before exposing UE4SS Lua object APIs.
Confidence: high.

Rank fallback proxy DLLs:

```bash
analysis/proton-proxy-candidates.py ~/.steam/steam/steamapps/common/TargetGame/TargetGame/Binaries/Win64/TargetGame-Win64-Shipping.exe
```

## Package

```bash
scripts/package-windows-client-loader.sh
```

Default package location:

```text
dist/windows-client-loader/
```

## Next UE4SS-Port Step

Use `analysis/summarize-client-loader-xrefs.py` against the real Proton canary
log to rank code neighborhoods for `CheatManager`, BRT strings, Deep Desert
state strings, and the current `GName` surface. The missing UE4SS-port anchors
remain object array, world, function dispatch, and a stronger names layout
candidate. Add read-only Unreal object discovery, then run the guarded
ProcessEvent hook probe and persistent hook scaffold, prove the native
ProcessEvent callback spine, enable the live Lua callback bridge with resolved
`Object`/`Function` handles and a `Params` context table, prove
`GetFunctionParamDescriptors`/`GetFunctionParams` plus descriptor-handle
`GetParamDescriptor` and `GetParamValue`/`SetParamValue` callback access,
then prove on a live Proton canary that `ctx.Function` from a real ProcessEvent
call hits the promoted `ue-function-param` registry and that guarded class-aware
`GetParamValue` works on the active params pointer. Then replace the bounded
`Reflection():GetProperty` descriptor shim with live UE property traversal and
argument marshaling.
