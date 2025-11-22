#!/bin/bash
BIN="$1"
for t in tests/*.txt; do echo "=== $t ==="; $BIN $t; done
