#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"
/**
* main - entry point
* @argc: instructions number
* @argv: instructions list
* Return: 0
*/

int main(int argc, char **argv)
{

	size_t size = 0;
	unsigned int ln = 1;
	stack_t *stack = NULL;

	varx.buffer = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	varx.fd = fopen(argv[1], "r");
	if (varx.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&varx.buffer, &size, varx.fd)) != -1)
	{
		go_to(&stack, ln);

		ln++;
	}
	clean_stack(stack);
	clean_all();
	return (0);
}
