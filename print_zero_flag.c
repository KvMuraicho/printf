#include "main.h"

/**
 * _printf_zero_flag - Prints an integer with leading zeros.
 * @args: A list of arguments from the _printf function.
 * @len: The total width or number of characters to print.
 *
 * Return: The number of characters printed.
 */
int _printf_zero_flag(va_list args, int len)
{
    int i, num, n, count = 0;
    n = va_arg(args, int);
    int space = len - num_length(n); 

    if (n < 0)
    {
        _putchar('-');
        n = -n;
        count++;
    }

    for (i = 0; i < space; i++)
    {
        _putchar('0');
        count++;
    }

    count += _print_number(n); 
    return count;
}

/**
 * num_length - Calculate the number of digits in an integer.
 * @n: The integer.
 *
 * Return: The number of digits.
 */
int num_length(int n)
{
    int length = 0;
    while (n)
    {
        n /= 10;
        length++;
    }
    return length;
}

/**
 * _print_number - Print the integer without leading zeros.
 * @n: The integer.
 *
 * Return: The number of digits printed.
 */
int _print_number(int n)
{
    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    if (n / 10)
        _print_number(n / 10);
    _putchar((n % 10) + '0');
    return num_length(n);
}

