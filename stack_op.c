#include "monty.h"

/**
 * mul_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void mul_node(stack_t **stack, unsigned int lineNumber)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lineNumber, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void mod_node(stack_t **stack, unsigned int lineNumber)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, lineNumber, "mod");


	if ((*stack)->n == 0)
		more_err(9, lineNumber);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
