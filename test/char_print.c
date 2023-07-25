#include "main.h"
/**
 * char_print - print a character function
 * @func: varadic func
 * Return: word count
 */
int char_print(va_list func)
{
	int c = 0;
	char word = va_arg(func, int);

	c += putchr(word);
	return (c);

}
