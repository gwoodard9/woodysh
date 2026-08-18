#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_STRINGS 256
#define MAX_LENGTH 256

int parse(char* line, char* argv[]) {
	char* token = strtok(line, " ");
	int count = 0;

	while (token != NULL) {
		argv[count] = token;
		count = count + 1;
		token = strtok(NULL, " ");
	}

	argv[count] = NULL;

	return count;
}