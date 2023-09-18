#include <stdio.h>
#include <stdarg.h>
#include"main.h"

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0;  
    for (const char *traverse = format; *traverse != '\0'; traverse++) {
        if (*traverse != '%') {
            putchar(*traverse);
            count++;
            continue;
        }

        traverse++;

        switch (*traverse) {
            case 'd':
            case 'i':
                {
                    int i = va_arg(args, int);
                    count += printf("%d", i);
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

