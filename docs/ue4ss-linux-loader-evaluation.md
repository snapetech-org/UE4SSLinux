# UE4SS Linux Server Loader Evaluation

Status on 2026-06-16: upstream UE4SS is not directly usable in the current
native Linux target profile dedicated-server containers. Confidence: high.

The linked `CheatManagerEnablerMod` is a UE4SS Lua client-style mod by default.
It becomes server-side only if UE4SS itself is loaded into the dedicated server
process. Installing the mod files into a target profile client is out of scope for this
repo, and this repo must not edit local Steam/target profile client files.

The upstream mod script itself is small: it registers a UE4SS Lua hook on
`/Script/Engine.PlayerController:ClientRestart`, checks
`PlayerController.CheatManager`, falls back to
`StaticFindObject("/Script/Engine.CheatManager")` when `CheatClass` is null,
then `StaticConstructObject`s the cheat manager and assigns it back to
`PlayerController.CheatManager`. That requires UE4SS object discovery,
`RegisterHook`, `StaticFindObject`, and `StaticConstructObject` inside the
target Unreal process; the Lua file alone cannot do anything in a Linux server
container. The current loader now proves the Lua API shape for
`StaticConstructObject` with a synthetic registry handle, not a real UE
allocation.

## Upstream Findings

- Upstream `xmake.lua` restricts platforms to Windows x64.
- Upstream CMake project config exposes `Win64` as the platform type.
- The release/install shape is a Windows proxy-DLL layout under `Binaries/Win64`.
- Native Linux configure cannot complete from the public checkout here because
  `deps/first/Unreal` points to `git@github.com:Re-UE4SS/UEPseudo.git`, which is
  not accessible from this environment.
- Source inspection shows Windows loader/API assumptions throughout the runtime:
  proxy generation, `LoadLibrary*`, `GetModuleHandle*`, Windows module handles,
  DLL entrypoints, Windows exception/crash handling, and `__declspec` exports.
- Upstream `CheatManagerEnablerMod` depends on UE4SS Lua APIs and an Unreal
  `PlayerController` hook. It is not a standalone binary patch, pak patch, or
  server config.

## Repo-Side Loader Foundation

This repo now has a native Linux preload probe with read-only UE anchor probes
and loader-owned UE4SS-style dispatch self-tests. It is not a complete UE4SS
port. It proves that we can inject a shared object into the Linux server
process, collect runtime module visibility, validate explicit UE runtime
anchors, run bounded pointer/layout/UObject/object-array/FName probes, register
candidate object handles for Lua, run guarded hook/mod dispatch self-tests,
execute Lua through a dynamic Lua C API, exercise typed Lua reflection
callbacks, and dispatch Lua callbacks through a ProcessEvent-shaped
loader-owned trampoline. It can also run a guarded mapped/executable
ProcessEvent target hookability probe that installs an inline hook and
immediately restores it when explicitly enabled. The persistent ProcessEvent
hook scaffold can also be installed behind a separate opt-in gate; it forwards
to the original function and restores on unload. A separate live-Lua gate now
routes loader-provided `RegisterHook` pre/post callbacks from that persistent
hook, but it does not yet decode live UE arguments or marshal real `FProperty`
payloads. Confidence: high for the local smoke path.

Build it:

```bash
scripts/build-linux-server-loader.sh
```

The default output is:

```text
build/linux-server-loader/libue4ssl_linux_server_loader.so
```

Enable it for a lab container only:

```dotenv
UE4SSL_ENABLE_LINUX_SERVER_PRELOAD=true
UE4SSL_LINUX_SERVER_PRELOAD=/workspace/build/linux-server-loader/libue4ssl_linux_server_loader.so
UE4SSL_LINUX_SERVER_PRELOAD_PARTITIONS=7
UE4SSL_SERVER_LOG=/tmp/ue4ssl-server-loader.log
UE4SSL_SERVER_SNAPSHOT_DELAY_SECONDS=0
```

`scripts/run_server_safe.sh` refuses to start with preload enabled unless the
library path exists and is readable inside the container. With preload disabled,
server startup behavior is unchanged.

Optional read-only scan mode:

