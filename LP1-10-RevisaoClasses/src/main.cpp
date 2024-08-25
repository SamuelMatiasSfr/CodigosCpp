//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Prova Mensal Prática-LP1-2ºBim-T1.pdf
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <clocale>

using namespace std;

//INICIO CLASS

class Movel{
private:
	int posX;
	int posY;
	int velX;
	int velY;
	string imagem;

public:
	Movel();
	Movel(int px, int py, int vx, int vy, string img);
	Movel(string linha);
	void mover(int tempo);
	void setPos(int x, int y);
	int getPosX();
	int getPosY();
	string toString();
};

Movel::Movel(){
	posX = 0;
	posY = 0;
	velX = 0;
	velY = 0;
	imagem = "";
}

Movel::Movel(int px, int py, int vx, int vy, string img){
	posX = px;
	posY = py;
	velX = vx;
	velY = vy;
	imagem = img;
}

Movel::Movel(string linha){
	stringstream stris(linha);

	int px, py, vx, vy;
	string img;

	stris >> px >> py >> vx >> vy >> img;

	posX = px;
	posY = py;
	velX = vx;
	velY = vy;
	imagem = img;
}

int Movel::getPosX(){
	return posX;
}

int Movel::getPosY(){
	return posY;
}

void Movel::mover(int tempo){
	posX = posX + velX * tempo;
	posY = posY + velY * tempo;
}

string Movel::toString(){
	stringstream ss;
	ss << posX << "," << posY << "," << velX << "," << velY << "," << imagem;
	return ss.str();
}

//FIM CLASS

vector<Movel> carregarMoveis(string nomeArquivo){
	vector<Movel> moveis;

	ifstream in( nomeArquivo.c_str() );

		if(!in.is_open()){
			cout << "Erro ao abrir o arquivo!" << endl;
		}

		int cont = 0;
		char line[999];
		while(in.getline(line, 999)){
			string stemp(line);

			for(int i = 0; i<stemp.length(); i++){
				if(stemp[i] == ','){
					stemp[i] = ' ';
				}
			}

			if(cont > 0){
				moveis.push_back(Movel(stemp));
			}

			cont++;
		}

		in.close();

		return moveis;
}

void salvarMoveis(string nomeArquivo, vector<Movel> moveis){
	ofstream out( nomeArquivo.c_str() );

	if(!out.is_open()){
		cout << "Erro ao abrir o arquivo!" << endl;
	}

	out << "posX,poxY,velX,velY,imagem\n";
	for(int i = 0; i < moveis.size(); i++){
		string string;
		string = moveis[i].toString();
		out << string << endl;
	}
	out.close();
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	setbuf(stdout, NULL);

	vector<Movel> moveis = carregarMoveis("moveis.csv");

	cout << "posX,poxY,velX,velY,imagem\n";
	for(int i = 0; i < moveis.size(); i++){
		moveis[i].mover(i);
		cout << moveis[i].toString() << endl;
	}

	salvarMoveis("moveis.csv", moveis);

	return 0;
}
