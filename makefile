CC=gcc
CFLAGS=-c -Wall
P_HUFFMAN = code/huffman

all:	program

# compression program
program:	statistic.o main.o
	$(CC) -o program statistic.o main.o

# huffman copression
statistic.o:	$(P_HUFFMAN)/statistic.c
	$(CC) $(CFLAGS) $(P_HUFFMAN)/statistic.c

# main file
main.o:	main.c
	$(CC) $(CFLAGS) main.c

# clean all files of compilations
clean:
	rm *.o program
