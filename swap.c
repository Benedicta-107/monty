#include "monty.h"
/**
  * swap_me - swap two top nodes in stack
  * @stack: pointer to first elm of the stack
  * @ln: instruction line in case of error
  */

void swap_me(stack_t **stack, unsigned int ln)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}

	temp1 = *stack;
	temp2 = (*stack)->next;
	if (temp2->next != NULL)
	{
		temp1->next = temp2->next;
		temp1->prev = temp2;
		temp2->next = temp1;
		temp2->prev = NULL;
		*stack = temp2;
	}
	else
	{
		temp2->next = *stack;
		temp2->prev = NULL;
		temp1->prev = temp2;
		temp1->next = NULL;
		*stack = temp2;

	}
}
