#include "main.h"

/**
* _print_int - Function to print integer
* @argPtr: argument Pointer
* Return: counter(number of printed characters)
*/

int _print_int(va_list argPtr)
{
	int n, lens, ext, i, numPrnt, count, num;

	n = va_arg(argPtr, int);
	count = 0;
	lens = 0;
	num = n;
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		while (num != 0)
		{
			num /= 10;
			lens++;
		}
		ext = 1;
		for (i = 1; i <= lens - 1; i++)
			ext *= 10;
		for (i = 1; i <= lens; i++)
		{
			numPrnt = n / ext;
			if (n < 0)
				_putchar((numPrnt * -1) + '0');
			else
				_putchar(numPrnt + '0');
			count++;
			n  = n - (numPrnt * ext);
			ext /= 10;
		}
	}
	else
	{
		putchar('0');
		return (1);
	}
	return (count);
}
