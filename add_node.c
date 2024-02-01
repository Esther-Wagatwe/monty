#include "monty.h"

/**
 * add_node - adds a node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */

void add_node(stack_t **head, int n)
{
	stack_t *new, *h;

	h = *head;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (h)
		h->prev = new;

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	*head = new;
}
