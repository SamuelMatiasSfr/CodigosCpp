//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : LP1-05-Atividade de laboratório.pdf
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamString 45

void tratarArquivo(char nome[], int tamMinimo){
	FILE *arq;
	arq = fopen(nome, "r");
	if (arq == NULL) {
	    printf("Erro ao abrir o arquivo.\n");
	}

	char linha[999];
	int cont=0;
	int tamMaior=0;
	char palavraMaior[tamString] = "";
	const char delimitadores[] = " ,.;-\n\"!()?";

	while(fgets(linha, 999, arq) != NULL){
		char *token = strtok(linha, delimitadores);

		while(token != NULL){
			int tamToken = strlen(token);
			if(tamToken > tamMinimo){
				cont++;

				if(tamToken > tamMaior){
					strcpy(palavraMaior, token);
					tamMaior = tamToken;

				}
			}

			token = strtok(NULL, delimitadores);
		}
	}

	fclose(arq);

	printf("A maior palavra é '%s' e possui %d caracteres.\n", palavraMaior, tamMaior);
	printf("Existem %d palavras maiores que %d caracteres.\n", cont, tamMinimo);
}

int main() {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "Portuguese");

	char nomeArq[tamString];

	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArq);

	tratarArquivo(nomeArq, 15);

	return 0;
}

