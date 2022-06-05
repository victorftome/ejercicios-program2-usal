OBJS = main.o listaEnlazada.o
CC = gcc

all: listaEnlazada clear

listaEnlazada: $(OBJS)
	$(CC) $^ -o $@

main.o: listaEnlazada.h
listaEnlazada.o: listaEnlazada.h listaEnlazada.c
	$(CC) -c listaEnlazada.c

clear:
	rm *.o