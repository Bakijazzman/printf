#include "printf.h"
#include <unistd.h>
/**
 * char_print - my putchar
 * @c:  the character to be printed
 * Return: value 1 and value of c
 */
int putchr(char c)
{
	return (write(1, &c, 1));
}
