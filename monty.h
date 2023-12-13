#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Define your stack and queue constants */
#define STACK 0
#define QUEUE 1

extern int stack_mode;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct op_s - opcode and its corresponding function
 * @opcode: the opcode
 * @op_func: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct op_s
{
    char *opcode;
    void (*op_func)(stack_t **stack, unsigned int line_number, char *data);
} op_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, char *data);
void pall(stack_t **stack, unsigned int line_number, char *ignored);
void execute_monty(FILE *file);
void free_stack(stack_t *stack);
int is_valid_integer(const char *str);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
void mod_stack(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);
void (*get_op_func(char *s))(stack_t **, unsigned int, char *);
void execute_opcode(const char *opcode, stack_t **stack, unsigned int line_number, const char *argument);
void rotr(stack_t **stack, unsigned int line_number);
char *_strdup(const char *str);

#endif /* MONTY_H */
