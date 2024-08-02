#include "main.h"
/**
 * _print_str - prints a string
 * @argPtr: argument pointer
 * @f: flag ptr
 * Return: string length
 */

int _print_str(va_list argPtr, flag *f)
{
	char *str;
	int len, count = 0;
	int padding;

	str = va_arg(argPtr, char *);

	if (!str)
		str = "(null)";

	len = _strlen(str);

	padding = f->width - len;
	while (padding-- > 0)
		count += _putchar(' ');

	count += _puts(str);
	return (count);
}
