#include "monty.h"

/**
 * pall_function - function that prints all contents of the stack
 * @head: stack head
 * @line_number: the line number of the bytecode
 * Return: void
*/
void pall_function(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
