#include "monty.h"

void add_function(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;

	head = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;
	(*stack)->prev = NULL;

	free(head);
}
