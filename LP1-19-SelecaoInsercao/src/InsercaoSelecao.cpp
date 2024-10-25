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

#include "funcoes.h"

//ATIVIDADES DE SELEÇÃO
void atividade1Selecao(){
	int vetor[1000];
	int tam=1000;

	for(int i=0; i<tam; i++){
		vetor[i] = i+1;
	}

	permut(vetor, tam);

	cout << "\nDesordenado: ";
	imprime(vetor, tam);

	cout << "\nSelecão:\n";
	selecao(vetor, tam);
	cout << "Vetor: ";
	imprime(vetor, tam);
}

void atividade2Selecao(){
	string palavra = "ordena";

	int tam = palavra.length();

	cout << "\nDesordenado: ";
	imprimeString(palavra, tam);

	cout << "\nSelecão:\n";
	selecaoString(palavra, tam);
	cout << "Palavra: ";
	imprimeString(palavra, tam);
}


//ATIVIDADES DE INSERCÃO
void atividade1Insercao(){
	int vetor[1000];
	int tam=1000;

	for(int i=0; i<tam; i++){
		vetor[i] = i+1;
	}

	permut(vetor, tam);

	cout << "\nDesordenado: ";
	imprime(vetor, tam);

	cout << "\nInsercão:\n";
	insercao(vetor, tam);
	cout << "Vetor: ";
	imprime(vetor, tam);
}

void atividade2Insercao(){
	string palavra = "ordena";

	int tam = palavra.length();

	cout << "\nDesordenado: ";
	imprimeString(palavra, tam);

	cout << "\nInsercão:\n";
	insercaoString(palavra, tam);
	cout << "Palavra: ";
	imprimeString(palavra, tam);
}


int main(){
	setlocale(LC_ALL, "Portuguese");

	atividade1Selecao();
	atividade2Selecao();

	atividade1Insercao();
	atividade2Insercao();

	return 0;
}
