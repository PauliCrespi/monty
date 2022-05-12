#include "monty.h"
/**
 * free_list - Free list.
 * @stack: stack
 */
void free_list(stack_t *stack)
{
	stack_t *aux = NULL;

	aux = stack;

	if (aux != NULL)
	{
		free_list(aux->next);
		free(aux);
	}
}
/**
 * free_stack - Frees **stack
 * @stack: Stack
 */
void free_stack(stack_t **stack)
{
	stack_t *aux = *stack;

	for (; aux; aux = *stack)
	{
		*stack = (*stack)->next;
		free(aux);
	}
}
/**
 * push_error - handle push error
 * @stack: is a stack
 * @line_num: int
 */
void push_error(stack_t *stack, int line_num)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
	free_list(stack);
	exit(EXIT_FAILURE);
}

/**
 * ins_error - Error handler
 * @stack: stack
 * @line_num: int
 */
void ins_error(stack_t *stack, int line_num)
{
	dprintf(STDERR_FILENO, "L%d: unknown instruction %d\n", value, line_num);
	free_list(stack);
	exit(EXIT_FAILURE);
}
