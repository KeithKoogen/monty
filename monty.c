#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[1024];
	instruction_t instructions[] = {
		{"push", }
	};
	
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
		printf("%s\n",buffer);
	    }
	fclose(fp);

}
