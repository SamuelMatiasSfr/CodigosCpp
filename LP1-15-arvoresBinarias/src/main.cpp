//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Enunciado.txt
//============================================================================

#include <iostream>
#include "Arvore.hpp"

using namespace std;

int main() {
	Arvore arvore;

	arvore.definirRaiz("30"); //0
	arvore.insereEsquerda("25", 0); //1
	arvore.insereDireita("40", 0); //2
	arvore.insereEsquerda("15", 1); //3
	arvore.insereDireita("65", 2); //4
	arvore.insereEsquerda("32", 2); //5
	arvore.insereDireita("27", 1); //6

	arvore.imprimirArvore();

	return 0;
}
