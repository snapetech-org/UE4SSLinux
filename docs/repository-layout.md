# Repository Layout

- `runtime/linux-elf/`: native Linux client and server `LD_PRELOAD` runtime
  loaders.
- `runtime/windows-proxy/`: Windows PE proxy DLL runtime loader for Wine/Proton.
- `compat/ue4ss-lua/`: UE4SS Lua compatibility notes and smoke surface.
- `analysis/`: scan, xref, signature, anchor, readiness, profile, and packaging
  support tools.
- `profiles/dune/`: Dune process filters, scan defaults, proxy defaults, legacy
  env compatibility, and caveats.
- `profiles/palworld/`: Palworld process filters, Proton/server notes, proxy
  candidates, and caveats.
- `docs/`: generic install, safety, target profile, roadmap, test, and parity
  docs.
- `scripts/`: build, launch, smoke, package, and Proton override helpers.
- `tests/`: unit tests for analysis and profile tooling.
