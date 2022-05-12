#include "main.h"
int value;
/**
 * op_commands - function to handle the opcode
 * @stack: is a stack or queue
 * @token1 : line
 * @line_number: int
 * Return: int
 */
int op_commands(stack_t **stack, char *token1, unsigned int line_number)
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
		if (!strcmp(token1, op[i].opcode))
		{
			op[i].f(stack, (unsigned int) line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
