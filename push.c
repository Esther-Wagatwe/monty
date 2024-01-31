#include "monty.h"

/**
  * push_function - function that adds an element to a stack
  * @head: pointer to the head
  * @line_number: number of the line
  * Return: void
  */
void push_function(stack_t **head, unsigned int line_number)
{
	int num, i = 0, flag = 0;

	printf("Before argument check: bus.arg: %s\n", bus.arg);
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1;
		}
		printf("After argument check: bus.arg: %s\n", bus.arg);
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.line);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.arg);
	printf("After conversion: num: %d\n", num);
	if (bus.sq_flag == 0)
		add_node(head, num);
	else
		add_queue(head, num);
}
