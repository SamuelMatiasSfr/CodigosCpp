/*
#include "GestorTarefas.hpp"

GestorTarefas::Tarefa::Tarefa(char descricao[], int numero){
	for(int i=0; descricao[i] != '\0'; i++){
		this->descricao[i] = descricao[i];
	}
	this->concluida = false;
	this->numeroTarefa = numero;
}

GestorTarefas::Tarefa::~Tarefa(){

}

GestorTarefas::Usuario::Usuario(char nome[], int id){
	for(int i=0; nome[i] != '\0'; i++){
		this->nome[i] = nome[i];
	}
	this->ID = id;
}

GestorTarefas::Usuario::~Usuario(){

}

void GestorTarefas::GestorTarefas::gerenciador(){
	int opcao = 0;
	while(opcao != -1){
		cout << "\nLista de ac�es: ";
		cout << "\nAdicinar tarefa: digite 1";
		cout << "\nRemover tarefa: digite 2";
		cout << "\nListar tarefas: digite 3";
		cout << "\nAdicinar usu�rio: digite 4";
		cout << "\nRemover usu�rio: digite 5";
		cout << "\nConcluir tarefa: digite 6";
		cout << "\nEncerrar gerenciador: digite -1";
		cout << "\nEscolha op��o: ";
		cin >> opcao;
		cout << endl;
	}

	switch(opcao){

		case 1:
			adicionarTarefa();
			break;
		case 2:
			removerTarefa();
			break;
		case 3:
			listarTarefas();
			break;
		case 4:
			adicionarUsuario();
			break;
		case 5:
			removerUsuario();
			break;
		case 6:
			concluirTarefas();
			break;
	}

	cout << "Gerenciador encerrado.";
}

void GestorTarefas::GestorTarefas::adicionarTarefa(){

	bool usuarioExiste = false;
	int id;
	cout << "\nID do usu�rio: ";
	cin >> id;

	for(int i=0; i<usuarios.size(); i++){
		if(usuarios[i].ID == id){
			usuarioExiste = true;
		}
	}

	if(usuarioExiste){
		char descricao[100];

		printf("\nDigite a descri��o: ");
		scanf("%s", descricao);

		int numTarefa = 0;
		for(int i=0; i<usuarios.size(); i++){
			if(usuarios[i].ID == id){
				for(int j=1; j<usuarios[i].tarefasUsuario.size(); j++){
					numTarefa++;
				}
				Tarefa *tarefa = new Tarefa(descricao, numTarefa);
				usuarios[i].tarefasUsuario.push_back(*tarefa);
			}
		}
	}else{
		cout << "\nUsu�rio n�o registrado.\n";
	}
}

void GestorTarefas::GestorTarefas::removerTarefa(){

	bool usuarioExiste = false;
	int id;
	cout << "\nID do usu�rio: ";
	cin >> id;

	for(int i=0; i<usuarios.size(); i++){
		if(usuarios[i].ID == id){
			usuarioExiste = true;
		}
	}

	if(usuarioExiste){

		cout << "\nLista de tarefas do usu�rio: ";
		for(int i=0; i<usuarios.size(); i++){
			if(usuarios[i].ID == id){
				for(int j=0; j<usuarios[i].tarefasUsuario.size(); j++){
					cout << endl << usuarios[i].tarefasUsuario[j].numeroTarefa << ". " << usuarios[i].tarefasUsuario[j].descricao;
				}
			}
		}

		int num;
		cout << "\nN�mero da tarefa que deseja remover: ";
		cin >> num;

		auto it = std::remove_if(usuario.tarefasUsuario.begin(), usuario.tarefasUsuario.end(),
		                [num](const Tarefa& t) { return t.numeroTarefa == num; });

		            if (it != usuario.tarefasUsuario.end()) {
		                usuario.tarefasUsuario.erase(it, usuario.tarefasUsuario.end());
		                cout << "\nTarefa conclu�da.\n";
		            } else {
		                cout << "\nTarefa n�o encontrada.\n";
		            }

		auto it = remove_if(usuarios.tarefasUsuario.begin(), usuarios.tarefasUsuario.end(), [num](const Tarefa& tarefa){return tarefa.numTarefa == num;});

		if(it != usuarios.tarefasUsuario.end()){
			usuarios.tarefasUsuario.erase(it, usuario.tarefasUsuario.end());
			cout << "\nTarefa conclu�da\n";
		}else{
			cout << "\nTarefa n�o encontrada.\n";
		}


		for(int i=0; i<usuarios.size(); i++){
			if(usuarios[i].ID == id){
				for(int j=0; j<usuarios[i].tarefasUsuario.size(); j++){
					if(usuarios[i].tarefasUsuario[j].numeroTarefa == num){

					}
				}
			}
		}

	}else{
		cout << "\nUsu�rio n�o registrado.\n";
	}
}

void GestorTarefas::GestorTarefas::listarTarefas(){

	bool usuarioExiste = false;
	int id;
	cout << "\nID do usu�rio: ";
	cin >> id;

	for(int i=0; i<usuarios.size(); i++){
		if(usuarios[i].ID == id){
			usuarioExiste = true;
		}
	}

	if(usuarioExiste){
		cout << "\nLista de tarefas do usu�rio: ";
		for(int i=0; i<usuarios.size(); i++){
			if(usuarios[i].ID == id){
				for(int j=0; j<usuarios[i].tarefasUsuario.size(); j++){
					cout << endl << usuarios[i].tarefasUsuario[j].numeroTarefa << ". " << usuarios[i].tarefasUsuario[j].descricao;
				}
			}
		}
	}else{
		cout << "\nUsu�rio n�o registrado.\n";
	}
}

void GestorTarefas::GestorTarefas::adicionarUsuario(){
	char nome[100];
	int id;
	bool usuarioExiste = false;

	printf("\nNome: ");
	scanf("%s", nome);
	cout << "\nID: ";
	cin >> id;

	for(int i=0; i<usuarios.size(); i++){
		if(usuarios[i].ID == id){
			usuarioExiste = true;
		}
	}

	if(!usuarioExiste){
		Usuario *usuario = new Usuario(nome, id);
		usuarios.push_back(*usuario);
	}else{
		"\nUsu�rio j� existe.\n";
	}
}

void GestorTarefas::GestorTarefas::removerUsuario(){
	char nome[100];
	int id;
	bool usuarioExiste = false;

	cout << "\nID: ";
	cin >> id;

	for(int i=0; i<usuarios.size(); i++){
		if(usuarios[i].ID == id){
			usuarioExiste = true;
			delete usuarios.pop_back(*usuario);
		}
	}

	if(!usuarioExiste){
		cout << "\nUsu�rio n�o registrado.\n";
	}
}

void GestorTarefas::GestorTarefas::concluirTarefas(){
	int id;
	bool usuarioExiste = false;

	cout << "\nID do usu�rio: ";
	cin >> id;

	for(int i=0; i<usuarios.size(); i++){
		if(usuarios[i].ID == id){
			usuarioExiste = true;
		}
	}

	if(usuarioExiste){
		cout << "\nLista de tarefas n�o conclu�das: ";
		for(int i=0; i<usuarios.size(); i++){
			if(usuarios[i].ID == id){
				for(int j=0; j<usuarios[i].tarefasUsuario.size(); j++){
					cout << endl << usuarios[i].tarefasUsuario[j].numeroTarefa << ". " << usuarios[i].tarefasUsuario[j].descricao;
				}
			}
		}

		int num;
		cout << "\nDigite o n�mero da tarefa que deseja concluir: ";
		cin >> num;

		bool tarefaExiste = false;
		for(int i=0; i<usuarios.size(); i++){
			if(usuarios[i].ID == id){
				for(int j=0; j<usuarios[i].tarefasUsuario.size(); j++){
					if(usuarios[i].tarefasUsuario[j].numeroTarefa == num){
						tarefaExiste = true;
					}
				}
			}
		}

		if(tarefaExiste){
			for(int i=0; i<usuarios.size(); i++){
				if(usuarios[i].ID == id){
					usuarioExiste = true;
					for(int j=0; j<usuarios[i].tarefasUsuario.size(); j++){
						if(usuarios[i].tarefasUsuario[j].numeroTarefa == num){
							delete usuarios[i].tarefasUsuario[j];
							cout << "\nTarefa conclu�da.\n";
						}
					}
				}
			}
		}

	}else{
		cout << "\nUsu�rio n�o registrado.\n";
	}
}
