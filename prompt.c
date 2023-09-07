#include <stdio.h>
#include <stdlib.h>

/**
 * prompt - function that displce prompt waiting to recieve input
 * Return: void
 */

void prompt(void)
{
	char *buffer = NULL;
	size_t count;

	printf("$ ");
	getline(&buffer, &count, stdin);
	printf("%s", buffer);
	free(buffer);
}
