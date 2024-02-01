#include "monty.h"

/**
 * div_function - divide the second top element by the top element of the stack
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 * Return: void
 */
void div_function(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;

	h = *stack;
	*stack = (*stack)->next;
	(*stack)->n = div;
	(*stack)->prev = NULL;

	free(h);
}