```dotenv
UE4SSL_SERVER_SCAN_ENABLED=true
UE4SSL_SERVER_SCAN_PRESETS=building,brt,deep-desert,gm,cheat
UE4SSL_SERVER_SCAN_STRINGS=DeepDesert;ServerRequestBaseBackup;BaseBackupTool;BuildingSettings;CheatManager;PrintAllowedCommands;PartitionIndex;BuildableMapRegion;FuncomLiveServices;FarmHealth
UE4SSL_SERVER_SCAN_SIGNATURES=brt-action-guard=48 85 c0 74 0a 41 b6 01 41 80 7f 55 01 75 03
UE4SSL_SERVER_SCAN_SIGNATURES_FILE=/path/to/server-signatures.txt
UE4SSL_SERVER_SCAN_MAX_HITS_PER_NEEDLE=16
UE4SSL_SERVER_SCAN_LOG_MAPPINGS=true
UE4SSL_SERVER_SCAN_MAX_MAPPING_BYTES=536870912
```

Scan mode reads `/proc/self/maps` from inside the process and logs string or byte
signature hits with runtime address, image offset, and file offset. It does not
write memory. The current Funcom Linux server executable is about 357 MiB, so
canaries need `UE4SSL_SERVER_SCAN_MAX_MAPPING_BYTES` above that size.
`UE4SSL_SERVER_SNAPSHOT_DELAY_SECONDS` is a constructor-time sleep, so keep
it `0` unless intentionally delaying a lab server start. The built-in presets
cover the current investigation surfaces:

- `building`: landclaim, subfief/totem, and building-piece cap strings.
- `brt`: Base Reconstruction Tool and placement-verdict strings.
- `deep-desert`: Deep Desert map identity and spice/system settings strings.
- `gm`: native server-command/GM command strings.
- `cheat`: CheatManager/UE4SS-adjacent strings.

Validate and export same-build ELF signature seeds after a scan/xref pass:

```bash
analysis/validate-elf-signatures.py /path/to/TargetGameServer-Linux-Shipping \
  --loader-log /tmp/ue4ssl-server-loader.log \
  --category brt \
  --format json > build/linux-server-loader/elf-signature-validation.json

analysis/export-elf-signature-manifest.py /path/to/TargetGameServer-Linux-Shipping \
  --loader-log /tmp/ue4ssl-server-loader.log \
  --target-loader server \
  --category brt \
  --format signatures > build/linux-server-loader/server-signatures.txt

analysis/export-elf-signature-manifest.py /path/to/TargetGameServer-Linux-Shipping \
  --loader-log /tmp/ue4ssl-server-loader.log \
  --target-loader server \
  --category ue \
  --format anchor-signatures > build/linux-server-loader/server-anchor-signatures.txt

analysis/prepare-ue-anchor-canary.py \
  --platform server \
  --binary /path/to/TargetGameServer-Linux-Shipping \
  --loader-log /tmp/ue4ssl-server-loader.log \
  --output-dir build/linux-server-loader/server-anchor-canary

analysis/plan-ue4ss-canary-env.py \
  --platform server \
  --server-log /tmp/ue4ssl-server-loader.log \
  --max-stage read-only \
  > build/linux-server-loader/next-canary.env
```

The validator reports `unique-expected`, `unique-unexpected`,
`ambiguous-expected`, `ambiguous`, or `missing` for each seed. The exported JSON
manifest is the cross-build revalidation artifact; the `signatures` output is a
line-based file for `UE4SSL_SERVER_SCAN_SIGNATURES_FILE`. The
`anchor-signatures` output is a line-based file for
`UE4SSL_SERVER_UE_ANCHOR_SIGNATURES_FILE`; it emits only validated
promotable rows whose names map to UE anchor groups. Confidence: high for
synthetic ELF validator coverage.
`prepare-ue-anchor-canary.py` is the one-command bridge for the next pass: it
writes the validated UE manifest, loader-consumable anchor signature sidecar,
second-pass anchor env, validation summary, and readiness report into one
directory. Confidence: high.
`plan-ue4ss-canary-env.py` reads readiness evidence and emits the next guarded
server env. It defaults to read-only object/reflection discovery; use
`--max-stage hook-probe`, `live-hook`, or `lua-dispatch` only for the matching
lab canary phase. `live-hook` and `lua-dispatch` plans also enable bounded live
ProcessEvent call logging so `ue-process-event-live-context` readiness evidence
is collected in the same canary. Confidence: high.

Optional read-only UE anchor probes:

