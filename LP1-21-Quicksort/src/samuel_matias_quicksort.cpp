//============================================================================
// Name        : samuel_matias_quicksort.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <climits>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <clocale>

using namespace std;

double gerarRand(){
	double resultado= (double) rand()/ INT_MAX; // Dividir pelo maior inteiro
	if(resultado>1.0) resultado= 1.0;
	return resultado;
}

//FUNÇÕES PARA INTEIROS
void imprime(int vetor[], int tam){
	for(int i=0; i<tam; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}

void particao(int esq, int dir, int *i, int *j, int vetor[]){
	int x, w;
	*i = esq;  *j = dir;
	x = vetor[(*i + *j) / 2]; //obtem o pivo x
	cout << "\nO pivô é: " << x << endl;

	do{
		while (x > vetor[*i]){
			(*i)++;
		}
		  while (x < vetor[*j]){
			  (*j)--;
		  }
		  if (*i <= *j){
			  w = vetor[*i];
			  vetor[*i] = vetor[*j];
			  vetor[*j] = w;

			  cout << vetor[*i] << " foi trocada com " << vetor[*j] << endl;

			  imprime(vetor, dir);

			  (*i)++;
			  (*j)--;
		  }
	}while (*i <= *j);
}

void ordena(int esq, int dir, int vetor[]){
	int i, j;

    particao(esq, dir, &i, &j, vetor);

    if (esq < j) ordena(esq, j, vetor);
    if (i < dir) ordena(i, dir, vetor);
}

void quicksort(int vetor[], int n){
	ordena(0, n, vetor);
}

//ATIVIDADE USANDO INTEIROS
void atividade1(){
	int vetor[] = {3, 0, 1, 8, 7, 2, 5, 4, 9, 6};

	int tam=10;

	cout << "\nDesordenado: ";
	imprime(vetor, tam);

	cout << "\nQuicksort:\n";
	quicksort(vetor, tam);
	cout << "\nVetor: ";
	imprime(vetor, tam);
}



//FUNÇÕES PARA STRINGS
void imprimeString(string &palavra, int tam){
	cout << palavra << endl;
}


void particaoString(int esq, int dir, int *i, int *j, string &vetor){
	char x, w;
	*i = esq;  *j = dir;
	x = vetor[(*i + *j) / 2]; //obtem o pivo x
	cout << "\nO pivô é: " << x << endl;

	do{
		while (x > vetor[*i]){
			(*i)++;
		}
		  while (x < vetor[*j]){
			  (*j)--;
		  }
		  if (*i <= *j){
			  w = vetor[*i];
			  vetor[*i] = vetor[*j];
			  vetor[*j] = w;
			  cout << vetor[*i] << " foi trocada com " << vetor[*j] << endl;

			  imprimeString(vetor, dir);

			  (*i)++;
			  (*j)--;
		  }
	}while (*i <= *j);
}

void ordenaString(int esq, int dir, string &vetor){
	int i, j;

    particaoString(esq, dir, &i, &j, vetor);

    if (esq < j) ordenaString(esq, j, vetor);
    if (i < dir) ordenaString(i, dir, vetor);
}

void quicksortString(string &vetor, int n){
	ordenaString(0, n-1, vetor);
}

//ATIVIDADE USANDO STRING
void atividade2(){
	string palavra;

	cout << "\n\nDigite a palavra: ";
	cin >> palavra;

	int tam = palavra.length();

	cout << "\nDesordenado: ";
	imprimeString(palavra, tam);

	cout << "\nQuicksort:\n";
	quicksortString(palavra, tam);
	cout << "\nPalavra: ";
	imprimeString(palavra, tam);
}


int main() {
	setlocale(LC_ALL, "Portuguese");

	atividade1();
	atividade2();

	return 0;
}

