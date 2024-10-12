//============================================================================
// Name        : main.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description :
/*

1 - Aloque dinamicamente um vetor de 5 posições de inteiros e insira como valores seus índices.

2 - Aloque dinamicamente uma matriz 4 x 4 usando ponteiros e insira em cada posição a soma de seus índices.

3 - Crie um array dinamicamente alocado de objetos Bola com 10 objetos e insira-os na tela para o arquivo fornecido (Projeto SFML).

 */
//============================================================================

#include <iostream>
#include "Bolas.hpp"
using namespace std;

void atividade1(){
	int *vetorDinamico = new int [5];

	for(int i=0; i<5; i++){
		vetorDinamico[i] = i;
	}

	for(int i=0; i<5; i++){
		cout << vetorDinamico[i] << endl;
	}

	delete [] vetorDinamico;
}

void atividade2(){
	int **matriz = new int*[4];

	for(int i=0; i< 4; i++){
		matriz[i] = new int[4];
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			matriz[i][j] = i+j;
		}
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout << matriz[i][j] << endl;
		}
		cout << endl;
	}

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			delete matriz[i];
		}
	}

	delete [] matriz;
}

void mover(sf::RectangleShape shape, float t, int *y, int *vy){
	float g = 0.5;

	*y = *y + (*vy * t);
	*vy = *vy + (g*t);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		*vy = -12.0;
	}

	shape.setPosition(0, *y);
}

int main() {
	//atividade1();
	//atividade2();
	//mainBola();

	std::srand(std::time(0)); // incializa a semente de  rand com tempo atual.

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(1.0f, 1.0f));
	shape.setFillColor(sf::Color::White);

		int y=300;
		int vy= -5.0;
		float t = 0.5;

		//Define a janela de desenho.
		sf::RenderWindow window(sf::VideoMode(800, 600), "Programação é Legal !!!");
		window.setFramerateLimit(60); // Limita o frame hate.

		//Bem mais Facil criar uma bolinha
		while (window.isOpen()) // Loop do jogo.
		{
			//Pega os eventos tipo fechar a janela ou
			//Digitar um tecla ou clicar o mouse.
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}
			//Atualiza os objetos do 'mundo'
			mover(shape, t, &y, &vy);


			//Desenha a tela.
			window.clear();

			window.display();
			window.draw(shape);
		} //Fim do loop do jogo.

	return 0;
}
