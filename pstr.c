#include "monty.h"
#include <stdio.h>

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecodes file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
