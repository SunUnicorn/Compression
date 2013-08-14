/* File main.c */
#include <stdio.h>
#include "code/huffman/types.h"
#include "code/huffman/statistic.h"

int main(int argc, char **argv){

  if(argc != 2){
  printf("You must write name of a file as argument\n");
  return 1;
  }
	NODE array[SIZE_OF_ARRAY];

    // test file
    make_tree(array, "data/stat.jpg");

	return 0;
}