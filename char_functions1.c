#include "shell.h"

/**
 * _putchar - writes character from c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_strncpy(char *dest, char *src, int n)
{
	int x;

	x = 0;
	while (x < n && *(src + x))
	{
	*(dest + x) = *(src + x);
	x++;
	}
	while (x < n)
	{
	*(dest + x) = '\0';
	x++;
	}
	return (dest);
}

/**
 * _strlen - lenght of string
 * @str: string
 * Return: string length
 */

int _strlen(char *str)
{
	int x;

		for (x = 0; str[x] != '\0'; x++)
		{
			continue;
		}
	return (x);
}

/**
 * _atoi - this function convert string to int
 * @s: string
 * Return:int
 */
int _atoi(char *s)
{
	int a, j, n, x;

	a = n = 0;
	x = 1;
	while ((s[a] < '0' || s[a] > '9') && (s[a] != '\0'))
	{
		if (s[a] == '-')
			x *= -1;
		a++;
	}
	j = a;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * _puts - print a string
 * @str: pointer to the string
 * return: void
 */
void _puts(char *str)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		_putchar(str[x]);
	}
_putchar('\n');
return;
}
