#include "game.hpp"

lp1::Game::Game() { //Construtor da classe
	std::cout << "Início do Jogo" << std::endl;
	iniciar();
	atualizar();

}

void lp1::Game::iniciar() {
	//Define a janela de desenho.
	window.create(sf::VideoMode(LARGURA, ALTURA), "Programação é Legal !!!");
	window.setFramerateLimit(60); // Limita o frame hate.

	//Bem mais Facil criar uma bolinha!
	bola1 = Bola::criaBolinha();
	bola1->setColor(sf::Color::Black);

	//Ou 5 !!!
	bolas.clear();
	for (int i = 0; i < 5; ++i) {
		Bola *bola = Bola::criaBolinha();
		bolas.push_back(bola);
	}

}

void lp1::Game::atualizar() {

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

		bola1->mover();

		for (int i = 0; i < 5; ++i) {
			bolas.at(i)->mover();
			//Bolinha com problema de sociabilidade.
			bola1->testaColisao(bolas.at(i));
		}

		desenhar();
	} //Fim do loop do jogo.

}

void lp1::Game::desenhar() {
	//Desenha a tela.
	window.clear(sf::Color::White);

	bola1->draw(window);

	for (int i = 0; i < 5; ++i) {
		bolas[i]->draw(window);
	}

	window.display();
}

lp1::Game::~Game() {
	std::cout << "Fim do Jogo" << std::endl;
	for (int i = 0; i < 5; ++i) {
		delete (bolas[i]);
	}
	delete bola1;
}
