#include "Loja.hpp"

Produto::Produto(int idProduto, string nome, float preco, int quantidade){
	this->idProduto = idProduto;
	this->nome = nome;
	this->preco = preco;
	this->quantidade = quantidade;
}

Produto::~Produto(){

}

int Produto::getIdProduto(){
	return this->idProduto;
}

string Produto::getNomeProduto(){
	return this->nome;
}

float Produto::getPreco(){
	return this->preco;
}

int Produto::getQuantidadeProduto(){
	return this->quantidade;
}

void Produto::setQuantidadeProduto(int quantidade){
	this->quantidade = quantidade;
}



Cliente::Cliente(string nome, int idCliente){
	this->nome = nome;
	this->idCliente = idCliente;
}

Cliente::~Cliente(){

}

int Cliente::getID(){
	return this->idCliente;
}

string Cliente::getNomeCliente(){
	return this->nome;
}



Recibo::Recibo(Produto produto, Cliente cliente){
	this->produto = produto;
	this->cliente = cliente;
}

Recibo::~Recibo(){

}



Loja::Loja():
produtos(), clientes(), recibos()
{

}

Loja::~Loja(){

}

void Loja::adicionarProduto(){
	string nome;
	float preco;
	int quant;
	int id;
	cout << endl << "ID Produto: ";
	cin >> id;
	cout << endl << "Produto: ";
	cin >> nome;
	cout << endl << "Preço: ";
	cin >> preco;
	cout << endl << "Quantidade: ";
	cin >> quant;


	produtos.push_back(new Produto(id, nome, preco, quant));
	cout << endl << "Produto adicionado.";
}

void Loja::removerProduto(){
	int id;
	cout << endl << "ID Produto: ";
	cin >> id;

	for(auto produto : produtos){
		if(produto->getIdProduto() == id){
			delete produto;
		}
	}

	cout << endl << "Produto removido.";
}

void Loja::listarProduto(){
	for(auto produto : produtos){
		cout << endl;
		cout << produto->getIdProduto();
		cout << produto->getNomeProduto();
		cout << produto->getPreco();
		cout << produto->getQuantidadeProduto();
	}
}


void Loja::adicionarCliente(){
	string nome;
	int id;
	cout << endl << "ID Cliente: ";
	cin >> id;
	cout << endl << "Nome: ";
	cin >> nome;


	clientes.push_back(new Cliente(nome, id));
	cout << endl << "Cliente adicionado.";
}

void Loja::removerCliente(){
	int id;
	cout << endl << "ID Cliente: ";
	cin >> id;

	for(auto cliente : clientes){
		if(cliente->getID() == id){
			delete cliente;
		}
	}

	cout << endl << "Cliente removido.";
}

void Loja::listarCliente(){
	for(auto cliente : clientes){
		cout << endl;
		cout << cliente->getID;
		cout << cliente->getNomeCliente();
	}
}


void Loja::gerarRecibos(Produto produto, Cliente cliente, int quantidade){
	recibos.push_back(new Recibo(produto, cliente));


}

void Loja::realizarVendas(){
	int idProduto;
	int idCliente;
	int formaPagamento;
	int quantidade;

	cout << endl << "ID Produto: ";
	cin >> idProduto;

	cout << endl << "ID Cliente: ";
	cin >> idCliente;

	cout << endl << "Quantidade desejada: ";
	cin >> quantidade;

	cout << endl << "1. Crédito\n2. Débito\n3. Boleto\nEscolha o tipo de pagamento:";
	cin >> formaPagamento;

	Produto produtoRecibo;
	Cliente clienteRecibo;

	for(auto produto : produtos){
		int quantidadeProduto;
		if(produto->getIdProduto() == idProduto){
			produtoRecibo = produto;
			produto->setQuantidadeProduto(produto->getQuantidadeProduto() - quantidade);
		}
	}

	for(auto cliente : clientes){
		if(cliente->getID() == idCliente){
			clienteRecibo = cliente;
		}
	}

	gerarRecibos(produtoRecibo, clienteRecibo, quantidade);

	cout << endl << "Compra realizada";

}
