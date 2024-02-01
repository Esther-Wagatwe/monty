#include "monty.h"

/**
  * pint_function - a function that prints all the elements
  * @stack: pointer to the head pointer
  * @line_number: number of the line
  * Return: void
  */
void pint_function(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
