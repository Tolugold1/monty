#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	char *string = NULL;

	if (argc != 2)
		arg_error();

	file = fopen(argv[1], "r");
	if (!file)
		file_err(argv[1]);

	while (fgets(line, sizeof(line), file) != NULL)
	{
		string = strtok(line, " \t");
		if (string[0] == '#')
		{
			(void)stack;
			(void)line_number;
		}
		else if (string[0] == '\n')
			fetch_opcode(&stack, string, line_number)(&stack,
					line_number);
		line_number++;
	}
	freeStack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * fetch_opcode - the function to be called
 * @stack: pointer to node
 * @str: the string to compare in order to know
 * maybe it stack or queue that'll be solve
 * line_number: the line number
 * Return: nothing
 */

void (*fetch_opcode(stack_t **stack, char *str, int line_number))(stack_t **, unsigned int)
{
	int i = 0;
	unsigned int j;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (ops[i].opcode)
	{
		for (j = 0; j < strlen(str); j++)
		{
			if (str[j] == '\n')
				str[j] = '\0';
		}
		if (strcmp(ops[i].opcode, str) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	freeStack(stack);
	exit(EXIT_FAILURE);
}
