// Estruturas de Dados.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "iostream"
#include "bloco.h"
#include "mPilha.h"
#include "dynamicArrayEmatrix.h"
#include "filaSimples.h"
#include "filaDupla.h"
#include "blocoDuplo.h"
#include "arvore.h"
#include "noGrafo.h"


int main()
{
	
	int** matrizCaminho;
	int** matrizPeso;
	int noVertice = 7;
	int noAresta = 10;

	matrizCaminho = alocarMatriz(noVertice, noVertice);
	matrizPeso = alocarMatriz(noVertice, noAresta);
	setValue(matrizCaminho[0], 7, 0);
	setValue(matrizCaminho[1], 7, 0);
	setValue(matrizCaminho[2], 7, 0);
	setValue(matrizCaminho[3], 7, 0);
	setValue(matrizCaminho[4], 7, 0);
	setValue(matrizCaminho[5], 7, 0);
	setValue(matrizCaminho[6], 7, 0);
	matrizCaminho[1][0] = 1;
	matrizCaminho[2][1] = 1;
	matrizCaminho[3][2] = 1;
	matrizCaminho[4][0] = 1;
	matrizCaminho[4][1] = 1;
	matrizCaminho[5][2] = 1;
	matrizCaminho[5][3] = 1;
	matrizCaminho[5][4] = 1;
	matrizCaminho[6][4] = 1;
	matrizCaminho[6][5] = 1;

	matrizCaminho[0][1] = 1;
	matrizCaminho[1][2] = 1;
	matrizCaminho[2][3] = 1;
	matrizCaminho[0][4] = 1;
	matrizCaminho[1][4] = 1;
	matrizCaminho[2][5] = 1;
	matrizCaminho[3][5] = 1;
	matrizCaminho[4][5] = 1;
	matrizCaminho[4][6] = 1;
	matrizCaminho[5][6] = 1;


	setValue(matrizPeso[0], 10, 01);
	setValue(matrizPeso[1], 10, 01);
	setValue(matrizPeso[2], 10, 01);
	setValue(matrizPeso[3], 10, 01);
	setValue(matrizPeso[4], 10, 01);
	setValue(matrizPeso[5], 10, 01);
	setValue(matrizPeso[6], 10, 01);
	//setValue(matrizPeso[7], 10, 01);




	int* result = menoresCustos(matrizCaminho, matrizPeso, noVertice, noAresta, 1);

	printf("%i\n", result[0]);
	printf("%i\n", result[1]);
	printf("%i\n", result[2]);
	printf("%i\n", result[3]);
	printf("%i\n", result[4]);
	printf("%i\n", result[5]);
	printf("%i\n", result[6]);
	
	system("pause");
    return 0;
}

/*

Arvore* p;
p = (Arvore*)malloc(sizeof(Arvore));
p->initialize();

p->addBlock(40);
printf("%i", p->tamanho);
p->addBlock(30);
printf("%i", p->tamanho);
p->addBlock(35);
printf("%i", p->tamanho);
p->addBlock(20);
printf("%i", p->tamanho);
p->addBlock(35);
printf("%i", p->tamanho);
p->addBlock(45);
printf("%i", p->tamanho);

p->addBlock(60);
printf("%i", p->tamanho);
p->addBlock(10);
printf("%i", p->tamanho);
p->addBlock(25);
printf("%i", p->tamanho);
p->addBlock(38);
printf("%i", p->tamanho);
p->addBlock(55);
printf("%i", p->tamanho);
p->addBlock(70);
printf("%i", p->tamanho);

printf("%i \n", p->raiz->dado);
printf("%i \n", p->raiz->anterior->dado);
printf("%i \n", p->raiz->anterior->anterior->dado);
printf("%i \n", p->raiz->anterior->anterior->anterior->dado);

printf("%i \n", p->raiz->anterior->anterior->proximo->dado);
printf("%i \n", p->raiz->anterior->proximo->dado);
printf("%i \n", p->raiz->anterior->proximo->proximo->dado);

printf("%i \n", p->raiz->proximo->dado);
//	printf("%i \n", p->raiz->proximo->anterior->dado);
printf("%i \n", p->raiz->proximo->proximo->dado);

printf("%i \n", p->raiz->proximo->proximo->anterior->dado);
printf("%i \n", p->raiz->proximo->proximo->proximo->dado);

//if (p->removeBlock(70)) {printf("OK1\n");}
//if (p->removeBlock(55)) { printf("OK2\n"); }
//if (p->removeBlock(38)) { printf("OK3\n"); }
//if (p->removeBlock(25)) { printf("OK4\n"); }
printf("\n");

int* arranjo;
arranjo = p->arranjoOfData();
for (int i = 0; i < p->tamanho ; i++) {
printf("%i \n", arranjo[i]);
}

*/
/*

FilaDupla* p;
p = (FilaDupla*)malloc(sizeof(FilaDupla));
p->initialize();
int x = 0;
while (x <= 100)
{
	p->addBlockFim(x);
	x++;
}
blocoDuplo* b;
b = p->inicio;
x--;
while (x >0) {

	b = b->proximo;
	printf("%i,\n", b->dado);
	x--;
}
int u = p->removeBlockFim();
printf("%i\n", u);
u = p->removeBlockFim();
printf("%i\n", u);
u = p->removeBlockFim();
printf("%i\n", u);

try {
	int v = p->removeBlockFim();
	printf("%i", v);
}
catch (int e) {
}
x = 97;
b = p->inicio;
while (x >0) {

	b = b->proximo;
	printf("%i,\n", b->dado);
	x--;
}

FilaDupla* p2;
p2 = (FilaDupla*)malloc(sizeof(FilaDupla));
p2->initialize();
p2->addBlockFim(10);
p2->addBlockInicio(13);
p2->addBlockFim(102);

p2->addBlockInicio(190);
p2->addBlockFim(193);
p2->addBlockInicio(1902);

p2->removeBlockFim();
p2->removeBlockInicio();

p2->removeBlockFim();
p2->removeBlockInicio();

p2->removeBlockFim();
p2->removeBlockInicio();

//int* arranjo;
//arranjo = p->arranjoOfData();
//for (int i = 0; i < p->tamanho; i++) {
//	printf("%i \n", arranjo[i]);
//}
/*
try {int v = p->removeBlock();
printf("%i", v);}
catch (int e) {
}



/*
bloco* a;
a = (bloco*)malloc(sizeof(bloco));
a->dado = NULL;
if (isNull(a)) {
printf("é nulo");
}
a->dado = 1;

Pilha* p;
p = (Pilha*)malloc(sizeof(Pilha));
p->initialize();
int x = 0;
while (x<100)
{
p->addBlock(x);
x++;
}
//x = 0;
bloco* b;
b = p->topo;
x--;
while (x >0) {

b = b->proximo;
printf("%i,\n",b->dado);
x--;
}
int u = p->removeBlock();
printf("%i\n", u);
u = p->removeBlock();
printf("%i\n", u);
u = p->removeBlock();
printf("%i\n", u);
/*
try {int v = p->removeBlock();
printf("%i", v);}
catch (int e) {
}


int v2 = p->removeBlock();
printf("%i", v2);
int v3 = p->removeBlock();
printf("%i", v3);
try {
int v4 = p->removeBlock();
printf("%i", v4);
}
catch (int e) {
}
*/

//system("pause");


//for (int i = 0; i++; i < 10000000000000000000) {
//	p->addBlock(i);
//}
//for (int i = 0; i++; i < 10000000000000000) {
//	p->removeBlock();
//}
