//============================================================================
// Name        : samuel_matias_selecao.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description :
/*
 * 1) Implementar ordenação por seleção e inserção
 * 	a) Verificar cada algoritmo
 * 	b) Modificar a entrada e verificar o tempo de compilamento (entrada: 1000)
 *	c) Verficar o exemplo do livro: ordena -> adenor
 */
//============================================================================

#include <climits>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

double gerarRand(){
	double resultado= (double) rand()/ INT_MAX;
	if(resultado>1.0) resultado= 1.0;
	return resultado;
}

//FUNÇÕES PARA INTEIROS
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

//FUNÇÕES PARA STRINGS
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

void imprimeString(string palavra, int tam){
	cout << palavra << endl;
}

//ATIVIDADE USANDO INTEIROS
void atividade1(){
	int vetor[1000];
	int tam=1000;

	for(int i=0; i<tam; i++){
		vetor[i] = i+1;
	}

	permut(vetor, tam);

	cout << "\nDesordenado: ";
	imprime(vetor, tam);

	cout << "\nSelecao:\n";
	selecao(vetor, tam);
	cout << "Vetor: ";
	imprime(vetor, tam);
}

//ATIVIDADE USANDO STRING
void atividade2(){
	string palavra = "ordena";

	int tam = palavra.length();

	cout << "\nDesordenado: ";
	imprimeString(palavra, tam);

	cout << "\nSelecao:\n";
	selecaoString(palavra, tam);
	cout << "Palavra: ";
	imprimeString(palavra, tam);
}


int main() {
	atividade1();
	atividade2();

	return 0;
}
