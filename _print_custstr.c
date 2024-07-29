#include "main.h"

/**
 * _print_custstr - prints a string
 * @argPtr: argument pointer
 * Return: string length
 */

int _print_custstr(va_list argPtr)
{
	char *str;
	int len = 0;

	str = va_arg(argPtr, char *);
	if (!str)
	{
	    str = "(null)";
	    len = _strlen(str);
	    _puts(str);
		return (len);
	}
	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			len += _putchar('\\');
			len += _putchar('x');
			len += _putchar('0');
			len += HEX(*str);
		}
		else
		{
		    len += _putchar(*str);
		}
	    str++;
	}
	return (len);
}
