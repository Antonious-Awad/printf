#include "main.h"
/**
 * _print_str - prints a string
 * @argPtr: argument pointer
 * Return: string length
 */

int _print_str(va_list argPtr)
{
	char *str;
	int i, len;

	str = va_arg(argPtr, char *);

	if (!str)
	{
		str = "(null)";
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}

	len = _strlen(str);
	for (i = 0; i < len; i++)
		_putchar(str[i]);
	return (len);
}
