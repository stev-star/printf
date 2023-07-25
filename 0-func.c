#include "main.h"

/************************* PRINT CHARACTER *************************/

/**
 * print_char - Prints a char
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_char(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	char ch = va_arg(d_types, int);

	return (handle_write_char(ch, buffer, flag, width, precision, length));
}
/************************* PRINT STRING *************************/
/**
 * print_int - Print strings
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_string(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	int measure = 0, i;
	char *str = va_arg(n_args, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[measure] != '\0')
		measure++;

	if (precision >= 0 && precision < measure)
		measure = precision;

	if (width > measure)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], measure);
			for (i = width - measure; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - measure; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], measure);
			return (width);
		}
	}

	return (write(1, str, measure));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_int - Print percent sign
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_percent(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	UNUSED(n_args);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_int(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(n_args, long int);
	unsigned long int num;

	n = convert_size_number(n, length);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flag, width, precision, length));
}

/************************* PRINT BINARY *************************/
/**
 * print_int - Print unsigned int number
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_binary(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	unsigned int j, k, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(length);

	j = va_arg(n_args, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	a[0] = j / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		a[i] = (j / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
