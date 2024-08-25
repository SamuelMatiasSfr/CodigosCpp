//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : LP1-PMP2-2
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <clocale>

using namespace std;

class Gpu{
public:
	int id;
	string code;
	string fabricante;
	float valor;

	Gpu();
	Gpu(string linha);
	Gpu(int id, string code, string fabricante, float valor);
	void mostraDados();
};

Gpu::Gpu(){

}

Gpu::Gpu(int id, string code, string fabricante, float valor){
	this->id = id;
	this->code = code;
	this->fabricante = fabricante;
	this->valor = valor;
}

Gpu::Gpu(string linha){
	stringstream stris(linha);

	int id;
	string codigo;
	string fabricante;
	float valor;

	string img;

	stris >> id >> codigo >> fabricante >> valor;

	this->id = id;
	this->code = codigo;
	this->fabricante = fabricante;
	this->valor = valor;
}

void Gpu::mostraDados(){
	cout << id << ";" << code << ";" << fabricante << ";" << valor << endl;
}

vector<Gpu> carregarGpus(string nomeArquivo){
	vector<Gpu> gpus;

	ifstream in( nomeArquivo.c_str() );

		if(!in.is_open()){
			cout << "Erro ao abrir o arquivo!" << endl;
		}

		int cont = 0;
		char line[999];
		while(in.getline(line, 999)){
			string stemp(line);

			for(int i = 0; i<stemp.length(); i++){
				if(stemp[i] == ';'){
					stemp[i] = ' ';
				}
			}

			if(cont > 0){
				gpus.push_back(Gpu(stemp));
			}

			cont++;
		}

		in.close();

		return gpus;
}

Gpu menorValor(vector<Gpu> gpus, string fabricante){
	float valorGPU = 10000;
	float valorTemp = 0;
	Gpu gpuMenorValor;

	for(int i=0; i<gpus.size(); i++){
		if(gpus[i].fabricante == fabricante){
			valorTemp = gpus[i].valor;
		}
		if(valorTemp <= valorGPU){
			valorGPU = valorTemp;
			gpuMenorValor = gpus[i];
		}
	}

	cout << "\nGPU de menor valor da fabricante " << fabricante << ": "<< endl;

	return gpuMenorValor;
}

void verificaValorMedio(vector<Gpu> gpus){
	vector<Gpu> gpusAMD;
	vector<Gpu> gpusIntel;

	float totalValorAMD = 0, totalValorIntel = 0;
	int contAMD = 0, contIntel = 0;

	for(int i=0; i<gpus.size(); i++){
		if(gpus[i].fabricante == "AMD"){
			gpusAMD.push_back(Gpu(gpus[i].id, gpus[i].code, gpus[i].fabricante, gpus[i].valor));
			totalValorAMD = totalValorAMD + gpus[i].valor;
			contAMD++;
		}else{
			gpusIntel.push_back(Gpu(gpus[i].id, gpus[i].code, gpus[i].fabricante, gpus[i].valor));
			totalValorIntel = totalValorIntel + gpus[i].valor;
			contIntel++;
		}
	}

	float mediaAMD = totalValorAMD/contAMD;
	float mediaIntel = totalValorIntel/contIntel;

	if(mediaIntel > mediaAMD){
		cout << "\nA AMD possui na m dia as placas mais baratas.\n";
		float valorTemp = 0, valorGPU = 10000;
		for(int i=0; i<gpusAMD.size(); i++){
			valorTemp = gpusAMD[i].valor;
			if(valorTemp <= valorGPU){
				valorGPU = valorTemp;
			}
		}

		for(int i=0; i<gpusAMD.size(); i++){
			if(valorGPU == gpusAMD[i].valor){
				cout << "A placa de menor valor  : ";
				gpusAMD[i].mostraDados();
			}
		}

	}else{
		cout << "\nA Intel possui na m dia as placas mais baratas.\n";
		float valorTemp = 0, valorGPU = 10000;
		for(int i=0; i<gpusIntel.size(); i++){
			valorTemp = gpusIntel[i].valor;
			if(valorTemp <= valorGPU){
				valorGPU = valorTemp;
			}
		}

		for(int i=0; i<gpusIntel.size(); i++){
			if(valorGPU == gpusIntel[i].valor){
				cout << "A placa de menor valor  : ";
				gpusIntel[i].mostraDados();
			}
		}

	}

}

int main() {
	setlocale(LC_ALL, "Portuguese.UTF-8");
	vector<Gpu> gpus = carregarGpus("gpus.csv");

	cout << "\nLista de GPUS:\n";
	for(int i=0; i<gpus.size(); i++){
		gpus[i].mostraDados();
	}

	Gpu gpuMenorValor;
	gpuMenorValor = menorValor(gpus, "Intel");
	gpuMenorValor.mostraDados();

	verificaValorMedio(gpus);

	return 0;
}
