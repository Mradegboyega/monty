#include "monty.h"
#include <stdlib.h>

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number); /* Remove the top element */
}
