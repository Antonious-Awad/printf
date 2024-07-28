#include "main.h"
/**
 * _print_oct - prints the Base 8 of the number
 * @argPtr: argument pointer
 * Return: digits count of Octal number
 */
int _print_oct(va_list argPtr)
{
	unsigned int n = va_arg(argPtr, unsigned int);
	int len = 0, i;
	unsigned int temp = n;
	/*11 octal digits maximum (32 bits)*/
	char buffer[11];

	if (n == 0)
		return (_putchar('0'));

	while (temp > 0)
	{
		buffer[len] = (temp % 8) + '0';
		temp /= 8;
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (len);
}
