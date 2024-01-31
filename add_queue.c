#include "monty.h"

/**
 * queue_function - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void queue_function(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.sq_flag = 1;
}


/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new, *h;

	h = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		printf("Error\n");
	new->n = n;
	new->next = NULL;

	if (h)
	{
		while (h->next)
			h = h->next;
	}
	if (!h)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		h->next = new;
		new->prev = h;
	}
}
