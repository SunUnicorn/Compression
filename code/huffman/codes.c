/* codes.c */
#include <stdio.h>
#include "types.h"
#include "codes.h"

// looking for beginning of the huffman tree
static NODE *find_tree_root(NODE *array){

  int i = SIZE_OF_ARRAY - 1;

    while(array[i].right == NULL)
    i--;

  return array + i;
}
// generate codes for function huffman_codes
static void recursive_huffman_codes(NODE *array){


  (*((*array).left)).code = (*array).code << 1;
  (*((*array).right)).code = (*array).code << 1;
  (*((*array).right)).code = ((*array).code << 1) + 1;

  if((*((*array).left)).left != NULL)
  recursive_huffman_codes((*array).left);
  if((*((*array).right)).left != NULL)
  recursive_huffman_codes((*array).right);

}
// generate codes of the huffman tree
void huffman_codes(NODE *array){
  NODE *root = find_tree_root(array);
  recursive_huffman_codes(root);
}