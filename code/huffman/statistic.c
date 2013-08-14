#include <stdio.h>
#include "types.h"

// An array of zeros
static void zero_array(NODE *array){

	int i = 0;

		for(i = 0; i < SIZE_OF_ARRAY; i++){
		array[i].number = 0;
		array[i].right = NULL;
		array[i].left = NULL;
		array[i].sign = 0;
		}

}
// Statistic of signs
static void char_statistic(NODE *array, char *file_name){

	int ch, i;
	FILE *fp;
	fp = fopen(file_name, "r");
	zero_array(array);

		while((ch = getc(fp)) != EOF)
		array[ch].number++;
		array[10].number--;

		for(i = 0; i < 256; i++)
			if(array[i].number)
			array[i].sign = 1;

	fclose(fp);
}
// Minimum value across array[i].numbers
static int array_min_value(NODE *array, int border){

	int i, j = SIZE_OF_ARRAY;
	unsigned int tmp = MAX_UNSIGNED_INT;

		for(i = 0; i < border; i++)
			if(array[i].sign  && array[i].number <= tmp){
			tmp = array[i].number;
			j = i;
			}

		if(j != SIZE_OF_ARRAY)
		array[j].sign = 0;

	return j;
}
// Huffman tree generator
void make_tree(NODE *array, char *file_name){

	int i, k1, k2;

	char_statistic(array, file_name);

		for(i = 256; i < SIZE_OF_ARRAY; i++){
		k1 = array_min_value(array, i);
		k2 = array_min_value(array, i);
			if(k1 != SIZE_OF_ARRAY && k2 != SIZE_OF_ARRAY){
			array[i].number = array[k1].number + array[k2].number;
			array[i].right = &(array[k1]);
			array[i].left = &(array[k2]);
			array[i].sign = 1;
			}
		}

		for(i = 0; i < SIZE_OF_ARRAY; i++)
		printf("%d => %d, %d:: %p => %p\n", i, array[i].number, array[i].sign, array + i, array[i].right);
}
