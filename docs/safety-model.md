# Safety Model

UE4SSLinux defaults to read-only discovery. Hooks, Lua dispatch, and file staging
are opt-in and should be enabled only after readiness evidence identifies the
target and required anchors.

## Runtime Gates

- Scanning and module logging are read-only.
- UE pointer, layout, UObject, FName, and reflection probes are bounded.
- `ProcessEvent` hook probes install and restore a hook only when explicitly
  enabled.
- Persistent `ProcessEvent` hooks and live Lua dispatch require separate
  `UE4SSL_*` toggles.
- Readiness tools report blockers before live hooks are enabled.

## Filesystem Rules

Existing game files are not modified by default. Proton staging must be
manifest-backed, reversible, and explicit. Prefer generated overlays, launch-time
injection, or package staging over in-place edits.

## Profile Isolation

Target-specific assumptions belong under `profiles/`. The runtime core should
use generic names and profile-provided filters, presets, and caveats instead of
hardcoding game-specific behavior.
