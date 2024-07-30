#include "main.h"

/**
 * _print_rot13 - encodes a string in rot13
 * @argPtr: string to be encoded
 * @f: flag ptr
 * Return: length of string
 */

int _print_rot13(va_list argPtr, flag *f)
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int len = 0;
	int i, j;
	char *str;

	(void)f;
	str = va_arg(argPtr, char *);
	if (!str)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; a[j] != '\0'; j++)
		{
			if (str[i] == a[j])
			{
				len++;
				_putchar(b[i]);
				break;
			}
		}
	}
	return (len);
}
