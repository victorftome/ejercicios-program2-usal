OBJS = main.o listaEnlazadaSimple.o
SOURCES = main.c listaEnlazadaSimple.c
HEADERS = listaEnlazadaSimple.h
CC = gcc
#CTAGS = -c
CTAGS = -c -g -DDEBUG

all : listaEnlazada clean

listaEnlazada : $(OBJS)
	$(CC) $(OBJS) -o listaEnlazada

main.o : main.c listaEnlazadaSimple.h
	$(CC) $(CTAGS) main.c

listaEnlazadaSimple.o : listaEnlazadaSimple.c listaEnlazadaSimple.h
	$(CC) $(CTAGS) listaEnlazadaSimple.c

	
listaEnlazada.tar : $(SOURCES) $(HEADERS) makefile
	tar -cvf listaEnlazada.tar $^

clean:
	rm $(OBJS)
