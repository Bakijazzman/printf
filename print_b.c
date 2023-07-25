#include "main.h"

/**
 * print_b - function that prints binary
 * @func: variadic function
 * Return: binary
 */
int print_b(va_list func)
{
	unsigned int index, index2;
	unsigned int sum = 0;
	unsigned int num[32];
	int count = 0;
	char s;
	int a = va_arg(func, int);

	unsigned int b = 2147483648;

	num[0] = a / b;

	for (index = 1; index < 32; index++)
	{
		b = (b / 2);
		num[index] = (a / b) % 2;
	}

	for (index2 = 0; index2 < 32; index2++)
	{
		sum = sum + num[index2];
		if (sum != 0 || index2 == 31)
		{
			s = num[index2] + '0';
			count = count + write(1, &s, 1);
		}
	}
	return (count);
}
