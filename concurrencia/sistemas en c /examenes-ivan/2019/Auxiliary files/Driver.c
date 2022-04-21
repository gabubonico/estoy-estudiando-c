#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

const char filename[] = "C:\\Users\\galvez\\Downloads\\output.bin";
int main(void) {
	T_List list = create();
	show(list);
	struct info myAvg = avg(list);
	printf("%d, %d, %d\n", myAvg.posX, myAvg.posY, myAvg.speed);
	for (int i = 0; i < 5; i++) {
		insert(&list, i, i, i);
		show(list);
		insert(&list, i, i, i);
		show(list);
		insert(&list, i, i, i);
		show(list); 
		myAvg = avg(list);
		printf("%d, %d, %d\n", myAvg.posX, myAvg.posY, myAvg.speed);
	}
	FILE * f;
	f = fopen(filename, "wb");
	if (f != NULL) {
		save(list, f);
		fclose(f);
	}
	show(list);
	destroy(&list);
	list = create();
	show(list);
	f = fopen(filename, "rb");
	list = load(f);
	fclose(f);
	show(list);
	system("pause");
}