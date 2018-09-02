#include "stdafx.h"
#include "iostream"
#include "tabelaHash.h"
#include "bloco.h"
#include "filaSimples.h"
#include "pacoteStr.h"

//método de Horner(modificado) para calcular o hash de cadeias alfanuméricas(string)
int Hash::ValorHash(char* v) {
	int i, h = v[0];
	for (i = 1; v[i] != '\0'; i++) {
		h = (h * 251 + v[i]) % tamanhoHash;
	}
	return h;
}


//Fazendo a busca de uma chave no hash
//retorna a posição dessa chave no Hash, ou NULL caso ela não esteja
int Hash::buscarChave(noHash* hash, char chave[]) {
	int posicao = ValorHash(chave);
	int aux = posicao;
	struprSubstituto(chave);
	while (aux < tamanhoHash && hash[aux].Usado) {//endereçamento fechado, caso a palavra não esteja na posição de Hash porcura-se na tabela até encontrá-la
		if (strcmpSubstituto(chave, hash[aux].dado) == 0) {
			return aux;
		}
		aux++;
	}
	aux = 0;
	while (aux < posicao && hash[aux].Usado) {
		if (chave == hash[aux].dado) {
			return aux;
		}
		aux++;
	}
	return NULL;
}

//deletando uma chave do Hash, não utilizada nesse exemplo, mas essencial para qualquer hash fechado
void Hash::deleteChave(noHash* hash, char chave[]) {
	int x = buscarChave(hash, chave);
	if (x != NULL) {
		char temp[] = " ";
		strcpySubstituto(hash[x].dado, temp);
		hash[x].Ocupado = false;//a posição não está mais ocupada
		hash[x].id = NULL;
	}
}

void Hash::inicializa(noHash* p, int tam) {
	//inicializa a tabela hash atribuindo valores nulos para os seus dados
	tamanhoHash = tam;
	for (int k = 0; k < tamanhoHash; k++) {
		p[k].Ocupado = false;
		p[k].Usado = false;
		p[k].id = NULL;
	}
}

void Hash::redimensiona() {//é necessário caso a tabela hash esteja cheia
	if (tamanhoHash <= 500) {
		tamanhoHash = 5003;//alguns números primos para manter a função hash com um bom espalhamento, 5003, 50021, 100003
	}
	else if (tamanhoHash <= 5004) {
		tamanhoHash = 50021;
	}
	else if (tamanhoHash <= 50000) {
		tamanhoHash = 100003;
	}
	else {
		tamanhoHash = 2 * tamanhoHash - 1;
	}
}

void Hash::inserirChave(noHash* p, char chave[], int doc) {

	int op = buscarChave(p, chave);
	if (op == NULL) {
		int posicao = ValorHash(chave);
		if (p[posicao].Ocupado) {
			int i = posicao;
			bool guardado = false;
			while (i < tamanhoHash && !guardado) {//procura o primeiro local vago após o número do hash
				if (!p[i].Ocupado) {
					guardado = true;
					p[i].dado = (char*)malloc(strlenSubstituto(chave) * sizeof(char));
					strcpySubstituto(p[i].dado, chave);
					p[i].Ocupado = true;
					p[i].Usado = true;
					inserir(&p[i].id, doc);//insere o id na bloco correspondente a posicao da palavra
					TamAtual++;
				}
				i++;
			}
			if (!guardado) {
				int x = 0;
				while (x < posicao && !guardado) {//procura o primeiro local vago após o número do hash a partir do começo, pois não há vagas após o valor calculado
					if (!p[x].Ocupado) {
						guardado = true;
						p[x].dado = (char*)malloc(strlenSubstituto(chave) * sizeof(char));
						strcpySubstituto(p[x].dado, chave);
						p[x].Ocupado = true;
						p[x].Usado = true;
						inserir(&p[x].id, doc);//insere o id na bloco correspondente a posicao da palavra
						TamAtual++;
					}
					x++;
				}
			}
		}
		else {
			//caso a posicao calculada para a palavra esteja vazia adiciona normalmente
			p[posicao].dado = (char*)malloc(strlenSubstituto(chave) * sizeof(char));
			strcpySubstituto(p[posicao].dado, chave);
			p[posicao].Ocupado = true;
			p[posicao].Usado = true;
			inserir(&p[posicao].id, doc);//insere o id na bloco correspondente a posicao da palavra
			TamAtual++;
		}
	}
	else {
		//a palavra já está na tabela nesse caso basta inserir o id do documento em que ela foi encontrada
		inserir(&p[op].id, doc);
	}
}


