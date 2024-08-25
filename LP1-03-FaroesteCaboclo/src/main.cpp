//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : LP1-03-Arquivos de texto-Para Casa.pdf
//============================================================================

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO_STRING 50

int main(){
	setlocale(LC_ALL, "Portuguese.UTF-8");
	setbuf(stdout, NULL);

	char nome1[TAMANHO_STRING], nome2[TAMANHO_STRING];
	printf("Digite o nome do primeiro arquivo: ");
	scanf("%s", nome1);
	printf("Digite o nome do segundo arquivo: ");
	scanf("%s", nome2);

	FILE *arq;
	arq = fopen(nome1, "r");
	if(arq == NULL){
		printf("Erro ao abrir um arquivo.");
		return 1;
	}

	char palavra[TAMANHO_STRING];
	printf("Digite a palavra a ser procurada: ");
	scanf("%s", palavra);

	int cont=0;
	char linha[999];
	while((fgets(linha, 999, arq) != NULL)){
		if(strstr(linha, palavra) != NULL){
			cont++;
		}
	}

	fclose(arq);

	printf("A palavra %s apararece %d vezes no arquivo.\n", palavra, cont);

	//FIM DA PRIMEIRA PARTE


	arq = fopen(nome1, "r");
	if(arq == NULL){
		printf("Erro ao abrir um arquivo.");
		return 1;
	}

	FILE *newFile;
	newFile = fopen(nome2, "w");
	if(newFile == NULL){
		printf("Erro ao abrir um arquivo.");
		return 1;
	}

	char substituida[TAMANHO_STRING];
	printf("\nDigite a palavra a ser substitui­da: ");
	scanf("%s", substituida);

	char nova[TAMANHO_STRING];
	printf("Digite a palavra nova: ");
	scanf("%s", nova);

	char string[TAMANHO_STRING];
	char c;

	while ((fscanf(arq, "%s", string) != EOF) && ((c = fgetc(arq)) != EOF)){
		if(strcmp(string, substituida) == 0){
			fprintf(newFile, "%s", nova);
		}else{
			fprintf(newFile, "%s", string);
		}
		if((c == ' ') || (c == '\n')){
			fputc(c, newFile);
		}
	}

	fclose(arq);
	fclose(newFile);

	system("pause");
	return 0;
}
