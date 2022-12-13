#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(int n, stack_t **h)
{
	stack_t *new_node;

	if (*h == NULL)
	{
		new_node = malloc(sizeof(stack_t));
		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;
		*h = new_node;
	}
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[1024];
	char *token, buffer2[102], buffer3[102];
	
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
	while (!feof(fp))
	    {
		fread(buffer, sizeof(buffer), 1, fp);
		
		sscanf(buffer, "%s %s", buffer2, buffer3);
		print("buffer2:%s buffer3:%s \n", buffer2, buffer3);

	    }
	fclose(fp);

}
