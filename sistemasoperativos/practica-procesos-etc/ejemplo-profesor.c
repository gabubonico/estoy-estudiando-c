#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int varglobal;

void main() {
	pid_t pidfork;
	varglobal = 1;
	int status;

	pidfork = fork(); // en el hijo vale 0, en el padre vale el pid del hijo

	if (pidfork == 0) {
		printf("Hijo (1): valor varglobal0 %d\n", varglobal);
		varglobal = 500;
		printf("Hijo (2): valor varglobal0 %d\n", varglobal);
	} else {
		while (pidfork != wait(&status));	
		if(WIFEXITED(status)) {
			printf("Fin por exit %d \n", WEXITSTATUS(status));
		} else if (WIFSIGNALED(status)) {
			printf("Fin por señal %d\n", WTERMSIG(status));			
		} else if (WIFSTOPPED(status)) {
			printf("Parado opr señal %d\n", WSTOPSIG(status));
		}
	}
	exit(0);
}
