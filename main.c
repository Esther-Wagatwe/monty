#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

instruction_t instructions[] = {
	{"push", push_function},
	{"queue", queue_function},
	{"pall", pall_function},
	{"pint", pint_function},
	{"swap", swap_function},
	{"pop", pop_function},
	{"add", add_function},
	{"nop", nop_function},
	/* Add more instructions as needed */
	{NULL, NULL}
};

/**
  * main - monty bytecode operator
  * @argc: Argument count
  * @argv: Argument vector
  * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
  */

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute_monty_file(file);

	fclose(file);

	return (EXIT_SUCCESS);
}
