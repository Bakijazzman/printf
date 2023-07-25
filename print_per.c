#include "main.h"

int print_per(va_list func)
{
	int c = 0;
	char a = va_arg(func, int);

	c += putchr(a);
	return(c);
}
