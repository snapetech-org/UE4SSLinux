# UE4SS Feature Parity Matrix

| Area | Current Status | Target |
| --- | --- | --- |
| Module/image logging | Present | Stable across ELF and PE |
| String/byte scanning | Present | Profile-driven presets |
| Anchor promotion | Present | Manifest-backed canaries |
| FName/UObject/GWorld probes | Present | Automatic discovery |
| Reflection probes | Partial | Live FProperty parity |
| ProcessEvent hook probe | Present, guarded | Persistent production-ready routing |
| Lua runtime loading | Present | UE4SS-compatible mod lifecycle |
| UE4SS Lua globals | Partial smoke surface | Full API parity |
| C++ mods | Not implemented | Platform-specific ABI/loading |
| SDK/header dumping | Not implemented | Adapter or native dumper |
