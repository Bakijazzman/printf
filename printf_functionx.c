#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: A character string with format specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int count = 0;
	va_list args;

	va_start(args, format);


	while (*format)
	{
		if (*format != '%')
		{
			count += print_char(*format);
		}
		else
		{
			format++;
			if (*format == 'd')

			{
				int num = va_arg(args, int);
				count += print_number(num);
			}

			else if (*format == 'i')
			{
				int num = va_arg(args, int);
				count += print_number(num);
			}

			else if (*format == '%')
			{
				count += print_char('%');
			}
			else
			{
				count += print_char('%');
				count += print_char(*format);
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
