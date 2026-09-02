#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_STRINGS 32
#define BUFFER_SIZE 100

void parse(char** strArr, char* buffer, char* input) {
	if (input == NULL)
		return;

	size_t len = strlen(buffer);

	if (len > 0 && buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';

	int i = 0;
	for (char* token = strtok(buffer, " ");
		 token != NULL && i < MAX_STRINGS - 1; token = strtok(NULL, " ")) {

		strArr[i] = malloc(strlen(token) + 1);

		if (strArr[i] == NULL) {
			printf("Memory Allocation Failed.");
		}

		strcpy(strArr[i], token);
		i++;
	}

	strArr[i] = NULL;
}

void execute(char** strArr) {
	pid_t pid = fork();

	if (pid == 0) {
		execvp(strArr[0], strArr);
	} else {
		waitpid(pid, NULL, 0);
	}
	printf("\n");
}

int main() {
	char* strArr[MAX_STRINGS];
	char buffer[BUFFER_SIZE];
	char cwd[PATH_MAX];

	while (1) {
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			printf("woodysh ~%s> ", cwd);
		} else {
			printf("cwd returned NULL.");
			return 0;
		}

		char* input = fgets(buffer, BUFFER_SIZE, stdin);
		parse(strArr, buffer, input);

		if (strcmp(strArr[0], "cd") == 0) {
			if (strArr[1] == NULL) {
				chdir(getenv("HOME"));
			}
			chdir(strArr[1]);
		} else {
			execute(strArr);
		}

		for (int j = 0; strArr[j] != NULL; j++) {
			free(strArr[j]);
		}
	}

	return 0;
}