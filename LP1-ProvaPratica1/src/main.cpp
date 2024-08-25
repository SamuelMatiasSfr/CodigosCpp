//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

//* QUESTÃO 2
#include <stdio.h>
#include <limits.h>

int media(int array[], int tamanho) {
	int i, valor = 0;
	for (i = 0; i < tamanho; ++i) {
		valor += *array;
		array++;
	}
	return valor/tamanho;
}

void questao2() {
	int array[] = { 12, 5, 15, 36, 8, 4, 6, 78, 1, 5 };
	int valor = media(array, 10);
	printf("Media: %d \n", valor);
}

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	questao2();
	return 0;
}
//*/

/* QUESTÃO 3
#include<stdio.h>

int main(int argc, char **argv) {

	int i, x = 10;
	int vetor[4];
	int *pv;

	for (i = 0; i < 4; ++i) {
		vetor[i] = i * x;
		pv = &vetor[i];
	}
	pv--;

	printf("%d", *pv);
	return 0;
}
*/

/* QUESTÃO 4
#include <stdio.h>
int main() {
	FILE *pFile;
	char minhaPalavra[100];
	pFile = fopen("dados.csv", "r");
	if (pFile != NULL) {
		if (fgets(minhaPalavra, 100, pFile) != NULL){
			fputs(minhaPalavra, stdout);
		}
		fclose(pFile);
	}
	return 0;
}

*/

/* QUESTÃO 5
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int *pv;
	pv = (int*) malloc(10 * sizeof(int));
	int *inicio;
	inicio = pv;
	for (int i = 0; i < 10; ++i) {
		*pv = i * 10;
		pv++;
	}
	pv = inicio;
	for (int i = 0; i < 10; ++i) {
		printf("%d - ", *pv);
		pv++;
	}
	free(inicio);
	return 0;
}
*/
