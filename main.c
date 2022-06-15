#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: int
 */

int main(int argc, char *argv[])
{
	File *file;
	char *line = NULL;
	size_t line_len = 0;
	unsigned int line_counter = 1; /* initial line */
	stack_t *stack = NULL;
	char *str = NULL;

	argumrnt.n_dataStruct = 1; /* default mode of stack */
	if (argc < 2 || argc > 2) /* test for arguments */
	{
		arg_error();
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		file_err(argv[1]);
	}

	while (getline(&line, &line_len, file) != -1)
	{
		if (*line == '\n')
		{
			line_counter++;
			continue;
		}

		str = strtok(line, "\t\n");
		if (*str == "#")
		{
			line_counter++;
			continue;
		}
		arguments.arg = strtok(NULL, "\t\n");
		opcode(&stack, str, line_counter);
		line_counter++;
	}
	free(line);
	freeStack(stack);
	fclose(file);
	exit(0);
}
