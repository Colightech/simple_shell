#include "shell.h"

/**
 * prompt - a function that displace prompt
 * Return: void
 */

void prompt(void)
{
	write(1, "$ ", 2);
}