```dotenv
UE4SSL_SERVER_UE_ANCHORS=FNamePool=0x0;GUObjectArray=0x0;GWorld=0x0;ProcessEvent=0x0
UE4SSL_SERVER_UE_ANCHOR_SIGNATURES=
UE4SSL_SERVER_UE_ANCHOR_SIGNATURES_FILE=/path/to/server-anchor-signatures.txt
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
UE4SSL_SERVER_UE_REFLECTION_FUNCTION_FLAGS_OFFSET=0x58
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
```

These probes are read-only. They report whether configured runtime addresses are
mapped, whether anchor pointers resolve to mapped targets, whether target memory
looks like expected UE layouts, and whether bounded object-array/FName reads can
produce Lua object handles. The probes do not install live UE hooks and do not
write game memory. Confidence: high for the self-test anchors, moderate for live
server anchors until a one-map canary supplies valid addresses.

`UE4SSL_SERVER_UE_ANCHOR_SIGNATURES` and
`UE4SSL_SERVER_UE_ANCHOR_SIGNATURES_FILE` use the same `name=aa bb ??`
syntax as scan signatures, but only unique runtime matches are promoted to UE
anchors before pointer/layout/UObject/FName probes run. Missing and ambiguous
matches log `event=ue-anchor-signature` and are skipped. Use `Name@hit+N`,
`Name@riprel32+N`, `Name@callrel32`, or `Name@ptr+N` when a signature match
must be transformed into the anchor address. Confidence: high.
Generate this file with
`analysis/export-elf-signature-manifest.py --format anchor-signatures` after a
same-build validation pass.

Export second-pass server anchor env from a scan log:

```bash
analysis/export-ue-anchor-env.py /tmp/ue4ssl-server-loader.log \
  --loader server \
  --platform server \
  --format env > ue-server-anchors.env

analysis/prepare-ue-anchor-canary.py \
  --platform server \
  --binary /path/to/TargetGameServer-Linux-Shipping \
  --loader-log /tmp/ue4ssl-server-loader.log \
  --output-dir build/linux-server-loader/server-anchor-canary

analysis/plan-ue4ss-canary-env.py \
  --platform server \
  --server-log /tmp/ue4ssl-server-loader.log \
  --max-stage read-only \
  > build/linux-server-loader/next-canary.env
```

That emits `UE4SSL_SERVER_UE_ANCHORS` plus the read-only pointer, layout,
UObject, object-array, and FName probe toggles for the Linux server loader.
The canary-prep helper emits the same env plus the corresponding signature and
readiness artifacts so the follow-up launch has one auditable input directory.
The canary env planner turns that readiness evidence into the next guarded
environment file, keeping hook-probe/live-hook/Lua-dispatch escalation behind an
explicit `--max-stage` boundary.

Optional loader-owned dispatch self-tests:

```dotenv
UE4SSL_SERVER_HOOK_SELF_TEST=false
UE4SSL_SERVER_MOD_SELF_TEST=false
UE4SSL_SERVER_LUA_SELF_TEST=false
UE4SSL_SERVER_LUA_LIBRARY=
UE4SSL_SERVER_LUA_REFLECTION_SELF_TEST=false
UE4SSL_SERVER_LUA_REFLECTION_RAW_SET_ENABLED=false
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
UE4SSL_SERVER_LUA_MODS_ENABLED=false
UE4SSL_SERVER_LUA_MOD_SCRIPTS=
UE4SSL_SERVER_LUA_MOD_DISPATCH_SELF_TEST=false
UE4SSL_SERVER_GAME_DIR=
UE4SSL_SERVER_UNREAL_VERSION_MAJOR=5
UE4SSL_SERVER_UNREAL_VERSION_MINOR=0
```

The local smoke runs these against `/usr/bin/true`:

```bash
scripts/smoke-linux-server-loader.sh
```

