#define MAX_UNSIGNED_INT 4294967295
#define SIZE_OF_ARRAY 511

struct node {
	unsigned int number;
  unsigned short int code;
	struct node *right;
	struct node *left;
	char sign;
};
typedef struct node NODE;