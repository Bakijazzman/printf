#include "main.h"
/**
 * str_print - print as a string
 * @str: the string to be printed
 * Return: word countt
 */

int str_print(char *str)
{
	unsigned int i = 0, count = 0;

	if (str)
	{
		while (str[i] != '\0')
		{
			char_print(str[i]);
			count++;
			i++;
		}
	}
	return (count);
}
