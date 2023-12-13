#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pchar - Prints the char at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecodes file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}
