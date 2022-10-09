#include "monty.h"

/**
 * push - pushes int to a stack
 * @stack: linked lists for the monty stack
 * @line_number: number of line opcodes occur
 */

void push(stack_t **stack, __attriute__((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * pall -prints values in the stack
 * @stack - this is a pointer to the linked list
 * @line_number: the number of the line opcode
 */

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *p;

	p = *stack;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * pint -prints the value at the top of the stack
 * @stack: pointer to the linked list stack
 * @line_number - the number of the line opcode
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	p = *stack;
	if(p == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	       exit(EXIT_FAILURE);
	}
	printf("%d\n", p->n);
}

/**
 * pop - removes the top element of the stack
 * @stack - pointer to the head node
 * @line_number- numberline opcode occurs
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if(*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * swap - swap top two elements of the stack
 * @stack: pointer to lists for the stack
 * @line_number: number of line opcode
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	int tmp;

	p = *stack;
	if (p == NULL || p->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = p->n;
	p->n = p->next->n;
	p->next->n = tmp;
}
