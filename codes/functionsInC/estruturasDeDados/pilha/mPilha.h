//Esta implementa��o de pilha permite realizar o comportamento padr�o de pilha 
//Ou seja, s� � poss�vel remover o �ltimo elemento empilhado
#pragma once
#include "bloco.h"

struct Pilha
{
	bloco* topo;
	int tamanho;

	//Fun��o necess�ria sempre que se criar uma nova pilha
	void initialize();
	//Adiciona um elemento com dado "value" ao topo da pilha
	void addBlock(int);
	//Remove o elemento do topo da pilha e retorna seu dado
	//Lan�a uma exce��o 0 se tentar remover um elemento de uma pilha vazia
	int removeBlock();
	//Retorna um array din�mico que cont�m os elementos da pilha a partir do topo
	int* arranjoOfData();
};

