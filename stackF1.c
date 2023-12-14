#include "monty.h"
/**
 * add_stack - adds a new node to stack
 * @new_node: pointer to new node
 * @ln: line number
 */
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_anyStack - print all of the stack
 * @stack: pointer to stack
 * @line_number: the line number
 */
void print_anyStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_T - removes the the element from the top
 * @stack: pointer to stack
 * @line_number: the line number
 */
void pop_T(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		error_ii(7, line_number);
	temp = *stack;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_T - print the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void print_T(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error_ii(6, line_number);
	printf("%d\n", (*stack)->n);
}
