#include "Biblioteca.hpp"

Livro::Livro(string titulo, int isbn, string autor, bool disponibilidade){
	this->titulo = titulo;
	this->ISBN = isbn;
	this->autor = autor;
	this->disponiblidade = disponibilidade;
}

Livro::Livro(string titulo, int isbn, string autor){
	this->titulo = titulo;
	this->ISBN = isbn;
	this->autor = autor;
}

Livro::~Livro(){

}

Usuario::Usuario(string nome, int id){
	this->nome = nome;
	this->ID = id;
}

Usuario::~Usuario(){

}

void Biblioteca::biblioteca(){
	int opcao = 0;
	while(opcao != -1){
		cout << "\nLista de ações:\n";
		cout << "Adicionar livro: digite 1\n";
		cout << "Remover livro: digite 2\n";
		cout << "Listar livros: digite 3\n";
		cout << "Adicionar usuário: digite 4\n";
		cout << "Removerr usuário: digite 5\n";
		cout << "Listar usuários: digite 6\n";
		cout << "Emprestar livro: digite 7\n";
		cout << "Devolver livro: digite 8\n";
		cout << "Exibir empréstimos: digite 9\n";
		cout << "Encerrar gerenciador: digite -1\n";
		cout << "Qual ação deseja realizar? Escolha uma opçao: ";
		cin >> opcao;
		cout << endl;

		switch(opcao){

		case 1:
			adicionarLivro();
			break;
		case 2:
			removerLivro();
			break;
		case 3:
			listarLivros();
			break;
		case 4:
			adicionarUsuario();
			break;
		case 5:
			removerUsuario();
			break;
		case 6:
			listarUsuarios();
			break;
		case 7:
			emprestarLivro();
			break;
		case 8:
			devolverLivro();
			break;
		case 9:
			emprestimos();
			break;
		}
	}

	cout << "Gerenciador encerrado.";
}

void Biblioteca::adicionarLivro(){
	string titulo;
	int isbn;
	string autor;

	cout << "Título: ";
	cin >> titulo;
	cout << "ISBN: ";
	cin >> isbn;
	cout << "Autor: ";
	cin >> autor;

	livros.push_back(Livro(titulo, isbn, autor, true));

	cout << "\nLivro adicionado.\n";
}

void Biblioteca::adicionarUsuario(){
	string nome;
	int id;

	cout << "Nome: ";
	cin >> nome;
	cout << "ID: ";
	cin >> id;

	usuarios.push_back(Usuario(nome, id));

	cout << "\nUsuário adicionado.\n";
}

void Biblioteca::removerLivro(){
	int isbn;
	cout << "Digite o ISBN do livro: ";
	cin >> isbn;

	for(auto it = livros.begin(); it != livros.end(); ++it){
		if(it->ISBN == isbn){
			livros.erase(it);
		}
	}

	cout << "\nLivro removido.\n";
}

void Biblioteca::removerUsuario(){
	int id;
	cout << "Digite o ID do usuário: ";
	cin >> id;

	for(auto it = usuarios.begin(); it != usuarios.end(); ++it){
		if(it->ID == id){
			usuarios.erase(it);
		}
	}

	cout << "\nUsuário removido.\n";
}

void Biblioteca::listarLivros(){
	ofstream arquivoLivros("ListaLivros.txt");

	cout << endl;
	cout << "Lista de livros: ";

	arquivoLivros << "Lista de livros: ";

	for(int i=0; i<livros.size(); i++){

		string disponibilidade;
		if(livros[i].disponiblidade){
			disponibilidade = "disponível";
		}else{
			disponibilidade = "indisponível";
		}

		cout << endl << livros[i].titulo << " - ISBN: " << livros[i].ISBN << " - Autor: " << livros[i].autor << " - " << disponibilidade;
		arquivoLivros << "\n" << livros[i].titulo << " - ISBN: " << livros[i].ISBN << " - Autor: " << livros[i].autor << " - " << disponibilidade;
	}
	cout << endl;
}

