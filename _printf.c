#include "holberton.h"

/**
 * take_form - Selecting the matching character from the structure.
 * @signo: All characters to be used acording to user.
 * Return: Characters
 */
int (*take_form(char signo))(va_list)
{
	simb op_list[] = {
	    {"c", print_char},
	    {"s", print_string},
	    {"%", print_porc},
	    {"d", print_int},
	    {"i", print_int},
	    {"b", print_binary},
	    {NULL, NULL}};
	int i = 0;

	if (signo == '\0')
		return (NULL);

	for (i = 0; op_list[i].simb != NULL; i++)
	{
		if (signo == op_list[i].simb[0])
		{
			return (op_list[i].f);
		}
	}
	return (NULL);
}

/**
 * _printf - List characters or parameters given to be listed
 *           in va_list.
 * @format: All characters to be used acording to user.
 * Return: Number of Characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, cont = -1;
	int (*simb)(va_list);
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	if (format[i] != '\0')
	{
		cont = 0;
		va_start(list, format);
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '\0')
				{
					cont = -1;
					break;
				}
				else
				{
					simb = take_form(format[i + 1]);
				}
				if (simb == NULL)
				{
					cont += _putchar('%');
					cont += _putchar(format[i + 1]);
				}
				else
				{
					cont += simb(list);
				}
				i++;
			}
			else
			{
				_putchar(format[i]);
				cont++;
			}
		}
		va_end(list);
	}
	return (cont);
}
