#include "main.h"

/**
 * get_sf - Gets the appropriate function for a specifier
 * @format: The format string
 * @i: Pointer to the current position in the format string
 * @f: Pointer to the flag structure
 * Return: Pointer to the appropriate function, or NULL if not found
 */
int (*get_sf(const char *format, int *i, flag * f))(va_list, flag *)
{
	int j, convert_len = 14;
	fs convert[] = {
			{"%s", _print_str},
			{"%%", _print_percent},
			{"%c", _print_char},
			{"%d", _print_int},
			{"%i", _print_int},
			{"%b", _print_bin},
			{"%X", _print_HEX},
			{"%x", _print_hex},
			{"%p", _print_ptr},
			{"%o", _print_oct},
			{"%u", _print_unsigned},
			{"%S", _print_STR},
			{"%R", _print_rot13},
			{"%r", _print_rev}};

	while (format[*i] == '+' || format[*i] == ' ' ||
				 format[*i] == '#' || format[*i] == 'l' ||
				 format[*i] == 'h' || format[*i] == '-' ||
				 (format[*i] >= '0' && format[*i] <= '9'))
	{
		if (format[*i] == 'l' || format[*i] == 'h')
			f->length = format[*i];
		if (format[*i] == '+')
			f->plus = 1;
		else if (format[*i] == ' ')
			f->space = 1;
		else if (format[*i] == '#')
			f->hash = 1;
		else if (format[*i] == '-')
		{
			if ((format[*i + 1] >= '0' && format[*i + 1] <= '9'))
				f->isLeft = 1;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
			f->width = f->width * 10 + (format[*i] - '0');
		(*i)++;
	}

	for (j = 0; j < convert_len; j++)
	{
		if (convert[j].specifier[1] == format[*i])
		{
			return (convert[j].conversion_func);
		}
	}

	return (NULL);
}
