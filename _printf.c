<<<<<<< HEAD
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
=======
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
	
	if (format == NULL)
	      return (-1);
	        
	va_start(list, format);
	
	for (i = 0; format && format[i] != '\0'; i++)
	{
	        if (format[i] != '%')
	        {
	              buffer[buff_ind++] = format[1];
	              if (buff_ind == BUFF_SIZE)
	                    print_buffer(buffer, &buff_ind);
	              /*write (1, &format[i], 1);*/
	              printed_chars++;
	         }
	         else
	         {
	              print_buffer(buffer, &buff_ind);
	              flags = get_flags(format, &i);
	              width = get_width(format, &i, list);
	              precision = get_precision(format, &i, list);
	              size = get_size(format, &i);
	              ++i;
	              printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
	              if (printed == -1)
	                    return (-1);
	              printed_chars += printed;
	          }
	  }
	        
	  print_buffer(buffer, &buff_ind);
	  
	  va_end(list);
	  
	  return (printed_chars);
	
}

void print_buffer(char buffer[],int *buff_ind)
{
      if (*buff_ind > 0)
            write (1, &buffer[0], *buff_ind);
            
      *buff_ind = 0;
>>>>>>> d32638e587d82601bbd050db0fc52609cd87178c
}
