#ifndef FUNCOES_H_
#define FUNCOES_H_

#include <climits>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <clocale>

using namespace std;

//FUN플O DE INSER플O PARA INTEIROS
void insercao(int vetor[], int tam){
	int j, x;

	for (int i = 2; i < tam; i++){
		x = vetor[i];
		j = i - 1;

	    while (x < vetor[j]){
	    	vetor[j+1] = vetor[j];
	    	j--;
		}

	  vetor[j+1] = x;
	}
}

//FUN플O DE INSER플O PARA STRINGS
void insercaoString(string &palavra, int tam){
	int j, x;

	for (int i = 2; i < tam; i++){
		x = palavra[i];
		j = i - 1;

	    while (x < palavra[j]){
	    	palavra[j+1] = palavra[j];
	    	j--;
		}

	    palavra[j+1] = x;
	}
}


//FUN플O DE SELE플O PARA INTEIROS
void selecao(int vetor[], int tam){
	int min, aux;

	for(int i = 1; i < tam-1; i++){
		min = i;
		for(int j = i + 1; j < tam; j++){
        	if(vetor[j] < vetor[min]) min = j;

        	aux = vetor[min];
        	vetor[min] = vetor[i];
        	vetor[i] = aux;
		}
	}
}

//FUN플O DE SELE플O PARA STRINGS
void selecaoString(string &palavra, int tam){
	int min;
	char aux;

	for(int i=0; i< tam-1; i++){
		min = i;

		for(int j = i+1; j < tam; j++){
			if(palavra[j] < palavra[min]){
				min = j;
			}
		}
		if(palavra[i] != palavra[min]){
			aux = palavra[i];
			palavra[i] = palavra[min];
			palavra[min] = aux;
		}
	}
}


//DEMAIS FUN합ES
double gerarRand(){
	double resultado= (double) rand()/ INT_MAX;
	if(resultado>1.0) resultado= 1.0;
	return resultado;
}

void permut( int vetor[], int tam){
	int j;
	int temp;

	for(int i = tam-1; i>0; i --){
		j = (i * gerarRand()) + 1 ;
		temp = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = temp;
	}
}

void imprime(int vetor[], int tam){
	for(int i=0; i<tam; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}

void imprimeString(string palavra, int tam){
	cout << palavra << endl;
}

#endif /* FUNCOES_H_ */
