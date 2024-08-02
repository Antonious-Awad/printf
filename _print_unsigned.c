#include "main.h"
/**
 * printU - prints and unsigned integer
 * @num: number
 * @width: field width
 * Return: digits count
 */

int printU(unsigned long int num, int width)
{
	int len = 0, i, padding;
	/*20 decimal digits maximum (64bits)*/
	char buffer[20];

	if (num == 0)
	{
		len = 1;
		padding = width - len;
		while (padding-- > 0)
			_putchar(' ');
		return (_putchar('0') + (width > 1 ? width - 1 : 0));
	}

	while (num > 0)
	{
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	}

	padding = width - len;
	while (padding-- > 0)
		_putchar(' ');

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (len > width ? len : width);
}

/**
 * _print_unsigned - prints an integer
 * @argPtr: argument pointer
 * @f: flag ptr
 * Return: digits count
 */

int _print_unsigned(va_list argPtr, flag *f)
{
	unsigned long int num;

	if (f->length == 'l')
		num = va_arg(argPtr, unsigned long int);
	else if (f->length == 'h')
		num = (unsigned short int)va_arg(argPtr, unsigned int);
	else
		num = va_arg(argPtr, unsigned int);

	return (printU(num, f->width));
}
