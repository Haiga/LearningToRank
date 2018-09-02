#include "stdafx.h"
#include "iostream"
#include "arvore.h"
#include "dynamicArrayEmatrix.h"

void Arvore::initialize()
{
	raiz = NULL;
	tamanho = 0;
}

//anterior é esquerda
//próximo é direita
void Arvore::addBlock(int value)
{
	blocoDuplo* tempBlock;
	tempBlock = (blocoDuplo*)malloc(sizeof(blocoDuplo));

	tempBlock->dado = value;
	tempBlock->anterior = NULL;
	tempBlock->proximo = NULL;
	if (tamanho == 0) {
		raiz = tempBlock;
	}
	else {
		blocoDuplo* auxiliarBlock;
		blocoDuplo* auxiliarBlockPai;
		auxiliarBlock = raiz;
		auxiliarBlockPai = raiz;
		//while para achar a posição
		while (auxiliarBlock!=NULL) {
			auxiliarBlockPai = auxiliarBlock;
			if (auxiliarBlock->dado > value) {
				auxiliarBlock = auxiliarBlock->anterior;
			}
			else if (auxiliarBlock->dado < value) {
				auxiliarBlock = auxiliarBlock->proximo;
			}
			else {
				break;
			}
		}
		if (value < auxiliarBlockPai->dado) {
			auxiliarBlockPai->anterior = tempBlock;
		}
		else if (value > auxiliarBlockPai->dado) {
			auxiliarBlockPai->proximo = tempBlock;
		}
		else {
			//Caso queira fazer algo com dados repitidos
			tamanho--;
		}
	}
	tamanho++;
}

bool Arvore::removeBlock(int value)
{
	blocoDuplo* auxiliarBlock;
	blocoDuplo* tempBlock;
	blocoDuplo* auxiliarBlockPai;
	auxiliarBlock = raiz;
	auxiliarBlockPai = raiz;
	if (value == raiz->dado) {
		if (raiz->proximo == NULL) {
			raiz = raiz->anterior;
		}
		else {
			raiz = raiz->proximo;
			blocoDuplo* auxiliarBlockBusca;
			auxiliarBlockBusca = raiz;
			while (auxiliarBlockBusca->anterior != NULL) {
				auxiliarBlockBusca = auxiliarBlockBusca->anterior;
			}
			auxiliarBlockBusca->anterior = auxiliarBlock->anterior;
		}
		delete(auxiliarBlock);
		tamanho--;
		return true;
	}
	else {
		while (auxiliarBlock != NULL) {
			tempBlock = auxiliarBlock;

			if (auxiliarBlock->dado > value) {
				auxiliarBlock = auxiliarBlock->anterior;
			}
			else if (auxiliarBlock->dado < value) {
				auxiliarBlock = auxiliarBlock->proximo;
			}
			else {
				if (auxiliarBlockPai->dado > value) {
					if (auxiliarBlock->proximo == NULL) {
						auxiliarBlockPai->anterior = auxiliarBlock->anterior;
					}
					else {
						auxiliarBlockPai->anterior = auxiliarBlock->proximo;
						blocoDuplo* auxiliarBlockBusca;
						auxiliarBlockBusca = auxiliarBlock->proximo;
						while (auxiliarBlockBusca->anterior != NULL) {
							auxiliarBlockBusca = auxiliarBlockBusca->anterior;
						}
						auxiliarBlockBusca->anterior = auxiliarBlock->anterior;
					}
				}
				else {
					if (auxiliarBlock->proximo == NULL) {
						auxiliarBlockPai->proximo = auxiliarBlock->anterior;
					}
					else {
						auxiliarBlockPai->proximo = auxiliarBlock->proximo;
						blocoDuplo* auxiliarBlockBusca;
						auxiliarBlockBusca = auxiliarBlock->proximo;
						while (auxiliarBlockBusca->anterior != NULL) {
							auxiliarBlockBusca = auxiliarBlockBusca->anterior;
						}
						auxiliarBlockBusca->anterior = auxiliarBlock->anterior;
					}
				}
				delete(auxiliarBlock);//
				tamanho--;
				return true;
			}
			auxiliarBlockPai = tempBlock;
		}
		return false;
	}
}

int * Arvore::arranjoOfData()
{
	int* arranjo;
	blocoDuplo* auxiliarBlock;
	blocoDuplo** pilha;
	pilha = (blocoDuplo**)malloc(sizeof(blocoDuplo));
	arranjo = alocarArray(tamanho);
	auxiliarBlock = raiz;

	int i = 0;
	int contPilha = 0;

	while (auxiliarBlock!=NULL) {
		arranjo[i] = auxiliarBlock->dado;
		i++;
		if (auxiliarBlock->anterior != NULL) {
			if (auxiliarBlock->proximo != NULL) {
				pilha[contPilha] = (blocoDuplo*)malloc(sizeof(blocoDuplo));
				pilha[contPilha] = auxiliarBlock->proximo;
				contPilha++;
			}
			auxiliarBlock = auxiliarBlock->anterior;
		}
		else if (auxiliarBlock->proximo != NULL) {
			auxiliarBlock = auxiliarBlock->proximo;
		}
		else {
			if (contPilha > 0) {
				contPilha--;
				auxiliarBlock = pilha[contPilha];
			}
			else {
				return arranjo;
			}
		}
	}
	return arranjo;
}