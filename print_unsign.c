#include "main.h"

/**
 * print_int - Print an integer
 * @args: Variable arguments list
 *
 *  i++;  // Fix variable increment
 *   k = -k;  // Fix variable name
 *
 *   num = num % exp;  // Fix modulo operation
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	int k = va_arg(args, int);
	int num, last = k % 10, digit, exp = 1;
	int i = 1;

	k = k / 10;
	num = k;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		k = -k;
		last = -last;
		i++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}

		num = k;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar('0' + digit);
			num = num % exp;
			exp = exp / 10;
			i++;
		}
	}
	_putchar('0' + last);

	return (i);
}
