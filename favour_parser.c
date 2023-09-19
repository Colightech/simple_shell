#include "shell.h"

/**
 * parse_cmd - Parse Line Of Input
 * @str: User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **parse_cmd(char *str)
{
	char **arr;
	char *token;
	int x, buffsize = BUFFER_SIZE;

	if (str == NULL)
		return (NULL);
	arr = malloc(sizeof(char *) * buffsize);
	if (!arr)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(str, "\n ");
	for (x = 0; token; x++)
	{
		arr[x] = token;
		token = _strtok(NULL, "\n ");
	}
	arr[x] = NULL;

	return (arr);
}
