//Esta implementa��o de fila Duplamente encade permite realizar o comportamento padr�o de fila
//Ou seja, � poss�vel remover o primeiro ou o �ltimo elemento enfileirado
#include "blocoDuplo.h"

struct FilaDupla
{
	blocoDuplo* inicio;
	blocoDuplo* fim;
	int tamanho;

	//Fun��o necess�ria sempre que se criar uma nova fila
	void initialize();
	//Adiciona um elemento com dado "value" ao inicio da fila
	void addBlockInicio(int);
	//Adiciona um elemento com dado "value" ao fim da fila
	void addBlockFim(int);
	//Remove o elemento do in�cio da fila e retorna seu dado
	//Lan�a uma exce��o 0 se tentar remover um elemento de uma fila vazia
	int removeBlockInicio();
	//Remove o elemento do fim da fila e retorna seu dado
	//Lan�a uma exce��o 0 se tentar remover um elemento de uma fila vazia
	int removeBlockFim();
	//Retorna um array din�mico que cont�m os elementos da fila a partir do in�cio
	int* arranjoOfData();
};

