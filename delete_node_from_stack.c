#include "monty.h"
/**
 * delete_node - delete fnode from linked list
 * @stack: pointer to the structure
 * Return: 1 if sucess, 0 if fail
 */

int delete_node(stack_t **stack)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
		return (0);
	*stack = (*stack)->next;
	free(temp);
	return (1);
}
