all: mainvector clean

mainvector: mainVector.o vectorAux.o vectorDinamica.o
	gcc mainVector.o vectorAux.o vectorDinamica.o -o mainVector

mainVector.o: vectorAux.h vectorDinamica.h mainVector.c
	gcc -c mainVector.c

vectorAux.o: vectorAux.h vectorAux.c
	gcc -c vectorAux.c

vectorDinamica.o: vectorDinamica.h vectorDinamica.c
	gcc -c vectorDinamica.c

clean:
	rm *.o