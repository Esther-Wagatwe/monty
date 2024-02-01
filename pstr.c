#include "monty.h"
/**
 *  pstr_function - print the string starting at the top of the stack
 * @stack: *head pointer
 * @line_number: the line number
 * Return: void
 */

void pstr_function(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL && current->n != 0 && current->n <= 126)
	{
		printf("%c", (char)(current->n));
		current = current->next;
	}
	printf("\n");
}
