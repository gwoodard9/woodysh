#include "parser.h"
#include <stdio.h>
#include <string.h>

int main() {
	char line[256];

	while (1) {
		printf("woodysh> ");

		if (fgets(line, 256, stdin) == NULL) {
			break;
		}

		size_t index = strcspn(line, "\n");

		line[index] = '\0';

		if (strcmp(line, "exit") == 0) {
			break;
		}
	}

	return 0;
}