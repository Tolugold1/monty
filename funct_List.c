#include "monty.h"
#include <stddef.h>

/**
 * addNode - function to add node to a stack
 * @stack: pointer to the nodes
 * @n: new node data value(int).
 * Return: address of new node)
 */

stack_t *addNode(stack_t **stack, unsigned int n)
{
	stack_t *newNode;
	if (!stack)
		return NULL;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		dprintf(2, "Error: malloc failed\n");
		free(newNode);
		return NULL;
	}

	newNode->n = n;
	newNode->prev = NULL;

	if (!(*stack))
	{
		newNode-next = NULL;
		*stack = newNode;
		return (newNode);
	}
	(*stack)->prev = newNode;
	newNode->next = (*stack);
	(*stack) = newNode;
	return (newNode);
}

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
