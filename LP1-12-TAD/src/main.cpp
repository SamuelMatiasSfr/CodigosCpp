//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Implementar um TAD Cubo e Cilindro em C++
//============================================================================

#include <cstdio>
#include <iostream>
#include <clocale>
#include "Cubo.hpp"
#include "Cilindro.hpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese.UTF-8");

	Cubo cubo(2.0);
	Cilindro cilindro(2.0, 2.0);

	cout << "O lado do cubo é: " <<	cubo.getXYZ() << endl;
	cout << "A área do cubo é: " << cubo.calcularArea() << endl;
	cout << "A área do cubo é: " << cubo.calcularVolume() << endl;
	cout << "O raio do cilindro é: " <<	cilindro.getRaio() << endl;
	cout << "O altura do cilindro é: " <<	cilindro.getAltura() << endl;
	cout << "A área do cilindro é: " << cilindro.calcularArea() << endl;
	cout << "A área do cilindro é: " << cilindro.calcularVolume() << endl;

	return 0;
}
