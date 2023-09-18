#include "main.h"

/**
 * printf_S - Prints a string. Non printable characters are printed as \xHH
 * @args: The arguments list to get the string from
 * Return: number of characters printed
 */
int printf_S(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0, count = 0;
    unsigned char c;

    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        c = str[i];
        if (c < 32 || c >= 127)
        {
            _putchar('\\');
            _putchar('x');
            if (c < 16)
                _putchar('0');
            print_hex(c);
            count += 4;
        }
        else
        {
            _putchar(c);
            count++;
        }
        i++;
    }
    return (count);
}

/**
 * print_hex - Prints a character's ASCII value in uppercase hexadecimal
 * @c: The character
 */
void print_hex(char c)
{
    char *hex = "0123456789ABCDEF";
    
    _putchar(hex[(c >> 4) & 0xF]);
    _putchar(hex[c & 0xF]);
}


