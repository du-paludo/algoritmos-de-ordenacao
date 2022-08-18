parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o geravetor.o
	gcc -o $(nomePrograma) main.o ordenacao.o geravetor.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

geravetor.o: geravetor.h geravetor.c
	gcc -c geravetor.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
