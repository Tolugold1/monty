#include "monty.h"

/**
 * pall - function to print all node
 * @stack: pointer to the nodes
 * @line_number: line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
