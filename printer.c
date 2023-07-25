#include <stdarg.h>
#include "printf.h"

int _printf(const char *format, ...)
{
	unsigned i, count, count2, count3;

	va_list vars;

	va_start(vars, format)
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] != '%')
			{
				char_print(format[i]);
			}
			else if (format[i + 1] == 'c')
			{
				char_print(va_arg(vars, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				count2 = str_print(va_arg(vars, char *));
				i++;
				count += (count2 - 1);
			}
			else if (format[i + 1] == '%')
			{
				char_print('%');
				i++;
			}
			count++;
		}
	return (count);
	va_end(vars);
}
