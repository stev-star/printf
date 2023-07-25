#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_pointer(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, measure = 2, padd_start = 1; 
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(n_args, void *);

	UNUSED(width);
	UNUSED(length);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		measure++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', measure++;
	else if (flag & F_SPACE)
		extra_c = ' ', measure++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, measure,
		width, flag, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @n_args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_non_printable(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	int o = 0, offset = 0;
	char *str = va_arg(n_args, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[o] != '\0')
	{
		if (is_printable(str[o]))
			buffer[o + offset] = str[o];
		else
			offset += append_hexa_code(str[o], buffer, o + offset);

		o++;
	}

	buffer[o + offset] = '\0';

	return (write(1, buffer, o + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */

int print_reverse(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	char *str;
	int o, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(length);

	str = va_arg(n_args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (o = 0; str[o]; o++)
		;

	for (o = o - 1; o >= 0; o--)
	{
		char z = str[o];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_rot13string(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	char x;
	char *str;
	unsigned int o, y;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(n_args, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	if (str == NULL)
		str = "(AHYY)";
	for (o = 0; str[o]; o++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == str[o])
			{
				x = out[y];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[y])
		{
			x = str[o];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
