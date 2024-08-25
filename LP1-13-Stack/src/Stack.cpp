#include "Stack.hpp"

Stack::Stack(){
	this->lim = 10;
	this->base = 1;
	this->topo = 0;
}

void Stack::inserir(int valor){
	cout << endl;
	if(this->topo < this->lim){
		Dados dado;
		dado.setDado(valor);
		this->topo = this->topo + 1;
		this->dados.push_back(dado);
		cout << "Valor " << valor << " inserido\n";
	}else{
		cout << "Valor " << valor << " nao foi inserido\n";
	}
}

void Stack::consultar(){
	int valor;
	if(this->topo >= this->base){
		valor = this->dados.back().getDado();
		cout << "\nValor do topo: " << valor << endl;
	}else{
		cout << "Pilha vazia\n";
	}
}

void Stack::remover(){
	int valorRemovido;
	if(this->topo >= this->base){
			valorRemovido = this->dados.back().getDado();
			this->dados.pop_back();
			this->topo = this->topo - 1;
			cout << "\nValor " << valorRemovido << " removido\n";
		}else{
			cout << "\nValor " << valorRemovido << " nao removido\n";
		}
}
