#include "monty.h"

/**
 * printx_me - prints the string starting at the top of the stack
 * @stack: pointer to the struct
 * @ln : line numbers
 * Return: void
**/

void printx_me(stack_t **stack, unsigned int ln)
{
	stack_t *temp;
	(void) ln;

	temp = *stack;
	if ((*stack) == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
