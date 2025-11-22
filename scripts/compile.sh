#!/bin/bash
SRC="$1"
for BS in 1 5 7 42 1000 5000; do echo "BUFFER_SIZE=$BS"; cc -Wall -Wextra -Werror -D BUFFER_SIZE=$BS $SRC/get_next_line.c $SRC/get_next_line_utils.c mains/main_basic.c -o gnl_$BS || exit 1; done
