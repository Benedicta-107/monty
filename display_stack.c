#include "monty.h"
/**
 * pall_me - display the stack
 * @stack: pointer to the stack
 * @ln: line numbers
**/
void pall_me(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack;
	(void)ln;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	free(temp);
	temp = NULL;
}

/**
  * pint_me - print from top of the stack
  * @stack: pointer to stack
  * @ln: number of lines
  */
void pint_me(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
  * pop_me - remove from top the stack
  * @stack: pointer to stack
  * @ln: instruction line in case of error
  */
void pop_me(stack_t **stack, unsigned int ln)
{
	if (delete_node(stack) == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}
}
