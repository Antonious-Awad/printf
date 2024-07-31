#include "main.h"
/**
 * printU - prints and unsigned integer
 * @num: number
 * Return: digits count
 */

int printU(unsigned long int num)
{
	int len = 0, i;
	/*20 decimal digits maximum (64bits)*/
	char buffer[20];

	if (num == 0)
		return (_putchar('0'));

	while (num > 0)
	{
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (len);
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
	int len;

	if (f->length == 'l')
		num = va_arg(argPtr, unsigned long int);
	else if (f->length == 'h')
		num = (unsigned short int)va_arg(argPtr, unsigned int);
	else
		num = va_arg(argPtr, unsigned int);

	len = printU(num);
	return (len);
}
