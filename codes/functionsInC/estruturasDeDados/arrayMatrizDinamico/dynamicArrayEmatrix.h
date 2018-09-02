#pragma once
//Aloca e retorna um array din�mico com o tamanho passado por par�metro
int* alocarArray(int);
//Seta um valor qualquer para todas as posi��es do array din�mico passado como par�metro
//par�metro 2: tamanho do array
//par�metro 3: valor que se quer setar
void setValue(int*,int,int);
//Cria e retorna uma matriz din�mica de nLinhas (par�metro 1) e nColunas (par�metro 2)
int** alocarMatriz(int, int);
