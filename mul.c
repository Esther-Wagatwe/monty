#include "monty.h"

/**
 * mul_function - multipy the second top element with the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 * Return: void
 */
void mul_function(stack_t **stack, unsigned int line_number)
{
	int mul;
	stack_t *h;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->next->n * (*stack)->n;

	h = *stack;
	*stack = (*stack)->next;
	(*stack)->n = mul;
	(*stack)->prev = NULL;

	free(h);
}
