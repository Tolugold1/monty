#include "monty.h"

/**
 * pint - print data at the top
 * @stack: pointer to node
 * @line_number: line number
 * Return: void
 */

void pint(stack_t **stack, unsigned in line_number)
{
	if (!(*stack))
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		globe = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}
