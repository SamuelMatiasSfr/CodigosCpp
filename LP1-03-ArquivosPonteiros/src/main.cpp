//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : LP1-03-Ponteiros-Atividade de laborat�rio.pdf
//============================================================================

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void atividade2(){
	FILE *arq;
	arq = fopen("arquivo.txt", "w");

	fprintf(arq, "A primeira linha: 'int *p, *q;' declara dois ponteiros para armazenar o endere�o de mem�ria do tipo inteiro.\n");
	fprintf(arq, "A segunda linha: 'p = malloc (sizeof (int));' eu n�o sei o que faz.\n");
	fprintf(arq, "A terceira linha: '*p = 123;' aloca o valor 123 no endere�o de mem�ria apontado por '*p1'.\n");
	fprintf(arq, "A quarta linha: 'q = malloc (sizeof (int));' eu n�o sei o que faz.\n");
	fprintf(arq, "A quinta linha: '*q = *p;' aloca o valor apontado '*p' no endere�o de mem�ria apontado por '*q'.\n");
	fprintf(arq, "A sexta linha: 'q = p;' faz com que o ponteiro 'q' passe a apontar para o mesmo endere�o de mem�ria de 'p'.\n");
	fprintf(arq, "A s�tima linha: 'free(p)'; libera a mem�ria alocada em 'p'.\n");
	fprintf(arq, "A oitava linha: 'free(q);' libera a mem�ria alocada em 'q'.\n");
	fprintf(arq, "A nona linha: 'q = NULL;' o ponteiro 'q' aponta para um endere�o de mem�ria inv�lido.\n");
}


void atividade3(){
	typedef struct{
		int dia, mes, ano;
	} data;

	printf("sizeof(data) = %d\n", sizeof(data));
	printf("sizeof(data*) = %d\n", sizeof(data*));

	printf("\nO primeiro printf est� mostrando o tamanho da estrutura 'data' em bytes.");
	printf("\nJ� o segundo printf exibe o tamanho de um ponteiro para estrura 'data' em bytes.");
}

void multiplicaPorDois(int array[]){
	for(int i=0; i<10; i++){
		array[i] = array[i] * 2;
	}
}

void atividade4(){
	int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("Array antes da fun��o: ");
	for(int i=0; i<10; i++){
		printf("%d\n", vetor[i]);
	}

	multiplicaPorDois(vetor);

	printf("\n\nArray depois da fun��o: ");
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
