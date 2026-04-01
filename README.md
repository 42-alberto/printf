# ft_printf - albrodri - Because ft_putnbr() is not enough

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="Score 125/100" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C" />
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" alt="Status Completed" />
</p>

## Overview

**ft_printf** is a project at 42 that challenges students to recode the standard `printf` function. The goal is to learn about **variadic functions** in C and to create a versatile and reusable logging tool for future projects.

This implementation includes all mandatory conversions and the full set of bonus flags, achieving a final score of **125/100**.

---

## Features

This version of `ft_printf` supports the following conversions and flags:

### 1. Mandatory Conversions
* `%c` - Single character.
* `%s` - String.
* `%p` - Void * pointer in hexadecimal.
* `%d` / `%i` - Base 10 numbers.
* `%u` - Unsigned base 10 numbers.
* `%x` / `%X` - Hexadecimal (lowercase/uppercase).
* `%%` - Percent sign.

### 2. Bonus Flags (125% Score)
* `-` Left-justify within the field width.
* `0` Left-pads the number with zeroes.
* `.` Precision management.
* `#` Alternate form for hex (`0x`/`0X`).
* ` ` (Space) Blank space before positive numbers.
* `+` Forces the sign (+ or -) to appear.

---

## Project Structure & Responsibilities

The project is highly modular, separating the parsing logic from the specific printing behaviors to manage the complexity of the bonus flags:

### Directory Map
* **`srcs/`**: Contains `ft_printf.c`, the main engine that parses the format string and manages `va_list`.
* **`utils/`**:
    * `ft_print_type.c`: The central router that calls the correct function based on the specifier.
    * `ft_print_[char|str|int|hex].c`: Specific logic for each conversion type.
    * `ft_count_utils.c` & `ft_put_utils.c`: Helper functions to manage the byte count and output.
* **`libft/`**: My custom library integrated into the project, organized by categories (`is`, `lst`, `mem`, `put`, `str`, `to`).

---

## How to Use

1. **Clone the repository:**
   ```bash
   git clone https://github.com/42-alberto/ft_printf.git
2. **Compile the project:**
   ```bash
   cd ft_printf
   make
  This command triggers the internal Libft Makefile and then creates libftprintf.a.
  
3. **Usage in your project:**
   ```c
  #include "ft_printf.h"
  
4. **Compile your code linking the library:**
   ```bash
   cc main.c -L. -lftprintf -o my_program
- **Breakdown:**

    -main.c: Your source file.
  
    -L.: Tells the compiler to look for libraries in the current directory.
  
    -lftprintf: Links the libftprintf.a library (the compiler automatically searches for the lib prefix and .a extension).
  
    -o: Defines the name of your final executable.
---
   
**What I Learned**

  **Variadic Functions:** Deep dive into stdarg.h (va_start, va_arg, va_end).

  **Advanced Parsing:** Creating a robust parser capable of handling multiple combinations of flags, width, and precision.

   **Modular Architecture:** Organizing a project where libft is a dependency and utils handle specific responsibilities.

  **Complex Logic Flow:** Managing the priority of flags (e.g., how 0 is ignored if - is present).

---

<p align="center">
Developed with much coffee and much love by Alberto (42 Madrid)
</p>
