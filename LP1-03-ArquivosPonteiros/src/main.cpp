//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : LP1-03-Ponteiros-Atividade de laboratório.pdf
//============================================================================

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void atividade2(){
	FILE *arq;
	arq = fopen("arquivo.txt", "w");

	fprintf(arq, "A primeira linha: 'int *p, *q;' declara dois ponteiros para armazenar o endereço de memória do tipo inteiro.\n");
	fprintf(arq, "A segunda linha: 'p = malloc (sizeof (int));' eu não sei o que faz.\n");
	fprintf(arq, "A terceira linha: '*p = 123;' aloca o valor 123 no endereço de memória apontado por '*p1'.\n");
	fprintf(arq, "A quarta linha: 'q = malloc (sizeof (int));' eu não sei o que faz.\n");
	fprintf(arq, "A quinta linha: '*q = *p;' aloca o valor apontado '*p' no endereço de memória apontado por '*q'.\n");
	fprintf(arq, "A sexta linha: 'q = p;' faz com que o ponteiro 'q' passe a apontar para o mesmo endereço de memória de 'p'.\n");
	fprintf(arq, "A sétima linha: 'free(p)'; libera a memória alocada em 'p'.\n");
	fprintf(arq, "A oitava linha: 'free(q);' libera a memória alocada em 'q'.\n");
	fprintf(arq, "A nona linha: 'q = NULL;' o ponteiro 'q' aponta para um endereço de memória inválido.\n");
}


void atividade3(){
	typedef struct{
		int dia, mes, ano;
	} data;

	printf("sizeof(data) = %d\n", sizeof(data));
	printf("sizeof(data*) = %d\n", sizeof(data*));

	printf("\nO primeiro printf está mostrando o tamanho da estrutura 'data' em bytes.");
	printf("\nJá o segundo printf exibe o tamanho de um ponteiro para estrura 'data' em bytes.");
}

void multiplicaPorDois(int array[]){
	for(int i=0; i<10; i++){
		array[i] = array[i] * 2;
	}
}

void atividade4(){
	int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("Array antes da função: ");
	for(int i=0; i<10; i++){
		printf("%d\n", vetor[i]);
	}

	multiplicaPorDois(vetor);

	printf("\n\nArray depois da função: ");
	for(int i=0; i<10; i++){
		printf("%d\n", vetor[i]);
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");

	//atividade1();
	//atividade2();
	//atividade3();
	//atividade4();

	return 0;
}
