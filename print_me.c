#include "monty.h"

/**
 * print_me - print the char at the top of stack
 * @stack: pointer to the struct
 * @ln : line numbers
 * Return: void
**/

void print_me(stack_t **stack, unsigned int ln)
{


	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
