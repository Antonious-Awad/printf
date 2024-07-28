#include "main.h"
/**
 * _print_HEX - converts passed number to hexadecimal
 * @argPtr: argument pointer
 * Return: length of hexadecimal
 */

int _print_HEX(va_list argPtr)
{
	long int len = 0, i;
	long int *p;
	unsigned int n = va_arg(argPtr, unsigned int);
	unsigned int temp = n;

	while (temp > 0)
	{
		temp /= 16;
		len++;
	}

	p = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
	{
		p[i] = n % 16;
		n /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (p[i] > 9)
			p[i] += 7;
		_putchar(p[i] + '0');
	}
	free(p);
	return (len);
}
