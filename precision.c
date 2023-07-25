#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string to print the arguments
 * @y: arguments to be printed.
 * @n_args: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *y, va_list n_args)
{
	int cur_y = *y + 1;
	int precision = -1;

	if (format[cur_y] != '.')
		return (precision);

	precision = 0;

	for (cur_y += 1; format[cur_y] != '\0'; cur_y++)
	{
		if (is_digit(format[cur_y]))
		{
			precision *= 10;
			precision += format[cur_y] - '0';
		}
		else if (format[cur_y] == '*')
		{
			cur_y++;
			precision = va_arg(n_args, int);
			break;
		}
		else
			break;
	}

	*y = cur_y - 1;

	return (precision);
}
