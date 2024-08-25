#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

namespace GestorTarefas{
	class Tarefa{
	public:
		string descricao;
		int numeroTarefa;
		bool concluida;

		Tarefa(char descricao[], int numero);
		~Tarefa();
	};
}

namespace GestorTarefas{
	class Usuario{
	public:
		string nome;
		int ID;
		vector<Tarefa> tarefasUsuario;

		Usuario(char nome[], int id);
		~Usuario();
	};
}

namespace GestorTarefas{
	class GestorTarefas{
	public:
		vector<Usuario> usuarios;

		void adicionarTarefa();
		void removerTarefa();
		void listarTarefas();
		void adicionarUsuario();
		void removerUsuario();
		void concluirTarefas();
		void gerenciador();
	};
}
