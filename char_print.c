#include "main.h"

int char_print(va_list func)
{
	int c = 0;
	char word = va_arg(func, int);

	c += putchr(word);
	return (c);

}
