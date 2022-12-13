#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2 || argc > 2)
	{
		printf("%d\n", argc);
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
