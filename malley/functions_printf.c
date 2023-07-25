#include <stdarg.h>
#include "main.h"

/**
 * char_print - Prints char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int char_print(va_list types, char buffer[])
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer));
}
/**
 * str_print - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int str_print(va_list types, char buffer[])
{
	int length = 0;
	char *str = va_arg(types, char *);

	UNUSED(buffer);

	if (str == NULL)
		str = "(null)";

	while (str[length] != '\0')
		length++;

	return (write(1, str, length));
}
/**
 * print_int - Prints an integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[])
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, 0);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer));
}

int _printf(const char *format, ...)
{
	unsigned int count = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += char_print(args, NULL);
			format++;
		}
		else
		{
			format++;
			if (*format == 'd' || *format == 'i')
				count += print_int(args, NULL);
			else if (*format == 's')
				count += str_print(args, NULL);
			else if (*format == '%')
				count += char_print(args, NULL);
		else
			count += char_print(args, NULL);
			format++;
		}
	}

	va_end(args);
	return (count);
}
