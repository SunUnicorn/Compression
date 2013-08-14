#define MAX_UNSIGNED_INT 4294967295
#define SIZE_OF_ARRAY 511

typedef struct node {
	unsigned int number;
	struct node *right;
	struct node *left;
	char sign;
} NODE;
