#include "monty.h"

/**
 * push_me - stack pushing operation
 * @stack: pointer to the struct
 * @ln : line numbers
 * Return: void
**/

void push_me(stack_t **stack, unsigned int ln)
{
	int powre;
	char *pow;
	stack_t *node;

	pow = strtok(NULL, " \n\t\a");

	if (pow == NULL || check_dig(pow) < 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}
	powre = atoi(pow);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed)");
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
	}

	node->n = powre;
	node->next = NULL;
	node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = node;
		node->next = *stack;
	}

	*stack = node;

}
