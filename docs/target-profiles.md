# Target Profiles

Profiles live under `profiles/<name>/profile.json` and use
`ue4sslinux-profile/v1`.

Each profile declares:

- Process filters for Linux clients, Linux servers, and Windows targets.
- Scan preset defaults.
- Windows proxy DLL candidates and a default proxy DLL.
- Unreal Engine version hints.
- Safe launch mode.
- Known caveats.

Resolve a profile for a platform with:

```sh
analysis/resolve-profile.py dune --platform windows --format env
analysis/resolve-profile.py palworld --platform linux-server --format json
```

The resolver emits the correct generic environment prefix:

- `UE4SSL_CLIENT_*` for native Linux clients.
- `UE4SSL_SERVER_*` for native Linux dedicated servers.
- `UE4SSL_WIN_*` for Windows/Wine/Proton targets.

## Dune

The Dune profile preserves the original loader behavior and keeps legacy
`DUNE_*` aliases isolated in `profiles/dune/compat-env.sh`. The current Windows
client proxy learning is `version.dll` with a `native,builtin` Wine/Proton
override.

## Palworld

The Palworld profile records the practical current path for existing UE4SS mods:
Windows client/server targets under Wine or Proton. Native Linux dedicated
servers can be scanned and studied, but loading existing UE4SS DLL mods directly
is not expected to work until native parity lands.