Passing `event=lua-reflection-self-test` proves integer, boolean, float,
double, string, object-handle, function-call, and read-only raw
reflected-candidate lookup against a loader-owned object when the bounded value
probe has populated the candidate registry. It also proves bounded
`FArrayProperty:GetInner()` metadata through `arrayInnerPropertyHits=1` and
bounded `FEnumProperty:GetEnum()` / `GetUnderlyingProperty()` metadata through
`enumPropertyHits=1 enumUnderlyingPropertyHits=1`, and bounded `FSetProperty`
element plus `FMapProperty` key/value metadata through
`setElementPropertyHits=1 mapKeyPropertyHits=1 mapValuePropertyHits=1`.
It also proves bounded `FProperty:ImportText()` text-to-value writes through
`importTextHits=1` and bounded `FProperty:ExportText()` value-to-text exports
through `exportTextHits=1`. Property descriptor metadata accessors are proven
through `propertyMetadataHits=7`, and descriptor-level `GetValue()` /
`SetValue()` on loader-owned descriptors is proven through
`descriptorValueGetHits=16 descriptorValueSetHits=8`.
The Lua object API now includes `StaticFindObject`, `FindObject`,
`FindFirstOf`, `GetKnownObjects`, `FindObjects`, `FindAllOf`,
`ForEachUObject`, `IsA`, and `LoadAsset`. Those calls operate on the loader
registry: self-test handles, class-mapped `ue-uobject` candidates, bounded
object-array candidates, and synthetic objects created by
`StaticConstructObject`. Synthetic construction now preserves `ClassAddress`
when the class argument is a known object or `UClass` handle. `LoadAsset`
currently resolves only already-known registry handles by path/name and returns
`nil` for unknown assets. This gives
mods a UE4SS-shaped object API before the backend is replaced with full
`GUObjectArray` enumeration and real package loading.
`NotifyOnNewObject(filter, callback)` is bounded to the synthetic construction
path for now: it stores up to 32 class/path/name filter registrations and
dispatches every matching callback when loader-owned `StaticConstructObject`
creates a matching handle. It is not a live Unreal object-construction hook
yet.
Returned object/function handles now include the first UE4SS-style method layer:
`GetFullName`, `GetName`, `GetPathName`, `GetAddress`, `IsValid`, `GetClass`,
`GetOuter`, `GetWorld`, `GetFName`, `type`, `IsClass`, `IsAnyClass`, `IsA`,
flag checks, `GetPropertyValue`, `SetPropertyValue`, `CallFunction`,
`ProcessConsoleExec`, `ULocalPlayerExec`, `GetFunctionFlags`,
`SetFunctionFlags`,
`GetSuperStruct`, `ForEachFunction`, `ForEachProperty`, `GetCDO`, `IsChildOf`,
and `GetLevel`.
Handles expose scan-derived `ClassAddress`, `OuterAddress`, and `SuperAddress`
where available. `GetClass` now returns a `UClass` handle with the live scanned
`ClassPrivate` address for promoted candidates and address zero for purely
synthetic entries. `GetOuter` resolves only the loader-owned outer for synthetic
constructed objects, and `GetSuperStruct` prefers scanned super pointers before
falling back to the synthetic `UObject` base for non-`UObject` synthetic
`UClass` handles. `IsChildOf` now walks the bounded scan-derived
`SuperAddress` chain when both class handles carry live addresses, while full
hierarchy enumeration still waits on a real `GUObjectArray` backend. `GetWorld`
now resolves registered world-like handles and loader-owned outer chains, with
a conservative `GWorld`/`UWorld`-like fallback for common world-context classes;
it is not a live engine `UObject::GetWorld` call yet. `GetCDO` now returns a
loader-owned `Default__<Class>` handle for `UClass` handles with
`RF_ClassDefaultObject` set, and `GetLevel` resolves registered level-like
handles through loader-owned outer chains. Neither path calls the live engine
implementation yet. `HasAllFlags`/`HasAnyFlags` use promoted
`ObjectFlags` for scanned UObject candidates; `HasAnyInternalFlags` uses
promoted `InternalFlags` when the object-array item flags word is readable and
returns false for handles without decoded internal flag metadata;
`GetFunctionFlags` returns promoted `FunctionFlags` for scanned UFunction
handles when readable.
`SetFunctionFlags` mutates loader-owned Lua handle metadata and syncs matching
loader registry entries, but it does not write live UFunction memory.
`ForEachFunction` iterates unique promoted `UFunction` handles for
loader-owned self-test object/class handles through the same bounded registry
as `GetKnownFunctions`; it is not full live `UStruct` function-chain traversal
yet.
`ProcessConsoleExec` now dispatches loader-owned
`RegisterProcessConsoleExecPreHook` callbacks, then
`RegisterConsoleCommandHandler`/`RegisterConsoleCommandGlobalHandler`
callbacks with `(context, command, args)`, then
`RegisterProcessConsoleExecPostHook` callbacks. Console exec hooks receive
`(context, rawCommand, command, args, handled)` and may return boolean true to
mark the command handled. It is not wired to the live engine console path yet.
`ULocalPlayerExec` dispatches loader-owned
`RegisterULocalPlayerExecPreHook` callbacks and
`RegisterULocalPlayerExecPostHook` callbacks with the same
`(context, rawCommand, command, args, handled)` shape. It is not wired to live
`ULocalPlayer::Exec` yet.
`CallFunction` now dispatches loader-owned
`RegisterCallFunctionByNameWithArgumentsPreHook` callbacks before its bounded
self-test function shim and `RegisterCallFunctionByNameWithArgumentsPostHook`
callbacks after it. Call-function hooks receive
`(context, functionName, args, handled, result)` and may return
`replacement, true` to short-circuit or replace the result. It is not wired to
the live engine `UObject::CallFunctionByNameWithArguments` path yet.
`Reflection()` now returns a loader-owned `UObjectReflection` table for known
handles. `Reflection():GetProperty(name)` resolves self-test properties,
promoted `UFunction` param descriptors, and scalar live reflection candidates
into UE4SS-style property descriptor tables. Those descriptors expose
`GetFullName`, `GetFName`, `IsA`, `GetClass`, `ContainerPtrToValuePtr`,
`ImportText`, `ExportText`, `ExportTextItem`, `GetOffset_Internal`,
`GetOffsetInternal`, `GetElementSize`, `GetSize`, `GetArrayDim`,
`GetPropertyFlags`, `HasAnyPropertyFlags`, `GetPropertyClass`, bool mask helpers, `GetStruct`, `GetInner`,
and `type`. The bounded self-test descriptor set now includes integer, bool,
float, double, string, and object properties. `ForEachProperty` iterates that
bounded descriptor set instead of being a pure no-op where descriptors exist.
This is still a shim: there is no complete live `FProperty` chain traversal or
full value marshaling yet.
The global compatibility shim now also covers `FName`, `FText`, immediate
`ExecuteAsync`/`ExecuteWithDelay`/`LoopAsync`, keybind/console/custom-event
registration names, `RegisterConsoleCommandGlobalHandler`,
`RegisterProcessConsoleExecPreHook`, `RegisterProcessConsoleExecPostHook`,
`RegisterCustomProperty`, `RegisterCallFunctionByNameWithArgumentsPreHook`,
`RegisterCallFunctionByNameWithArgumentsPostHook`,
`RegisterULocalPlayerExecPreHook`, `RegisterULocalPlayerExecPostHook`,
`IterateGameDirectories`, UE4SS metadata
tables (`UE4SS`, `UnrealVersion`, `ModRef`), flag/property/key constant tables,
and loader-local `ModRef` shared variables. `FName` uses the method shape
expected by Lua mods, including `ToString()` and `GetComparisonIndex()`.
These unblock mods that probe for UE4SS APIs or do setup without registering
hooks, but they are not real scheduler threads, timers, key events, console
command dispatch, or live engine lifecycle callbacks yet. Loader-owned
custom-event and lifecycle dispatch shims now exercise registered Lua refs, but
they are not wired to live `LoadMap`, `BeginPlay`, or `InitGameState` callsites.
Passing `event=lua-process-event-self-test` proves Lua callback dispatch through
a loader-owned `ProcessEvent(UFunction*, void*)` stand-in. The default Lua
script also exercises guarded `GetParamValue`/`SetParamValue` access against
the loader-owned params block and logs
`paramDescriptorHits=2 paramDescriptorLookupHits=13
functionParamDescriptorHits=2 paramGetHits=21 paramSetHits=7`. The `Params`
table also includes descriptor
metadata under `Properties`, and Lua retrieves handles through
`GetParamDescriptor`. `Params.<Name>` and `Params.Values.<Name>` also expose
loader-owned `RemoteUnrealParam`-style wrappers with `get()`, `Get()`, `set()`,
`Set()`, and `type() == "RemoteUnrealParam"`. The default params fixture now
covers bool, object, `FName`, `FStrProperty`, an `FVector`-shaped
`FStructProperty` whose `GetStruct()` returns a synthetic
`/Script/CoreUObject.Vector` `UScriptStruct`, signed/unsigned integers, and
`float`/`double` scalar get/set paths. `RegisterHook` returns `preId, postId` pairs and
`UnregisterHook` removes temporary registrations. The ProcessEvent scripts keep
a non-target hook registered before the target hook to prove route filtering,
so the target hook id result is `4`. Lua can also call `GetFunctionParamDescriptors` or
`GetFunctionParams` on `ctx.Function` to retrieve a function-scoped descriptor
table with `PropertyCount` and `Properties`. Mods can resolve the promoted
runtime function registry with `FindFunction(pathOrName)`,
`FindFirstFunction()`, and `GetKnownFunctions()`, which returns a table keyed by
runtime `PathName` plus `Count`; compatible owner/class handles can enumerate
the same promoted functions with `ForEachFunction(callback)`. These APIs only
expose UFunctions already discovered by the bounded `functionLink` descriptor
probe. The routing self-test registers a
nonmatching hook plus the target hook, so `hooks=2` with
`preCalls=1 postCalls=1` proves known-path `RegisterHook` filtering through
`ctx.functionPath`. Passing
`event=lua-mod-dispatch-self-test` proves a Lua script entrypoint can register
callbacks and have those callbacks invoked by native code. `RegisterHook` is a
bounded registry with up to 32 hook registrations, so a later mod script does
not replace earlier pre/post callbacks for the loader-level dispatch path. None
of these events prove live typed `FProperty` marshaling yet. Unknown live
`UFunction` paths remain permissive until real path/name discovery is proven.
Confidence: high.

