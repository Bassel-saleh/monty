#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments counter
 * @argv: arguments value
 * Return: always 0 (success)
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	free_allNodes();
	return (0);
}

/**
 * create_Node - creats a new node
 * @n: date inside the node
 * Return: node
 */
stack_t *create_Node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_i(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_allNodes - frees all nodes in the stack
 */
void free_allNodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * add_queue - adds a node to queue
 * @new_node: pointer to the new node
 * @ln: line number (opcode)
 */
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}
