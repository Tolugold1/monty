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



/**
 * file_err - file error message
 * @argv: arguments passed
 * Return: void
 */

void file_err(char *argv)
{
	dprintf(2, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
