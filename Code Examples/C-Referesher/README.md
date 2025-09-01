# C Refresher Code Examples

This repository contains C programming examples organized by chapter, as part of the "Embedded Systems by Dr. Polachan" series. Each chapter folder contains several C source files demonstrating key concepts.

## Folder Structure

- `Chapter-x1/` — Contains example programs 1.c to 6.c
- `Chapter-x2/` — Contains example programs 1.c to 4.c
- `Chapter-x3/` — Contains example programs 1.c to 3.c
- `Chapter-x4/` — Contains example programs 1.c to 4.c

Each `.c` file is a standalone C program. The corresponding `.exe` files are generated after compilation (but may be deleted for cleanliness).

## How to Compile the Programs

1. **Open a terminal** in the root directory (where the chapter folders are located).
2. **Navigate to the desired chapter folder**, for example:
   ```powershell
   cd Chapter-x1
   ```
3. **Compile a C file** using a C compiler (e.g., GCC):
   ```powershell
   gcc 1.c -o 1.exe
   ```
   Replace `1.c` and `1.exe` with the desired source and output file names.

4. **Run the compiled program**:
   ```powershell
   .\1.exe
   ```

Repeat for any other `.c` file you wish to compile and run.

## Requirements
- A C compiler (such as GCC or MinGW) must be installed and available in your system's PATH.

## Notes
- The `.exe` files are not included by default. Compile the `.c` files as needed.
- Each program is independent and can be compiled and run separately.

---

For any questions or issues, please refer to your C compiler's documentation or contact your instructor.
