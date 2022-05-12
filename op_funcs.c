#include "main.h"
int value;
/**
 *create_node - node creator
 *@n : int
 *Return: node
 */
stack_t *create_node(int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}
/**
 *_push - push func
 *@stack : stack
 *@line_number : int
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	(void)line_number;

	newnode = create_node(value);
	newnode->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = newnode;
	*stack = newnode;
}
/**
 *_pall - pall func
 *@stack : stack
 *@n : int
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *node;
	(void)n;

	node = *stack;
	while (node != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", node->n);
		node = node->next;
	}
}
/**
 *_pint - print first node func
 *@stack : stack
 *@n : int
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
        }
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pop - removes first element  of the stack.
 * @stack: Stack 
 * @line_number: Number line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	aux = *stack;

	*stack = aux->next;
	if (aux->next != NULL)
		aux->next->prev = aux->prev;
	free(aux);
}
