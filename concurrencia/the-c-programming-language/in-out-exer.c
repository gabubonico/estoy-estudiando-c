#include <stdio.h>

int main (){
	int c;
	int a;
	
	a = 0;

	c = getchar();
	while (c != EOF) {
		if (c != a && c != 32) {
			a = c;
			putchar(c);
			c=getchar();
		}
	}
	return 0;
}
