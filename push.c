#include "monty.h"

/**
 * push - function to add to stack
 * @stack: pointer to node
 * @line_number: the line number
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	if ((isdigit(arguments.arg)) == 0)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (arguments.n_dataStruct == 1)
	{
		addNode(stack, atoi(line_number));
		if (addNode(stack, atoi(line_number)) == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
}
