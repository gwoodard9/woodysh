#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 32
#define BUFFER_SIZE 100

void parse(char** strArr, char* buffer, char* input) {
	if (input == NULL)
		return;

	size_t len = strlen(buffer);

	if (len > 0 && buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';

	int i = 0;
	for (char* token = strtok(buffer, " "); token != NULL && i < MAX_STRINGS;
		 token = strtok(NULL, " ")) {

		strArr[i] = malloc(strlen(token) + 1);

		if (strArr[i] == NULL) {
			printf("Memory Allocation Failed.");
		}

		strcpy(strArr[i], token);
		printf("%s", token);

		i++;
	}

	for (int j = 0; j < i; j++) {
		free(strArr[j]);
	}
}

int main() {
	char* strArr[MAX_STRINGS];
	char buffer[BUFFER_SIZE];

	while (1) {
		printf("\nwoodysh> ");
		char* input = fgets(buffer, BUFFER_SIZE, stdin);
		parse(strArr, buffer, input);
	}

	return 0;
}