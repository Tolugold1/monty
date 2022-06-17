#include "monty.h"

/**
 * push - function to add to stack
 * @stack: pointer to node
 * @line_number: the line number
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char str[128] = "";
	char *string = str;
	int var;
	unsigned int i;

	access.arg = strtok(NULL, " \t");
	if (string)
	{
		if (string[0] == '\n')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		for (i = 0; i < strlen(string); i++)
		{
			if (!isdigit(string[i]) && string[0] != '-' &&
					string[i] != '\n')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		var = atoi(string);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (access.n_dataStruct == 0)
	{
		addNode(stack, var);
	}
	else
	{
		add_qnode(stack, var);
	}
}
