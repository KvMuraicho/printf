#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - custom printf function
 * @format: the format string
 * @...: the values to format and print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    const char *traverse;
    int count = 0;

    va_start(args, format);

    for (traverse = format; *traverse != '\0'; traverse++)
    {
        
        if (*traverse != '%')
        {
            putchar(*traverse);
            count++;
            continue;
        }

     
        traverse++;
        switch (*traverse)
        {
            case 'c':
                {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                }
                break;

            case 's':
                {
                    char *s = va_arg(args, char*);
                    while (*s)
                    {
                        putchar(*s);
                        count++;
                        s++;
                    }
                }
                break;

            case '%':
                {
                    putchar('%');
                    count++;
                }
                break;

            default:
          
                putchar('%');
                putchar(*traverse);
                count += 2;
                break;
        }
    }

    va_end(args);

    return count;
}

int main(void)
{
    _printf("Character: %c, String: %s, Percent sign: %%\n", 'A', "Hello");
    return 0;
}

