//============================================================================
// Name        : heapsort.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description :
/*
 * 1) Testar o código de 1 a 20 mostrando passo a passo do vetor
 * 2) Fazer a mesma coisa que a 1 mas com um vetor inserido pelo usuário
 * 3) Fazer a mesma coisa que a 1 e a 2, mas com uma string
 */
//============================================================================

#include <iostream>
using namespace std;

//FUNÇÕES PARA INTEIRO
void imprime(int vetor[], int tam){
	for(int i=0; i<tam; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}

void refaz(int esq, int dir, int vetor[]){
	int i = esq;
    int j, aux;

    j = i * 2;

    aux = vetor[i];
    while (j <= dir){

    	if (j < dir){
    		if (vetor[j] < vetor[j+1])
    		j++;
    	}

    	if (aux >= vetor[j]) goto L999;
    	vetor[i] = vetor[j];
    	i = j;
    	j = i * 2;
    }

    L999: vetor[i] = aux;
}

void constroi(int vetor[], int n){
	int esq;
	esq = n/2 + 1;
	while (esq > 0){ //mexi
		esq--;
		refaz(esq, n, vetor);
    }
}

void heapsort(int vetor[], int n){
	int esq, dir;
	int aux;
	constroi(vetor, n);  // constroi o heap
	esq = 0;  dir = n; //mexi

	while (dir > 0) { //mexi
		// ordena o vetor
		aux = vetor[0]; //mexi
		vetor[0] = vetor[dir]; //mexi
		vetor[dir] = aux;

		cout << endl << vetor[0] << " foi trocada com " << vetor[dir-1] << endl; //mexi

		dir--;
		refaz(esq, dir, vetor);

		imprime(vetor, n);
    }
}

/*
void heapsort(int vetor[], int n){
	int esq, dir;
	int aux;
	constroi(vetor, n);  // constroi o heap
	esq = 0;  dir = n; //mexi

	while (dir > 0) { //mexi
		// ordena o vetor
		aux = vetor[0]; //mexi
		vetor[0] = vetor[dir]; //mexi
		vetor[dir] = aux;
		dir--;
		refaz(esq, dir, vetor);
		cout << endl;
		imprime(vetor, n);
    }
}*/

void atividade1(){
	int vetor[20];

	for(int i=0; i<20; i++){
		vetor[i] = i+1;
	}

	int tam=20;

	refaz(0, tam, vetor); //mexi

	cout << "\nDesordenado: ";
	imprime(vetor, tam);

	cout << "\nHeapsort:\n";
	heapsort(vetor, tam);
	cout << "\nVetor: ";
	imprime(vetor, tam);
}

void atividade2(){
	int vetor[20];

	cout << "Digite o vetor:\n";
	for(int i=0; i<5; i++){
		cin >> vetor[i];
	}

	int tam=5;

	refaz(0, tam, vetor); //mexi

	cout << "\nDesordenado: ";
	imprime(vetor, tam);

	cout << "\nHeapsort:\n\n";
	heapsort(vetor, tam);
	cout << "\nVetor: ";
	imprime(vetor, tam);
}


//FUNÇÕES PARA CHAR
void imprimeChar(char *vetor, int tam){
	for(int i=0; i<tam; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}

void refazChar(int esq, int dir, char *vetor){
	int i = esq;
    int j;
    char aux;

    j = i*2+1;

    aux = vetor[i];
    while (j <= dir){

    	if (j < dir){
    		if (vetor[j] < vetor[j+1])
    		j++;
    	}

    	if (aux >= vetor[j]) goto L999;

    	vetor[i] = vetor[j];
    	i = j;
    	j = i*2+1;
    }

    L999: vetor[i] = aux;
}

void constroiChar(char *vetor, int n){
	int esq;
	esq = n/2 + 1;
	while (esq >= 0){ //mexi
		refazChar(esq, n, vetor);
		esq--;
    }
}

void heapsortChar(char *vetor, int n){
	int esq, dir;
	int aux;
	constroiChar(vetor, n);  // constroi o heap
	esq = 0;  dir = n-1; //mexi

	while (dir > 0) { //mexi
		// ordena o vetor
		aux = vetor[0]; //mexi
		vetor[0] = vetor[dir]; //mexi
		vetor[dir] = aux;

		cout << endl << vetor[0] << " foi trocada com " << vetor[dir] << endl; //mexi

		dir--;
		refazChar(esq, dir, vetor);

		imprimeChar(vetor, n);
    }
}

void atividade3(){
	char palavra[50];

    cout << "Digite a palavra: ";
    cin.getline(palavra, 100);

	int tam = strlen(palavra);

	refazChar(0, tam, palavra); //mexi

	cout << "\nDesordenado: ";
	imprimeChar(palavra, tam);

	cout << "\nHeapsort:\n";
	heapsortChar(palavra, tam);
	cout << "\nVetor: ";
	imprimeChar(palavra, tam);
}

int main() {

	//atividade1();
	//atividade2();
	atividade3();

	return 0;
}
