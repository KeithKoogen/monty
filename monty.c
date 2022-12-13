#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[1024];

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

void function_selector(char *str)
{
	char *token, *line, tmp[1024];
	instruction_t functions[] = {
	
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	
	line = strtok(buffer, "\n", " ");
		     
	while (line != NULL)
	{
		memset(tmp, 0, sizeof(tmp));
		strcpy(tmp, line);
		printf("%s\n", tmp);
		
		token = strtok(tmp, " ");
		printf("%s\n", token);
		line = strtok(NULL, "\n", " ");
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
