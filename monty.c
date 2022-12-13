#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	
	if (argc < 2 || argc > 2)
	{
		printf("%d\n", argc);
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		perror("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

}
