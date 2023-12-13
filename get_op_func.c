#include "monty.h"
#include "string.h"

/**
 * get_op_func - Selects the correct function to perform the operation.
 * @s: Opcode to perform.
 *
 * Return: Pointer to the correct function, or NULL if not found.
 */
void (*get_op_func(char *s))(stack_t **, unsigned int, char *)
{
	int i;
	op_t ops[] = {
		{"push", push},
		{"pall", pall},
		/* Add more operations as needed */
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].op_func);
	}

	return (NULL);
}
