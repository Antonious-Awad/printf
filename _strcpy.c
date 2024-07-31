#include "main.h"

/**
* _strcpy - copy string to another string
* @dest: Destination string
* @src: source string
* Return: dest (destination string)
*/
char *_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return (dest);
}
