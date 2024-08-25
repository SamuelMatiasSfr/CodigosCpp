#include "Fila.hpp"

Fila::Fila(){
	this->limInferior = 1;
	this->limSuperior = max;
	this->inicio = 0;
	this->final = 0;
}

void Fila::inserir(int valor){
	if((final != inicio-1) && ((inicio != limInferior) || (final != limSuperior))){
		if(inicio ==  limInferior-1){
			inicio = limInferior;
			final = limInferior;
		}else if(final == limSuperior){
			final = limInferior;
		}else{
			final++;
		}
		fila[final] = valor;
		std::cout << "Valor inserido.\n";
	}
}

void Fila::remover(){
	if(inicio != limInferior-1){
		if(inicio == final){
			inicio = limInferior-1;
			final = limInferior-1;
		}else if(inicio == limSuperior){
			inicio = limInferior;
		}else{
			inicio++;
		}
		std::cout << "\nValor removido.\n";
	}
}

void Fila::consultar(){
	if(inicio != limInferior-1){
		std::cout << "\nO primeiro elemento: " << fila[getInicio()] << std::endl;
	}
}
