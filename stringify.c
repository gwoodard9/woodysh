#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_STRINGS 256
#define MAX_LENGTH 256
// char** tok_array = malloc(MAX_LENGTH * sizeof(char*));

int stringify(char* argv[], int count) {
	int input_count = count;
	char* strings = malloc(sizeof(char) * input_count);

	if (strings == NULL) {
		printf("Memory Allocation Failed.");
		return 1;
	}

	for (int i = 0; i < input_count; i++) {
		printf("%p\n", &strings[i]);
	}

	free(strings);

	return 0;
}
