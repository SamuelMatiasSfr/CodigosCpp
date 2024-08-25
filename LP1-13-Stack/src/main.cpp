//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description :
/*
1) Etapa 1: Implementação e Demonstração de como funciona uma Pilha em C++

2) Etapa 2: Enunciado.txt
*/
//============================================================================

#include <iostream>

#include "Stack.hpp"

using namespace std;


Stack reunirPilhas(Stack pilha1, Stack pilha2){
	cout << "\n\nReunindo pilhas...\n";

	Stack pilhaReunida;

	int tam1=0;
	int tam2=0;

	for(int i=0; i<pilha1.dados.size(); i++){
		tam1++;
	}

	for(int i=0; i<pilha2.dados.size(); i++){
		tam2++;
	}

	pilhaReunida.setLim(tam1+tam2);

	for(int i=0; i<tam1; i++){
		int valor = pilha1.dados[i].getDado();
		pilhaReunida.inserir(valor);
	}

	for(int i=0; i<tam2; i++){
		int valor = pilha2.dados[i].getDado();
		pilhaReunida.inserir(valor);
	}

	return pilhaReunida;
}

void compilarReunirPilhas(Stack pilha1, Stack pilha2){
	Stack pilhaJunta = reunirPilhas(pilha1, pilha2);

	cout << "\nPilha 1 e 2 reunida: ";
	for(int i=pilhaJunta.dados.size()-1; i>=0; i--){
		cout << endl << pilhaJunta.dados[i].getDado();
	}
}

Stack dividirPilha(Stack *pilha1){
	cout << "\nPilha original: ";
	for(int i=pilha1->dados.size(); i>=0; i--){
		cout << endl << pilha1->dados[i].getDado();
	}

	cout << "\n\nDividindo pilha...\n";

	Stack pilhaTemp;

	int metade = pilha1->dados.size()/2;
	for(int i=0; i<metade; i++){
		int valor = pilha1->dados[pilha1->getTopo()-1].getDado();
		pilhaTemp.inserir(valor);
		pilha1->remover();
	}

	Stack pilha2;

	int tam = pilhaTemp.dados.size();
	for(int i=0; i<tam; i++){
		int valor = pilhaTemp.dados[pilhaTemp.getTopo()-1].getDado();
		pilha2.inserir(valor);
		pilhaTemp.remover();
	}

	return pilha2;
}

void compilarDividirPilha(Stack *pilha1){
	Stack pilha2 = dividirPilha(pilha1);

	cout << "\nPilha 1: ";
	for(int i=pilha1->dados.size()-1; i>=0; i--){
		cout << endl << pilha1->dados[i].getDado();
	}

	cout << "\nPilha 2: ";
	for(int i=pilha2.dados.size()-1; i>=0; i--){
		cout << endl << pilha2.dados[i].getDado();
	}
}

void somarPilha(Stack pilha){
	cout << "\n\nSomando pilha...\n";

	Stack pilhaTemp;
	pilhaTemp.setLim(pilha.getLim());

	int soma=0;
	while(pilha.getTopo() >= pilha.getBase()){
		int valor = pilha.dados[pilha.getTopo()-1].getDado();
		pilhaTemp.inserir(valor);
		pilha.remover(); //OK
		soma = soma + valor;
	}
	cout << "\nSoma: " << soma << endl;

	while(pilhaTemp.getTopo() >= pilhaTemp.getBase()){
		int valor = pilhaTemp.dados[pilhaTemp.getTopo()-1].getDado();
		pilha.inserir(valor);
		pilhaTemp.remover();
	}

	cout << "\nPilha original devidamente estruturada: ";
	for(int i=pilha.dados.size()-1; i>=0; i--){
		cout << endl << pilha.dados[i].getDado();
	}
}

void compilarSomarPilha(Stack pilha){
	somarPilha(pilha);
}

int main() {
	Stack pilha1;

	for(int i=0; i < 4; i++){
		pilha1.inserir(i);
	}

	Stack pilha2;
	for(int i=0; i<8; i++){
		pilha2.inserir(i);
	}

	//compilarReunirPilhas(pilha1, pilha2);
	//compilarDividirPilha(&pilha1);
	//compilarSomarPilha(pilha1);

	return 0;
}
