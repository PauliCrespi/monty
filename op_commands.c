/**
 * get_opc - function to handle the opcode
 * @stack: is a stack or queue
 * @token : line
 * @count: is a line command
 * Return: nothing
 */
int op_comands(stack_t **stack, char **token, int count)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"nop", _nop},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(token[0], op[i].opcode))
		{
			if (!strcmp(token[0], "push"))
			{
				if (_isdigit(token[1]) == 1)
					value = atoi(token[1]);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
