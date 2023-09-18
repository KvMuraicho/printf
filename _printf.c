#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *format, ...) {
    va_list args;
    const char *traverse;  
    int count = 0;  

    va_start(args, format);
    
    for (traverse = format; *traverse != '\0'; traverse++) {
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

int main() {
    my_printf("This is a test: %d and %i\n", 1234, -5678);
    return 0;
}

