#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


void _error(int _code, ...);
void more_(int error_code, ...);
void string_(int _code, ...);

void _open(char *file_name);
void _read(FILE *fd);
int _parse(char *buffer, int lineNumber, int i);
void _call(op_func func, char *op, char *val, int ln, int f);
void find_func(char *op, char *val, int ln, int i);

stack_t *_node(int n);
void f_nodes(void);
void add_queue(stack_t **, unsigned int );

void add_stack(stack_t **, unsigned int );
void printf_stack(stack_t **, unsigned int );
void pop_(stack_t **, unsigned int );
void printF_top(stack_t **, unsigned int );

void ynop(stack_t **, unsigned int );
void swap_node(stack_t **, unsigned int );
void add_node(stack_t **, unsigned int );
void sub_node(stack_t **, unsigned int );
void div_node(stack_t **, unsigned int );

void mul_node(stack_t **, unsigned int );
void mod_node(stack_t **, unsigned int );

void printf_char(stack_t **, unsigned in );
void printF_str(stack_t **, unsigned int );
void roYHYtl(stack_t **, unsigned int );
void roYHYtr(stack_t **, unsigned int );


#endif
