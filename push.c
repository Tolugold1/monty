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
		addNode(stack, atoi(access.arg));
		if (!addNode(stack, atoi(access.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		add_qnode(stack, atoi(access.arg));
		if (!add_qnode(stack, atoi(access.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

