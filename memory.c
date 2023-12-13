#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	size_t len;
	char *dup_str;

	if (!str)
		return (NULL);

	len = strlen(str);
	dup_str = malloc(len + 1);

	if (!dup_str)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	strcpy(dup_str, str);
	return (dup_str);
}

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current, *next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
