#include "main.h"

/**
 * print_bin - Prints the binary representation of a number.
 * @val: Parameter representing the number to be printed.
 *
 * _putchar(b + '0');  // Print the binary digit as a character
 *count++;  // Increment the count of printed characters
 *
 * Return: Number of characters printed.
 */
int print_bin(va_list val)
{
	int flag = 0;
	int count = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + '0');
			count++;
		}
	}

	if (count == 0)
	{
		count++;
		_putchar('0');
	}

	return (count);
}
