#include "main.h"

/**
 * add_flag - adds a flag to the number
 * @f: pointer to flag struct
 * Return: 1(for add flag)
 */
int add_flag(flag *f)
{
	if (f->plus)
		return (_putchar('+'));
	else if (f->space)
		return (_putchar(' '));
	return (0);
}

/**
 * _print_int - Function to print integer
 * @argPtr: argument Pointer
 * @f: pointer to flag struct
 * Return: counter(number of printed characters)
 */
int _print_int(va_list argPtr, flag *f)
{
	long int n;
	int count = 0, i = 0, padding, is_negative = 0;
	unsigned long int num;
	char buffer[20];

	if (f->length == 'l')
		n = va_arg(argPtr, long int);
	else if (f->length == 'h')
		n = (short int)va_arg(argPtr, int);
	else
		n = va_arg(argPtr, int);
	if (n == 0)
	{
		buffer[i++] = '0';
		num = n;
	}
	else if (n < 0)
	{
		is_negative = 1;
		num = (unsigned long int)(-n);
	}
	else
		num = (unsigned long int)n;
	while (num > 0)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}
	padding = f->width - i - (is_negative || f->plus || f->space ? 1 : 0);
	if (!f->isLeft)
		count += _print_padding(padding);
	if (is_negative)
		count += _putchar('-');
	else
		count += add_flag(f);
	while (i > 0)
		count += _putchar(buffer[--i]);
	if (f->isLeft)
		count += _print_padding(padding);
	return (count);
}
