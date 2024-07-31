#include "main.h"

/**
 * _print_rev - reverses a given string
 * @argPtr: argument pointer
 * @f: flag Pointer
 * Return: length of string
 */

int _print_rev(va_list argPtr, flag *f)
{
	const char *str;
	char *rev_str;
	int len = 0, i, j;

	(void)f;
	str = va_arg(argPtr, char*);

	if (!str)
		return (0);

	rev_str = malloc(len + 1);
	_strcpy(rev_str, str);
	len = _strlen(rev_str);

	if (!rev_str)
		return (-1);


	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		char temp = rev_str[i];

		rev_str[i] = rev_str[j];
		rev_str[j] = temp;
	}

	_puts(rev_str);
	free(rev_str);

	return (len);
}
