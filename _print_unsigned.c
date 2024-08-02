#include "main.h"
/**
 * printU - prints and unsigned integer
 * @num: number
 * @f: flag pointer
 * Return: digits count
 */

int printU(unsigned long int num, flag *f)
{
	int len = 0, i, padding, count = 0;
	char buffer[20];

	if (num == 0)
	{
		len = 1;
		padding = f->width - len;
		if (!f->isLeft)
			count += _print_padding(padding);
		count += _putchar('0');
		if (f->isLeft)
			count += _print_padding(padding);
		return (count);
	}

	while (num > 0)
	{
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	}

	padding = f->width - len;

	if (!f->isLeft)
		count += _print_padding(padding);

	for (i = len - 1; i >= 0; i--)
		count += _putchar(buffer[i]);

	if (f->isLeft)
		count += _print_padding(padding);

	return (count);
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

	return (printU(num, f));
}
