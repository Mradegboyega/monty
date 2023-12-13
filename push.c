#include "monty.h"
#include <stdlib.h>

/**
 * push - Pushes an element onto the stack or queue.
 * @stack: Pointer to the top of the stack or front of the queue.
 * @line_number: Line number where the push operation is called.
 * @data: Array containing the opcode and argument.
 */
void push(stack_t **stack, unsigned int line_number, char *data)
{
	stack_t *new_node;

	if (!data || !data[0] || !is_valid_integer(data))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(data);
	new_node->prev = NULL;

	if (stack_mode == STACK)  /* Stack mode (LIFO) */
	{
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;

		*stack = new_node;
	}
	else if (stack_mode == QUEUE)  /* Queue mode (FIFO) */
	{
		new_node->next = NULL;

		if (!*stack)  /* If the queue is empty */
		{
			*stack = new_node;
		}
		else
		{
			stack_t *temp = *stack;

			while (temp->next)
			{
				temp = temp->next;
			}

			temp->next = new_node;
			new_node->prev = temp;
		}
	}
}
