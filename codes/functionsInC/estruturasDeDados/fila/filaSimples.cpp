#include "stdafx.h"
#include "iostream"
#include "dynamicArrayEmatrix.h"
#include "filaSimples.h"

void Fila::initialize()
{
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

void Fila::addBlock(int value)
{
	bloco* tempBlock;
	tempBlock = (bloco*)malloc(sizeof(bloco));

	tempBlock->dado = value;
	tempBlock->proximo = NULL;
	if (tamanho == 0) {
		inicio = tempBlock;
	}
	else {
		fim->proximo = tempBlock;
	}
	fim = tempBlock;
	tamanho++;
}


int Fila::removeBlock()
{
	if (inicio == NULL) {
		throw 0;
	}

	int value;
	bloco* tempBlock;

	value = inicio->dado;
	tempBlock = inicio;
	inicio = inicio->proximo;
	tamanho--;

	delete tempBlock;
	return value;
}

int * Fila::arranjoOfData()
{
	int* arranjo;
	bloco* auxiliarBlock;

	arranjo = alocarArray(tamanho);
	auxiliarBlock = inicio;
	arranjo[0] = auxiliarBlock->dado;

	for (int i = 1; i < tamanho; i++) {
		auxiliarBlock = auxiliarBlock->proximo;
		arranjo[i] = auxiliarBlock->dado;
	}
	return arranjo;
}


//necessário para não inserir elementos repetidos na bloco de documentos
bool buscaID(bloco *p, int id)
{
	while (p != NULL)
	{
		if (p->dado == id) {
			return true;
		}
		p = p->proximo;
	}
	return false;
}

void inserir(bloco **p, int num) {//função base da bloco: insere novos elementos na bloco
	if (!(buscaID(*p, num))) {

		bloco *atual, *novo, *anterior;
		novo = (bloco *)malloc(sizeof(bloco));

		atual = *p;
		anterior = NULL;
		novo->dado = num;

		if (atual == NULL) {
			novo->proximo = NULL;
			*p = novo;
		}
		else {
			while (atual != NULL && atual->dado < num) {

				anterior = atual;
				atual = atual->proximo;
			}
			novo->proximo = atual;
			if (anterior == NULL) {
				*p = novo;
			}
			else {
				anterior->proximo = novo;
			}
		}
	}
}


void mostrabloco(bloco *p)//mostra os IDs onde a palavra aparece
{
	while (p != NULL)
	{
		printf("%d \n", p->dado);
		p = p->proximo;
	}
}
