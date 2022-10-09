#include "monty.h"

/**
 * create_node_stack - crreate a node stack
 * @stack - pointer to the top of the stack
 * @n - the value being added
 * Return: the node
 */

stack_t *create_node_stack(stack_t **stack, int n)
{
	stack_t *newnode_stack;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		stderr_malloc();
	newnode_stack-> = n;
	newnode_stack->next = *stack;
	newnode_stack->prev = NULL;
	*stack = newnode_stack;
	return (newnode_stack);
}

/**
 * create_node_stack_end - create a node at the end of the stack
 * @stack- a pointer to the end of the stack
 * @n : value being added to the stack
 * Return: the node
 */

stack_t *create_node_stack_end(stack_t **stack, int n)
{
	stack_t *newnode_stack;
	stack_t *temp;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		stderr_malloc();
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode_stack;
	newnode_stack->n = n;
	newnode_stack->prev = temp;
	newnode_stack->next = NULL;
	return (newnode_stack);
}

/**
 * add_nodeint - adds the new node at the beginning of the list
 * @head: pointer to the first of the list
 * @n: integer
 * Return: the pointer to a new node
 */
stack_t *add_nodeint(stack_t **head, int n)
{
	stack_t *newnode = NULL;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return(newnode);
	}
	newnode->n = n;
	(*head)->prev = newnode;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}

/**
 * free_node_stack- frees a stack_t stack
 * @stack: pointer to the top or bottom of the stack
 *
 */

void free_node_stack(stack_t **stack)
{
	stack_t *temp_node = *stack;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;}
}

/**
 * check opcode- checks if it is a stack or queue
 * @stack: pointer to the stack
 * Return: the value of stack or queue
 */

int check_opcode(stack_t *stack)
{
	int ret_val = 2;

	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (ret_val);
}
