#include "monty.h"

/**
 * _open - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void _open(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		_error(2, file_name);

	_read(fd);
	fclose(fd);
}


/**
 * _read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void _read(FILE *fd)
{
	int lineNumber, i = 0;
	char *buffer = NULL;
	size_t n = 0;

	for (lineNumber = 1; getline(&buffer, &n, fd) != -1; lineNumber++)
	{
		i = _parse(buffer, lineNumber, i);
	}
	free(buffer);
}


/**
 * _parse - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @lineNumber: line number
 * @i:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int _parse(char *buffer, int lineNumber, int i)
{
	char *op, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		_error(4);

	op = strtok(buffer, delim);
	if (op == NULL)
		return (i);
	val = strtok(NULL, delim);

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	find_func(op, val, lineNumber, i);
	return (i);
}

/**
 * find_func - find the appropriate function for the opcode
 * @op: opcode
 * @val: argument of opcode
 * @i:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *op, char *val, int ln, int i)
{
	int n;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", printf_stack},
		{"pint", printF_top},
		{"pop", pop_},
		{"nop", ynop},
		{"swap", swap_node},
		{"add", add_node},
		{"sub", sub_node},
		{"div", div_node},
		{"mul", mul_node},
		{"mod", mod_node},
		{"pchar", printf_char},
		{"pstr", printF_str},
		{"rotl", roYHYtl},
		{"rotr", roYHYtr},
		{NULL, NULL}
	};

	if (op[0] == '#')
		return;

	for (flag = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(op, func_list[n].opcode) == 0)
		{
			_call(func_list[n].f, op, val, ln, i);
			flag = 0;
		}
	}
	if (flag == 1)
		_error(3, ln, op);
}


/**
 * _call - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @f: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void _call(op_func func, char *op, char *val, int ln, int f)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				_error(5, ln);
		}
		node = _node(atoi(val) * flag);
		if (f == 0)
			func(&node, ln);
		if (f == 1)
			add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
