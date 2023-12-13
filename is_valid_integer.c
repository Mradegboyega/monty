#include "monty.h"
#include <ctype.h>

/**
 * is_valid_integer - Checks if a string represents a valid integer.
 * @str: The string to check.
 * Return: 1 if a valid integer, 0 otherwise.
 */
int is_valid_integer(const char *str)
{
	if (!str || *str == '\0')
		return (0);

	while (isspace(*str))
		str++;

	if (*str == '-' && !isdigit(*(str + 1)))
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
