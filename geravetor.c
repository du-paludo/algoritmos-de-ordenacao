#include <stdio.h>
#include <stdlib.h>
#include "geravetor.h"

void copia_vetor(int v1[], int v2[], int N)
{
	for (int i = 0; i < N; i++)
		v2[i] = v1[i];
}

void crescente(int v[], int N)
{
	for (int i = 0; i < N; i++)
		v[i] = i;
}

void decrescente(int v[], int N)
{
	int j = N - 1;
	for (int i = 0; i < N; i++)
	{
		v[i] = j;
		j--;
	}
}

void aleatorio(int v[], int N)
{
	for (int i = 0; i < N; i++)
		v[i] = rand()%N;
}
