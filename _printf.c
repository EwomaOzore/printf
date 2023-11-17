#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    count += _puts(va_arg(args, char *));
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int));
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'b':
                    count += print_binary(va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += print_octal(va_arg(args, unsigned int));
                    break;
                case 'x':
                    count += print_hex(va_arg(args, unsigned int), 0);
                    break;
                case 'X':
                    count += print_hex(va_arg(args, unsigned int), 1);
                    break;
                case 'S':
                    count += print_str_non_printable(va_arg(args, char *));
                    break;
                case 'p':
                    count += print_pointer(va_arg(args, void *));
                    break;
                case 'r':
                    count += print_reverse(va_arg(args, char *));
                    break;
                case 'R':
                    count += print_rot13(va_arg(args, char *));
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
