//Esta implementação de fila Duplamente encade permite realizar o comportamento padrão de fila
//Ou seja, é possível remover o primeiro ou o último elemento enfileirado
#include "blocoDuplo.h"

struct FilaDupla
{
	blocoDuplo* inicio;
	blocoDuplo* fim;
	int tamanho;

	//Função necessária sempre que se criar uma nova fila
	void initialize();
	//Adiciona um elemento com dado "value" ao inicio da fila
	void addBlockInicio(int);
	//Adiciona um elemento com dado "value" ao fim da fila
	void addBlockFim(int);
	//Remove o elemento do início da fila e retorna seu dado
	//Lança uma exceção 0 se tentar remover um elemento de uma fila vazia
	int removeBlockInicio();
	//Remove o elemento do fim da fila e retorna seu dado
	//Lança uma exceção 0 se tentar remover um elemento de uma fila vazia
	int removeBlockFim();
	//Retorna um array dinâmico que contém os elementos da fila a partir do início
	int* arranjoOfData();
};

