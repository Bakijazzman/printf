#include "main.h"
/**
 * for_spec - fumction that returns format
 * @format: struct for specified data type
 * @func: variiable arguement list
 * Return: word count
 */
int for_spec(char format, va_list func)
{
	const formats con[] = {
		{'%', print_per},
		{'s', str_print},
		{'c', char_print},
		{'b', print_b},
		{'d', print_d},
		{'i', print_i},
		{'u', print_u},
		{'o', print_o},
		{'X', print_X},
		{'x', print_x},
		{'p', print_p},
		{'r', print_r}
	};
	unsigned int i = 0, c = 0;

	if ('%' == format)
	{
		putchr('%');
		return (c);
	}

	for (; i < (sizeof(con) / sizeof(formats)); i++)
	{
		if (con[i].format == format)
		{
			return (con[i].run(func));
		}
	}
	putchr('%');
	putchr(format);
	c += 2;
	return (c);
}
