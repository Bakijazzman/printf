#include "main.h"
/**
 * str_print - prints string
 * @func: variadic function
 * Return: word count
 */

int str_print(va_list func)
{
	int i = 0, c = 0;
	char *s = va_arg(func, char *);

	if (s == NULL)
	{
		s = "(null)";
	}

	for (; s[i] != '\0'; i++)
	{
		putchr(s[i]);
		c++;
	}
	return (c);
}
