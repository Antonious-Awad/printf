#include "main.h"
/**
 * _print_oct - prints the Base 8 of the number
 * @argPtr: argument pointer
 * Return: digits count of Octal number
 */
int _print_oct(va_list argPtr)
{
	long int len = 0, i;
	long int *p;
	unsigned int n = va_arg(argPtr, unsigned int);
	unsigned int temp = n;

	while (temp > 0)
	{
		temp /= 8;
		len++;
	}

	p = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
	{
		p[i] = n % 8;
		n /= 8;
	}
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(p[i] + '0');
	}
	free(p);
	return (len);
}
