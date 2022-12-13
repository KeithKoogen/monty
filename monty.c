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
	char buffer[1024], *str;
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
		memset(buffer, 0, sizeof(buffer));
		fread(buffer, sizeof(buffer), 1, fp);
		
		str = malloc(sizeof(buffer));
		memset(str, 0, sizeof(str));
		strcpy(str, buffer);
		
		sscanf(str, "%s %s", buffer2, buffer3);
		printf("buffer2:%s buffer3:%s \n", buffer2, buffer3);
		memset(buffer2, 0, sizeof(buffer2));
		memset(buffer3, 0, sizeof(buffer3));
		printf("%s\n", buffer);
		free(str);

	    }
	fclose(fp);

}
