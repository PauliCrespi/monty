#include "monty.h"
int value;
/**
 * _swap - swaps top two elements of the stack.
 * @stack: Stack
 * @line_number: Number line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int var = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	var = aux->n;
	aux->n = aux->next->n;
	aux->next->n = var;
}
/**
 * _add - addition
 * @stack: Stack list
 * @line_number: Number line
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	sum = aux->n + aux->next->n;
	aux->next->n = sum;
	_pop(stack, line_number);
}
/**
 * _nop - function void
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * _pint - prints top tack.
 * @stack: stack
 * @line_number: Number line
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
