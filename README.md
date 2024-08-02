# Printf

- Printf project, part of alx swe program

## What is Printf

- printf() is a predefined function from `stdio` header file
- It's used to write formatted output to stdout
- Syntax

```c
printf("Hello"); //outputs: Hello
printf("Hi my name is %s\n", "Tony"); //outputs: Hi my name is Tony
```

## Available Features

- Currently our `_printf()` functions can handle the following conversion specifiers
- Custom conversion specifiers do not exist on the original printf

|Specifier |Output| custom or non-custom |
|---------|-------|--------|
| `c` | Character | non-custom |
| `d` or `i` | Signed integer | non-custom |
| `s` | String of characters |non-custom |
| `b` | Binary Representation of unsigned integer |non-custom |
| `u` | Unsigned integer |non-custom |
| `o` | Unsigned octal |non-custom |
| `x` | Unsigned hexadecimal integer |non-custom |
| `X` | Unsigned hexadecimal integer (uppercase) |non-custom |
| `S` | String with hex-ascii value replacing special chars | custom |
| `p` | Pointer address | custom |
| `r` | Reversed string of characters | custom |
| `R` | ROT13 Translation of string | custom|

- It's also optimized to handle printing out characters once each 1 KB (1024 Byte) (check `_putchar.c` for reference)
- It can also handle the following flags

|Flag|Description|
|----|-----------|
| `-` |Left-justify the output within the field width that was given; Right justification is the default (see _width_ sub-specifier). |
| `+` |Precedes the result with a plus sign for positive numbers. By default, only negative numbers are preceded with a `-` sign. |
| `(space)` |If no sign is going to be written, a blank space is inserted before the value. |
| `#` | Used with hexadecimal and Octal specifiers to add a `0` (octal) or `0x` (`0X` if used with `%X`)(hexadecimal) before printing the value of the number |

- It's also implemented to handle the following length modifiers

|Length modifier | Description |
|----------------|---------------|
| `h` | For Long Integers and unsigned long numbers |
| `l` | For short integers and unsigned short numbers |

- It contains Field Width handling

|Width           |Description                    |
|----------------|-------------------------------|
| `(number)` |Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|

## Usage & Example
Function Prototype : `int _printf(const char *format, ...);`

Here's an example main.c file for testing out the function
```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
```

## Contributors

- Tony | [X](https://x.com/Antonious_A/) | [LinkedIn](https://www.linkedin.com/in/antoniousawad/)
- George | [X](https://x.com/GeorgeSamir350) | [LinkedIn](https://www.linkedin.com/in/george-samir-4b050b1a7/)

## Resources

### Strings

- [Passing NULL to printf](https://www.geeksforgeeks.org/g-fact-44-passing-null-to-printf-in-c/)

### Buffer

- [Write Documentation](https://pubs.opengroup.org/onlinepubs/007908799/xsh/write.html)
- [write function: is there a way to write only a part of the buffer?](https://stackoverflow.com/questions/8026114/write-function-is-there-a-way-to-write-only-a-part-of-the-buffer)
- [Static Variables in C](https://www.shiksha.com/online-courses/articles/static-variables-in-c/)
- [What are the default values of static variables in C?](https://www.geeksforgeeks.org/g-fact-53/)