/*
 * Pilha.hpp
 *
 *  Created on: 24 de mai de 2016
 *      Author: Alisson
 */

#ifndef PILHA_HPP_
#define PILHA_HPP_

#include <iostream>

using namespace std;

#define InicioArranjo   1
#define MaxTam 100

class Pilha {
private:
	int base, topo, limite;
	int pilha[MaxTam];
public:
	Pilha() {
		inicializarPilha();
	}

	void inicializarPilha() {
		base = 1;
		topo = base - 1;
		limite = 10;
	}

	bool inserirPilha(int valor) {
		if (topo < limite) {
			topo++;
			pilha[topo] = valor;
			return true;
		}
		return false;
	}

	bool removerPilha(int *valorRemovido) {
		if (topo >= base) {
			*valorRemovido = pilha[topo];
			topo--;
			return true;
		}
		return false;
	}

	bool consultarPilha(int *valorRemovido) {
		if (topo >= base) {
			*valorRemovido = pilha[topo];
			return true;
		}
		return false;
	}

};

int testePilha() {

	Pilha pilha;
	int item;
	int max = 101;

	/*Insere cada chave na lista */
	for (int i = 0; i < max; i++) {
		item = i;
		if (pilha.inserirPilha(item)) {
			cout << "Empilhou: " << item << endl;
		} else {
			cout << "Nao empilhou: " << item << endl;
		}
	}

	/*Retira cada chave da lista */
	while (pilha.removerPilha(&item) == true) {
		/*retira chave apontada */
		cout << "Desempilhou: " << item << endl;
	}

	return 0;
}
#endif /* PILHA_HPP_ */
