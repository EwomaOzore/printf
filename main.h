#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>


/**
 * struct print - Structure for printer functions
 * @type_arg: Identifier for the type
 * @f: Pointer to a printer function
 *
 * Description: This structure stores pointers to printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t; 

#define UNUSED(x) (void)(x)

int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);
#define MAX_BUF_SIZE 1024

#define S_LONG 0
#define S_SHORT 1

#define F_PLUS '+'
#define F_SPACE '\0'

#define BUFF_SIZE 1024

#ifdef FD_ZERO
#undef FD_ZERO
#endif
#define FD_ZERO

#ifdef BUFSIZ
#undef BUFSIZ
#endif
#define BUFSIZ 100

int ibuf;
char buf[MAX_BUF_SIZE];
int print_HEX_extra(int value);
int print_hex_extra(int value);

int _putchar(char c);
int handl_buf(char *buf, char c, int ibuf);
int printf_string(va_list val);
void print_buffer(char buffer[], int *buff_ind) __attribute__((unused));

int process_format(const char *format, va_list args);
int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list val);
int printf_char(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int print_hexc_string(va_list val);
int print_percent(void);
int print_int(va_list args);
int print_bin(va_list val);
int print_unsigned(va_list args);
int print_oct(va_list val);
int print_hex(va_list val);
int print_Hex(va_list val);
int print_pointer(va_list val);
int print_hexa_extra(unsigned long int num);
int print_rev(va_list arguments, char *buf, unsigned int ibuf);
int print_rot(va_list arguments, char *buf, unsigned int ibuf);
int get_size(const char *format, int *i);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);

int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int prec, int length, char padd, char extra_c);
int handle_print(const char *format, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);
#endif
