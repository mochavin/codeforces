#!/usr/bin/env bash
# Cari dan (opsional) hapus semua folder bernama ".cph" dan ".bin"
# Default: dry-run (hanya tampilkan hasil). Gunakan --delete atau -d untuk hapus.
# Usage:
#   ./remove_cph_bin.sh            # list (dry-run) dari current dir
#   ./remove_cph_bin.sh /path/to/dir
#   ./remove_cph_bin.sh --delete   # hapus semua yang ditemukan
#   ./remove_cph_bin.sh -d /path/to/dir
# sh .\clean.sh -d
set -euo pipefail

PRINT_ONLY=1
TARGET_DIR="."

print_usage() {
  cat <<EOF
Usage: $0 [--delete|-d] [directory]
  --delete, -d    : perform deletion (otherwise script only lists matches)
  directory       : directory to search (default: current directory)
EOF
}

# parse args
while (( "$#" )); do
  case "$1" in
    --delete|-d)
      PRINT_ONLY=0
      shift
      ;;
    -h|--help)
      print_usage
      exit 0
      ;;
    *)
      # treat as target directory
      TARGET_DIR="$1"
      shift
      ;;
  esac
done

if [ ! -d "$TARGET_DIR" ]; then
  echo "Error: target is not a directory: $TARGET_DIR" >&2
  exit 2
fi

echo "Searching under: $TARGET_DIR"
echo

# find directories named .cph, .bin or bin (case-insensitive) and files ending with .bin
# handle names with spaces safely via -print0
found=0
# collect into array safely
matches=()
while IFS= read -r -d '' d; do
  matches+=("$d")
done < <(find "$TARGET_DIR" -type d \( -iname ".cph" -o -iname ".bin" -o -iname "bin" \) -print0)

# also find files that end with .bin (like some build artifacts)
while IFS= read -r -d '' f; do
  matches+=("$f")
done < <(find "$TARGET_DIR" -type f -iname "*.bin" -print0)

# deduplicate matches while preserving order
declare -A _seen
uniq_matches=()
for p in "${matches[@]}"; do
  if [ -z "${_seen[$p]:-}" ]; then
    _seen[$p]=1
    uniq_matches+=("$p")
  fi
done
matches=("${uniq_matches[@]}")

if [ "${#matches[@]}" -eq 0 ]; then
  echo "No .cph or .bin directories found."
  exit 0
fi

echo "Found ${#matches[@]} directories:"
for p in "${matches[@]}"; do
  printf '  %s\n' "$p"
done

if [ "$PRINT_ONLY" -eq 1 ]; then
  echo
  echo "Dry-run: nothing deleted. Re-run with --delete to remove these directories."
  exit 0
fi

echo
read -p "Are you sure you want to permanently delete all ${#matches[@]} directories? [y/N] " confirm
case "$confirm" in
  y|Y|yes|YES) ;;
  *) echo "Aborted."; exit 0 ;;
esac

# Perform deletion
echo "Deleting..."
for p in "${matches[@]}"; do
  if [ -d "$p" ]; then
    # directory: allow .cph, .bin, bin (case-insensitive already matched by find)
    base="$(basename "$p")"
    if [ "$base" != ".cph" ] && [ "$base" != ".bin" ] && [ "$base" != "bin" ]; then
      echo "Skipping unexpected directory match: $p" >&2
      continue
    fi
    rm -rf -- "$p" && echo "Deleted directory: $p"
  elif [ -f "$p" ]; then
    # file: allow files that end with .bin
    case "$p" in
      *.bin|*.BIN)
        rm -f -- "$p" && echo "Deleted file: $p"
        ;;
      *)
        echo "Skipping unexpected file match: $p" >&2
        ;;
    esac
  else
    # fallback: try safe remove
    rm -rf -- "$p" && echo "Deleted (fallback): $p" || echo "Failed to delete: $p" >&2
  fi
done

echo "Done."