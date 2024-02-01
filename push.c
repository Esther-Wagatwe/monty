#include "monty.h"

/**
  * push_function - function that adds an element to a stack
  * @head: pointer to the head
  * @line_number: number of the line
  * Return: void
  */
void push_function(stack_t **head, unsigned int line_number)
{
	int num; /*i = 0flag = 0;*/

	if (!bus.arg || (bus.arg[0] != '-' && !isdigit(bus.arg[0])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.arg);
	if (bus.sq_flag == 0)
		add_node(head, num);
	else
		add_queue(head, num);
}
