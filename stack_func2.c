#include "monty.h"

/**
 * ynop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void ynop(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}


/**
 * swap_node - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void swap_node(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lineNumber, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void add_node(stack_t **stack, unsigned int lineNumber)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lineNumber, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void sub_node(stack_t **stack, unsigned int lineNumber)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, lineNumber, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_node - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void div_node(stack_t **stack, unsigned int lineNumber)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, lineNumber, "div");

	if ((*stack)->n == 0)
		more_err(9, lineNumber);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
