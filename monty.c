#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[1024];

void function_selector(char *str)
{
	char *token, *line;
	instruction_t functions[] = {
	
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	
	line = strtok(buffer, "\n");
		      print("%s\n", line);
	token = strtok(line, " ");
		      print("%s\n", token);
	
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

int main(int argc, char *argv[])
{
	FILE *fp;
	char *token;
	unsigned int line_number;
	stack_t **stack;
	
	*stack = NULL;
	
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
	memset(buffer, 0, sizeof(buffer));
	fread(buffer, sizeof(buffer), 1, fp);
	function_selector(buffer);
	



	fclose(fp);

}
