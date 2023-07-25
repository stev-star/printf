#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @n_args: List of arguments to be printed.
 * @index: ind.
 * @buffer: Buffer array to handle print.
 * @flag: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: 1 or 2
 */
int handle_print(const char *fmt, int *index, va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	int y, unknow_length = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (y = 0; fmt_types[y].fmt != '\0'; y++)
		if (fmt[*index] == fmt_types[y].fmt)
			return (fmt_types[y].fn(n_args, buffer, flag, width, precision, length));

	if (fmt_types[y].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_length += write(1, &fmt[*index], 1);
		return (unknow_length);
	}
	return (printed_chars);
}
