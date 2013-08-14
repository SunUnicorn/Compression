#include <stdio.h>
#include "types.h"

//extern void zero_array(NODE *array);
extern void char_statistic(NODE *array, char *string);
extern void make_tree(NODE *array);

int main(int argc, char **argv){

	NODE array[511];
	int i ;

		char_statistic(array, "stat.jpg");
		printf("%s\n", argv[1]);

		make_tree(array);

	return 0;
}
