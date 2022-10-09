#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

extern int push_arg;

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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
}instruction_t;

/**
 * struct global_variable - the struct contains global variables
 * @token2: integer
 * @line_buf: points to the next lement of the stack or queue
 * @fd: it points to the previous element of the queue or stack
 *
 * Description: doubly linked list node structure 
 */
typedef struct global_variable
{
	char token2;
	FILE *fd;
	char *line_buf;
} global_var;

extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);
typedef void(*instruct_func)(stack_t **stack, unsigned int line_number);

/*Functions*/
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void rot1(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/*math functions*/
void sub(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/*string functions*/
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/*utility functions*/
void free_dlistint(stack_t *head);
int _isalpha(int c);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);

#endif
