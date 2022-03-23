#include <stdio.h>

int main() {
	float f, c;
	float lo, up, st;

	lo = 0;
	up = 300;
	st = 20;

	c = lo;
	while(c <= up){
		f = c * 1.8 + 32;
		printf("%3.0f %6.1f\n", c, f);
		c = c + st;
	}
}
