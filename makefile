CC=gcc
CFLAGS=-c -Wall
P_HUFFMAN = code/huffman

all:	program

# compression program
program:	statistic.o tree.o codes.o auxiliary.o compress.o main.o
	$(CC) -o program statistic.o tree.o codes.o auxiliary.o compress.o main.o

# statistic of chars from a file
statistic.o:	$(P_HUFFMAN)/statistic.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/statistic.c

# make huffman tree
tree.o:	$(P_HUFFMAN)/tree.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/tree.c

# make huffman codes
codes.o:	$(P_HUFFMAN)/codes.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/codes.c

# auxiliary functions
auxiliary.o:	$(P_HUFFMAN)/auxiliary.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/auxiliary.c

# compress function
compress.o: $(P_HUFFMAN)/compress.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/compress.c

# main file
main.o:	main.c
	$(CC) $(CFLAGS) main.c

# clean all files of compilations
clean:
	rm *.o program
