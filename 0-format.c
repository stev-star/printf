#include "main.h"

void print_buffer(char buffer[], int *buffer_ind);

/**
 * _printf - Printf function
 * @format: for the charcter %.
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int flag, width, precision, length, o; 
	int buffer_ind = 0, printed = 0, print_chars = 0;
	char buffer[BUFF_SIZE];
	va_list n_args;
	

	if (format == NULL)
		return (-1);

	va_start(n_args, format);

	for (int o = 0; format && format[o] != '\0'; o++)
	{
		if (format[o] != '%')
		{
			buffer[buffer_ind++] = format[o];
			if (buffer_ind == BUFF_SIZE)
				print_buffer(buffer, &buffer_ind);
			
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buffer_ind);
			flag = get_flags(format, &o);
			width = get_width(format, &o, n_args);
			precision = get_precision(format, &o, n_args);
			length = get_size(format, &o);
			++o;
			printed = handle_print(format, &o, n_args, buffer,
				flag, width, precision, length);
			if (printed == -1)
				return (-1);
			print_chars += printed;
		}
	}

	print_buffer(buffer, &buffer_ind);

	va_end(n_args);

	return (print_chars);
}

/**
 * print_buffer - Prints every character inside it.
 * @buffer: An array of characters.
 * @buffer_ind: Index at which to add next character.
 */
void print_buffer(char buffer[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}
