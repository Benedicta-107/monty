#ifndef MONTY_H
#define MONTY_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#include<fcntl.h>
#include<sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var - global variables container
 * @buffer: Memory storage area
 * @fd: file Descriptor for inpu
 * Description: a struct containing variables to
 * all the program functions(easy access).
 */

struct var
{
	char *buffer;
	FILE *fd;
} var;

struct var varx;

void push_opt(stack_t **, unsigned int);
void pall_opt(stack_t **, unsigned int);
void go_to(stack_t **stack, unsigned int ln);
void free_nodes(stack_t *);
int add_node(stack_t **head, int n);
int is_digit(char *);
void push_me(stack_t **stack, unsigned int ln);
int check_dig(char *s);
void pall_me(stack_t **stack, unsigned int ln);
void clean_stack(stack_t *stack);
void clean_all(void);
void pint_me(stack_t **stack, unsigned int ln);
void pop_me(stack_t **stack, unsigned int ln);
int delete_node(stack_t **stack);
void swap_me(stack_t **stack, unsigned int ln);
void add_me(stack_t **stack, unsigned int ln);
void nop_me(stack_t **stack, unsigned int ln);
void subtract_me(stack_t **stack, unsigned int ln);
void divide_me(stack_t **stack, unsigned int ln);
void multiply_me(stack_t **stack, unsigned int ln);
void mod_me(stack_t **stack, unsigned int ln);
void print_me(stack_t **stack, unsigned int ln);
void printx_me(stack_t **stack, unsigned int ln);
void rotl(stack_t **stack, unsigned int ln);
#endif
