#include "monty.h"

/**
 * push - function to add node to a stack
 * @stack: pointer to node
 * @line_number: the line count
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	/* test if int argumment is integer or no arg is pass */
	if (isdigit(argument.arg) == 0)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* test stack default */
	if (arguments.n_dataStruct == 1)
	{
		addNode(stack, atoi(line_number));
		if (addNode(stack, atoi(line_number)) == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
}
