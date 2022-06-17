#include "monty.h"

/**
 * arg_error - argument error function
 * Return: void
 */

void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_err - file error message
 * @argv: arguments passed
 * Return: void
 */

void file_err(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
