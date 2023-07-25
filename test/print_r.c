#include "main.h"

/**
 * print_o - print reverse
 * @func: a list of arguemnets passed to the string
 * Return: word_count
 */
int print_r(va_list func)
{
	int i, c = 0, j = 0;
	char *s = va_arg(func, char *);

	while (s[j] != '\0')
	{
		j++;
	}
	if (s == NULL)
	{
		s = "(null)";
	}
	else
	{
		for (i = j - 1; i >= 0; i--)
		{
			c += putchr(s[i]);
		}
	}
	return (c);
}
