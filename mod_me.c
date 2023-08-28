#include "monty.h"
/**
  * mod_me - divide the top two elements of the stack.
  * @stack: pointer to first elm of the stack
  * @ln: instruction line in case of error
  */
void mod_me(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n %= temp->n;
	pop_me(stack, ln);
}
