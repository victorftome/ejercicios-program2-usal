CC = gcc
OBJS = estudiante.o pantalla.o principal.o

all: principal clean

principal: $(OBJS)
	$(CC) $^ -o $@

principal.o: pantalla.h
pantalla.o: estudiante.h
estudiante.o: estudiante.h estudiante.c
	$(CC) -c estudiante.c

clean:
	rm *.o
