#include "shell.h"
/**
 * print_number -Print Unsigned Int Putchar
 * @m: Unisigned Integer
 * Return: Void
 */
void print_number(unsigned int m)
{
	unsigned int x = m;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_number_in -Print Number Putchar
 * @m:Integer
 * Return: void
 */
void print_number_in(int m)
{
	unsigned int x = m;

	if (m < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
