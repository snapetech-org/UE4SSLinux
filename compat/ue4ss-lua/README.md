# UE4SS Lua Compatibility Layer

The current runtime exposes a UE4SS-shaped Lua smoke surface for object handles,
hook registration, reflection descriptors, console hook APIs, timers, metadata
tables, and mod lifecycle scaffolding.

The compatibility target is upstream UE4SS Lua behavior, but this extraction is
still staged. Real live `ProcessEvent` callback routing and full FProperty
marshalling are readiness-gated roadmap items.
