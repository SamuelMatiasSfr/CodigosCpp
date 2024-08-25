//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Prova Mensal Prática-LP1-1ºBim.pdf
//============================================================================

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>


int determinante(int a[2][2]){
	return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
}

void atividade1(){
	int matriz[2][2];

	printf("Entre com elementos da matriz:\n");
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("Entre com o elemento [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}

	printf("\nMatriz fornecida:\n");
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("[%d]", matriz[i][j]);
		}
		printf("\n");
	}

	int detA = determinante(matriz);
	printf("\nDeterminante da matriz: %d", detA);
}



void substituir(char matriz[2][2]){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			switch(matriz[i][j]){
			case 48:
				matriz[i][j] = 'a';
				break;
			case 49:
				matriz[i][j] = 'e';
				break;
			case 50:
				matriz[i][j] = 'i';
				break;
			case 51:
				matriz[i][j] = 'o';
				break;
			case 52:
				matriz[i][j] = 'u';
				break;
			}
		}
	}
}

void atividade2(){
	char matriz[2][2];
	char nome[50];

	FILE *arq;

	printf("Digite o nome do arquivo: ");
	scanf("%s", nome);

	arq = fopen(nome, "r");

	if (arq == NULL) {
	   printf("Erro ao abrir o arquivo");
	}

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			char c = fgetc(arq);
			printf("%c", c);
			if((c != ' ') && (c != '\n') && (c != ',')){
				matriz[i][j] = c;
			}else j--;
		}
	}

	fclose(arq);

	printf("\nMatriz fornecida:\n");
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("[%c]", matriz[i][j]);
		}
		printf("\n");
	}

	substituir(matriz);

	printf("Matriz modififcada:\n");
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("[%c]", matriz[i][j]);
		}
		printf("\n");
	}
}

void inverter(int array[], int t){
	int temp[t];
	for(int i=0; i<t; i++){
		temp[i] = array[i];
	}

	int j=0;
	for(int i=(t-1); i>=0; i--){
		array[j] = temp[i];
		j++;
	}

	printf("\nArray invertido:\n");
	for(int i=0; i<t; i++){
		printf("Array[%d] = %d\n", i, array[i]);
	}
}

void maior_menor(int array[], int t){
	int maior = array[0];
	int menor = array[0];
	for(int i=0; i<t; i++){
		if(array[i] > maior){
			maior = array[i];
		}
		if(array[i] < menor){
			menor = array[i];
		}
	}
	printf("\nMaior valor: %d \nMenor valor: %d", maior, menor);
}

void atividade3(){
	int tam;
	printf("Digite o tamanho da função: ");
	scanf("%d", &tam);

	int vetor[tam];
	for(int i=0; i<tam; i++){
		printf("Digite o elemento array[%d]: ", i);
		scanf("%d", &vetor[i]);
	}

	inverter(vetor, tam);
	maior_menor(vetor, tam);
}

int main() {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "Portuguese");

	//atividade1();
	atividade2();
	//atividade3();

	return 0;

}
