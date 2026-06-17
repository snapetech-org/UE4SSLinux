# Install

UE4SSLinux builds three current runtime artifacts:

- `libue4ssl_linux_client_loader.so` for native Linux ELF clients.
- `libue4ssl_linux_server_loader.so` for native Linux dedicated servers.
- `ue4ssl_windows_proxy_loader.dll` for Windows targets under Wine/Proton.

## Build From Source

```sh
make build-linux
scripts/build-windows-client-loader.sh
```

The Windows build needs either `x86_64-w64-mingw32-gcc` or `clang`/`ld.lld`
with Wine x86_64 Windows import libraries.

## Package

```sh
make package
```

Archives and `.sha256` files are written under `dist/`. Package scripts include
the runtime binary, source, examples, analysis tools, tests, ABI/export reports,
and profile-safe environment examples.

## Linux ELF Launch

Use the launch helper or set `LD_PRELOAD` yourself:

```sh
UE4SSL_CLIENT_LOG=/tmp/ue4ssl-client.log \
UE4SSL_CLIENT_SCAN_ENABLED=true \
scripts/launch-linux-client-probe.sh -- /path/to/Game-Linux-Shipping
```

Native server launch is the same `LD_PRELOAD` model, but use the
`UE4SSL_SERVER_*` environment prefix and the server loader.

## Windows/Wine/Proton Launch

For Windows targets, stage the proxy DLL under a DLL name imported early by the
target, then use a Wine/Proton DLL override. Profiles publish candidate names;
for Dune the known working default is `version.dll`.

The staging helpers create a manifest and backup path. Use the unstage mode to
remove staged files instead of editing game directories manually.
