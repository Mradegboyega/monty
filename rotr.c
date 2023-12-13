#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode in the Monty bytecode file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number; /* Unused parameter */

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		while (last->next != NULL)
		{
			last = last->next;
		}

		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
