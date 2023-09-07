#include "shell.h"

/**
 * main - the main function of the simple shell project
 * Return: 0 on success
 */

int main(void)
{
	char str[MAX_STR];

	while (1)
	{
		prompt();
		accept_input();
		execute_process(str);
	}
	return (0);
}
