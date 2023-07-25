#include "main.h"

/**
 * get_precision - function that gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @func: the argument pointer
 *
 *
 * Return: new pointer
 */

char *get_precision(char *p, params_t *params, va_list func)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(func, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
