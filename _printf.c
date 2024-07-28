#include "main.h"

/**
 * _printf - prints string and variables passed with format specifiers .
 * @format: the format specifier of the variable to be printed
 * Return: length of the output
 *
 */

int _printf(const char *format, ...)
{
	fs convert[] = {
			{"%s", _print_str},
			{"%%", _print_percent},
			{"%c", _print_char},
			{"%d", _print_int},
			{"%i", _print_int},
			{"%b", _print_bin},
			{"%X", _print_HEX},
			{"%x", _print_hex},
	};
	/*Length of convert struct*/
	int convert_len = 8, i, j, output_len = 0, isSpecifier;
	va_list argPtr;

	va_start(argPtr, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		isSpecifier = 0;
		for (j = 0; j < convert_len; j++)
		{
			if (convert[j].specifier[0] == format[i] &&
					convert[j].specifier[1] == format[i + 1])
			{
				output_len += convert[j].conversion_func(argPtr);
				i++;
				isSpecifier = 1;
				break;
			}
		}
		if (!isSpecifier)
		{
			_putchar(format[i]);
			output_len++;
		}
	}
	_putchar(-1);
	va_end(argPtr);
	return (output_len);
}
