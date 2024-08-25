#include "Pilha.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Aluno{
public:
	int matricula;
	string turma;
	int idade;
	string nome;

	Aluno(int matricula, string turma, int idade, string nome){
		this->matricula = matricula;
		this->turma = turma;
		this->idade = idade;
		this->nome = nome;
	}
};

void consultarAlunos(vector<Aluno>alunos, Pilha pilha){
	int consultado;
	bool sucesso;
	sucesso = pilha.consultarPilha(&consultado);

	if(sucesso){
		for(int i=0; i<alunos.size(); i++){
			if(alunos[i].matricula == consultado){
				cout << "Matricula: " << alunos[i].matricula << " - " << alunos[i].nome << " - " << alunos[i].idade << " anos - " << alunos[i].turma << endl;
			}
		}
	}
}

int main1(){
	vector<Aluno>alunos;
	Pilha pilhaAlunos;

	alunos.push_back(Aluno(1, "CAMB1", 16, "Jane"));
	alunos.push_back(Aluno(2, "INFO2", 15, "Samuel"));
	alunos.push_back(Aluno(3, "ELEOT1", 17, "José"));
	alunos.push_back(Aluno(4, "CAMB2", 15, "Laura"));

	for(int i=0; i<4; i++){
		pilhaAlunos.inserirPilha(alunos[i].matricula);
	}

	consultarAlunos(alunos, pilhaAlunos);

	return 0;
}
