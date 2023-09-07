#include "shell.h"

/**
 * execute_process - function that executes command and processes
 * @str; str or command to execute
 * Return: void
 */

void execute_process(void)
{
	char str[MAX_STR];
	pid_t child_process;
	int status;

	while (true)
	{
		prompt();
		if (fgets(str, sizeof(str), stdin) == NULL)
		{
			printf("Exiting Chris_Favour's Shell.\n"); /* exit to parent with Ctr+D */
			break;
		}
		str[strlen(str) - 1] = '\0'; /* remove newline character */
		child_process = fork(); /* create a child process to execute a command */
		if (child_process == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_process == 0)
		{
			if (execlp(str, str, NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* parent procees wait for child process to finish executing */
			if (waitpid(child_process, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
}
