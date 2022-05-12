#include "monty.h"
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
	int l_num = 1, found = 0;

	file = fopen(argv, "r");
	if (file)
	{
		for (l_num = 1; (getline(&line, &len, file) != -1); l_num++)
		{
			token1 = strtok(line, " \t\n");
			if (token1 == NULL || token1[0] == '#')
				continue;
			token2 = strtok(NULL, " \t\n");
			found = op_commands(&stack, token1, token2, l_num);
			if (found == 1)
			{
				free(line);
				fclose(file);
				push_error(stack, l_num);
			}
		}
		free(line);
		free_list(stack);
		fclose(file);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
