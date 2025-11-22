# Get Next Line — Evaluation Toolkit

This repository contains everything needed to evaluate the 42 `get_next_line` project according to the official evaluation steps (Q1–Q7).  
This toolkit is **for evaluators**, not for students.  
You plug in the **student’s project** and use this repo to test it.

---

## 0. Requirements Before Starting the Evaluation

You must have:

- This toolkit cloned locally  
- The **student’s get_next_line project** cloned elsewhere  
- A terminal capable of running:
  - `bash` scripts
  - `cc` or `gcc`
  - `norminette`

Throughout this README:

- Toolkit directory example → `~/Get-Next-Line-Evaluation-Process`
- Student project example → `~/student-gnl`

Adjust paths to your system.

---

## 1. Toolkit Structure

```
Get-Next-Line-Evaluation-Process/
├── README.md              # This file
├── mains/
│   ├── main_basic.c       # Basic GNL testing (file input)
│   ├── main_fd.c          # Invalid FD and error management
│   ├── main_stdin.c       # Test GNL reading from stdin
│   └── main_custom_sep.c  # For live-coding custom separator test (Q7)
├── scripts/
│   ├── compile.sh         # Compile GNL with many BUFFER_SIZE values
│   ├── run_all.sh         # Run a compiled binary against all test files
│   ├── check_fd.sh        # Run invalid FD tests
│   └── generate_long.py   # Generate a 10k+ long line test file
└── tests/
    ├── empty.txt
    ├── short.txt
    ├── long.txt
    ├── long2k.txt
    ├── no_newline.txt
    ├── multi_empty.txt
    ├── multi_long.txt
    ├── multi_short.txt
```

---

# Evaluation Steps (Matching Q1–Q7)

---

## 🔹 Q1 — Preliminaries

- Student must be present  
- If project missing → **0, stop evaluation**  
- If any part is non-functional → **stop evaluation immediately**

No scripts used here.

---

## 🔹 Q2 — Check the Student’s README.md

Open the student repo and verify:

- First line formatted exactly as required  
- Has:
  - Description  
  - Instructions  
  - Resources + AI usage explanation  
  - Library description  
  - Algorithm explanation  

Manual check — no script.

---

## 🔹 Q3 — Norminette

In the student repo:

```bash
cd ~/student-gnl
norminette
```

If ANY error appears → **stop evaluation**.

---

## 🔹 Q4 — Compilation Testing (Use Toolkit)

From toolkit root:

```bash
cd ~/Get-Next-Line-Evaluation-Process
./scripts/compile.sh ~/student-gnl
```

This compiles student code using:

- BUFFER_SIZE = 1
- BUFFER_SIZE = 5
- BUFFER_SIZE = 7
- BUFFER_SIZE = 42
- BUFFER_SIZE = 1000
- BUFFER_SIZE = 5000

If anything fails → **stop evaluation**.

This produces binaries:

```
gnl_1
gnl_5
gnl_7
gnl_42
gnl_1000
gnl_5000
```

---

## 🔹 Q5 — Error Management Tests

### 1. Compile invalid-FD tester:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_fd.c    -o gnl_fd
```

### 2. Run invalid FD test:

```bash
./scripts/check_fd.sh ./gnl_fd
```

Checks expected:

- No crash  
- `get_next_line(42)` returns `NULL`  

If not → **stop evaluation**.

---

## 🔹 Q6 — Functional Testing

### Test All BUFFER_SIZE Variants

Use the binaries built by `compile.sh`.

### 6.1. Run full file tests:

```bash
./scripts/run_all.sh ./gnl_42
./scripts/run_all.sh ./gnl_1
./scripts/run_all.sh ./gnl_1000
```

This tests:

- Empty files  
- No-newline EOF  
- Short lines  
- Long lines  
- Multi-line mixed files  

You check visually:

- Line correctness  
- Newline presence  
- EOF behavior (returns NULL once)

### 6.2. Test STDIN

Compile:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42    ~/student-gnl/get_next_line.c    ~/student-gnl/get_next_line_utils.c    mains/main_stdin.c    -o gnl_stdin
```

Run:

```bash
./gnl_stdin
```

Type:

```
hello
world
^D
```

Verify:

- Each typed line is printed correctly  
- Program exits correctly after EOF  

### 6.3. Test ultra-long lines (optional but recommended)

```bash
python3 scripts/generate_long.py
./gnl_42 tests/generated_long.txt
```

---

## 🔹 Q7 — Live Coding: Custom Separator

You ask the student:

> “Modify get_next_line to support a custom separator instead of '\n'.”

They must:

- Modify their code everywhere required  
- Do it in **≤10 minutes**  
- Demonstrate functionality using `main_custom_sep.c`  

This confirms:

- Understanding of code structure  
- Ability to extend logic  
- Ability to quickly adjust GNL internals  

---

## ✔️ Quick Command Cheat Sheet

```bash
# Norm check
cd ~/student-gnl
norminette

# Back to toolkit
cd ~/Get-Next-Line-Evaluation-Process

# Multi-BUFFER_SIZE compile
./scripts/compile.sh ~/student-gnl

# Run all tests
./scripts/run_all.sh ./gnl_42

# Invalid FD
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ~/student-gnl/get_next_line.c ~/student-gnl/get_next_line_utils.c mains/main_fd.c -o gnl_fd
./scripts/check_fd.sh ./gnl_fd

# STDIN
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ~/student-gnl/get_next_line.c ~/student-gnl/get_next_line_utils.c mains/main_stdin.c -o gnl_stdin
./gnl_stdin

# Ultra long
python3 scripts/generate_long.py
./gnl_42 tests/generated_long.txt
```

---

This toolkit ensures you fully comply with all **Q1–Q7 evaluation requirements** every time you evaluate `get_next_line`.

