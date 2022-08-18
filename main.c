#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"
#include "geravetor.h"

int main()
{
	// Declara variáveis gerais

	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;

	// Declara variáveis de relógio

	clock_t start, end;
    double total;

	// Gera uma seed aleatória para o rand

    srand(time(NULL));

	// Imprime informações dos autores

	getNome(nome);
	printf("\n");
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	printf("\n");

	// Declara vetor original e vetor cópia com tamanhos diferentes
	// O vetor cópia é necessário para não alterar o vetor aleatório original

	int N = 10000;
	int* vetor = malloc(sizeof(int) * N);
	if (vetor == NULL)
	{
		printf("Falha fatal. Impossível alocar memória.\n");
		return 1;
	}
	int* vetorCopia = malloc(sizeof(int) * N);
	if (vetorCopia == NULL)
	{
		printf("Falha fatal. Impossível alocar memória.\n");
		return 1;
	}

    // Inicializa vetores de formas diferentes

    // crescente(vetor, N);
    // decrescente(vetor, N);
	aleatorio(vetor, N);

	// InsertionSort

	printf("Algoritmo: %s\n", "insertionSort");
	copia_vetor(vetor, vetorCopia, N);
	start = clock();
	numComp = insertionSort(vetorCopia, N);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\nComparações: %d\n\n", total, numComp);

	// SelectionSort

	printf("Algoritmo: %s\n", "selectionSort");
	copia_vetor(vetor, vetorCopia, N);
	start = clock();
	numComp = selectionSort(vetorCopia, N);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\nComparações: %d\n\n", total, numComp);

	// MergeSort

	printf("Algoritmo: %s\n", "mergeSort");
	copia_vetor(vetor, vetorCopia, N);
	start = clock();
	numComp = mergeSort(vetorCopia, N);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\nComparações: %d\n\n", total, numComp);

	// QuickSort

	printf("Algoritmo: %s\n", "quickSort");
	copia_vetor(vetor, vetorCopia, N);
	start = clock();
	numComp = quickSort(vetorCopia, N);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\nComparações: %d\n\n", total, numComp);

	// Busca Sequencial

	printf("Algoritmo: %s\n", "buscaSequencial");
	numComp = 0;
	start = clock();
	idxBusca = buscaSequencial(vetorCopia, N, 17354, &numComp);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
	printf("Índice: %d\nComparações: %d\n", idxBusca, numComp);
	printf("\n");

	// Busca Binária

	printf("Algoritmo: %s\n", "buscaBinaria");
	numComp = 0;
	start = clock();
	idxBusca = buscaBinaria(vetorCopia, N, 17354, &numComp);
    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;
   	printf("Tempo total: %f\n", total);
	printf("Índice: %d\nComparações: %d\n", idxBusca, numComp);
    printf("\n");

    // Os índices obtidos pela busca binária podem ser diferentes
    // dos obtidos pela busca sequencial, visto que podem existir
    // elementos repetidos no vetor

    // Testes com média do número de comparações e tempo de execução

    /* int media_comp = 0;
    double media_tempo = 0;
    for (int i = 0; i < 100; i++)
    {
    	aleatorio(vetor, N);
    	start = clock();
		numComp = quickSort(vetor, N);
		end = clock();
		total = ((double)end - start)/CLOCKS_PER_SEC;
		media_comp += numComp;
		media_tempo += total;
    }
    printf("Média de comparações: %d\n", media_comp/100);
    printf("Média de tempo: %f\n", media_tempo/100);
    */

    // Libera a memória alocada

    free(vetor);
    free(vetorCopia);

	return 0;
}
