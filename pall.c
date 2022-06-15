#include "monty.h"

/**
 * pall - function to print all node
 * @stack: pointer to the nodes
 * @line_number: line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_all_stack(*stack);
}
