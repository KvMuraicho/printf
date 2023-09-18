#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, len = 0, width = 0, width_flag = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && is_digit(format[i + 1]))
        {
            width_flag = 1;
            i++;
            while (is_digit(format[i]))
            {
                width = width * 10 + (format[i] - '0');
                i++;
            }
        }
        
        if (format[i] == '%' && is_conversion_specifier(format[i + 1]))
        {
            len += handle_conversion_specifier(format[i + 1], args, width);
            if (width_flag)
            {
                width = 0;
                width_flag = 0;
            }
            i += 2;
        }
        else
        {
            _putchar(format[i]);
            len++;
            i++;
        }
    }

    va_end(args);
    return (len);
}

/**
 * is_digit - Check if a character is a digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * is_conversion_specifier - Check if a character is a recognized specifier
 * @c: the character to check
 * Return: 1 if recognized, 0 otherwise
 */
int is_conversion_specifier(char c)
{
    char *specifiers = "diucs";
    while (*specifiers)
    {
        if (c == *specifiers)
            return (1);
        specifiers++;
    }
    return (0);
}

/**
 * handle_conversion_specifier - Process and print data based on the specifier
 * @spec: the conversion specifier
 * @args: list of arguments
 * @width: field width
 * Return: number of characters printed
 */
int handle_conversion_specifier(char spec, va_list args, int width)
{
    int len = 0;
    char *str;

  
    if (spec == 's')
    {
        str = va_arg(args, char*);
        len = _puts_width(str, width);  
    }


    return (len);
}

/**
 * _puts_width - Print a string considering field width
 * @str: the string to print
 * @width: field width
 * Return: number of characters printed
 */
int _puts_width(char *str, int width)
{
    int len = 0;
    while (str && *str && width--)
    {
        _putchar(*str);
        str++;
        len++;
    }

    while (width-- > 0) 
    {
        _putchar(' ');
        len++;
    }

    return (len);
}
i
