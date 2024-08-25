#include "Cubo.hpp"

Cubo::Cubo(float xyz){
	this->xyz = xyz;
}

Cubo::~Cubo(){

}

float Cubo::getXYZ(){
	return xyz;
}

void Cubo::setXYZ(float xyz){
	this->xyz = xyz;
}

float Cubo::calcularArea(){
	float area = 6 * (xyz*xyz);
	return area;
}

float Cubo::calcularVolume(){
	float volume = xyz*xyz*xyz;
	return volume;
}
