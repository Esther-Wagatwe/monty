#include "monty.h"

/**
 * sub_function - subtracts the top element from the second top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 * Return: void
 */
void sub_function(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;

	h = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sub;
	(*stack)->prev = NULL;

	free(h);
}
