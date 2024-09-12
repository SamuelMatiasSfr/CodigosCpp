#include "ContaBancaria.h"

llp::ContaBancaria::ContaBancaria(){

}

llp::ContaBancaria::ContaBancaria(int numero, std::string titular, float saldo){
	this->numero = numero;
	this->titular = titular;
	this->saldo = saldo;
}

std::string llp::ContaBancaria::getTitular(){
	return this->titular;
}

void llp::ContaBancaria::setNumero(int numero){
	this->numero = numero;
}

void llp::ContaBancaria::setTitular(std::string titular){
	this->titular = titular;
}

void llp::ContaBancaria::setSaldo(float saldo){
	this->saldo = saldo;
}

std::string llp::ContaBancaria::toString(){
	std::stringstream ss;
	ss << numero << "," << titular << "," << saldo;
	return ss.str();
}
