#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack - points to the linked list for the stack
 * @line_number: number of line opcodes
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if(tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * nop - it doesn't do anything
 * @stack - pointer to linked lists
 * @line_number: number of line opcodes
 */

void nop(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	;
}

/**
 * sub - subtacts the top elements of stack
 * @stack: pointer to the linked lists
 * @line_number: number of line opcodes
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);

	(*stack)->n = sub;
}

/**
 * div - divides the second top element by the top element of the stack
 * @stack: pointer to linked lists
 * @line_number: the number of line opcodes
 */

void div(stack_t **stack, unsigned int line_number)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n /= div;
	}
}

/**
 * mul - multiplies the top elements of the stack
 * @stack: pointer to the linked list
 * @line_number: number of line opcode
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n *= aux;
	}
}
