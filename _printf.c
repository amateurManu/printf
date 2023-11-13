#include "main.h"

/**
 * _printf - prints data to stdout
 * @format: string to be printed
 *
 * Return: returns no of characters to be printed
 */
int _printf(const char *format, ...)
{
	size_t i;
	int no_of_chars = 0;
	va_list args;

	if (format == NULL || format == "")
		return (-1);
	va_start(args, format);
	for (i = 0; i < strlen(format); i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			no_of_chars++;
		} else
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == 'c')
			{
				char letter = va_arg(args, int);

				write(1, &letter, 1);
				no_of_chars++;
			} else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				int len = strlen(str);

				write(1, str, len);
				no_of_chars += len;
			} else if (format[i] == '%')
			{
				write(1, "%", 1);
				no_of_chars++;
			}
		}
	}
	va_end(args);
	return (no_of_chars);
}
