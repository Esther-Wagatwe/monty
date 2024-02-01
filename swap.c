#include "monty.h"

/**
 * swap_function - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 * Return: void
 */
void swap_function(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
