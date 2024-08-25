/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Funcionario{
public:
	string nome;
	int ID;
	float salario;
	string cargo;

	Funcionario();
	Funcionario(string nome, int ID, float salario, string cargo);
	~Funcionario();

};

class Empresa{

private:
	vector<Funcionario> funcionarios;

public:
	void realizarAcao();
	void adicionarFuncionario();
	void removerFuncionario();
	void listarFuncionarios();
	void atualizarFuncionario();

};
