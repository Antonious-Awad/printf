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
	char s;
	int len = 0, i, j;

	(void)f;
	str = va_arg(argPtr, char*);
	len = _strlen(str);
	
	if (!str)
		str = "(null)";
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		s = str[i];
		str[i] = str[j];
		str[j] = s;
	}
	_puts(str);
	return (len);
}
