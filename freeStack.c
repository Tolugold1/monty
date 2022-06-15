#include "monty.h"

/**
 * freeStack - function to free node
 * @stack: pointer to the node
 * Return: none
 */

void freeStack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
