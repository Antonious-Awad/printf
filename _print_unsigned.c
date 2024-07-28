#include "main.h"
/**
 * printU - prints and unsigned integer
 * @num: number
 * Return: digits count
 */

int printU(unsigned int num)
{
	unsigned int temp = num;
	int len = 0, last, i;
	char *p;

	if (num == 0)
		return (_putchar('0'));

	while (temp)
	{
		temp /= 10;
		len++;
	}

	if (len == 0)
		return (0);

	p = malloc(sizeof(char) * len);

	if (!p)
		return (-1);

	i = 0;
	while (num)
	{
		last = num % 10;
		p[i++] = last + '0';
		num /= 10;
	}
	for (i = (len - 1); i >= 0; i--)
	{
		_putchar(p[i]);
	}
	free(p);
	return (len);
}

/**
 * _print_unsigned - prints an integer
 * @argPtr: argument pointer
 * Return: digits count
 */

int _print_unsigned(va_list argPtr)
{
	unsigned int num;
	int len;

	num = va_arg(argPtr, unsigned int);

	len = printU(num);
	return (len);
}
