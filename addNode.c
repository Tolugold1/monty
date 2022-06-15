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
		return NULL;

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
