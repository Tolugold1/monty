#include "monty.h"

/**
 * arg_error - argument error function
 * Return: void
 */

void arg_error(void)
{
	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
