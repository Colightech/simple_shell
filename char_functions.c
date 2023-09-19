#include "shell.h"

/**
 * _strcmp - Compare Two String
 * @s1:String 1
 * @s2:String 2
 * Return: 0 If Identical Otherwise How Much Diffrent
 */
int _strcmp(char *s1, char *s2)
{
int cmp = 0, x, lent1, lent2;
lent1 = _strlen(s1);
lent2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (lent1 != lent2)
		return (1);
	for (x = 0; s1[x]; x++)
	{
		if (s1[x] != s2[x])
		{
			cmp = s1[x] - s2[x];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _isalpha - Check if Alphabtic
 *@b: Character
 * Return: 1 If True 0 If Not
 */
int _isalpha(int b)
{
if (((b >= 97) && (b <= 122)) || ((b >= 65) && (b <= 90)))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n)
{
	int lent = 0, x = 0;
	char *s;

	lent = intlen(n);
	s = malloc(lent + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[x] = (n % 10) + '0';
		n /= 10;
		x++;
	}
	s[x] = (n % 10) + '0';
	array_rev(s, lent);
	s[x + 1] = '\0';
	return (s);
}
/**
 *  array_rev - Reverse Array
 * @arr:Array To Reverse
 * @lent: Length Of Array
 * Return: Void(Reverse Array)
 */
void array_rev(char *arr, int lent)
{
	int x;
	char tmp;

	for (x = 0; x < (lent / 2); x++)
	{
		tmp = arr[x];
		arr[x] = arr[(lent - 1) - x];
		arr[(lent - 1) - x] = tmp;
	}
}
/**
 * intlen - Determine Length Of Int
 * @num: Given Int
 * Return: Length Of Int
 */
int intlen(int num)
{
	int lent = 0;

	while (num != 0)
	{
		lent++;
		num /= 10;
	}
	return (lent);
}
