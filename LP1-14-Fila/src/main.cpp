//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Implementação e Demonstração de Filas em C++
//============================================================================

#include <iostream>
#include "Fila.hpp"

using namespace std;

int main() {
	Fila fila;

	for(int i=1; i < 6; i++){
		fila.inserir(i);
	}

	fila.consultar();

	fila.remover();

	fila.consultar();

	return 0;
}
