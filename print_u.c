#include "main.h"

/**
 * print_u - function that checks for format specifier
 * @func: variadic function
 * Return: word_count
 */
int print_o(va_list func)
{
	int num[10];

	unsigned int a = 1000000000;

	int index;
	int index2;
	int count = 0;
	int b = va_arg(func, int);
	char c;

	if (b == 0)
	{
		c = '0';
		count = count + write(1, &c, 1);
		return (count);
	}

	for (index = 0; index < 10; index++)
	{
		num[index] = b / a;
		b = b % a;
		a = a / 10;
	}

	for (index2 = 0; index2 < 10; index2++)
	{
		if (num[index2] != 0 || index2 == 9)
			c = num[index2] + '0';
		count = count + write(1, &c, 1);
	}

	return (count);
}
p
