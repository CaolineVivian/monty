#include "monty.h"

/**
 * push - pushes a value to a stack_t linked list
 * @mystack: A pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 */

void push(stack_t **mystack, unsigned int line_number)
{
	stack_t *newnode;

	if (mystack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	newnode = malloc(size of(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}

	newnode->next = *mystack;
	newnode->prev = NULL;
	newnode->n = global.vars;
	if (*mystack)
	{
		(*mystack)->prev = new;

	}
	*mystack = new;
}

/**
 * pall - Prints the values of a stack_t linked list.
 * @mystack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of file.
 */

void pall(stack_t **mystack, unsigned int line_number)
{
	stack_t *tmp = (*mystack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * pint - prints the top value of a stack_t linked list.
 * @mystack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of file.
 */
void pint(stack_t **mystack, unsigned int line_number)
{
	if (*mystack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*mystack)->next->n);
}

/**
 * pop - removes the top element of stack
 * @mystack: pointer to the head node pointer of stack
 * @line_number: the line number
 * Return: Nothing.
 */
void pop(stack_t **mystack, unsigned int line_number)
{
	if (mystack == NULL || *mystack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*mystack)->next != NULL)
	{
		*mystack = (*mystack)->next;
		free((*mystack)->prev);
		(*mystack)->prev = NULL;
	}
	else
	{
		free(*mystack);
		*mystack = NULL;
	}
}

/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @mystack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of file.
 */
void monty_swap(stack_t **mystack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*mystack)->next == NULL || (*mystack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
	}

	tmp = (*mystack)->next->next;
	(*mystack)->next->next = tmp->next;
	(*mystack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*mystack)->next;
	tmp->next = (*mystack)->next;
	tmp->prev = *mystack;
	(*mystack)->next = tmp;
}
