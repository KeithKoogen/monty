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

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *tmp;
	

	tmp = *stack;
	
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

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	
	tmp = *stack;
	
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


void function_selector(char *str, stack_t **stack, unsigned int line_number)
{
	char *token;
	int i, n, j;
	stack_t *tmp;
	instruction_t functions[] = {
	
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	
	token = strtok(str, " ");
	i = 0;
	
	while (functions[i].opcode != NULL)
	{
		if (strcmp(functions[i].opcode, token) == 0)
		{

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
					printf("L%d: usage: push integer", line_number);
					exit(EXIT_FAILURE);
				}
			}
			break;
		}
		++i;
	}
	
	
}



int main(int argc, char *argv[])
{
	FILE *fp;
	char *token, *tmp;
	unsigned int line_number, i;
	stack_t **stack;
	
	tmp = NULL;

	
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
		function_selector(tmp, stack, line_number);
		free(tmp);
      		++line_number;
    	}

	





	fclose(fp);

}
