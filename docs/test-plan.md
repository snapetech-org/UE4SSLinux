# Test Plan

## Unit Tests

```sh
python3 -m pytest tests
```

Coverage includes:

- Log summarizers.
- ELF and PE signature validators.
- Signature manifest exporters.
- UE anchor exporters and canary planners.
- Readiness planner gates.
- Proton proxy candidate ranking.
- Profile resolution.

## Build Tests

```sh
make build-linux
scripts/build-windows-client-loader.sh
```

These verify Linux client/server `LD_PRELOAD` artifacts and the Windows proxy
DLL when a Windows cross toolchain is installed.

## Runtime Smoke Tests

```sh
make smoke
scripts/smoke-windows-client-loader.sh
analysis/stage-windows-lua-runtime.sh
UE4SSL_WIN_LUA_DLL="$PWD/build/windows-lua-runtime/lua54.dll" \
  scripts/smoke-windows-client-loader-lua.sh
```

These cover Linux loader self-tests, module and scan logging, loader-owned hook
self-tests, guarded `ProcessEvent`-shaped self-tests, Windows proxy loading, and
UE4SS-shaped Lua smoke behavior.

## Packaging

```sh
make package
```

Packages must include checksums and ABI/export reports for all three current
artifacts.
