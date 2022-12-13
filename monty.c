#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 3 || argc > 3)
	{
		print("%d\n", argc);
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
