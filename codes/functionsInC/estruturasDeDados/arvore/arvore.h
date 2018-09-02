//Esta implementação de fila permite realizar o comportamento padrão de fila
//Ou seja, só é possível remover o primeiro elemento enfileirado
#pragma once
#include "blocoDuplo.h"

struct Arvore
{
	blocoDuplo* raiz;
	int tamanho;

	//Função necessária sempre que se criar uma nova fila
	void initialize();
	//Adiciona um elemento com dado "value" ao fim da fila
	void addBlock(int);
	//Remove o elemento do início da fila e retorna seu dado
	//Lança uma exceção 0 se tentar remover um elemento de uma fila vazia
	bool removeBlock(int);
	//Retorna um array dinâmico que contém os elementos da fila a partir do início
	int* arranjoOfData();
};

