//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description :
/*
1 ) Carregue os dados do arquivo csv no programa (Solicite ao usuário qual arquivo ele quer carregar).

2) Calcule e apresente a media das notas para cada subturma.

3) O programa deve funcionar para qualquer um dos arquivos (eles tem o mesmo formato, mas o tamanho é diverso).
*/
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <clocale>

using namespace std;

void Exibir(vector<int>& sub, vector<float>& nt, int position){
	float soma=0;
	int cont=0;

	vector<float>tempNota;
	vector<int>tempSub;

	for(int i=0; i < sub.size(); i++){
		if(sub[i] == position){
			tempSub.push_back(sub[i]);
			tempNota.push_back(nt[i]);
			cont++;
			sub.erase(sub.begin()+i);
		}
	}

	for(int i=0; i < tempSub.size(); i++){
		soma += tempNota[i];
	}

	for(int i=0; i<cont; i++){
		tempSub.pop_back();
		tempNota.pop_back();
	}

	float media = soma/cont;
	if(cont > 0){
		cout << endl;
		printf("A média da subturma %d é igual a %.2f\n", position, media);
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	string nome;
	cout << "Digite o nome do arquivo: ";
	cin >> nome;

	string nomeArquivo(nome);
	ifstream in( nomeArquivo.c_str() );

	if (!in.is_open()) {
	    cout << "Erro ao abrir o arquivo!" << endl;
	}

	vector<int>vetorSubturma;
	vector<float>vetorNotas;

	int cont=0;
	char line[999];
	while(in.getline(line, 999)){
		string stemp( line );

		for(int i=0; i<stemp.length(); i++){
			if(stemp[i] == ','){
				stemp[i] = ' ';
			}
		}
		stringstream stris( stemp );

		int id;
		int subturma;
		string nome;
		string sobrenome;
		float nota;

		if(cont > 0){
			stris >> id >> nome >> sobrenome >> subturma >> nota;

			vetorSubturma.push_back(subturma);
			vetorNotas.push_back(nota);
		}

		cont++;
	}
	in.close();

	int sub=1;
	while(!vetorSubturma.empty()){
		Exibir(vetorSubturma, vetorNotas, sub);
		sub++;
	}

	return 0;
}
