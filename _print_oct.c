#include "main.h"
/**
 * _print_oct - prints the Base 8 of the number
 * @argPtr: argument pointer
 * @f: flag pointer
 * Return: digits count of Octal number
 */
int _print_oct(va_list argPtr, flag *f)
{
	unsigned long int n;
	int len = 0, i, flag_len = 0;
	unsigned long int temp;
	/*22 octal digits maximum (64 bits)*/
	char buffer[22];

	if (f->length == 'l')
		n = va_arg(argPtr, unsigned long int);
	else if (f->length == 'h')
		n = (unsigned short int)va_arg(argPtr, unsigned int);
	else
		n = va_arg(argPtr, unsigned int);

	temp = n;

	if (n == 0)
		return (_putchar('0'));

	if (f->hash && n != 0)
	{
		_putchar('0');
		flag_len++;
	}

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

	return (len + flag_len);
}
