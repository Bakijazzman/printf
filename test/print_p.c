#include "main.h"

/**
 *  print_p- function that prints address
 * @func: variadic function
 * Return: word_count
 */

int print_p(va_list func)
{
	void *ptr = va_arg(func, void *);

	char buffer[1024];
	int i;
	int count = 0;

	sprintf(buffer, "%p", ptr);

	for (i = 0; buffer[i] != '\0'; i++)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}

