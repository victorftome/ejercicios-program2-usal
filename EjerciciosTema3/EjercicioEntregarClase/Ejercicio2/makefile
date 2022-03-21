all: mainvector clean

mainvector: mainVector.o vectorAux.o
	gcc mainVector.o vectorAux.o -o mainVector

mainVector.o: vectorAux.h mainVector.c
	gcc -c mainVector.c

vectorAux.o: vectorAux.h vectorAux.c
	gcc -c vectorAux.c

clean:
	rm *.o