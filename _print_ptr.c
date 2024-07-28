#include "main.h"
/**
 * _print_ptr - prints a pointer address
 * @argPtr: argument pointer
 * Return: address length
 */

int _print_ptr(va_list argPtr)
{
	void *p;
	char *s = "(nil)";
	long int num;
	int hexLen;

	p = va_arg(argPtr, void *);

	if (!p)
	{
		return (_puts(s));
	}

	num = (unsigned long int)p;

	_putchar('0');
	_putchar('x');

	hexLen = hex(num);

	return (hexLen + 2);
}
