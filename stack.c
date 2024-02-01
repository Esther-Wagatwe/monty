#include "monty.h"
/**
 * stack_function - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */
void stack_function(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	bus.sq_flag = 0;
}
