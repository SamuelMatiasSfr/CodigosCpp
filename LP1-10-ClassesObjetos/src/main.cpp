//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : LP1-11-Classes e objetos-Atividade de laboratório.pdf
//============================================================================

#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Pessoa{
	public:
		string nome;
		int idade;
		int numeroMatricula;
		float peso;
		void imprime(){
			cout << "Nome: " << nome << endl;
			cout << "Idade: " << idade << endl;
			cout << "Matrícula: " << numeroMatricula << endl;
			cout << "Peso: " << peso << endl;
			cout << endl;
		};
};

void Atividade1(){
	cout << "Atividade de laboratório" << endl;

	Pessoa alisson;
	alisson.nome = "Alison";
	alisson.idade = 10;
	alisson.numeroMatricula = 1225;
	alisson.peso = 180.5f;
	alisson.imprime();
}

void Atividade2(){
	Pessoa samuel;
	samuel.nome = "Samuel";
	samuel.idade = 17;
	samuel.numeroMatricula = 1226;
	samuel.peso = 67.65f;
	samuel.imprime();

	Pessoa jane;
	jane.nome = "Jane";
	jane.idade = 45;
	jane.numeroMatricula = 1227;
	jane.peso = 72.5f;
	jane.imprime();
}

void Atividade3(){
	Pessoa pessoas[5];

	pessoas[0].nome = "Samuel";
	pessoas[0].idade = 17;
	pessoas[0].numeroMatricula = 12345;
	pessoas[0].peso = 67.65f;

	pessoas[1].nome = "Jane";
	pessoas[1].idade = 45;
	pessoas[1].numeroMatricula = 12346;
	pessoas[1].peso = 72.5f;

	pessoas[2].nome = "Laura";
	pessoas[2].idade = 22;
	pessoas[2].numeroMatricula = 12347;
	pessoas[2].peso = 78.5f;

	pessoas[3].nome = "Jose";
	pessoas[3].idade = 58;
	pessoas[3].numeroMatricula = 12348;
	pessoas[3].peso = 92.5f;

	pessoas[4].nome = "Bethoven";
	pessoas[4].idade = 5;
	pessoas[4].numeroMatricula = 12349;
	pessoas[4].peso = 50.5f;

	for(int i=0; i<5; i++){
		pessoas[i].imprime();
	}
}

void Atividade4(){
	string NomeArquivo("dados.csv");

	ifstream in( NomeArquivo.c_str() );

	if (!in.is_open()) {
	    cout << "Erro ao abrir o arquivo!" << endl;
	}

	Pessoa pessoas[5];

	int j=0;
	int teste=0;

	string buffer;
	while(j < 5){
		getline(in, buffer);
		if(getline(in, buffer)){
			teste++;
		}

		for(int i=0; i < buffer.length(); i++){
			if(buffer[i] == ','){
				buffer[i] = ' ';
			}
		}
		stringstream stris( buffer );

		if(teste > 0){
			stris >> pessoas[j].nome >> pessoas[j].idade >> pessoas[j].numeroMatricula >> pessoas[j].peso;
			j++;
		}
	}
	in.close();

	for(int i=0; i<5; i++){
		pessoas[i].imprime();
	}
}

int main() {
	//Atividade1();
	//Atividade2();
	//Atividade3();
	//Atividade4();

	return 0;
}

