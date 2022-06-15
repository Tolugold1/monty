#include "monty.h"

/**
 * print_all_stack - function to print all nodes
 * @stack: pointer to the node
 * Return: number of nodes
 */

size_t print_all_stack(const stack_t *stack)
{
	size_t i = 0;

	if (!stack)
	{
		return (0);
	}
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		i++;
	}
	return (i);
}
