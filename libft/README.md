  *This project has been created as part of the 42 curriculum by joaopedr.*

# Libft

## Description

Libft is a custom C library developed as part of the 42 curriculum.  
The goal of this project is to recreate a collection of standard C library functions, as well as implement additional utility functions that will be reused throughout future 42 projects.

This project helps strengthen understanding of:
- Memory management
- Strings and arrays manipulation
- Linked lists
- Pointer arithmetic
- Low-level programming in C
- Static library creation

The library includes reimplementations of common functions from:
- `<string.h>`
- `<stdlib.h>`
- `<ctype.h>`
- `<unistd.h>`

It also contains additional helper functions such as:
- String splitting
- String trimming
- Integer conversion
- Linked list utilities

The final result is a static library file named `libft.a`.

---

## Features

### Part 1 — Libc Functions
Reimplemented standard C functions, including:
- `ft_strlen`
- `ft_strdup`
- `ft_memcpy`
- `ft_memset`
- `ft_strncmp`
- `ft_atoi`
- `ft_isalpha`
- `ft_isdigit`
- and more.

### Part 2 — Additional Functions
Custom utility functions such as:
- `ft_substr`
- `ft_strjoin`
- `ft_split`
- `ft_strtrim`
- `ft_itoa`
- `ft_strmapi`

### Bonus Part
Linked list utilities:
- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstiter`
- `ft_lstmap`
- and others.

---

## Project Structure

```text
├── ft_*.c
├── Makefile
├── libft.h
└── README.md
```

---

## Instructions

### Build the library

```bash
make
```

This compiles all source files and creates the static library `libft.a`.

### Use in your project

Include the header and link against the library when compiling:

```bash
gcc your_file.c -L. -lft -I. -o your_program
```

### Available targets

| Target | Description |
|--------|-------------|
| `make` / `make all` | Build `libft.a` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libft.a` |
| `make re` | Full rebuild |

---

## Resources

- `man 3 strlen` — reference for string functions (`strlen`, `strchr`, `strncmp`, etc.)
- `man 3 memcpy` — reference for memory functions (`memcpy`, `memset`, `memmove`, etc.)
- `man 3 atoi` — reference for conversion functions (`atoi`, `itoa`)
- `man 3 isalpha` — reference for character classification functions (`isalpha`, `isdigit`, etc.)
- `man 3 malloc` — reference for memory allocation (`malloc`, `calloc`, `free`)

> Use `man 3 <function_name>` in your terminal to consult the manual page for any standard C library function.


