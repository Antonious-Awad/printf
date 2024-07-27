#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buffer[BUFF_SIZE];
	static int i;

	if (i >= BUFF_SIZE || c == -1)
	{
		write(1, &buffer, i);
		i = 0;
	}
	else if (c != -1)
	{
		buffer[i++] = c;
	}
	return (1);
}
