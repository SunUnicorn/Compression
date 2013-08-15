/* dictionary.c*/
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "auxiliary.h"


// compres file to .compress format
void compress_file(NODE *array, char *file_name){

  unsigned short int buffor;
  unsigned short int code;
  unsigned short int mark = 1 << 15;
  unsigned short int mark_buffor = 1 << 15;

  char count = 16;
  int ch;
  unsigned int c_c=0;

  char new_file_name[256];
  strncpy(new_file_name, file_name, 256 - 1);
  new_file_name[256 -1] = '\0';
  new_file_name[strlen(new_file_name) - 4] = '\0';
  strncat(new_file_name, ".compress", 256 - 1);
  new_file_name[256 -1] = '\0';

  FILE *fp_r, *fp_w;
  fp_r = fopen(file_name, "r");
  fp_w = fopen(new_file_name, "w");

    while((ch = getc(fp_r)) != EOF){
    c_c++;
    code = array[ch].code;
      while(!(code & mark))
      mark >>= 1;
      mark >>= 1;

      while(mark != 0){
        if(code & mark)
        buffor |= mark_buffor;
        else
        buffor &= ~mark_buffor;

        mark >>= 1;
        mark_buffor >>= 1;
        count--;

        if(count == 0){
        fwrite(&buffor, sizeof(buffor), 1, fp_w);
        count = 16;
        mark_buffor = 1 << 15;
        }
      }
    mark = 1 << 15;
    }

  if(count != 16)
  fwrite(&buffor, sizeof(buffor), 1, fp_w);

  fclose(fp_r);
  fclose(fp_w);
}



