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
		fprintf(stderr, "L%u: cant pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
