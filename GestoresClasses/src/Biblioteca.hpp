#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Livro{
public:
	string titulo;
	int ISBN;
	string autor;
	bool disponiblidade;

	Livro(string titulo, int isbn, string autor);
	Livro(string titulo, int isbn, string autor, bool disponibilidade);
	~Livro();
};

class Usuario{
public:
	string nome;
	int ID;

	Usuario(string nome, int id);
	~Usuario();
};

class Biblioteca{
public:
	vector<Livro> livros;
	vector<Usuario> usuarios;
	vector<Livro>livrosEmprestados;
	vector<Usuario>usuariosComLivro;

	void biblioteca();
	void adicionarLivro();
	void removerLivro();
	void listarLivros();
	void adicionarUsuario();
	void removerUsuario();
	void listarUsuarios();
	void emprestarLivro();
	void devolverLivro();
	void emprestimos();
};
