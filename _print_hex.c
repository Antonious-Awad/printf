#include "main.h"
/**
 * _print_hex - converts passed number to hexadecimal (lower case)
 * @argPtr: argument pointer
 * @f: pointer to flag structure
 * Return: length of hexadecimal
 */
int _print_hex(va_list argPtr, flag *f)
{
	unsigned long int n;
	int len = 0, i, flag_len = 0, padding;
	/*16 hex digits maximum(64 bits)*/
	char buffer[16];
	unsigned long int temp;

	if (f->length == 'l')
		n = va_arg(argPtr, unsigned long int);
	else if (f->length == 'h')
		n = (unsigned short int)va_arg(argPtr, unsigned int);
	else
		n = va_arg(argPtr, unsigned int);

	temp = n;

	if (n == 0)
	{
		len = 1;
		padding = f->width - len;
		while (padding-- > 0)
			_putchar(' ');
		return (_putchar('0') + (f->width > 1 ? f->width - 1 : 0));
	}

	if (f->hash && n != 0)
		flag_len += 2;

	while (temp > 0)
	{
		unsigned int digit = temp % 16;

		buffer[len] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
		temp /= 16;
		len++;
	}

	padding = f->width - len - flag_len;
	while (padding-- > 0)
		_putchar(' ');

	if (f->hash && n != 0)
	{
		_putchar('0');
		_putchar('x');
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (len + flag_len > f->width ? len + flag_len : f->width);
}
