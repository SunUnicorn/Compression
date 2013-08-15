CC=gcc
CFLAGS=-c -Wall
P_HUFFMAN = code/huffman

all:	program

# compression program
program:	statistic.o tree.o codes.o auxiliary.o main.o
	$(CC) -o program statistic.o tree.o codes.o auxiliary.o main.o

# statistic of chars from a file
statistic.o:	$(P_HUFFMAN)/statistic.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/statistic.c

# make huffman tree
tree.o:	$(P_HUFFMAN)/tree.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/tree.c

# make huffman codes
codes.o:	$(P_HUFFMAN)/codes.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/codes.c

# make huffman codes
auxiliary.o:	$(P_HUFFMAN)/auxiliary.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/auxiliary.c

# main file
main.o:	main.c
	$(CC) $(CFLAGS) main.c

# clean all files of compilations
clean:
	rm *.o program
