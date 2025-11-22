# Get Next Line – Evaluation Process

This repository contains a complete evaluation process for the 42 project **get_next_line**.

## Files Included

- `README.md`                 — The full evaluation checklist and instructions.
- `main_basic.c`              — Simple tester for a single file descriptor.
- `main_multi_fd.c`           — Tester for multiple file descriptors interleaved.
- `tests/test_basic.txt`      — Simple 3-line file.
- `tests/test_no_last_nl.txt` — File where the last line has no trailing newline.
- `tests/test_empty.txt`      — Empty file.
- `tests/test_long_line.txt`  — One long line bigger than typical BUFFER_SIZE.
- `tests/test_with_empty_lines.txt` — Mix of normal and empty lines.
- `tests/a.txt` and `tests/b.txt`   — Used by the multi-FD tester.

## How to Use

1. Copy your implementation files into this repo:

   - `get_next_line.c`
   - `get_next_line_utils.c`
   - `get_next_line.h`

2. Build and run the basic tester with a chosen `BUFFER_SIZE`:

   ```bash
   cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
      get_next_line.c get_next_line_utils.c main_basic.c -o gnl_basic

   ./gnl_basic tests/test_basic.txt
   ```

3. Try other test files:

   ```bash
   ./gnl_basic tests/test_no_last_nl.txt
   ./gnl_basic tests/test_empty.txt
   ./gnl_basic tests/test_long_line.txt
   ./gnl_basic tests/test_with_empty_lines.txt
   ```

4. Test multiple file descriptors:

   ```bash
   cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
      get_next_line.c get_next_line_utils.c main_multi_fd.c -o gnl_multi

   ./gnl_multi
   ```

5. Optionally run under Valgrind:

   ```bash
   valgrind --leak-check=full ./gnl_basic tests/test_basic.txt
   ```

You can extend this repo with more tests or CI (GitHub Actions) as you like.
