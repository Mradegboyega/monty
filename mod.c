#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mod_stack - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the current opcode.
 */
void mod_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
}
