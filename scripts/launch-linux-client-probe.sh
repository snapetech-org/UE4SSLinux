#!/usr/bin/env bash
set -euo pipefail

usage() {
  cat >&2 <<'EOF'
Usage:
  scripts/launch-linux-client-probe.sh -- /path/to/TargetGame-Linux-Shipping [args...]

Environment:
  UE4SSL_LINUX_CLIENT_PRELOAD=/abs/path/libue4ssl_linux_client_loader.so
  UE4SSL_CLIENT_LOG=/tmp/ue4ssl-client-loader.log
  UE4SSL_CLIENT_SCAN_ENABLED=true
  UE4SSL_CLIENT_SCAN_PRESETS=core,ue,client,cheat,brt,deep-desert
  UE4SSL_CLIENT_SCAN_SIGNATURES_FILE=/path/to/client-signatures.txt

This wrapper supports native Linux ELF clients. If the target is a Windows/PE
client under Proton, it exits instead of pretending LD_PRELOAD can inject a .so.
EOF
}

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
build_dir="${UE4SSL_LINUX_CLIENT_LOADER_BUILD_DIR:-$repo_root/build/linux-client-loader}"
loader="${UE4SSL_LINUX_CLIENT_PRELOAD:-$build_dir/libue4ssl_linux_client_loader.so}"

if [ "${1:-}" = "--" ]; then
  shift
fi

if [ "$#" -eq 0 ]; then
  usage
  exit 2
fi

if [ ! -f "$loader" ]; then
  "$repo_root/scripts/build-linux-client-loader.sh" >/dev/null
fi

if [ ! -r "$loader" ]; then
  echo "client preload library is not readable: $loader" >&2
  exit 1
fi

target="$1"
resolved_target="$target"
if [ ! -e "$resolved_target" ]; then
  resolved_target="$(command -v "$target" || true)"
fi

if [ -z "$resolved_target" ] || [ ! -e "$resolved_target" ]; then
  echo "client executable not found: $target" >&2
  exit 1
fi

file_report=""
if command -v file >/dev/null 2>&1; then
  file_report="$(file -b "$resolved_target" || true)"
fi

if printf '%s\n' "$file_report" | grep -Eiq 'PE32|MS Windows|COFF executable'; then
  echo "refusing native Linux preload for Windows/PE client target: $resolved_target" >&2
  echo "file reports: $file_report" >&2
  echo "A Proton client needs a Windows DLL/proxy/injection path, not libue4ssl_linux_client_loader.so." >&2
  exit 3
fi

if [ -n "$file_report" ] &&
   ! printf '%s\n' "$file_report" | grep -Eiq 'ELF .*executable|ELF .*shared object'; then
  if [ "${UE4SSL_CLIENT_ALLOW_NON_ELF:-false}" != "true" ]; then
    echo "target does not look like a native Linux ELF executable: $resolved_target" >&2
    echo "file reports: $file_report" >&2
    exit 3
  fi
fi

if [ -z "${UE4SSL_CLIENT_LOG+x}" ]; then
  export UE4SSL_CLIENT_LOG=/tmp/ue4ssl-client-loader.log
fi
if [ -z "${UE4SSL_CLIENT_FORCE+x}" ]; then
  export UE4SSL_CLIENT_FORCE=true
fi
if [ -z "${UE4SSL_CLIENT_SCAN_ENABLED+x}" ]; then
  export UE4SSL_CLIENT_SCAN_ENABLED=true
fi
if [ -z "${UE4SSL_CLIENT_SCAN_PRESETS+x}" ]; then
  export UE4SSL_CLIENT_SCAN_PRESETS=core,ue,client,cheat,brt,deep-desert
fi
if [ -z "${UE4SSL_CLIENT_SCAN_MAX_HITS_PER_NEEDLE+x}" ]; then
  export UE4SSL_CLIENT_SCAN_MAX_HITS_PER_NEEDLE=16
fi
if [ -z "${UE4SSL_CLIENT_SCAN_MAX_MAPPING_BYTES+x}" ]; then
  export UE4SSL_CLIENT_SCAN_MAX_MAPPING_BYTES=268435456
fi
if [ -z "${UE4SSL_CLIENT_SNAPSHOT_DELAY_SECONDS+x}" ]; then
  export UE4SSL_CLIENT_SNAPSHOT_DELAY_SECONDS=0
fi

if [ -n "${LD_PRELOAD:-}" ]; then
  export LD_PRELOAD="$loader:$LD_PRELOAD"
else
  export LD_PRELOAD="$loader"
fi

exec "$@"
