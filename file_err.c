#include "monty.h"

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
