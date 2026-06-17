#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source_dir="$repo_root/runtime/linux-elf"
build_dir="${UE4SSL_LINUX_CLIENT_LOADER_BUILD_DIR:-$repo_root/build/linux-client-loader}"
build_type="${CMAKE_BUILD_TYPE:-RelWithDebInfo}"

if ! command -v cmake >/dev/null 2>&1; then
  echo "cmake is required to build the Linux client loader" >&2
  exit 1
fi

generator=()
if command -v ninja >/dev/null 2>&1; then
  generator=(-G Ninja)
fi

cmake -S "$source_dir" -B "$build_dir" "${generator[@]}" -DCMAKE_BUILD_TYPE="$build_type"

build_args=(--build "$build_dir" --target ue4ssl_linux_client_loader)
if [ -n "${UE4SSL_LINUX_CLIENT_LOADER_JOBS:-}" ]; then
  build_args+=(--parallel "$UE4SSL_LINUX_CLIENT_LOADER_JOBS")
fi
cmake "${build_args[@]}"

loader="$build_dir/libue4ssl_linux_client_loader.so"
if [ ! -f "$loader" ]; then
  loader="$(find "$build_dir" -name libue4ssl_linux_client_loader.so -type f -print -quit)"
fi

if [ -z "$loader" ] || [ ! -f "$loader" ]; then
  echo "built target but did not find libue4ssl_linux_client_loader.so under $build_dir" >&2
  exit 1
fi

printf 'built Linux client probe loader: %s\n' "$loader"
