#include "monty.h"

/**
 * mod_function - compute modulus of second top element by top element of stack
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 * Return: void
 */
void mod_function(stack_t **stack, unsigned int line_number)
{
	int mod;
	stack_t *h;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;

	h = *stack;
	*stack = (*stack)->next;
	(*stack)->n = mod;
	(*stack)->prev = NULL;

	free(h);
}
