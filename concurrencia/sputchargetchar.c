#include <stdio.h>

int main() {
	
	int vector[4] = {1.0, 2.0, 3.0, 5.0};
	int matriz[4][4] = {{1.0, 2.0, 3.0, 5.0},{1.0, 2.0, 3.0, 5.0},{1.0, 2.0, 3.0, 5.0},{1.0, 2.0, 3.0, 5.0}};

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%f", matriz[j][i]);
		}
	}

	return 0;
}
