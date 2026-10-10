*This activity has been created as part of the 42 curriculum by aabuward.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C `printf` function. The goal is
to learn how variadic functions and formatted output work. The project builds
the static library `libftprintf.a`, which also includes my libft, and returns
the number of characters printed, like the original `printf`.

Supported conversions:

| Conversion | Output                                  |
| ---------- | --------------------------------------- |
| `%c`       | a character                             |
| `%s`       | a string                                |
| `%p`       | a pointer address in hexadecimal        |
| `%d`, `%i` | a signed decimal integer                |
| `%u`       | an unsigned decimal integer             |
| `%x`, `%X` | hexadecimal, lowercase or uppercase     |
| `%%`       | a percent sign                          |

## Instructions

Build the library:

    make

Other rules: `make clean`, `make fclean`, `make re`.

Use it in a program:

    #include "ft_printf.h"

## Algorithm and data structure

**Algorithm.** `ft_printf` reads the format string once, from left to right.
A normal character is printed directly. When `%` is found, the next character
selects a conversion function, and the argument is read with `va_arg`. Each
conversion function returns the number of characters it wrote, and `ft_printf`
adds these values to get the total (or returns -1 if a write fails).

I chose this single-pass parser because a format string is naturally
sequential: each specifier consumes the next argument in order. It runs in
O(n) over the format string.

**Data structures.** The only special structure is `va_list`, the standard
way to access a variable number of arguments. Strings are plain `char *`.
Numbers are printed with recursion (divide by 10 or 16 and print the digits
in the correct order), so no buffer or `malloc` is needed. A linked list,
tree or hash table would add complexity without any benefit for a linear
parse.

Type choices: `%c` reads `int` (arguments are promoted through `...`),
`%x` reads `unsigned int`, and `%p` uses `unsigned long` to hold a full
64-bit address.

## Resources

- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [Stack Overflow](https://stackoverflow.com/)
- [W3Schools](https://www.w3schools.com/)

### AI usage

**AI usage.** Claude was used to debug compilation and norminette errors, to
review edge cases (NULL strings, `va_arg` types, trailing `%`),
to explain concepts such as argument promotion, and to format this README.
