#include "main.h"

/**
 * _printf_reverse - Prints a string in reverse.
 * @args: A list of arguments from the _printf function.
 *
 * Return: The number of characters printed.
 */
int _printf_reverse(va_list args)
{
    char *str;
    int len, i, count = 0;

    str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";

    len = _strlen(str);

    for (i = len - 1; i >= 0; i--)
    {
        _putchar(str[i]);
        count++;
    }

    return count;
}

/**
 * _strlen - Calculate the length of a string.
 * @s: The string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    int length = 0;

    while (*s++)
        length++;

    return length;
}

