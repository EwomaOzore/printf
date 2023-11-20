#include "main.h"
#include <stdio.h>

/**
 * printf_char - Writes the character 'c' to the standard output.
 * @val: Argument list containing the character to be printed.
 *
 * Return: On success, returns 1.
 */
int printf_char(va_list val)
{
	char c;

	c = va_arg(val, int);

	_putchar(c);
	return (1);
}
