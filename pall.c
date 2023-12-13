#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the pall operation is called.
 * @ignored: Ignored argument for compatibility with the op_t struct.
 */
void pall(stack_t **stack, unsigned int line_number, char *ignored)
{
	stack_t *current;  /* Declare here to comply with ISO C90 */

	(void)ignored;  /* Unused parameter, suppress the warning */

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	(void)line_number;  /* Unused parameter, suppress the warning */
}
