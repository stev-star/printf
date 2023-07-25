#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @y: List of arguments to be printed.
 * @n_args: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *y, va_list n_args)
{
	int cur_y;
	int width = 0;

	for (cur_y = *y + 1; format[cur_y] != '\0'; cur_y++)
	{
		if (is_digit(format[cur_y]))
		{
			width *= 10;
			width += format[cur_y] - '0';
		}
		else if (format[cur_y] == '*')
		{
			cur_y++;
			width = va_arg(n_args, int);
			break;
		}
		else
			break;
	}

	*y = cur_y - 1;

	return (width);
}
