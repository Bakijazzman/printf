#include "main.h"

/**
 * print_x - function that prints the hex format.
 * @func: variadic func
 *  Return: count
 */
int print_x(va_list func)
{
	static const char hex[] = "0123456789abcdef";
	static char buffer[1024];

	int count = 0;
	char *ptr = &buffer[1023];
	unsigned int a = va_arg(func, unsigned int);

	*ptr = '\0';

	do {
		*--ptr = hex[a % 16];
		a = a / 16;
	} while (a != 0);

	while (*ptr != '\0')
	{
		count = count + write(1, ptr, 1);
		ptr++;
	}

	return (count);
}
