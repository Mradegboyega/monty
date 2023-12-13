#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * execute_opcode - Executes an individual opcode.
 * @opcode: The opcode to execute.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the opcode is called.
 * @argument: Argument associated with the opcode.
 */
void execute_opcode(const char *opcode, stack_t **stack, unsigned int line_number, const char *argument)
{
	if (strcmp(opcode, "push") == 0)
	{
		char *arg_copy = argument ? _strdup(argument) : NULL;
		if (arg_copy != NULL)
		{
			push(stack, line_number, arg_copy);
		}
		else
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number, NULL);
	}
	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
