#include "monty.h"

/**
 * push - function to add to stack
 * @stack: pointer to node
 * @line_number: the line number
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	if ((isdigit(access.arg)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (access.n_dataStruct == 0)
	{
		if (!addNode(stack, atoi(access.arg)))
		{
			exit(EXIT_FAILURE);
		}
		addNode(stack, atoi(access.arg));
	}
	else
	{
		if (!add_qnode(stack, atoi(access.arg)))
		{
			exit(EXIT_FAILURE);
		}
		add_qnode(stack, atoi(access.arg));
	}
}
