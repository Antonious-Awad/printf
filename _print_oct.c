#include "main.h"
/**
 * print_oct_prefix - prints  the prefix if there's a # passed
 * @f: flag pointer
 * @n: number
 * Return: characters printed
 */

int print_oct_prefix(flag *f, unsigned long int n)
{
	int count = 0;

	if (f->hash && n != 0)
	{
		count += _putchar('0');
	}
	return (count);
}

/**
 * get_oct_len - returns number of digits of oct number
 * @temp: original number copy
 * @buffer: buffer array to update
 * Return: number of digits
 */
int get_oct_len(unsigned long int temp, char *buffer)
{
	int len = 0;

	while (temp > 0)
	{
		buffer[len] = (temp % 8) + '0';
		temp /= 8;
		len++;
	}
	return (len);
}

/**
 * _print_oct - prints the Base 8 of the number
 * @argPtr: argument pointer
 * @f: flag pointer
 * Return: digits count of Octal number
 */
int _print_oct(va_list argPtr, flag *f)
{
	unsigned long int n;
	int len = 0, i, flag_len = 0, padding, count = 0;
	char buffer[22];

	if (f->length == 'l')
		n = va_arg(argPtr, unsigned long int);
	else if (f->length == 'h')
		n = (unsigned short int)va_arg(argPtr, unsigned int);
	else
		n = va_arg(argPtr, unsigned int);

	if (n == 0)
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
	if (f->hash && n != 0)
		flag_len++;
	len += get_oct_len(n, buffer);
	padding = f->width - len - flag_len;
	if (!f->isLeft)
	{
		count += _print_padding(padding);
		count += print_oct_prefix(f, n);
	}
	else
		count += print_oct_prefix(f, n);

	for (i = len - 1; i >= 0; i--)
		count += _putchar(buffer[i]);

	if (f->isLeft)
		count += _print_padding(padding);
	return (count);
}
