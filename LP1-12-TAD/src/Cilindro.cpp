#include "Cilindro.hpp"

Cilindro::Cilindro(float raio, float altura){
	this->raio = raio;
	this->altura = altura;
}

Cilindro::~Cilindro(){

}

float Cilindro::getRaio(){
	return raio;
}

void Cilindro::setRaio(float raio){
	this->raio = raio;
}

float Cilindro::getAltura(){
	return altura;
}

void Cilindro::setAltura(float altura){
	this->altura = altura;
}

float Cilindro::calcularArea(){
	float area = 3.14 * (raio*raio);
	return area;
}

float Cilindro::calcularVolume(){
	float volume = (raio*raio) * 3.14 * altura;
	return volume;
}
