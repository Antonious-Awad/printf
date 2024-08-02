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
	if (!f->isLeft)
		count += _print_padding(padding);

	count += _puts(str);

	if (f->isLeft)
		count += _print_padding(padding);
	return (count);
}
