#include "main.h"
/**
 * print_per - print %
 * @func: variadic func
 * Return: word count
 */
int print_per(va_list func)
{
	int c = 0;
	char a = va_arg(func, int);

	c += putchr(a);
	return (c);
}
