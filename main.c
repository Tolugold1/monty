#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

	while (fgets(line, sizeof(line), file))
	{
		string = strtok(line, " \t");
		if (string[0] == '#')
		{
			(void)stack;
			(void)line_number;
		}
		else if (string[0] != '\n')
			fetch_ops(&stack, string, line_number)(&stack,
					line_number);
		line_number++;
	}
	freeStack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * fetch_ops - the function to be called
 * @stk: pointer to node
 * @s: the string to compare in order to know
 * maybe it stack or queue that'll be solve
 * @line: the line number
 * Return: nothing
 */

void (*fetch_ops(stack_t **stk, char *s, int line))(stack_t **, unsigned int)
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
		for (j = 0; j < strlen(s); j++)
		{
			if (s[j] == '\n')
				s[j] = '\0';
		}
		if (strcmp(ops[i].opcode, s) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, s);
	freeStack(stk);
	exit(EXIT_FAILURE);
}
