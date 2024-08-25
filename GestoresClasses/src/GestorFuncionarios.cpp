#include "GestorFuncionarios.hpp"

Funcionario::Funcionario(string nome, int ID, float salario, string cargo){
	this->nome = nome;
	this->ID = ID;
	this->salario = salario;
	this->cargo = cargo;
}

Funcionario::~Funcionario(){

}

void Empresa::realizarAcao(){
	int opcao = 0;
	while(opcao != -1){
		cout << "\nLista de ações:\n";
		cout << "Adicionar funcionário: digite 1\n";
		cout << "Remover funcionário: digite 2\n";
		cout << "Atualizar funcionário: digite 3\n";
		cout << "Listar funcionários: digite 4\n";
		cout << "Encerrar gerenciador: digite -1\n";
		cout << "Qual ação deseja realizar? Escolha uma opçao: ";
		cin >> opcao;
		cout << endl;

		switch(opcao){

		case 1:
			adicionarFuncionario();
			break;
		case 2:
			removerFuncionario();
			break;
		case 3:
			atualizarFuncionario();
			break;
		case 4:
			listarFuncionarios();
			break;

		}
	}

	cout << "Gerenciador encerrado.";
}

void Empresa::adicionarFuncionario(){
	string nome;
	int id;
	float salario;
	string cargo;

	cout << "Nome: ";
	cin >> nome;
	cout << "ID: ";
	cin >> id;
	cout << "Salário: ";
	cin >> salario;
	cout << "Cargo: ";
	cin >> cargo;

	funcionarios.push_back(Funcionario(nome, id, salario, cargo));

	cout << "\nFuncionário adicionado.\n";
}

void Empresa::removerFuncionario(){
	int id;
	cout << "Digite o ID do funcionário: ";
	cin >> id;

	for(int i=0; i<funcionarios.size(); i++){
		if(funcionarios[i].ID == id){
			funcionarios[i].~Funcionario();
		}
	}

	cout << "\nFuncionários removido.\n";
}

void Empresa::atualizarFuncionario(){
	int opcao;
	int id;
	cout << "Digite o ID do funcionário que deseja atualizar: ";
	cin >> id;
	cout << "\nO que deseja atualizar:";
	cout << "\nSalário: digite 1";
	cout << "\nCargo: digite 2";
	cout << "\nEscolha uma opção: ";
	cin >> opcao;

	switch(opcao){

		case 1:
			int opcaoSalario;
			float valor;
			cout << "\nAumentar salário: digite 1";
			cout << "\nDiminuir salário: digite 2";
			cout << "\nEscolha uma opção:";
			cin >> opcaoSalario;
			cout << "\nQuanto deseja aumentar ou diminuir? ";
			cin >> valor;

			for(int i=0; i<funcionarios.size(); i++){
				if(funcionarios[i].ID == id){
					if(opcaoSalario == 1){
						funcionarios[i].salario = funcionarios[i].salario + valor;
					}
				}else{
					funcionarios[i].salario = funcionarios[i].salario - valor;
				}
			}

			break;

		case 2:
			string novoCargo;
			cout << "\nDigite o cargo deseja atribuir ao funcionário: ";
			cin >> novoCargo;

			for(int i=0; i<funcionarios.size(); i++){
				if(funcionarios[i].ID == id){
					funcionarios[i].cargo = novoCargo;
				}
			}

			break;
	}

	//criar uma forma de atualizar no arquivo

	cout << "\nFuncionário atualizado.\n";
}

void Empresa::listarFuncionarios(){

	ofstream arquivo("Funcionarios.txt");

	cout << endl;
	cout << "Lista de funcionários:";

	arquivo << "Lista de funcionários:";

	for(int i=0; i<funcionarios.size(); i++){
		cout << endl << funcionarios[i].nome << " - ID: " << funcionarios[i].ID << " - Salário: " << funcionarios[i].salario << " - " << funcionarios[i].cargo;
		arquivo << "\n" << funcionarios[i].nome << " - ID: " << funcionarios[i].ID << " - Salário: " << funcionarios[i].salario << " - " << funcionarios[i].cargo;
	}
	cout << endl;
}


