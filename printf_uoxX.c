#include "main.h"

/**
 * _printf - A custom printf function.
 * @format: The format string.
 * ...
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
    va_list args;
    const char *traverse;
    int char_count = 0;

    va_start(args, format);

    for (traverse = format; *traverse != '\0'; traverse++)
    {
        while (*traverse != '%' && *traverse != '\0')
        {
            write(1, traverse, 1);
            char_count++;
            traverse++;
        }

        if (*traverse == '%')
        {
            traverse++;
            switch (*traverse)
            {
                case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_unsigned(num);
                    break;
                }

                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_octal(num);
                    break;
                }

                case 'x':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_hex(num, 0);
                    break;
                }

                case 'X':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    char_count += print_hex(num, 1);
                    break;
                }

                default:
                    write(1, traverse, 1);
                    char_count++;
                    break;
            }
        }
    }

    va_end(args);
    return (char_count);
}

int print_unsigned(unsigned int num)
{
    int count = 0;
    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    if (num > 0)
    {
        int length = num_len(num);

        char buffer[length];

        for (int i = length - 1; i >= 0; i--)
        {
            buffer[i] = (num % 10) + '0';
            num /= 10;
        }

        write(1, buffer, length);
        return length;
    }

    return count;
}

int print_octal(unsigned int num)
{
    char buffer[100];
    int index = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (num > 0)
    {
        buffer[index] = '0' + (num % 8);
        num /= 8;
        index++;
    }

    for (int i = index - 1; i >= 0; i--)
        write(1, &buffer[i], 1);

    return index;
}

int print_hex(unsigned int num, int is_uppercase)
{
    char buffer[100];
    char hex_chars[] = "0123456789abcdef";
    char HEX_CHARS[] = "0123456789ABCDEF";
    char *chars = is_uppercase ? HEX_CHARS : hex_chars;
    int index = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (num > 0)
    {
        buffer[index] = chars[num % 16];
        num /= 16;
        index++;
    }

    for (int i = index - 1; i >= 0; i--)
        write(1, &buffer[i], 1);

    return index;
}

int num_len(unsigned int num)
{
    int length = 0;

    while (num != 0)
    {
        length++;
        num /= 10;
    }

    return length;
}

/**
 * main - The main function for testing our _printf
 * 
 * This is where we test our custom printf function.
 * Returns 0 on successful execution.
 */

int main(void)
{
    int printed_chars;

    printed_chars = _printf("Unsigned: %u\n", 123456);
    _printf("Printed %d characters.\n", printed_chars);

    printed_chars = _printf("Octal: %o\n", 123456);
    _printf("Printed %d characters.\n", printed_chars);

    printed_chars = _printf("Hex: %x\n", 123456);
    _printf("Printed %d characters.\n", printed_chars);

    printed_chars = _printf("HEX: %X\n", 123456);
    _printf("Printed %d characters.\n", printed_chars);

    return (0);
}

