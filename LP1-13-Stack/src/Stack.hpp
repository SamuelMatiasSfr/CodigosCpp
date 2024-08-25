#include <iostream>
#include <vector>

using namespace std;

class Dados{
private:
	int x;

public:
	int getDado(){
		return x;
	}
	void setDado(int x){
		this->x = x;
	}
};

class Stack{
private:
	int topo;
	int base;
	int lim;

public:
	vector<Dados>dados;
	Stack();

	int getTopo(){
		return topo;
	}

	int getLim(){
		return lim;
	}

	int getBase(){
		return base;
	}

	void setLim(int lim){
		this->lim = lim;
	}

	void inserir(int valor);
	void remover();
	void consultar();
};
