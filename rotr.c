#include "monty.h"
/**
  *rotr_function - rotates the stack to the bottom
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void rotr_function(stack_t **stack, unsigned int line_number)
{
	stack_t *cpy;
	(void)line_number;

	cpy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *stack;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*stack)->prev = cpy;
	(*stack) = cpy;
}
