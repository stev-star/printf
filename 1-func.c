#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_unsigned(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	int p = BUFF_SIZE - 2;
	unsigned long int num = va_arg(n_args, unsigned long int);

	num = convert_size_unsgnd(num, length);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = (num % 10) + '0';
		num /= 10;
	}

	p++;

	return (write_unsgnd(0, p, buffer, flag, width, precision, length));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(n_args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, length);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, length));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	return (print_hexa(n_args, "0123456789abcdef", buffer,
		flag, 'x', width, precision, length));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @n_args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list n_args, char buffer[],
	int flag, int width, int precision, int length)
{
	return (print_hexa(n_args, "0123456789ABCDEF", buffer,
		flag, 'X', width, precision, length));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @n_args: List of arguments
 * @map_to: Array of values to map the number to
 * @flag_ch: Calculates active flags
 * @buffer: Buffer array to handle print
 * @flag:  Calculates no. of active flag
 * @width: get width.
 * @precision: Precision specification
 * @length: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list n_args, char map_to[], char buffer[],
	int flag, char flag_ch, int width, int precision, int length)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(n_args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, length);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, length));
}
