#include "main.h"

/**
 * print_hex_extra - Prints a hexadecimal number.
 * @num: Number to be converted to hexadecimal.
 *
 * Return: Number of characters printed.
 */
int print_hexa_extra(unsigned long int num)
{
	long int i;
	long int *array;
	unsigned long int temp = num;
	int counter = 0;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;

	array = malloc(counter * sizeof(long int));
	if (array == NULL)
	{
		return (0);
	}

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}

	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;

		_putchar(array[i] + '0');
	}
	free(array);

	return (counter);
}