Set `UE4SSL_SERVER_UE_REFLECTION_FIELD_WALK=true` after the read-only
UObject, FName, and UClass slot probes are stable. It walks bounded
`children`, `childProperties`, `propertyLink`, and `functionLink` chains and
logs `event=ue-reflection-field status=candidate`. This is the server-side
equivalent of the client field/function discovery gate; it proves candidate
reflection-chain visibility, not live `FProperty` marshaling. Confidence: high
for the synthetic smoke fixture, moderate for live target profile until offsets are
validated on the current build.

Set `UE4SSL_SERVER_UE_REFLECTION_PROPERTY_PROBE=true` after the field walk
is stable. It implies the bounded field walk and reads property-shaped
descriptor fields from `childProperties` and `propertyLink`: `ArrayDim`,
`ElementSize`, `PropertyFlags`, and `Offset_Internal`. It logs
`event=ue-reflection-property status=candidate`. This is descriptor telemetry,
not live `FProperty` marshaling. Confidence: high for the synthetic smoke
fixture, moderate for live target profile until offsets are validated on the current
build. For each bounded `functionLink` candidate, the same probe also reads
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
runtime-probe identity, not a resolved Unreal package path yet. When FName/class
reads are available, the registry carries decoded `fieldClassName`/`ClassName` so Lua
can distinguish scalar, bool, object-pointer, `FName`, and `FString` params.
This is server-side
descriptor visibility, not full live `FProperty` marshaling.

