#include <stdio.h>

int main() {
	float fahr, cel;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("%s \t %s \n", "fahr", "cel");
	printf("________________\n");

	while (fahr <= upper) {
		cel = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f\t%.1f\n", fahr, cel);
		fahr = fahr + step;
	}
}
