#ifndef PRINTF_H_
#define PRINTF_H_

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define F_MINUS1
#define F_PLUS2
#define F_ZERO4
#define F_HASH8
#define F_SPACE16
/**
 * formats - structs for specifiers
 * @format: specifiers
 * @run: action/function to run
 */
typedef struct formats
{
	char format;
	int (*run)(va_list);
}formats;

int for_spec(char format, va_list func);
int str_print(va_list func);
int char_print(va_list func);
int print_per(va_list func);
int print_b(va_list func);
int print_d(va_list func);
int print_i(va_list func);
int print_u(va_list func);
int print_o(va_list func);
int print_X(va_list func);
int print_x(va_list func);
int print_p(va_list func);
int print_r(va_list func);
int putchr(char c);
extern formats con;
extern int count;


#endif
