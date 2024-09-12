/*
 * questoes.h
 * LLP1-PMP2B
 * Prova mensal do segundo bimestre - LLP1
 * Author: Alisson RS
 */

#ifndef QUESTOES_H_
#define QUESTOES_H_

#include "ContaBancaria.h"

void questao1() {
	std::cout << "Questão 1" << std::endl;

	llp::ContaBancaria conta1(1000, "Samuel", 1000.50);
	std::cout << "Nome do titular da conta 1: " << conta1.getTitular()
			<< std::endl;

	std::cout << "Fim da Questão 1" << std::endl;
	std::cout << std::string(40, '_') << std::endl;
}

void questao2() {
	std::cout << "Questão 2" << std::endl;

	llp::ContaBancaria *conta2 = new llp::ContaBancaria(1001, "Lara", 2000.75);
	//llp::ContaBancaria conta2(1001, "Lara", 2000.75);
	std::cout << "Nome do titular da conta 2: " << conta2->getTitular()
			<< std::endl;

	std::cout << "Fim da Questão 2" << std::endl;
	std::cout << std::string(40, '_') << std::endl;

	delete conta2;
}

void questao3() {
	std::cout << "Questão 3" << std::endl;
	std::string titulares[10] = { "Beto", "Clara", "Daniel", "Eva", "Fábio",
			"Gisele", "Hugo", "Isabel", "Jonas", "Karla" };

	double saldos[10] = { 500.00, 1500.00, 2000.00, 2500.00, 3000.00, 3500.00,
			4000.00, 4500.00, 5000.00, 5500.00 };

	std::string titulo = "numero,titular,saldo";

	llp::ContaBancaria *contas = new llp::ContaBancaria[10];



	for (int i = 0; i < 10; ++i) {
		contas[i].setNumero(i + 1002);
		contas[i].setTitular(titulares[i]);
		contas[i].setSaldo(saldos[i]);
	}

	std::cout << titulo << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << contas[i].toString() << std::endl;
	}
	std::cout << "Fim da Questão 3" << std::endl;
	std::cout << std::string(40, '_') << std::endl;

	delete [] contas;
}


#endif /* QUESTOES_H_ */
