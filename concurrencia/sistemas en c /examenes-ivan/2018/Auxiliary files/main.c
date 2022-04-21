#include "componentList.h"
#include <stdio.h>

int main(){


	TList lc, ordered;
    int num;
	createList(&lc);
	num=read_file_to_list(&lc);
	printf("%d components were read from the file to the list\n",num);
	fflush(stdout);

	printf("\nOriginal list:\n");
    show_list(lc);
    fflush(stdout);

    new_ordered_list(lc, &ordered);
    printf("\nOrdered list:\n");
    show_list(ordered);
    fflush(stdout);

    remove_elements(&lc, 8);
    printf("\nOriginal list, without elements of the manufacturer with code 8:\n");
    show_list(lc);
    fflush(stdout);

    remove_elements(&lc, -1);
    printf("\nOriginal list should be now empty\n");
    show_list(lc);
    fflush(stdout);

    remove_elements(&ordered, -1);
    printf("\nOrdered list should be now empty\n");
    show_list(ordered);
    fflush(stdout);


	return 0;
}
