#include "stdafx.h"
#include "iostream"
#include "noGrafo.h"
#include "dynamicArrayEmatrix.h"
int * menoresCustos(int** matrizCaminho, int **matrizPesos, int numeroDeVertices,int numeroDeArestas, int origem)
{
	int* custos = alocarArray(numeroDeVertices);
	int* abertoOuFechado = alocarArray(numeroDeVertices);//alocar array está com o comentário aparecendo, verificar depois

	setValue(custos, numeroDeVertices, 1000);//<<<<<<<<<<<<<<<DEVE SER INFINITO>>>>>>>>>>>>>
	setValue(abertoOuFechado, numeroDeVertices, 1);//1 para aberto, 0 para fechado

	origem = origem - 1;
	custos[origem] = 0;

	int verticeAvaliado = origem;
	while (1) {
		for (int i = 0; i < numeroDeVertices; i++) {
			if (matrizCaminho[verticeAvaliado][i] == 1) {
				for (int j = 0; j < numeroDeArestas; j++) {
					if (matrizPesos[verticeAvaliado][j] == matrizPesos[i][j]) {
						if (custos[i] > custos[verticeAvaliado] + matrizPesos[verticeAvaliado][j]) {
							custos[i] = custos[verticeAvaliado] + matrizPesos[verticeAvaliado][j];
						}
					}
				}
			}
		}
		abertoOuFechado[verticeAvaliado] = 0;

		int qtdeFechados =0;
		for (int i = 0; i < numeroDeVertices; i++) {
			if (!abertoOuFechado[i]) {
				qtdeFechados++;
			}
		}
		if (qtdeFechados == numeroDeVertices) {
			return custos;
		}
		int menor = 1000;
		for (int i = 0; i < numeroDeVertices; i++) {
			if (menor > custos[i] && abertoOuFechado[i]) {
				menor = custos[i];
				verticeAvaliado = i;
			}
		}
	}

	
}
