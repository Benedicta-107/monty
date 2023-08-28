#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

/**
 * struct Stack - A stack structure.
 * @data: An array to store stack elements.
 * @top: The index of the top element in the stack.
 */
typedef struct Stack {
    int data[STACK_SIZE];
    int top;
} Stack;

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the stack structure.
 * @value: The value to push onto the stack.
 */
void push(Stack *stack, int value)
{
	if (stack->top >= STACK_SIZE)
	{
		fprintf(stderr, "Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	stack->data[stack->top++] = value;
}

/**
 * pall - Prints all elements on the stack.
 * @stack: A pointer to the stack structure.
 */
void pall(Stack *stack)
{
    for (int i = stack->top - 1; i >= 0; i--)
    {
        printf("%d\n", stack->data[i]);
    }
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	
	Stack stack;
	stack.top = 0;

	char line[256];
	int line_number = 1;

	while (fgets(line, sizeof(line), file))
	{
		char *opcode = strtok(line, " \t\n");
		
		if (opcode == NULL)
			continue;
		
		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \t\n");
            if (arg == NULL || !isdigit(arg[0]))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                return EXIT_FAILURE;
            }
            push(&stack, atoi(arg));
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }

        line_number++;
    }

    fclose(file);

    return EXIT_SUCCESS;
}

