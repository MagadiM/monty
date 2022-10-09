#include "monty.h"

/**
 * mod - computes the rest of the division of the stack
 * @stack: pointer to the linked list stack
 * @line_number: number of lines opcodes
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int mode = 0;

	if(*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
		mod = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n %= mod;
	}
}

/**
 * pchar - prints a string ASCII value at the top of the stack
 * @stack: pointer to the linked list stack
 * @line_number: the index of the current line
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * pstr - prints the string at the top of the stack
 * @stack: pointer to linked list
 * @line_number: number of line opcode
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the stack at the top
 * @stack: pointer to the linked list
 * @line_number: number of line opcode
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;


	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = p->n;

	while (p->next)
	{
		p = runner->next;
		p->prev->n = p->n;
	}

	p->n = aux1;
}

/**
 * rotr - rotates the stack at the bottom
 * @stack: pointer to linked list
 * @line_number: number of line opcode
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (p->next)
		p = p->next;

	aux1 = p->n;

	while (p->prev)
	{
		p = p->prev;
		p->next->n = p->n;
	}

	p->n = aux1;
}
