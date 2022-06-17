#include "monty.h"
#include <stddef.h>

/**
 * addNode - function to add node to a stack
 * @stack: pointer to the nodes
 * @n: new node data value(int).
 * Return: address of new node)
 */

void addNode(stack_t **stack, unsigned int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newNode);
	}

	newNode->n = n;
	newNode->prev = NULL;

	if (!(*stack))
	{
		newNode->next = NULL;
		(*stack) = newNode;
	}
	(*stack)->prev = newNode;
	newNode->next = (*stack);
	(*stack) = newNode;
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

void add_qnode(stack_t **stack, unsigned int n)
{
	stack_t *newNode;
	stack_t *temp;

	temp = *stack;
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
	}

	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	temp = newNode;
}
