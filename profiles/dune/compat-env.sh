#!/usr/bin/env bash
# Temporary compatibility aliases for scripts or operator runbooks that still use
# the original Dune loader environment names.

alias_if_set() {
  local old_name="$1"
  local new_name="$2"
  if [ -n "${!old_name:-}" ] && [ -z "${!new_name:-}" ]; then
    export "$new_name=${!old_name}"
  fi
}

while IFS='=' read -r old_prefix new_prefix; do
  for old_name in $(env | awk -F= -v p="$old_prefix" 'index($1, p) == 1 { print $1 }'); do
    suffix="${old_name#$old_prefix}"
    alias_if_set "$old_name" "$new_prefix$suffix"
  done
done <<'MAP'
DUNE_CLIENT_PROBE UE4SSL_CLIENT
DUNE_WIN_CLIENT_PROBE UE4SSL_WIN
DUNE_PROBE_LOADER UE4SSL_SERVER
MAP