Set `UE4SSL_SERVER_UE_REFLECTION_VALUE_PROBE=true` after descriptor offsets
are stable. It implies descriptor probing and reads up to
`UE4SSL_SERVER_UE_REFLECTION_VALUE_MAX_BYTES` raw bytes from the owning
object at `Offset_Internal`, logging `event=ue-reflection-value status=read`
with `fieldName`, `raw`, and `rawLe`. Successful reads are registered as
read-only Lua raw property candidates keyed by decoded field names such as
`SelfTestUObjectName_0` when the FName reader is available, with positional
fallback keys such as `propertyLink[0]`; Lua `GetPropertyValue` re-reads
1/2/4/8-byte scalar candidates from the owning object through the same guarded
memory checks. The reflection self-test queries `/RuntimeProbe/SelfTestUObject`
by decoded field name first and falls back to the positional raw path when
needed. If
`UE4SSL_SERVER_LUA_REFLECTION_RAW_SET_ENABLED=true`, `SetPropertyValue` can
write bounded 1/2/4/8-byte scalar candidates only when the destination range is
writable; keep it false for read-only live canaries. The smoke fixture enables
it only against loader-owned memory and expects `rawPropertySetHits=1
rawPropertySetValue=17` plus `namedPropertyHits=2`. This is bounded server-side
value telemetry and live raw Lua scalar get/set, not typed `FProperty`
marshaling. The Lua reflection self-test also covers loader-owned
`FNameProperty` and `FTextProperty` get/set surfaces, with readiness reported as
`luaReflectionNameTextPropertyValues=true`, and bounded array inner metadata as
`luaReflectionArrayInnerProperty=true`, and bounded enum metadata as
`luaReflectionEnumProperty=true`; real live `FText` mutation, live enum value
marshaling, arbitrary live property ImportText dispatch, and arbitrary
container storage marshaling still require
target-layout proof. Confidence: high
for the synthetic smoke fixture, moderate for live target profile until offsets are
validated on the current build.

