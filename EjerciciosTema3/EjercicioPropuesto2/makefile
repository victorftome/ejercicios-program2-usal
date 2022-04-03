CC = gcc
OBJS = empleado.o main.o

all: main clean

main: $(OBJS)
	$(CC) $^ -o $@

main.o: empleado.h
empleado.o: empleado.h

clean:
	rm *.o