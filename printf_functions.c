#include "main.h"

/**
 * binary_converter - converts decimal to binary
 * @number: the decimal parameter
 *
 * Return: the binary form
 */
int binary_converter(int number)
{
	int counter = 0, i;
	int *array;

	array = malloc(sizeof(int) * number);
	if (array == 0)
	{
		return (0);
	}
	while (number != 0)
	{
		*(array + counter) = number % 2;
		counter++;
		number = number / 2;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar('0' + array[i]);
	}
	free(array);
	return (counter);
}

/**
 * hexa_decimal_converter_small - converts decimal to binary
 * @number: the decimal parameter
 *
 * Return: the number of characters printed
 */
int hexa_decimal_converter_small(unsigned int number)
{
	int counter = 0, i;
	char *array;
	char *hexa = "0123456789abcdef";
	int bits = 8;

	array = malloc(sizeof(char) * 50);
	if (array == 0)
	{
		return (0);
	}
	while (number != 0)
	{
		array[counter] = hexa[number % 16];
		counter++;
		number = number / 16;
	}
	if (counter > bits)
		bits += 8;
	while (counter < bits)
	{
		array[counter] = '0';
		counter++;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(array[i]);
	}
	free(array);
	return (counter);
}

/**
 * hexa_decimal_converter_big - converts decimal to binary
 * @number: the decimal parameter
 *
 * Return: the number of characters printed
 */
int hexa_decimal_converter_big(unsigned int number)
{
	int counter = 0, i;
	char *array;
	char *hexa = "0123456789ABCDEF";
	int bits = 8;

	array = malloc(sizeof(char) * 50);
	if (array == 0)
	{
		return (0);
	}
	while (number != 0)
	{
		array[counter] = hexa[number % 16];
		counter++;
		number = number / 16;
	}
	if (counter > bits)
		bits += 8;
	while (counter < bits)
	{
		array[counter] = '0';
		counter++;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(array[i]);
	}
	free(array);
	return (counter);
}

/**
 * octal_converter - converts decimal to binary
 * @number: the decimal parameter
 *
 * Return: the number of characters printed
 */
int octal_converter(unsigned int number)
{
	int counter = 0, i;
	int *array;

	array = malloc(sizeof(int) * 32);
	if (array == 0)
	{
		return (0);
	}
	while (number != 0)
	{
		array[counter] = number % 8;
		counter++;
		number = number / 8;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar('0' + array[i]);
	}
	free(array);
	return (counter);
}

/**
 * _puts - prints the value of the string pointer parameter
 * @str: the String parameter
 *
 * Return: the size of the printed string
 */
int _puts(char *str)
{
	int i;
	int string_length = _strlen(str);

	for (i = 0; i < string_length; i++)
	{
		_putchar(str[i]);
	}
	return (string_length);
}

/**
 * _strlen - returns length of a string
 * @str: string to get length of
 *
 * Return: length of string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (*str++)
		len++;
	return (len);
}

/**
 * print_number - prints out the value of an integer
 * @val: number to be printed
 *
 * Return: the number of digits printed
 */
int print_number(int val)
{
	int rem = 0;
	int num = 0;

	if (val < 0)
	{
		val = val * -1;
		num = num + _putchar('-');
	}
	if (val > 9)
	{
		num = num + print_number(val / 10);
		rem = val % 10;
		num = num + _putchar('0' + rem);
	}
	else
	{
		num = num + _putchar('0' + val);
	}
	return (num);
}

/**
 * prints_pointers - prints the address of a pointer variable
 * @number: the address value
 *
 * Return: the number of characters printed
 */
int prints_pointers(long int number)
{
	int counter = 0, i;
	char *array;
	char *hexa = "0123456789abcdef";

	array = malloc(sizeof(char) * 50);
	if (array == 0)
	{
		return (0);
	}
	while (number != 0)
	{
		array[counter] = hexa[number % 16];
		counter++;
		number = number / 16;
	}
	array[counter++] = 'x';
	array[counter++] = '0';
	for (i = counter - 1; i >= 0; i--)
	{
		_putchar(array[i]);
	}
	free(array);
	return (counter);
}

