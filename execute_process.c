#include "shell.h"

/**
 * execut_process - function that executes command and processes
 * @str; str or command to execute
 * Return: void
 */

void execute_process(const char *str)
{
	pid_t child_process;

	child_process = fork();
	if (child_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		execlp(str, str, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL); /* parent process */
	}
}
