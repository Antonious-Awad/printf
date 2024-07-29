#include "main.h"

/**
 * _print_rot13 - encodes a string in rot13
 * @argPtr: string to be encoded
 * @f: flag ptr
 * Return: length of string
 */

int _print_rot13(va_list argPtr, flag *f)
{
	int len = 0;
	char *str;
	char *result;

	(void)f;
	str = va_arg(argPtr, char *);
	result = rot13(str);
	len = _strlen(result);
	_puts(result);
	return (len);
}

/**
 * rot13 - encodes a string in rot13
 * @s: string to be encoded
 * Return: the resulting string
*/


char *rot13(char *s)
{
	int i, j;

	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; a[j] != '\0'; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
				break;
			}
		}
	}
	return (s);
}

