#include "main.h"

/**
* _print_rev - reverses a given string
* @argPtr: argument pointer
* @f: flag Pointer
* Return: length of string
*/

int _print_rev(va_list argPtr, flag *f)
{
	char *str;
	int len = 0, i;

	(void)f;
	str = va_arg(argPtr, char*);

	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
		len++;

	for (i = len - 1;  i >= 0; i--)
		_putchar(str[i]);

	return (len);
}
