#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecodes file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;

		while (last->next)
			last = last->next;

		*stack = first->next;
		(*stack)->prev = NULL;

		first->next = NULL;
		first->prev = last;
		last->next = first;
	}
}
