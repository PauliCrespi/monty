#include "main.h"
/**
 *main - main
 *@argc : int
 *@argv : pointer array
 *Return: int
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		command_interpreter(argv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 *command_interpreter - main
 *@argv : pointer
 */
void command_interpreter(char *argv)
{
	FILE *file;
	char *token1 = NULL, *token2 = NULL, *line;
	size_t len = 0;
	stack_t *stack = NULL;
	int l_num = 1;
	int found = 0;

	file = fopen(argv, "r");
	if (file)
	{
		for (l_num = 1; (getline(&line, &len, file) != -1); l_num++)
		{
			token1 = strtok(line, " \t\n");
			if (token1 == NULL || token1[0] == '#')
			{
				continue;
			}
			token2 = strtok(NULL, " \t\n");
			if (token2 != NULL && _isdigit(token2) == 1)
				value = atoi(token2);
			found = op_commands(&stack, token1, l_num);
			if (found == 1)
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", l_num);
			else if (found == 2)
				dprintf(STDERR_FILENO, "L%s: unknown instruction %d\n", token2, l_num);
		}
		free(line);
		free(stack);
		fclose(file);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
