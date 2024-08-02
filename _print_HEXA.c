#include "main.h"
/**
 * print_HEX_prefix - prints  the prefix if there's a # passed
 * @f: flag pointer
 * @n: number
 * Return: characters printed
 */

int print_HEX_prefix(flag *f, unsigned long int n)
{
	int count = 0;

	if (f->hash && n != 0)
	{
		count += _putchar('0');
		count += _putchar('X');
	}
	return (count);
}

/**
 * get_HEX_len - returns number of digits of hex number
 * @temp: original number copy
 * @buffer: buffer array to update
 * Return: number of digits
 */
int get_HEX_len(unsigned long int temp, char *buffer)
{
	unsigned long int digit;
	int len = 0;

	while (temp > 0)
	{
		digit = temp % 16;
		buffer[len] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
		temp /= 16;
		len++;
	}
	return (len);
}

/**
 * _print_HEX - converts passed number to hexadecimal
 * @argPtr: argument pointer
 * @f: flag pointer
 * Return: length of hexadecimal
 */
int _print_HEX(va_list argPtr, flag *f)
{
	unsigned long int n;
	int len = 0, i, flag_len = 0, padding, count = 0;
	char buffer[16];

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
		flag_len += 2;
	len += get_HEX_len(n, buffer);
	padding = f->width - len - flag_len;
	if (!f->isLeft)
	{
		count += _print_padding(padding);
		count += print_HEX_prefix(f, n);
	}
	else
		count += print_HEX_prefix(f, n);
	for (i = len - 1; i >= 0; i--)
		count += _putchar(buffer[i]);
	if (f->isLeft)
		count += _print_padding(padding);
	return (count);
}
