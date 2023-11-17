#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_number(int n);
int print_unsigned(unsigned int n);
int print_binary(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_str_non_printable(char *str);
int print_pointer(void *p);
int print_reverse(char *str);
int print_rot13(char *str);

#endif /* MAIN_H */
