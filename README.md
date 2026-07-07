# C Projects

This is a collection of C programs, that I built while learning C programming core concepts, data structures, and systems fundamentals.

## Projects

- [Student Record CRUD](./student-record-crud) — create/update/delete student records, single user mode
- [Matrix Operations Engine](./matrix-operations) — Matrices addition, multiplication, and transpose with manual memory management
- [Sorting & Searching Toolkit](./sorting-searching-toolkit) — Binary search and "generic" sorting across data types
- [Text Analyzer](./text-analyzer) — word, character, lines, frequent character counter. It's split into .c/.h files
- [String Library](./string-library) — recreation of string.h using pointer arithmetic 
- [Number System Converter](./number-system-converter) — conversions from decimal to binary, , hex, and octal, binary to decimal
- [Custom Calculator](./custom-calculator) — a simple CLI calculator 
- [Command-Line Tool](./command-line-tool) — linux command recreation such as:mv, cp, rm, wc, head, tail, grep
- [Tic-Tac-Toe](./tictactoe) — console based tictactoe game

## Build

Each project folder contains a single `.c` file (exculding text-analyzer foler). Compile with:

    gcc <filename>.c -o <output_name>
For text-analyzer foler we can compile three separate files using:
    gcc mini_text_analyzer.c textanalyzer.c -o textanalyzer