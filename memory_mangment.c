#include "shell.h"

/**
 **_realloc -  Reallocates Memory Using Malloc
 *@ptr: Pointer
 *@old_size: Previous Size Of The Pointer
 *@new_size: Newly allocated size
 *Return: Void Pointer Rellocated Memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *output;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	output = malloc(new_size);
	if (output == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(output, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(output, ptr, old_size);
		free(ptr);
	}
	return (output);

}
/**
 * free_all - Free Array Of Char Pointers
 * @str: Array Pointer
 * @line: Char Pointer
 * Return: Void
 */
void free_all(char **str, char *line)
{
	free(str);
	free(line);
	str = NULL;
	line = NULL;
}

/**
 * _memcpy - Copy n Byte From Source To Destination
 * @dest: Destination
 * @src: Source
 * @n: Size to copy
 *Return: Void
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}
/**
 * fill_an_array - Fill An Array with Constant Byte
 * @a: Void Pointer
 * @el: Int
 * @lent: Length Int
 *Return: Void Pointer
 */
void *fill_an_array(void *a, int el, unsigned int lent)
{
	char *p = a;
	unsigned int x = 0;

	while (x < lent)
	{
		*p = el;
		p++;
		x++;
	}
	return (a);
}
/**
 * _calloc -  Allocates Memory Using Malloc.
 * @size: Size
 * Return: Void Pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int x;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (x = 0; x < size; x++)
	{
		a[x] = '\0';
	}
	return (a);
}
