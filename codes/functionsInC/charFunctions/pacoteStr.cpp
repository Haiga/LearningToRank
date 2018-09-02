#include "stdafx.h"
#include "iostream"
#include "pacoteStr.h"

int strcmpSubstituto(char chave1[], char chave2[]) {
	int i = 0;
	while (chave1[i]) {
		if (chave1[i] > chave2[i]) {
			return 1;
		}
		else if (chave1[i] < chave2[i]) {
			return -1;
		}
		i++;
	}
	return 0;
}
int strlenSubstituto(char chave[]) {
	int i = 0;
	while (chave[i]) {
		i++;
	}
	return i;
}
void struprSubstituto(char chave[]) {
	int i = 0;
	while (chave[i]) {
		chave[i] = toupper(chave[i]);
		i++;
	}
}
void strcpySubstituto(char chave1[], char chave2[]) {
	int i = 0;
	while (chave1[i]) {
		chave1[i] = chave2[i];
		i++;
	}
}