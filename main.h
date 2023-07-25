#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *index,
va_list n_args, char buffer[], int flag, int width, int precision, int length);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);
int print_string(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);
int print_percent(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);

/* Functions to print numbers */
int print_int(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);
int print_binary(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);
int print_unsigned(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);
int print_octal(va_list n_types, char buffer[],
	int flag, int width, int precision, int length);
int print_hexadecimal(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);
int print_hexa_upper(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);

int print_hexa(va_list n_args, char map_to[],
char buffer[], int flag, char flag_ch, int width, int precision, int length);

/* Function to print non printable characters */
int print_non_printable(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);

/* Funcion to print memory address */
int print_pointer(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *y);
int get_width(const char *format, int *y, va_list list);
int get_precision(const char *format, int *y, va_list list);
int get_size(const char *format, int *y);

/*Function to print string in reverse*/
int print_reverse(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);

/*Function to print a string in rot 13*/
int print_rot13string(va_list n_args, char buffer[],
	int flag, int width, int precision, int length);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flag, int width, int precision, int length);
int write_number(int is_positive, int index, char buffer[],
	int flag, int width, int precision, int length);
int write_num(int index, char bff[], int flag, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int index, int length,
	int width, int flag, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int index,
char buffer[],
	int flag, int width, int precision, int length);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int length);
long int convert_size_unsgnd(unsigned long int num, int length);

#endif
