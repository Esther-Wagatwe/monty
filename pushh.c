#include "monty.h"

/**
  *
  * @head: pointer to the head
  * @line_number: number of the line
  *
  */
void f_push(stack_t **head, unsigned int line_number)
{
	int num, i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1;
		}
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
	if (bus.sq_flag)
		add_node(head, num);
	else
		add_queue(head, num);
}
