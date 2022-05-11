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
	char *line, **token = NULL;
	size_t len = 1024, *stack = NULL;
	int linenum = 1, found = 1;

	file = fopen(argv, "r");
	if (file)
	{
		for (linenum = 1; getline(&line, &len, file) != -1; linenum++)
		{
			token = tokenize(line, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (token[0] == '#')
				continue;
			found = op_commands(&stack, token, linenum);
			if (found != 0)
			{
				ERROR
			}
		}
		free(line);
		free(token);
		free(stack);
		fclose(file);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
