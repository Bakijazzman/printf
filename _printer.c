#include "main.h"
/**
 * _printf - imitate the printf function
 * @format: a pointer to string
 * Return: word count
 */

int _printf(const char *format, ...)
{
	long int c = 0, i = 0;

	va_list func;

	if ((format[i] == '%' && format[i + 1] == '\0') || format == NULL)
	{
		return (-1);
	}
	else if (!format[i])
	{
		return (0);
	}
	va_start(func, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchr(format[i]);
			c++;
		}
		else
		{
			c += for_spec(format[i + 1], func);
			i++;
		}
		i++;
	}
	return (c);
	va_end(func);
}
