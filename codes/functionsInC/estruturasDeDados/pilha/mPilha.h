//Esta implementação de pilha permite realizar o comportamento padrão de pilha 
//Ou seja, só é possível remover o último elemento empilhado
#pragma once
#include "bloco.h"

struct Pilha
{
	bloco* topo;
	int tamanho;

	//Função necessária sempre que se criar uma nova pilha
	void initialize();
	//Adiciona um elemento com dado "value" ao topo da pilha
	void addBlock(int);
	//Remove o elemento do topo da pilha e retorna seu dado
	//Lança uma exceção 0 se tentar remover um elemento de uma pilha vazia
	int removeBlock();
	//Retorna um array dinâmico que contém os elementos da pilha a partir do topo
	int* arranjoOfData();
};

