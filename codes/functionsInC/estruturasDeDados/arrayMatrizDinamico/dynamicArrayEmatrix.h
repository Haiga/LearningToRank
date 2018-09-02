#pragma once
//Aloca e retorna um array dinâmico com o tamanho passado por parâmetro
int* alocarArray(int);
//Seta um valor qualquer para todas as posições do array dinâmico passado como parâmetro
//parâmetro 2: tamanho do array
//parâmetro 3: valor que se quer setar
void setValue(int*,int,int);
//Cria e retorna uma matriz dinâmica de nLinhas (parâmetro 1) e nColunas (parâmetro 2)
int** alocarMatriz(int, int);
