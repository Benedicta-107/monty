#include "monty.h"
/**
* go_to- bride to the stack operations
* @stack: pointer to the struct
* @ln: line number
* Return: void
*/
void go_to(stack_t **stack, unsigned int ln)
{
	unsigned int i;
	char *tryr;

	instruction_t opst[] = {
				{"push", push_me},
				{"pall", pall_me},
				{"pint", pint_me},
				{"pop", pop_me},
				{"swap", swap_me},
				{"add", add_me},
				{"nop", nop_me},
				{"sub", subtract_me},
				{"div", divide_me},
				{"mul", multiply_me},
				{"mod", mod_me},
				{"pchar", print_me},
				{"pstr", printx_me},
				{"rotl", rotl},
				{NULL, NULL}
				};

	tryr = strtok(varx.buffer, " \n\t\a");
	if (tryr == NULL || tryr[0] == '#')
		return;

	i = 0;
	while (opst[i].opcode != NULL)
	{
		if (tryr != NULL && strcmp(opst[i].opcode, tryr) == 0)
		{
			opst[i].f(stack, ln);
			return;
		}
		i++;
	}
	if (opst[i].opcode == NULL)
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, tryr);
		clean_stack(*stack);
		clean_all();
		exit(EXIT_FAILURE);
}
