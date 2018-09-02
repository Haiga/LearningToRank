#include "stdafx.h"
#include "iostream"
#include "mPilha.h"
#include "dynamicArrayEmatrix.h"


void Pilha::initialize()
{
	topo = NULL;
	tamanho = 0;
}

void Pilha::addBlock(int value)
{
	bloco* tempBlock;
	tempBlock = (bloco*)malloc(sizeof(bloco));

	tempBlock->dado = value;
	tempBlock->proximo = topo;
	topo = tempBlock;
	tamanho++;
}

int Pilha::removeBlock()
{
	if (topo == NULL) {
		throw 0;
	}

	int value;
	bloco* tempBlock;

	value = topo->dado;
	tempBlock = topo;
	topo = topo->proximo;
	tamanho--;

	delete tempBlock;
	return value;
}

int* Pilha::arranjoOfData()
{
	int* arranjo;
	bloco* auxiliarBlock;

	arranjo = alocarArray(tamanho);
	auxiliarBlock = topo;
	arranjo[0] = auxiliarBlock->dado;
	
	for (int i = 1; i < tamanho; i++) {
		auxiliarBlock = auxiliarBlock->proximo;
		arranjo[i] = auxiliarBlock->dado;
	}
	return arranjo;
}

