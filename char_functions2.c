#include "shell.h"
/**
 * _strcpy - Copie Source To Destination Char
 * @dest:Destination
 * @src: Source
 * Return: Copie Of Char *
 */
char *_strcpy(char *dest, char *src)
{
	int x;

x = 0;
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
return (dest);
}
/**
 * _strcat - Concat Two String
 * @dest: First String
 * @src: Second String
 * Return:First String + Second String Char *
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - Locate Charactere In String
 * @s: String Search In
 * @b: Char To Search For
 * Return: Pointer To Char*
 */
char *_strchr(char *s, char b)
{

	do		{

		if (*s == b)
		{
		break;
		}
	}	while (*s++);

return (s);
}
/**
 * _strncmp - Compare n size Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	if (s1 == NULL)
		return (-1);
	for (x = 0; x < n && s2[x]; x++)
	{
		if (s1[x] != s2[x])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */
char *_strdup(char *str)
{
	size_t lent, x;
	char *str2;

	lent = _strlen(str);
	str2 = malloc(sizeof(char) * (lent + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (x = 0; x <= lent; x++)
	{
		str2[x] = str[x];
	}

	return (str2);
}
