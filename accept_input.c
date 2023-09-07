#include "shell.h"

/**
 * accept_input - a function recieve input at the prompt
 * @str: string input
 * @count: size of input
 * Return: void
 */

void accept_input()
{
	char str[MAX_STR];

	if (fgets(str, sizeof(str), stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Error: cant read input\n");
			exit(EXIT_FAILURE);
		}
	}
}
