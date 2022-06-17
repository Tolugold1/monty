#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define  _GNU_SOURCE

int globe = 0;
/**
 * main - entry point
 * @argc: argument counte
 * @argv: arguments
 * Return: nothing
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	unsigned int line_counter = 1;
	stack_t *stack = NULL;
	char *string = NULL;

	access.n_dataStruct = 1;
	if (argc < 2 || argc > 2)
	{
		arg_error();
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
		file_err(argv[1]);
	while (fgets(line, sizeof(line), file))
	{
		if (globe)
		{
			break;
		}

		if (*line == '\n')
		{
			line_counter++;
			continue;
		}
		string = strtok(line, "\t\n");
		if (*string == '#')
		{
			line_counter++;
			continue;
		}
		access.arg = strtok(NULL, "\t\n");
		opcode(&stack, string, line_counter);
		line_counter++;
	}
	freeStack(&stack);
	fclose(file);
	exit(globe);
}

/**
 * opcode - the function to be called
 * @stack: pointer to node
 * @str: the string to compare in order to know
 * maybe it stack or queue that'll be solve
 * line_number: the line number
 * Return: nothing
 */

void opcode(stack_t **stack, char *str, unsigned int line_number)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (!strcmp(str, "queue"))
	{
		access.n_dataStruct = 0;
		return;
	}
	if (!strcmp(str, "stack"))
	{
		access.n_dataStruct = 1;
	}

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, str) == 0)
		{
			ops[i].f(stack,line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	globe = EXIT_FAILURE;
}
