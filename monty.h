#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct bus_s - variables - args, file, line content
 * @arg: pointer to a character string,can be used to store some argument.
 * @file: pointer to the monty file
 * @content: pointter to a string used to store line content
 * @sq_flag: integer variable used as a flag to show change in btn stack and queue
 *
 * Description: struct for the centralization of program state in one place.
 */
typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *line;
    int sq_flag;
} bus_t;

extern bus_t bus;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t instructions[];

void push_function(stack_t **stack, unsigned int line_number);
void add_queue(stack_t **head, int n);
void queue_function(stack_t **head, unsigned int counter);
void pall_function(stack_t **stack, unsigned int line_number);
void pint_function(stack_t **stack, unsigned int line_number);
void pop_function(stack_t **stack, unsigned int line_number);
void swap_function(stack_t **stack, unsigned int line_number);
/*void swap_function(stack_t **stack, unsigned int line_number);
void add_function(stack_t **stack, unsigned int line_number);
void nop_function(stack_t **stack, unsigned int line_number);*/
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void add_node(stack_t **head, int n);
void execute_monty_file(FILE *file);
void free_stack(stack_t *stack);
#endif
