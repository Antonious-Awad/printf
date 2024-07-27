#include "main.h"

/**
* _print_int - Function to print integer
* @argPtr: argument Pointer
* Return: counter(number of printed characters)
*/

int _print_int(va_list argPtr)
{
	int count;
	int n;

	n = va_arg(argPtr, int);
	count = 0;
	if (n < 0)
	{
		putchar('-');
		count++;
		n = -n;
	}
	if (n / 10)
	{
		count += print_int_recursive(n / 10);
	}
	putchar(n % 10 + '0');
	count++;
	return (count);
}
