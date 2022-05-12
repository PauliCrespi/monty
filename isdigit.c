#include "monty.h"

/**
 *_isdigit - checking for a digit
 *@c : input
 *Return: 1 if digit, 0 if else
 */
int _isdigit(char *c)
{
	char *string = c;

	if (c == NULL)
		return (0);
	if (*string == '-')
		string++;
	for (; *string != '\0'; string++)
	{
		if ((*string < '0' || *string > '9'))
		{
			return (0);
		}
	}
	return (1);
}
