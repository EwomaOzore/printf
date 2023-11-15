#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - Produces output according to a format.
 * @format: Format string.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *str;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					write(1, str, strlen(str));
					count += strlen(str);
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
