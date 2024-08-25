#include <iostream>

using namespace std;

class Arvore{
private:
	const static int root=0;
	string arvore[10];

public:
	Arvore(){
		arvore[0] = "";
	}

	void definirRaiz(string raiz){;
		arvore[0] = raiz;
	}

	void insereEsquerda(string dado, int raiz){
		int posicao = (raiz*2) + 1;
		arvore[posicao] = dado;
	}

	void insereDireita(string dado, int raiz){
		int posicao = (raiz*2) + 2;
		arvore[posicao] = dado;
	}

	void imprimirArvore(){
		for(int i=0; i<10; i++){
			if(arvore[i] != ""){
				cout << arvore[i] << ", ";
			}
		}
	}
};
