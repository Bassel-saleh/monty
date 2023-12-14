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

void error_i(int ERROR_code, ...);
void error_ii(int ERROR_code, ...);
void errorStr(int ERROR_code, ...);
void open_f(char *file_name);
void read_f(FILE *fd);
int parse_l(char *buffer, int linec, int format);
void choose_Afun(char *opcode, char *value, int ln, int format);
void call_function(op_func func, char *op, char *val, int ln, int format);
stack_t *create_Node(int n);
void free_allNodes(void);
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void print_anyStack(stack_t **stack, unsigned int line_number);
void pop_T(stack_t **stack, unsigned int line_number);
void print_T(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap_N(stack_t **stack, unsigned int line_number);
void addNodes(stack_t **stack, unsigned int line_number);
void subNodes(stack_t **stack, unsigned int line_number);
void divNodes(stack_t **stack, unsigned int line_number);
void mulNodes(stack_t **stack, unsigned int line_number);
void modNodes(stack_t **stack, unsigned int line_number);
void printChar(stack_t **stack, unsigned int line_number);
void printStr(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln);

#endif
