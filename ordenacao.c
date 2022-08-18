#include <stdio.h>
#include <string.h>
#include "ordenacao.h"

void getNome(char nome[])
{
	// substitua por seu nome
	strncpy(nome, "Eduardo Paludo e Nico Ramos", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0'; // adicionada terminação manual para caso de overflow
}

unsigned int getGRR()
{
	return 20210581;
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();


// Buscas

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes)
{
	if (tam == 0)
		return -1;
	(*numComparacoes)++;
	if (vetor[tam-1] == valor)
		return tam-1;
	return buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

int buscaBinaria_(int vetor[], int a, int b, int valor, int* numComparacoes)
{
    if (a > b)
        return -1;
    int m = (a + b) / 2;
    (*numComparacoes)++;
    if (vetor[m] == valor)
        return m;
    (*numComparacoes)++;
    if (vetor[m] < valor)
        return buscaBinaria_(vetor, m+1, b, valor, numComparacoes);
    return buscaBinaria_(vetor, a, m-1, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes)
{
	int a = 0;
	int b = tam - 1;
	return buscaBinaria_(vetor, a, b, valor, numComparacoes);
}

// InsertionSort

void troca(int vetor[], int a, int b)
{
    int aux;
    aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}

int busca(int vetor[], int tam, int valor, int* numComparacoes)
{
    if (tam < 0)
        return -1;
    (*numComparacoes)++;
    if (valor >= vetor[tam])
        return tam;
    return busca(vetor, tam-1, valor, numComparacoes);
}

void insere(int vetor[], int tam, int* numComparacoes)
{
    int x = busca(vetor, tam-1, vetor[tam], numComparacoes);
    for (int i = tam; i > x+1; i--)
        troca(vetor, i, i-1);
}

int insertionSort_(int vetor[], int tam, int* numComparacoes)
{
    if (tam > 0)
    {
        insertionSort_(vetor, tam-1, numComparacoes);
        insere(vetor, tam, numComparacoes);
    }
    return *numComparacoes;
}

int insertionSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	return insertionSort_(vetor, tam-1, &numComparacoes);
}

// SelectionSort

int minimo(int vetor[], int a, int b, int* numComparacoes)
{
    int m = a;
    for (int i = a+1; i <= b; i++)
    {
        (*numComparacoes)++;
        if (vetor[i] < vetor[m])
            m = i;
    }
    return m;
}

int selectionSort_(int vetor[], int a, int b, int* numComparacoes)
{
    if (a < b)
    {
        int m = minimo(vetor, a, b, numComparacoes);
        troca(vetor, a, m);
        selectionSort_(vetor, a+1, b, numComparacoes);
    }
    return *numComparacoes;
}

int selectionSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	return selectionSort_(vetor, 0, tam-1, &numComparacoes);
}

// MergeSort

int intercala(int vetor[], int a, int m, int b)
{
    int numComparacoes = 0;
    if (a < b)
    {
        int aux[b-a+1];
        int i = a;
        int j = m + 1;
        int k;
        for (k = 0; k <= b-a; k++)
        {
            numComparacoes++;
            if ((j > b) || (i <= m && vetor[i] <= vetor[j]))
            {
                aux[k] = vetor[i];
                i++;
            }
            else
            {
                aux[k] = vetor[j];
                j++;
            }
        }
        i = 0;
        for (k = a; k <= b; k++)
            vetor[k] = aux[i++];
    }
    return numComparacoes;
}

int mergeSort_(int vetor[], int a, int b, int* numComparacoes)
{
    if (a < b)
    {
        int m = (a + b) / 2;
		*numComparacoes += mergeSort_(vetor, a, m, numComparacoes);
		*numComparacoes += mergeSort_(vetor, m+1, b, numComparacoes);
		return intercala(vetor, a, m, b);
	 }
	return 0;
}

int mergeSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	return numComparacoes + mergeSort_(vetor, 0, tam-1, &numComparacoes);
}

// QuickSort

int particiona(int vetor[], int a, int b, int x, int* numComparacoes)
{
    int m = a - 1;
    for (int i = a; i <= b; i++)
    {
        (*numComparacoes)++;
        if (vetor[i] <= x)
        {
            m++;
            troca(vetor, m, i);
        }
    }
    return m;
}

void quickSort_(int vetor[], int a, int b, int* numComparacoes)
{
    if (a < b)
    {
        int m = particiona(vetor, a, b, vetor[b], numComparacoes);
        quickSort_(vetor, a, m - 1, numComparacoes);
        quickSort_(vetor, m + 1, b, numComparacoes);
    }
}

int quickSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	quickSort_(vetor, 0, tam-1, &numComparacoes);
	return numComparacoes;
}
