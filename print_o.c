#include "main.h"
/**
 * print_o - print octal
 * @func: variadic functions
 * Return: word count
 */
int print_o(va_list func)
{
	static const char octal[] = "0123456789ABCDEF";
	static char buffer[1024];
	int c = 0;
	char *p = &buffer[1023];
	unsigned int a = va_arg(func, int);

	*p = '\0';
	do {
		*--p = octal[a % 8];
		a = a / 8;
	}while (a != 0);

	while (*p != '\0')
	{
		c += putchr(p);
		p++;
	}
	return (c);
}
