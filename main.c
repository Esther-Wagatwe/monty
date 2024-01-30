#include "monty.h"

/**
  * main - monty bytecode operator
  * @argc: Argument count
  * @argv: Argument vector
  * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
  */

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LEN];
	char *opcode, *argument;
	size_t length;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n" argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		length = strlen(line);
		if (length > 0 && line[length - 1] == '\n')
			line[length - 1] = '\0';

		opcode = strtok(line, " \t\n");
		argument = strtok(NULL, " \t\n");

		if (opcode != NULL)
		{
			printf("Opcode: %s, Argument: %s\n", opcode, argument ? argument : "None");
		}
	}

	fclose(file);

	return (EXIT_SUCCESS);
}
