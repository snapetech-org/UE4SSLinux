# UE4SSLinux Roadmap

## Milestone 1: Generic Extraction

- Build Linux client, Linux server, and Windows/Proton proxy artifacts with
  generic names.
- Remove Dune-specific environment prefixes from core runtime.
- Preserve Dune behavior through `profiles/dune`.
- Add Palworld profile guidance for Proton/server deployment.

## Milestone 2: UE4SS Lua Runtime Parity

- Implement UE4SS mod folder discovery, `enabled.txt`, `Scripts/main.lua`,
  shared scripts, mod metadata, and lifecycle callbacks.
- Stabilize `RegisterHook`, object discovery, timers, console hook APIs, and
  UE4SS metadata tables.
- Route real `ProcessEvent` callbacks into Lua with object/function handles.

## Milestone 3: Reflection and FProperty Parity

- Decode live `UFunction` parameter chains.
- Marshal primitive, enum, name, string/text, object, struct, array, map, and
  set values.
- Support safe get/set wrappers, `ImportText`, `ExportText`, descriptor
  metadata, and param mutation inside hooks.

## Milestone 4: Full UE4SS Feature Parity

- Add C++ mod ABI/loading per platform.
- Add SDK/header dumpers or adapters to upstream UE4SS dumpers.
- Add blueprint modloader support where feasible.
- Add live property viewer/editor backend and console unlock support.
- Track upstream UE4SS API deltas in a compatibility matrix.
