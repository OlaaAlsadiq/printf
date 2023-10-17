#include "main.h"

int _strlen(char *s);
int _write_specifier(char specifier, va_list arg);

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}

/**
 * _write_specifier - print the formatted output based on the format specifier
 * @specifier: print specifier
 * @arg: function parameter
 *
 * Return: printed chracter
 */

int _write_specifier(char specifier, va_list arg)
{
	int result = 0;
	int l, m;
	char c, *s, buffer[12];

	if (specifier == 'c')
	{
		c = va_arg(arg, int);
		result = write(1, &c, 1);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		l = va_arg(arg, int);
		m =  sprintf(buffer, "%d", l);
		result = write(1, buffer, m);
	}
	else if (specifier == 's')
	{
		s = va_arg(arg, char *);
		if (s == NULL)
		{
			s = "(null)";
		}
		result = write(1, s, strlen(s));
	}
	else
	{
		/*handle other specifier*/
	}
	return (result);
}

/**
 * _printf - Printf function
 * @format: function parameter
 *
 * Return: Printed chars
 */

int _printf(const char *format, ...)
{
	int final;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format != '%' && (write(1, format, 1), 1))
		{
			final++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				final++;
			}
			else
			{
				final += _write_specifier(*format, args);
			}
		}
		format++;
	}
	va_end(args);
	return (final);

}
