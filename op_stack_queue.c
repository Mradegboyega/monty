#include "monty.h"

/**
 * op_stack - Set the stack mode to stack (LIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the instruction in the Monty file
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    stack_mode = STACK;
}

/**
 * op_queue - Set the stack mode to queue (FIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the instruction in the Monty file
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    stack_mode = QUEUE;
}

