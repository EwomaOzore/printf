#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...);
int process_format(const char *format, va_list args);

/**
 * struct FormatSpecifier - Struct to hold format specifiers and their corresponding functions.
 * @format: Format specifier.
 * @function: Pointer to the function handling the specifier.
 */
struct FormatSpecifier
{
    const char *format;
    int (*function)(va_list);
};

int main(void)
{
    _printf("Hello, %s!\n", "world");
    return (0);
}

/**
 * _printf - Prints formatted output.
 * @format: Format string.
 *
 * Return: The length of the printed string.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int length = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    length = process_format(format, args);

    va_end(args);
    return (length);
}

/**
 * process_format - Processes the format string.
 * @format: Format string.
 * @args: Variable arguments list.
 *
 * Return: The length of the printed string.
 */
int process_format(const char *format, va_list args)
{
    int i = 0, j, length = 0;
    struct FormatSpecifier p[] = {
        {"%s", printf_string}, {"%c", printf_char},
        {"%%", print_int}, {"%i", print_int},
        {"%d", print_pointer},
        {"%r", print_hexc_string}, {"%R", print_hexc_string},
        {"%b", print_bin}, {"%u", print_unsigned},
        {"%o", print_oct}, {"%x", print_hex}, {"%X", print_hex},
        {"%S", print_pointer}, {"%p", print_pointer}
    };

    while (format[i] != '\0')
    {
        j = sizeof(p) / sizeof(p[0]) - 1;
        while (j >= 0)
        {
            if (format[i] == '%' && format[i + 1] == p[j].format[1])
            {
                length += p[j].function(args);
                i += 2;
                break;
            }
            j--;
        }

        if (j < 0)
        {
            _putchar(format[i]);
            length++;
            i++;
        }
    }

    return (length);
}
