/* auxiliary.c */
#include <stdio.h>
#include "types.h"
#include "auxiliary.h"

// display whole huffman tree
void display_tree(NODE *array){

  int i;

    for(i = 0; i < SIZE_OF_ARRAY; i++)
    printf( "i: %d\n \
unsigned int number: %d\n \
unsigned short int code: %d\n \
struct node *right: %p\n \
struct node *left: %p\n \
char sign: %d\n \
own address: %p\n\n ", i, array[i].number, array[i].code, array[i].right, array[i].left, array[i].sign, array + i );
}
// debuging help function
void S(char *message){
printf("%s\n", message);
}