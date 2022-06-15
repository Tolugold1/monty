#include "monty.h"

/**
 * pall - function that prints all the
 * values on the stack
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number __atribute__((unused)))
{
	print_all_stack(*stack);
}
