# UE4SSLinux

UE4SSLinux is a generic-first extraction of the Dune loader work into a reusable
UE4/UE5 runtime framework. Dune and Palworld are target profiles under
`profiles/`; the runtime core is not meant to hardcode either game.

## Runtime Targets

- `runtime/linux-elf/`: `LD_PRELOAD` loaders for native Linux clients and native
  Linux dedicated servers.
- `runtime/windows-proxy/`: PE proxy DLL loader for Windows clients and servers
  running under Wine/Proton.
- `compat/ue4ss-lua/`: UE4SS-shaped Lua compatibility notes and smoke scripts.
- `analysis/`: signature, xref, anchor, readiness, and canary planning tools.

## Environment Prefixes

- Linux native clients: `UE4SSL_CLIENT_*`
- Windows/Wine/Proton targets: `UE4SSL_WIN_*`
- Native Linux dedicated servers: `UE4SSL_SERVER_*`

The Dune profile includes temporary aliases for the legacy `DUNE_*` variables.

## Build

```sh
make build-linux
scripts/build-windows-client-loader.sh
```

The Windows proxy build requires either `x86_64-w64-mingw32-gcc` or
`clang`/`ld.lld` plus Wine import libraries.

## Safety Model

The default path is read-only scanning and explicit readiness gates. Existing
game files are not modified by default. Proton game-directory staging writes a
manifest and backup path and must be explicitly unstaged when no longer needed.

Confidence: moderate. The current extraction preserves the working Dune loader
behavior as generic code, but full UE4SS parity is roadmap work tracked in
`docs/roadmap.md`.

## Docs

- `docs/install.md`
- `docs/target-profiles.md`
- `docs/safety-model.md`
- `docs/test-plan.md`
- `docs/feature-parity.md`
- `docs/roadmap.md`
