/* statistic.c */
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
		array[i].code = 1;
		}

}
// Statistic of signs
void char_statistic(NODE *array, char *file_name){

	int ch, i;
	FILE *fp;
	fp = fopen(file_name, "r");
	zero_array(array);

		while((ch = getc(fp)) != EOF)
		array[ch].number++;
//		array[10].number--;

		for(i = 0; i < 256; i++)
			if(array[i].number)
			array[i].sign = 1;

	fclose(fp);
}