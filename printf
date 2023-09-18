#include "main.h"

/**
 * _printf - Our custom printf function.
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
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    print_number(num);

                    int temp = num < 0 ? -num : num;
                    do 
                    {
                        char_count++;
                        temp /= 10;
                    } 
                    while (temp != 0);

                    if (num < 0)
                        char_count++;
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

/**
 * print_number - Function to handle number printing
 * @n: The number to be printed
 * 
 * This function processes the number and handles negative numbers. 
 * It then writes the processed number to the standard output.
 */

void print_number(int n)
{
    if (n == 0)
    {
        write(1, "0", 1);
        return;
    }

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }

    int temp = n, size = 0;
    while (temp != 0)
    {
        temp /= 10;
        size++;
    }

    char buffer[size];
    int index = size - 1;

    while (n != 0)
    {
        buffer[index] = (n % 10) + '0';
        n /= 10;
        index--;
    }

    write(1, buffer, size);
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

    printed_chars = _printf("Number: %d\n", 1234);
    _printf("Printed %d characters.\n", printed_chars);

    printed_chars = _printf("Number: %i\n", -5678);
    _printf("Printed %d characters.\n", printed_chars);

    return (0);
}

