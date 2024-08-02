#include "main.h"

/**
 * _print_padding - Function to print padding
 * @padding: number of spaces
 * Return: counter(number of printed spaces)
 */

int _print_padding(int padding)
{
	int count = 0;

	while (padding-- > 0)
		count += _putchar(' ');
	return (count);
}
