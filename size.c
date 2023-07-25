#include "main.h"

/**
 * get_size - Calculates the size for casting the argument
 * @format: Formatted string to print the arguments
 * @y: arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *y)
{
	int cur_y = *y + 1;
	int size = 0;

	if (format[cur_y] == 'l')
		size = S_LONG;
	else if (format[cur_y] == 'h')
		size = S_SHORT;

	if (size == 0)
		*y = cur_y - 1;
	else
		*y = cur_y;

	return (size);
}
