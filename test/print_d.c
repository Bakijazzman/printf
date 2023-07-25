#include "main.h"
/**
 * print_d - prints double
 * @func: variadic functions
 * Return: word count
 */
int print_d(va_list func)
{
	unsigned int x, y, i;
	int d, count = 0;

	d = va_arg(func, int);
	if (d < 0)
	{
		x = (d * (-1));
		count += putchr('-');
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
		char c = ((x / i) % 10 + '0');
		count += write(1, &c, 1);
		i /= 10;
	}
	return (count);
}
