#include "monty.h"

/**
  * pop_function - function that removes the top element of the stack
  * @stack: pointer to the head pointer
  * @line_number: the number of the line
  *
  * Return: void
  */
void pop_function(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	}
	head = *stack;
	*stack = (*stack)->next;
	free(head);
}
