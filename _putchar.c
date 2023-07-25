#include "main.h"

/**
 * put_string - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */

int put_string(char *str)
{
	char *a = str;

	while (*str)
		putchr(*str++);
	return (str - a);
}

/**
 * putchr - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int putchr(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
