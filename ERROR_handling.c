#include "monty.h"
/**
 * ERROR - print the right error
 * @ERROR_code: error code
 */
void ERROR(int ERROR_code, ...)
{
	va_list arg;
	char *op;
	int l_num;

	va_start(arg, ERROR_code);
	switch (ERROR_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			l_num = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_allNodes();
	exit(EXIT_FAILURE);
}

/**
 * ERRORmore - print the right error
 * @ERROR_code: error code
 */
void ERRORmore(int ERROR_code, ...)
{
	va_list arg;
	char *op;
	int l_num;

	va_start(arg, ERROR_code);
	switch (ERROR_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			l_num = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_allNodes();
	exit(EXIT_FAILURE);
}

/**
 * str_ERROR - print the right error
 * @ERROR_code: error code
 */
void str_ERROR(int ERROR_code, ...)
{
	va_list arg;
	int l_num;

	va_start(arg, ERROR_code);
	l_num = va_arg(arg, int);
	switch (ERROR_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_allNodes();
	exit(EXIT_FAILURE);
}
