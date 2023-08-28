#include "monty.h"
/**
 *rotl - rotates the stack to the top.
 *
 *@stack: pointer to the first element of the stack
 *@ln: cont the number of ech line
 *
 */
void rotl(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack;

	if (!stack || !*stack)
		return;

	while (temp->next)
	{
		swap_me(&temp, ln);
		temp = temp->next;
	}

}
