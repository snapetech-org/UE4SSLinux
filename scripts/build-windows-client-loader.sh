#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source_file="$repo_root/runtime/windows-proxy/ue4ssl_windows_proxy_loader.c"
build_dir="${UE4SSL_WINDOWS_LOADER_BUILD_DIR:-$repo_root/build/windows-client-loader}"
output="$build_dir/ue4ssl_windows_proxy_loader.dll"
build_type="${CMAKE_BUILD_TYPE:-RelWithDebInfo}"

mkdir -p "$build_dir"

common_flags=(-Wall -Wextra -Wpedantic)
case "$build_type" in
  Debug)
    common_flags+=(-O0 -g)
    ;;
  *)
    common_flags+=(-O2 -g)
    ;;
esac

if command -v x86_64-w64-mingw32-gcc >/dev/null 2>&1; then
  x86_64-w64-mingw32-gcc \
    "${common_flags[@]}" \
    -ffreestanding \
    -fno-stack-protector \
    -nostdlib \
    -shared \
    -Wl,--entry,DllMain \
    -Wl,--subsystem,windows \
    -Wl,--no-insert-timestamp \
    -o "$output" \
    "$source_file" \
    -lkernel32
elif command -v clang >/dev/null 2>&1 &&
     command -v ld.lld >/dev/null 2>&1 &&
     [ -f /usr/lib/wine/x86_64-windows/libkernel32.a ]; then
  clang \
    --target=x86_64-w64-windows-gnu \
    -fuse-ld=lld \
    "${common_flags[@]}" \
    -ffreestanding \
    -fno-stack-protector \
    -nostdlib \
    -shared \
    -Wl,--entry,DllMain \
    -Wl,--subsystem,windows \
    -Wl,--no-insert-timestamp \
    -L/usr/lib/wine/x86_64-windows \
    -o "$output" \
    "$source_file" \
    -lkernel32
else
  cat >&2 <<'EOF'
No Windows x86_64 build toolchain was found.

Install one of:
  - x86_64-w64-mingw32-gcc
  - clang + ld.lld + Wine x86_64 Windows import libraries

Expected Wine import library fallback:
  /usr/lib/wine/x86_64-windows/libkernel32.a
EOF
  exit 1
fi

if [ ! -f "$output" ]; then
  echo "built target but did not find $output" >&2
  exit 1
fi

printf 'built Windows client probe loader: %s\n' "$output"
