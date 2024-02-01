#include "monty.h"

/**
 * rotl_function - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 * Return: void
 */
void rotl_function(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *new_top;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		new_top = (*stack)->next;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = *stack;
		(*stack)->prev = last;
		(*stack)->next = NULL;

		*stack = new_top;
		new_top->prev = NULL;
	}
}
