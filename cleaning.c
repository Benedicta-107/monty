#include "monty.h"
/**
 * clean_stack - Memory leak management
 * @stack: pointer to the struct
 * Return: void
 *
**/

void clean_stack(stack_t *stack)
{
	stack_t *temp = stack;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
/**
 * clean_all - Memory Leak manageme
 *
 * Return: void
**/

void clean_all(void)
{
	fclose(varx.fd);
	free(varx.buffer);
}
