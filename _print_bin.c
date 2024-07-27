#include "main.h"
/**
 * _print_bin - prints binary number
 * @argPtr: argument pointer
 * Return: number of digits of binary number
 */

int _print_bin(va_list argPtr)
{
	unsigned int temp, num;
	int len = 0, i, bin, counter;
	char *p;

	num = va_arg(argPtr, unsigned int);
	if (!num)
		_putchar('0');
	temp = num;

	while (temp > 0)
	{
		temp /= 2;
		len++;
	}

	p = malloc(sizeof(char) * len);

	if (!p)
		return (-1);

	while (num > 0)
	{
		bin = num % 2;
		p[i++] = bin + '0';
		num /= 2;
	}
	p[i] = '\0';

	for (i = (len - 1); i >= 0; i--)
		counter += _putchar(p[i]);
	free(p);
	return (counter);
}
