//============================================================================
// Name        : samuel_matias_insercao.cpp
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

	cout << "\nInsercao:\n";
	insercao(vetor, tam);
	cout << "Vetor: ";
	imprime(vetor, tam);
}

//ATIVIDADE USANDO STRING
void atividade2(){
	string palavra = "ordena";

	int tam = palavra.length();

	cout << "\nDesordenado: ";
	imprimeString(palavra, tam);

	cout << "\nInsercao:\n";
	insercaoString(palavra, tam);
	cout << "Palavra: ";
	imprimeString(palavra, tam);
}


int main() {
	atividade1();
	atividade2();

	return 0;
}
