#include <iostream>
#include <vector>

using namespace std;

class Produto{
private:
	int idProduto;
	string nome;
	float preco;
	int quantidade;

public:
	Produto(int idProduto, string nome, float preco, int quantidade);
	~Produto();
	string getNomeProduto();
	float getPreco();
	int getQuantidadeProduto();
	void setQuantidadeProduto(int quantidade);
	int getIdProduto();
};


class Cliente{
private:
	string nome;
	int idCliente;

public:
	Cliente(string nome, int idCliente);
	~Cliente();
	string getNomeCliente();
	int getID();
};


class Recibo{
private:
	Produto produto;
	Cliente cliente;

public:
	Recibo(Produto produto, Cliente cliente);
	~Recibo();
};


class Loja{
private:
	vector<Produto*>produtos;
	vector<Cliente*>clientes;
	vector<Recibo*> recibos;

public:
	Loja();
	~Loja();
	void adicionarProduto();
	void removerProduto();
	void listarProduto();
	void adicionarCliente();
	void removerCliente();
	void listarCliente();
	void realizarVendas();
	void gerarRecibos(Produto produto, Cliente cliente, int quantidade);
};
