#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf- the main function
 * @d- first conversion specifier
 * @i - second conversion specifier
 *
 */

int _printf(const char *format, ...) {
    unsigned int count = 0;

    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            count += my_putchar(*format);
        } else {
            format++; /* Move past the '%' */

            /* Check the conversion specifier */
            switch (*format) {
                case 'i':
                case 'd': {
                    int num = va_arg(args, int);
                    count += my_putint(num);
                    break;
                 }
                case '%': {
                    count += my_putchar('%');
                    break;
                }
                default: {
                    count += my_putchar('%');
                    count += my_putchar(*format);
                    break;
                }
            }
        }
        format++; /* Move to the
