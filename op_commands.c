#include "monty.h"
int value;
/**
 * op_commands - function to handle the opcode
 * @stack: is a stack or queue
 * @t1 : line
 * @t2 : line
 * @line_number: int
 * Return: int
 */
int op_commands(stack_t **stack, char *t1, char *t2, unsigned int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(t1, op[i].opcode))
		{
			if (!strcmp(t1, "push"))
			{
				if (t2 != NULL && _isdigit(t2) == 1)
					value = atoi(t2);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int) line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, t1);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	return (0);
}
