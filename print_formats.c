#include "main.h"

/**
 * print_char - prints character
 * @func: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */

int print_char(va_list func, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(func, int);

	if (params->minus_flag)
		sum += putchr(ch);
	while (pad++ < params->width)
		sum += putchr(pad_char);
	if (!params->minus_flag)
		sum += putchr(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @func: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */

int print_int(va_list func, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(func, long);
	else if (params->h_modifier)
		l = (short int)va_arg(func, int);
	else
		l = (int)va_arg(func, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @func: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list func, params_t *params)
{
	char *str = va_arg(func, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += putchr(*str++);
		else
			sum += put_string(str);
	}
	while (j++ < params->width)
		sum += putchr(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += putchr(*str++);
		else
			sum += put_string(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @func: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list func, params_t *params)
{
	(void)func;
	(void)params;
	return (putchr('%'));
}

/**
 * print_S - custom format specifier
 * @func: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list func, params_t *params)
{
	char *str = va_arg(func, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (put_string(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += putchr('\\');
			sum += putchr('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += putchr('0');
			sum += put_string(hex);
		}
		else
		{
			sum += putchr(*str);
		}
	}
	return (sum);
}
