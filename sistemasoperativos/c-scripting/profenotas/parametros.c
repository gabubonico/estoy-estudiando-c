#include <stdio.h>

int main (int argc, char *argv[], char *env[]) {
	for (int i = 0; i < argc; i++) {
		printf("arg[%d] = %s\n", i, argv[i]);
	}
	
	int i = 0;
	while (env[i] != NULL) {
		printf("%s\n", env[i++]);
	}
}
