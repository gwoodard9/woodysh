#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int create_fork(char* argv[], int count) {
	pid_t pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed\n");
		return 1;
	}

	if (pid == 0) {
		char** tokenized = malloc(count * sizeof(char*));

		for (int i = 0; i < count; i++) {
			tokenized[i] = strdup(argv[i]);
		}

		free(tokenized);
	}

	return 0;
}
