#include "monty.h"
/**
 * mulNodes - mul top 2 elements of the stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void mulNodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_ii(8, line_number, "mul");
	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modNodes - mod the top 2 elements of the stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void modNodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_ii(8, line_number, "mod");
	if ((*stack)->n == 0)
		error_ii(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
