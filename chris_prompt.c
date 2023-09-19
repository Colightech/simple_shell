#include "shell.h"

/**
 * prompt - Display Simple Shell Prompt
 */
void prompt(void)
{
	PRINT_OUT("$ ");
}
/**
 * print_error - Display Error Based on Command
 * @input: User Input
 * @counter: Simple Shell Count Loop
 * @argv: argureent vector
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *err;

	PRINT_OUT(argv[0]);
	PRINT_OUT(": ");
	err = _itoa(counter);
	PRINT_OUT(err);
	free(err);
	PRINT_OUT(": ");
	PRINT_OUT(input);
	PRINT_OUT(": not found\n");
}
