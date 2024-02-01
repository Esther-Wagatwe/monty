#include "monty.h"

void swap_function(stack_t **stack, unsigned int line_number)
{
	int head;	

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	head = (*stack)->n;
	(*stack)->n = (*stack)->n;
	(*stack)->n = head;
}
