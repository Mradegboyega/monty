#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * execute_monty - Executes Monty bytecode from a file.
 * @file: Pointer to the file containing Monty bytecode.
 */
void execute_monty(FILE *file)
{
	stack_t *stack = NULL;
	char line[256];
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *opcode;
		char *argument;

		line_number++;

		/* Parse the line and extract opcode and arguments */
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || *opcode == '#')
			continue;

		argument = strtok(NULL, " \t\n");

		/* Call the corresponding function based on the opcode */
		execute_opcode(opcode, &stack, line_number, argument);
	}

	free_stack(stack);
	fclose(file);
}
