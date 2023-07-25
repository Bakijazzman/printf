#include "main.h"

/**
 * _printf - prints anything according to a format
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list func;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(func, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, func);
		if (*p != '%')
		{
			count += putchr(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, func);
		p = get_precision(p, &params, func);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			count += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			count += get_print_func(p, func, &params);
	}
	putchr(BUF_FLUSH);
	va_end(func);
	return (count);
}
