#include "main.h"

/**
 * add_flag - adds a flag to the number
 * @f: pointer to flag struct
 * Return: 1(for add flag)
 */

int add_flag(flag *f)
{
	if (f->plus)
		_putchar('+');
	else if (f->space)
		_putchar(' ');
	return (1);
}
/**
 * _print_int - Function to print integer
 * @argPtr: argument Pointer
 * @f: pointer to flag struct
 * Return: counter(number of printed characters)
 */

int _print_int(va_list argPtr, flag *f)
{
	int n = va_arg(argPtr, int), lens = 0, ext, i, numPrnt, count = 0, num;

	num = n;
	if (n >= 0)
		count += add_flag(f);
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
			n = n - (numPrnt * ext);
			ext /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1 + (f->plus || f->space));
	}
	return (count);
}
