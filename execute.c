#include "monty.h"
#include <stdio.h>
/**
  * execute_monty_file - function that executes the monty file
  * @file: The file to read from
  *
  * Return: void
  */
void execute_monty_file(FILE *file)
{
	char *line, *opcode;
	size_t size = 0, length;
	ssize_t line_read = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	while (line_read > 0)
	{
		line = NULL;
		line_read = getline(&line, &size, file);
		bus.line = line;
		counter++;

		if (line_read > 0)
		{
			opcode = strtok(line, " \t\n");

			if (opcode != NULL)
			{
				length = strlen(opcode);
				if (length > 0 && opcode[length - 1] == '$')
				opcode[length - 1] = '\0';
				execute_opcode(opcode, &stack, counter);
			}
		}
		free(line);
	}
	free_stack(stack);
}

/**
  * execute_opcode - function that executes monty bytecode based on  the opcode
  * @opcode: The opcode of the Monty instruction.
  * @stack: A pointer to the head of the stack.
  * @line_number: line number in the Monty file where the instruction appear
  *
  * Return: void
  */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	if (opcode && opcode[0] == '#')
		return;/* ignore comments */
	bus.arg = strtok(NULL, " \n\t");

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			/*free(bus.arg);*/
			return; /* found and executed the opcode */
		}
	}
	if (opcode && instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		/*fclose(bus.file);
		free(bus.arg);
		free_stack(*stack);*/
		exit(EXIT_FAILURE);
	}
	free(bus.arg);
}
