#include "main.h"

/**
 * printf_d - prints a decimal integer considering flags.
 * @args: The arguments list
 * @flags: The flags affecting the output
 * Return: number of characters printed
 */
int printf_d(va_list args, char *flags)
{
    int n = va_arg(args, int);
    int i = 0;

    if (n >= 0 && contains_flag(flags, '+'))
    {
        _putchar('+');
        i++;
    }
    else if (n >= 0 && contains_flag(flags, ' '))
    {
        _putchar(' ');
        i++;
    }

    // Insert your normal printf for %d here
    // and count the number of characters printed

    return i + count_of_normal_printf;
}

/**
 * contains_flag - checks if a certain flag exists within the flags string.
 * @flags: The string containing the flags
 * @flag: The flag to check for
 * Return: 1 if flag exists, 0 otherwise
 */
int contains_flag(char *flags, char flag)
{
    while (*flags)
    {
        if (*flags == flag)
            return (1);
        flags++;
    }
    return (0);
}

