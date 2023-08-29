#include "monty.h"
/**
  * subtract_me - adds the top two elements of the stack.
  * @stack: pointer to first elm of the stack
  * @ln: instruction line in case of error
  */
void subtract_me(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n -= temp->n;
	pop_me(stack, ln);
}
