#include "dynamicArrayEmatrix.h"
#include "stdafx.h"
#include "iostream"

int* alocarArray(int tamanho)
{
	int* inicio;
	inicio = (int*)malloc(tamanho*sizeof(int));
	return inicio;
}

void setValue(int* arranjo,int tamanho,int value) {
	for (int i = 0; i < tamanho; i++) {
		arranjo[i] = value;
	}
}

int** alocarMatriz(int nLinha, int nColuna)
{
	int **matriz = (int**)malloc(nLinha * sizeof(int*)); 

	for (int i = 0; i < nLinha; i++) { 
		//Em termos de desempenho qual dessas opções seria melhor?
		//matriz[i] = (int*)malloc(nColuna * sizeof(int)); 
		matriz[i] = alocarArray(nColuna);
	}
	return matriz; 
}


