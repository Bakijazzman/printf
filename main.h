#ifndef PRINTF_H_
#define PRINTF_H_
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>



#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


int char_print(char c);
int str_print(char *str);
int _printf(const char *format, ...);



/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int char_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int str_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsignd(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex_dec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);













#endif
