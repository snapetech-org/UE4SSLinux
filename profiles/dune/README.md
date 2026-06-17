# Dune Profile

This profile preserves the behavior from the original Dune loader work while
keeping Dune-specific assumptions out of the runtime core.

Known current client path: stage the Windows proxy as `version.dll` and set the
Wine/Proton override to `native,builtin` for `DuneSandbox-Win64-Shipping.exe`.

Use `profiles/dune/compat-env.sh` only as a temporary bridge for old `DUNE_*`
runbooks. New scripts should use `UE4SSL_CLIENT_*`, `UE4SSL_WIN_*`, and
`UE4SSL_SERVER_*`.
