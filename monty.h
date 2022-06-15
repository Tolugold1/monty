#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *addNode(stact_t **stack, unsigned int n);
size_t print_all_stack(const stack_t *stack);
void freeStack(stack_t *stack);

extern int globe;

/**
 * struct assist - argument for the opcode
 * @n_dataStruct: stack default mode
 * @arg: the string argument
 *
 * Description: global structure used to pass
 * data around the functions
 */
typedef struct assist
{
	int n_dataStruct;
	char *arg;
} arguments;

void arg_error(void);
void file_err(char *argv);


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

#endif
