#include <iostream>
#define max 10;

class Fila{
private:
	int limInferior;
	int limSuperior;
	int final;
	int inicio;
	int fila[10];

public:
	Fila();
	void inserir(int valor);
	void remover();
	void consultar();
	int getInicio(){
		return inicio;
	}
};
