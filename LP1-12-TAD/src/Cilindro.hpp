#include <iostream>

using namespace std;

class Cilindro{
private:
	float raio;
	float altura;

public:
	Cilindro(float raio, float altura); //cria
	~Cilindro(); //libera
	float getRaio(); //acessa
	void setRaio(float raio); //atribui
	float getAltura(); //acessa
	void setAltura(float altura); //atribui
	float calcularArea();
	float calcularVolume();
};
