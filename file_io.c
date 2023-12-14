#include "monty.h"
/**
 * open_f - open a certain file
 * @file_name: is the path and file name of the file
 */
void open_f(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		error_i(2, file_name);
	read_f(fd);
	fclose(fd);
}

/**
 * read_f - reads a certain file
 * @fd: pointer to file descriptor
 */
void read_f(FILE *fd)
{
	int linec, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (linec = 1; getline(&buffer, &len, fd) != -1; linec++)
		format = parse_l(buffer, linec, format);
	free(buffer);
}

/**
 * parse_l - separates each line into tokens
 * @buffer: stores the the data from the lines
 * @linec: the lines counter
 * @format: format (stack or queue) if 0: stack, 1: for a queue
 * Return: Returns 0 if opcode is stack. 1 if queue
 */
int parse_l(char *buffer, int linec, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error_i(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	choose_Afun(opcode, value, linec, format);
	return (format);
}

/**
 * choose_Afun - find the right function
 * @opcode: the opcode
 * @value: the argument of the opcode
 * @ln: line number
 * @format: format (stack or queue) if 0: stack, 1: for a queue
 */
void choose_Afun(char *opcode, char *value, int ln, int format)
{
	int i, flag;

	instruction_t fun_list[] = {
		{"push", add_stack},
		{"pall", print_anyStack},
		{"pint", print_T},
		{"pop", pop_T},
		{"nop", nop},
		{"swap", swap_N},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", printChar},
		{"pstr", printStr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; fun_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, fun_list[i].opcode) == 0)
		{
			call_function(fun_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_i(3, ln, opcode);
}

/**
 * call_function - calls the right function
 * @func: pointer to the function which will be called
 * @op: string (opcode)
 * @val: string (value)
 * @ln: line number
 * @format: format specifier
 */
void call_function(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error_i(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error_i(5, ln);
		}
		node = create_Node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
