//Esta implementa��o de fila permite realizar o comportamento padr�o de fila
//Ou seja, s� � poss�vel remover o primeiro elemento enfileirado
#pragma once
#include "blocoDuplo.h"

struct Arvore
{
	blocoDuplo* raiz;
	int tamanho;

	//Fun��o necess�ria sempre que se criar uma nova fila
	void initialize();
	//Adiciona um elemento com dado "value" ao fim da fila
	void addBlock(int);
	//Remove o elemento do in�cio da fila e retorna seu dado
	//Lan�a uma exce��o 0 se tentar remover um elemento de uma fila vazia
	bool removeBlock(int);
	//Retorna um array din�mico que cont�m os elementos da fila a partir do in�cio
	int* arranjoOfData();
};

