#include "monty,h"
global_var  var_global;

/** main - the function the monty program is based
 * @ac: integre number of arguements 
 * @av: opcode file
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(sterr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);

	free_dlistint(stack);
	return(0);
}
