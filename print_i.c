#include "main.h"
/**
 * print_i - print an integer
 * @func: variadic func
 * Return: word count
 */
int print_i(va_list func)
{
	char ch;
	unsigned int x, y, i;
	int c = 0, d;

	d = va_arg(func, int)
	if (d < 0)
	{
		 x = (d * -1);
		 c += putchr('-');
	}
	else
	{
		x = d;
	}
	y = x;
	i = 1;
	while (y > 9)
	{
		y = y / 10;
		i = i * 10;
	}
	while (i >= 1)
	{
		ch = ((x / i) % 10 + '0');
		c += putchr(ch);
		i += i / 10;
	}
	return (c);
}
