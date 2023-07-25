#include "main.h"

/**
 * get_flags - Calculates no. of active flags
 * @format: Formatted string to print the arguments
 * @y: used to take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *y)
{
	int z, cur_y;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_y = *y + 1; format[cur_y] != '\0'; cur_y++)
	{
		for (z = 0; FLAGS_CH[z] != '\0'; z++)
			if (format[cur_y] == FLAGS_CH[z])
			{
				flags |= FLAGS_ARR[z];
				break;
			}

		if (FLAGS_CH[z] == 0)
			break;
	}

	*y = cur_y - 1;

	return (flags);
}
