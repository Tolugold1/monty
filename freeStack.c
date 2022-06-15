#include "monty.h"

/**
 * free - function to free node
 * @stack: pointer to the node
 * Return: none
 */

void free(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