Set `UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_PROBE=true` after a unique
`ProcessEvent` target exists through
`UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_ADDRESS`,
`UE4SSL_SERVER_UE_PROCESS_EVENT_ADDRESS`, explicit UE anchors, or
signature-resolved UE anchors. The probe validates that the target is mapped and
executable. With `UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_INSTALL=true`, it
temporarily installs the inline hook and restores the original bytes before
returning. Use
`UE4SSL_SERVER_UE_PROCESS_EVENT_HOOK_SELF_TEST_TARGET=true` only for
loader-owned smoke tests. This is the live-target hardening gate before a
persistent ProcessEvent dispatcher, not the dispatcher itself. Confidence:
high.

Set `UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK=true` only after the guarded
hookability probe passes on the same resolved target. The scaffold resolves the
target from `UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_HOOK_ADDRESS`, the
hook-probe address, the generic ProcessEvent address, explicit anchors, or
signature-resolved anchors. It installs once, leaves the hook active for the
process lifetime, calls the original through the trampoline, optionally logs
bounded calls, and restores on loader unload. When bounded call logging is
enabled, `event=ue-process-event-live-context status=resolved` proves sampled
raw `Object`/`Function`/`Params` pointers resolved to a Lua-visible object
handle, a `UFunction` path, a nonzero params pointer, and promoted function
param descriptors. The same bounded sample emits
`event=ue-process-event-live-param` for descriptor-backed scalar, bool,
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
`event=ue-function-param-container-child` for decoded `FArrayProperty`,
`FSetProperty`, or `FMapProperty` inner/key/value child metadata; the bounded
scan window defaults to `0x48..0xa0` via
`UE4SSL_SERVER_UE_REFLECTION_CONTAINER_CHILD_SCAN_START` and
`UE4SSL_SERVER_UE_REFLECTION_CONTAINER_CHILD_SCAN_END`. Promoted live param
descriptors expose those children to Lua as `ContainerChildren` plus
`GetInner()`, `GetElementProperty()`, `GetKeyProperty()`, and
`GetValueProperty()` where applicable.
Unsupported complex values, including non-vector structs, still emit
`status=raw value=rawHex=...` and Lua returns a `RawUnrealParam` table. It still
does not perform typed container element unmarshaling or complete live
`FProperty` object marshaling.
Confidence: high.

Set `UE4SSL_SERVER_UE_PROCESS_EVENT_DISPATCH_SELF_TEST=true` with the live
hook scaffold in a smoke/lab run to arm native ProcessEvent pre/post callbacks.
The persistent hook invokes those callbacks around the original function and
logs the callback counts. This proves the native dispatch spine before Lua is
attached. Confidence: high.

