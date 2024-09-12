//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * main.cpp
 * LLP1-PMP2B
 * Prova mensal do segundo bimestre - LLP1
 * Author: Alisson RS
 */

#include<iostream>

#include "ContaBancaria.h" 	//Criar
#include "questoes.h" 	//Fornecido

//Main deve ser devolvido sem alterações.
int main(int argc, char **argv) {

	std::cout << "Prova Mensal Prática 2º Bimestre (PMP2B)" << std::endl;
	std::cout << std::string(40, '_') << std::endl;

	questao1();

	questao2();

	questao3();

	std::cout << "Fim da prova." << std::endl;
	std::cout << std::string(40, '_') << std::endl;

	return 0;
}
