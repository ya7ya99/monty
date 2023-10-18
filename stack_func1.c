#include "monty.h"


/**
 * add_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * printf_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: line number of  the opcode.
 */
void printf_stack(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	(void) lineNumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_ - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void pop_(stack_t **stack, unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, lineNumber);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * printF_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNumber: Interger representing the line number of of the opcode.
 */
void printF_top(stack_t **stack, unsigned int lineNumber)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, lineNumber);
	printf("%d\n", (*stack)->n);
}
