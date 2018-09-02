//Esta implementação de pilha permite realizar o comportamento padrão de pilha 
//Ou seja, só é possível remover o último elemento empilhado
#pragma once
#include "bloco.h"
struct noHash {
	char* dado;
	bool Usado;//false para não usado, true para usado
	bool Ocupado;//false para não ocupado, true para ocupado
	bloco* id;//ponteiro para um arranjo dos documentos
};
struct Hash
{
	//bloco* block;

	int tamanhoHash;////1003
	int TamAtual;////0

	void inicializa(noHash*, int);
	void redimensiona();
	int ValorHash(char*);
	void inserirChave(noHash*, char chave[], int);
	int buscarChave(noHash*, char chave[]);
	void deleteChave(noHash*, char chave[]);
};

