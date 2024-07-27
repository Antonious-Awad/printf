#include "main.h"
/**
 * _print_str - prints a string
 * @argPtr: argument pointer
 * Return: string length
 */

int _print_str(va_list argPtr)
{
	char *str;
	int len;

	str = va_arg(argPtr, char *);

	if (!str)
	{
		str = "(null)";
		len = _strlen(str);
		_puts(str);
		return (len);
	}

	len = _strlen(str);
	_puts(str);
	return (len);
}
