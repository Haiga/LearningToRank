#include "stdafx.h"
#include "iostream"
#include "dynamicArrayEmatrix.h"
#include "filaDupla.h"

void FilaDupla::initialize()
{
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

void FilaDupla::addBlockInicio(int value)
{
	blocoDuplo* tempBlock;
	tempBlock = (blocoDuplo*)malloc(sizeof(blocoDuplo));

	tempBlock->dado = value;
	tempBlock->proximo = inicio;
	if (tamanho == 0) {
		inicio = tempBlock;
	}
	else {
		inicio->anterior = tempBlock;
	}
	inicio = tempBlock;
	tamanho++;
}

void FilaDupla::addBlockFim(int value)
{
	blocoDuplo* tempBlock;
	tempBlock = (blocoDuplo*)malloc(sizeof(blocoDuplo));

	tempBlock->dado = value;
	if (tamanho == 0) {
		inicio = tempBlock;
	}
	else {
		fim->proximo = tempBlock;
	}
	tempBlock->proximo = NULL;
	tempBlock->anterior = fim;
	fim = tempBlock;
	tamanho++;
}

int FilaDupla::removeBlockInicio()
{
	if (inicio == NULL) {
		throw 0;
	}

	int value;
	blocoDuplo* tempBlock;

	value = inicio->dado;
	tempBlock = inicio;
	inicio = inicio->proximo;
	//inicio->anterior = NULL;
	tamanho--;

	delete tempBlock;
	return value;
}

int FilaDupla::removeBlockFim()
{
	if (fim == NULL) {
		throw 0;
	}

	int value;
	blocoDuplo* tempBlock;

	value = fim->dado;
	tempBlock = fim;
	fim = fim->anterior;
	fim->proximo = NULL;
	tamanho--;

	delete tempBlock;
	return value;
}

int * FilaDupla::arranjoOfData()
{
	int* arranjo;
	blocoDuplo* auxiliarBlock;

	arranjo = alocarArray(tamanho);
	auxiliarBlock = inicio;
	arranjo[0] = auxiliarBlock->dado;

	for (int i = 1; i < tamanho; i++) {
		auxiliarBlock = auxiliarBlock->proximo;
		arranjo[i] = auxiliarBlock->dado;
	}
	return arranjo;
}
