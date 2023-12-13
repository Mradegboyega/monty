#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * div_stack - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the current opcode.
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
}
