#include <iostream>

using namespace std;

class Cubo{
private:
	float xyz;

public:
	Cubo(float xyz); //cria
	~Cubo(); //libera
	float getXYZ(); //acessa
	void setXYZ(float xyz); //atribui
	float calcularArea();
	float calcularVolume();
};
