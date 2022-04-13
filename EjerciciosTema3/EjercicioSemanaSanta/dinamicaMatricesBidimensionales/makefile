OBJS = main.o matrizBidimensional.o
CC = gcc
#CTAGS = -c 
CTAGS = -c -g -DDEBUG

all: matrices clean

matrices : $(OBJS)
	$(CC) $(OBJS) -o matrices

main.o : main.c matrizBidimensional.h  
	$(CC) $(CTAGS) main.c

matrizBidimensional.o : matrizBidimensional.c matrizBidimensional.h
	$(CC) $(CTAGS) matrizBidimensional.c
	

clean:
	rm *.o