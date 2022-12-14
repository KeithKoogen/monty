#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[1024];

int numbers_only(char *str)
{
	int i, j;
	
	j = 0;
	i = 0;
	
	while(str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			j = 1;
		++i;
	}
	return (j);
}

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	
	tmp = *stack;
	
	if (tmp != NULL)
	{
		printf("%d\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
}

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *tmp;
	

	tmp = *stack;
	line_number = line_number;
	
	if (tmp == NULL)
	{
		new_node = malloc(sizeof(stack_t));
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node = malloc(sizeof(stack_t));
		new_node->next = *stack;
		new_node->prev = NULL;
		tmp->prev = new_node;
		*stack = new_node;
	}
}
void free_stack(stack_t *head)
{
	if (head == NULL)
	{
		return;
	}
	free_stack(head->next);
	free(head);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	
	tmp = *stack;
	line_number = line_number;
	
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;
	
	tmp = *stack;
	if (tmp != NULL)
	{	
		*stack = tmp->next;
		tmp2 = *stack;
		tmp2->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	
}


void function_selector(char *str, stack_t **stack, unsigned int line_number)
{
	char *token;
	int i, n, j, k;
	stack_t *tmp;
	instruction_t functions[] = {
	
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	
	token = strtok(str, " ");
	i = 0;
	k = 0;
	
	while (functions[i].opcode != NULL)
	{
		if (strcmp(functions[i].opcode, token) == 0)
		{
			k = 1;

			functions[i].f(stack, line_number);
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " ");
				j = numbers_only(token);
				if (j == 0)
				{
					n = atoi(token);
					tmp = *stack;
					tmp->n = n;
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
			break;
		}

		++i;
	}
	if (k == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		exit(EXIT_FAILURE);
	}
	
}



int main(int argc, char *argv[])
{
	FILE *fp;
	char *tmp;
	unsigned int line_number, i;
	stack_t **stack;
	
	tmp = NULL;

	stack = malloc(sizeof(stack_t));
	*stack = NULL;
	line_number = 1;
	
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while(fgets(buffer,sizeof(buffer),fp)!= NULL)
	{
		i = 0;
		while (buffer[i] != '\n')
			++i;
		tmp = malloc(sizeof(char) * (i - 1));
		i = 0;
		while (buffer[i] != '\n')
		{
			tmp[i] = buffer[i];
			++i;
		}
		print("the line: %s", tmp);
		function_selector(tmp, stack, line_number);
		free(tmp);
      		++line_number;
		memset(buffer, 0, sizeof(buffer));
    	}

	





	fclose(fp);
	free_stack(*stack);
	free(stack);
	return (0);

}
