#include "main.h"
#include <unistd.h>

/**
 * _putchar - Custom putchar function
 * @c: Character to be printed
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Custom puts function
 * @str: String to be printed
 *
 * Return: Number of characters printed
 */
int _puts(char *str)
{
    int count = 0;

    while (str && *str)
    {
        _putchar(*str);
        count++;
        str++;
    }

    return count;
}

/**
 * print_number - Print an integer
 * @n: Integer to be printed
 *
 * Return: Number of digits printed
 */
int print_number(int n)
{
    int count = 0;
    int divisor = 1;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }

    while (n / divisor > 9)
        divisor *= 10;

    while (divisor != 0)
    {
        count += _putchar((n / divisor) + '0');
        n %= divisor;
        divisor /= 10;
    }

    return count;
}

/**
 * print_unsigned - Print an unsigned integer
 * @n: Unsigned integer to be printed
 *
 * Return: Number of digits printed
 */
int print_unsigned(unsigned int n)
{
    int count = 0;
    unsigned int divisor = 1;

    while (n / divisor > 9)
        divisor *= 10;

    while (divisor != 0)
    {
        count += _putchar((n / divisor) + '0');
        n %= divisor;
        divisor /= 10;
    }

    return count;
}

/**
 * print_binary - Print a binary representation of an unsigned integer
 * @n: Unsigned integer to be printed in binary
 *
 * Return: Number of binary digits printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    unsigned int mask = 1 << 31;

    while (mask > 0)
    {
        count += _putchar((n & mask) ? '1' : '0');
        mask >>= 1;
    }

    return count;
}

/**
 * print_octal - Print an octal representation of an unsigned integer
 * @n: Unsigned integer to be printed in octal
 *
 * Return: Number of octal digits printed
 */
int print_octal(unsigned int n)
{
    int count = 0;
    unsigned int octal_digits[100];
    int i = 0;

    while (n > 0)
    {
        octal_digits[i] = n % 8;
        n /= 8;
        i++;
    }

    while (--i >= 0)
        count += _putchar(octal_digits[i] + '0');

    return count;
}

/**
 * print_hex - Print a hexadecimal representation of an unsigned integer
 * @n: Unsigned integer to be printed in hexadecimal
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: Number of hexadecimal digits printed
 */
int print_hex(unsigned int n, int uppercase)
{
    int count = 0;
    char hex_digits[] = "0123456789abcdef";
    if (uppercase)
        hex_digits[10] = 'A';

    int hex_digits_array[100];
    int i = 0;

    while (n > 0)
    {
        hex_digits_array[i] = n % 16;
        n /= 16;
        i++;
    }

    while (--i >= 0)
        count += _putchar(hex_digits[hex_digits_array[i]]);

    return count;
}

/**
 * print_str_non_printable - Print a string with non-printable characters
 * @str: String to be printed
 *
 * Return: Number of characters printed
 */
int print_str_non_printable(char *str)
{
    int count = 0;

    while (str && *str)
    {
        if (*str < 32 || *str >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += print_hex(*str, 1);
        }
        else
        {
            count += _putchar(*str);
        }
        str++;
    }

    return count;
}

/**
 * print_pointer - Print the address of a pointer
 * @p: Pointer to be printed
 *
 * Return: Number of characters printed
 */
int print_pointer(void *p)
{
    int count = 0;
    unsigned long int n = (unsigned long int)p;

    count += _putchar('0');
    count += _putchar('x');
    count += print_hex(n, 0);

    return count;
}

/**
 * print_reverse - Print a reversed string
 * @str: String to be printed in reverse
 *
 * Return: Number of characters printed
 */
int print_reverse(char *str)
{
    int count = 0;

    while (str && *str)
        str++;

    while (--str >= 0)
        count += _putchar(*str);

    return count;
}

/**
 * print_rot13 - Print a string in ROT13 encoding
 * @str: String to be printed in ROT13
 *
 * Return: Number of characters printed
 */
int print_rot13(char *str)
{
    int count = 0;

    while (str && *str)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            char base = (*str >= 'a' && *str <= 'z') ? 'a' : 'A';
            count += _putchar(((*str - base + 13) % 26) + base);
        }
        else
        {
            count += _putchar(*str);
        }
        str++;
    }

    return count;
}
