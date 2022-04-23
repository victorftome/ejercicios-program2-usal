CC = gcc
OBJS = listaSimple.o main.o

all: main clean

main: $(OBJS)
	$(CC) $^ -o $@

main.o: listaSimple.h
listaSimple.o: listaSimple.h

clean:
	rm *.o