Set `UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH=true` with the live
hook scaffold after native dispatch passes. The loader creates a persistent Lua
VM for the live hook, executes
`UE4SSL_SERVER_UE_PROCESS_EVENT_LIVE_LUA_SCRIPT` or the default
`RegisterHook` script, stores Lua pre/post refs, and invokes those callbacks
from the live ProcessEvent hook around the original call. The callback receives
a table with raw `object`, `function`, and `params` addresses plus `stage`,
`call`, `originalCalled`, `preCallbacks`, and `postCallbacks`; when the loader
can resolve those addresses, it also includes UE4SS-shaped `Object` and
`Function` handle tables plus a `Params` context table. A pass logs
`event=ue-process-event-live-lua-dispatch status=armed` and the live hook line
reports `luaDispatch=true luaObjectHandleHits=2 luaFunctionHandleHits=2
luaParamsHandleHits=2 luaParamDescriptorHits=2
luaParamDescriptorLookupHits=12 luaFunctionParamDescriptorHits=2
luaParamGetHits=18 luaParamSetHits=6`. `GetFunctionParamDescriptors`/
`GetFunctionParams` first return live registry descriptors when `ctx.Function`
matches a scanned `UFunction`, and fall back to the self-test `Value`,
`OriginalResult`, and `Touched` fields for loader-owned callbacks.
`FindFunction`, `FindFirstFunction`, and `GetKnownFunctions` expose the same
promoted runtime UFunction handles to Lua mods, keyed by runtime `PathName`.
`GetKnownObjects`, `FindObjects`, `FindAllOf`, and `ForEachUObject` expose the
current object registry with the same keyed-table/handle shape across Linux and
Windows/Proton. `LoadAsset` is the same registry-backed lookup on each target,
not package loading yet.
Decoded UObject `FName` values are promoted into `/RuntimeProbe/<DecodedName>`
object aliases when the bounded FName reader is active, with duplicate
object-array aliases skipped for the same object address/name.
`GetParamValue` and `SetParamValue` accept descriptor tables from either source,
but they are guarded to the active callback's params block, mapped page
permissions, descriptor type, and scalar/bool/object/name/string width. This
proves live ProcessEvent-to-Lua callback routing with handle-backed
object/function context, a stable params address table, and bounded
scalar/bool/object-pointer plus in-place `FName`/`FString` params get/set
plumbing plus known-path `RegisterHook` filtering, not full live `FProperty`
marshaling. Unknown live
`UFunction` paths remain permissive until real path/name discovery is proven.
Confidence: high on
hosts with a compatible Lua 5.4 C API library.

## Integration Plan

1. Use the probe loader in a disposable Linux server container and verify:
   process load, module list, configured scan hits, and no crash.
2. Use scan/xref output to promote same-build UE anchors into
   `UE4SSL_SERVER_UE_ANCHORS`, then validate FName/object/world readers on
   exactly one live map before any live hook work.
3. Add real Unreal object discovery: find `GUObjectArray`, `FNamePool`/`GNames`,
   `GWorld`, `UClass`/`UFunction` metadata, and `ProcessEvent` without manual
   anchor input.
4. Replace the bounded `Reflection():GetProperty` descriptor shim with live
   `FProperty` chain traversal and value marshaling for primitive values,
   strings, object references, arrays/maps, and function params/returns.
5. Run the guarded ProcessEvent hookability probe on the resolved live target.
6. Install the persistent ProcessEvent hook scaffold only after a lab canary
   survives restarts and map travel.
7. Prove native ProcessEvent pre/original/post callback dispatch through the
   persistent hook before Lua routing.
8. Prove live ProcessEvent-to-Lua `RegisterHook` callback routing through the
   persistent hook with resolved `Object`/`Function` handles and a `Params`
   context table before live reflection marshaling.
9. Prove Lua `GetFunctionParamDescriptors`/`GetFunctionParams` plus
   descriptor-handle `GetParamDescriptor` and `GetParamValue`/`SetParamValue`
   access from ProcessEvent callbacks.
10. Prove, on a live canary, that `ctx.Function` from a real ProcessEvent call
   has a nonempty runtime `PathName`, hits the promoted `ue-function-param`
   registry, and that guarded class-aware `GetParamValue` works on the active
   params pointer before replacing the self-test params block with full
   `FProperty` param marshaling.
11. Convert proven read-only anchors into guarded runtime patches only after the
   injected hook path has cleanup and recovery coverage.
12. Add Lua mod compatibility APIs beyond the current scaffold: replace the
   synthetic `StaticConstructObject`/`NotifyOnNewObject` path with guarded live
   construction and object notification, replace
   registry-only `LoadAsset` with real package/asset resolution, promote live
   class/outer/world/flag fields into object methods, broaden live
   `RegisterHook` argument marshaling, object notifications, game-thread
   scheduling, and UE4SS-compatible mod lifecycle loading.
13. Keep existing file/DB/pak patch paths as the production mechanism until the
   injected Linux runtime path has equivalent recovery hooks and startup tests.
14. Treat full upstream UE4SS compatibility as a separate porting project:
   replace the Windows proxy-DLL loader, port module/symbol handling, replace
   Windows crash/thread APIs, and verify Unreal object discovery on the Linux
   dedicated server binary.
