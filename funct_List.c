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
		return (NULL);

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newNode);
		return (NULL);
	}

	newNode->n = n;
	newNode->prev = NULL;

	if (!(*stack))
	{
		newNode->next = NULL;
		(*stack) = newNode;
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

void freeStack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
		free(temp);
	}
}

/**
 * print_all_stack - function to print all nodes
 * @stack: pointer to the node
 * Return: number of nodes
 */

size_t print_all_stack(stack_t **stack)
{
	size_t i = 0;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
		i++;
	}
	return (i);
}

/**
 * add_qnode - function to add node to a queue
 * @stack: pointer to the nodes
 * @n: new node data value(int).
 * Return: address of new node)
 */

stack_t *add_qnode(stack_t **stack, unsigned int n)
{
	stack_t *newNode;

	if (!stack)
	{
		return (NULL);
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		free(newNode);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->next = NULL;

	if (!(*stack))
	{
		newNode->prev = NULL;
		(*stack) = newNode;
		return (newNode);
	}

	while ((*stack)->next)
	{
		(*stack) = (*stack)->next;
	}
	(*stack)->next = newNode;
	newNode->prev = (*stack);
	(*stack) = newNode;
	return (newNode);
}
