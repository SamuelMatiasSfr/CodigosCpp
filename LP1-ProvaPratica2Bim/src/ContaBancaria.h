#ifndef CONTABANCARIA_H_
#define CONTABANCARIA_H_

#include <iostream>
#include <string>
#include <sstream>
#include "ContaBancaria.h"

namespace llp{

	class ContaBancaria{
	private:
		int numero;
		float saldo;
		std::string titular;
	public:
		ContaBancaria();
		ContaBancaria(int numero, std::string titular, float saldo);
		std::string getTitular();
		void setNumero(int numero);
		void setTitular(std::string titular);
		void setSaldo(float saldo);
		std::string toString();
	};

}

#endif