void Biblioteca::listarUsuarios(){
	ofstream arquivoUsuarios("ListaUsuarios.txt");

	cout << endl;
	cout << "Lista de Usuários";

	arquivoUsuarios << "Lista de usuários: ";

	for(int i=0; i<usuarios.size(); i++){
		cout << endl << usuarios[i].nome << " - ID: " << usuarios[i].ID;
		arquivoUsuarios << "\n" << usuarios[i].nome << " - ID: " << usuarios[i].ID;
	}
	cout << endl;
}

void Biblioteca::emprestarLivro(){
	int id, isbn;

	cout << "Digite o ID do usuário: ";
	cin >> id;
	cout << "Digite a ISBN do livro: ";
	cin >> isbn;

	string nomeUsuario, tituloLivro, autorLivro;
	bool usuarioEncontrado = false, livroEncontrado = false;

	for(int i=0; i<usuarios.size(); i++){
		if(usuarios[i].ID == id){
			nomeUsuario = usuarios[i].nome;
			usuariosComLivro.push_back(Usuario(nomeUsuario, id));
			usuarioEncontrado = true;
			break;
		}
	}

	if(!usuarioEncontrado){
		cout << "\nEste usuário não está registrado.";
	}

	for(int i=0; i<livros.size(); i++){
		if(livros[i].ISBN == isbn){
			livroEncontrado = true;
			if(!livros[i].disponiblidade){
				cout << "\nEste livro está indisponível.";
			}else{
				tituloLivro = livros[i].titulo;
				autorLivro = livros[i].autor;
				livros[i].disponiblidade = false;
				livrosEmprestados.push_back(Livro(tituloLivro, isbn, autorLivro));
				livroEncontrado = true;
				break;
			}
		}
	}

	cout << "\nO livro " << tituloLivro << " do autor " << autorLivro << " - ISBN: " << isbn << " foi emprestado ao usuário " << nomeUsuario << " - ID: " << id << "\n";

	if(!livroEncontrado){
		cout << "\nEste livro não está registrado.\n";
	}
}

void Biblioteca::devolverLivro(){
	int isbn;

	cout << "Digite o ISBN do livro: ";
	cin >> isbn;

	for(int i=0; i<livros.size(); i++){
		if(livros[i].ISBN == isbn){
			livros[i].disponiblidade = true;
		}
	}

	for(int i=0; i<livrosEmprestados.size(); i++){
		if(livrosEmprestados[i].ISBN == isbn){
			livrosEmprestados[i].~Livro();
			usuariosComLivro[i].~Usuario();
		}
	}

	cout << "\nLivro devolvido.\n";
}

void Biblioteca::emprestimos(){
	ofstream arquivoEmprestimo("LivrosEmprestados.txt");

	cout << endl;
	cout << "Lista de empréstimos: ";

	arquivoEmprestimo << "Lista de empréstimos: ";

	for(int i=0; i<livrosEmprestados.size(); i++){
		cout << "\nTítulo: " << livrosEmprestados[i].titulo;
		cout << "\nISBN: " << livrosEmprestados[i].ISBN;
		cout << "\nAutor: " << livrosEmprestados[i].autor;
		cout << "\nUsuário: " << usuariosComLivro[i].nome << " - ID: " << usuariosComLivro[i].ID;
		cout << endl;

		arquivoEmprestimo << "\nTítulo: " << livrosEmprestados[i].titulo;
		arquivoEmprestimo << "\nISBN: " << livrosEmprestados[i].ISBN;
		arquivoEmprestimo << "\nAutor: " << livrosEmprestados[i].autor;
		arquivoEmprestimo << "\nUsuário: " << usuariosComLivro[i].nome << " - ID: " << usuariosComLivro[i].ID << "\n";
	}
	cout << endl;
}
