#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

/**
 * @Autor Alisson RS
 * @site https://gpjecc.blogspot.com/search/label/SFML?&max-results=7
 * @site https://www.sfml-dev.org/learn.php
 */

using std::vector;

class Bola {
private:
	sf::CircleShape shape;
	sf::Color cor;
public:
	int x, y;
	int vx, vy;
	int raio;

	Bola() {
		x = y = vx = vy = 0;
		this->raio = 30;
		cor = sf::Color::White;
		this->shape.setRadius(raio);
		this->shape.setPosition(x, y);
		this->shape.setFillColor(cor);
		//Define a borda da bolinha para torná-la visível se ela for da mesma cor do fundo.
		this->shape.setOutlineColor(sf::Color::White);
		this->shape.setOutlineThickness(0.6f);
	}

	Bola(int x, int y, int vx, int vy, sf::Color cor, int raio) {
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		this->raio = raio;
		this->cor = cor;
		this->shape.setRadius(raio);
		this->shape.setPosition(x, y);
		this->shape.setFillColor(cor);
		//Define a borda da bolinha para torná-la visível se ela for da mesma cor do fundo.
		this->shape.setOutlineColor(sf::Color::Yellow);
		this->shape.setOutlineThickness(0.6f);
	}

	void mover() {

		//Testa os limites e inverte as velocidades
		if (x >= 800 - 2 * raio) {
			vx = -vx;
		} else if (x <= 0) {
			vx = -vx;
		}

		if (y >= 600 - 2 * raio) {
			vy = -vy;
		} else if (y <= 0) {
			vy = -vy;
		}

		//Incrementa as posições
		x = x + vx;
		y = y + vy;

		//Testa se depois do incremento ela sai da tela e então volta a bolinha
		x = (x > 800 - 2 * raio) ? 800 - 2 * raio : x;
		y = (y > 600 - 2 * raio) ? 600 - 2 * raio : y;

		x = (x < 0) ? 0 : x;
		y = (y < 0) ? 0 : y;

		//Muda a posição do shape.
		this->shape.setPosition(x, y);
	}

	void draw(sf::RenderWindow &window) {
		//Desenha ao shape na janela.
		window.draw(shape);
	}

	//Um extra!
	void testaColisao(Bola &outra){
		if (shape.getGlobalBounds().intersects(outra.shape.getGlobalBounds())){
			this->vx *= -1;
			this->vy *= -1;
			outra.vx *= -1;
			outra.vy *= -1;
		}
	}

	void setColor(sf::Color novaCor){
		this->cor = novaCor;
		this->shape.setFillColor(cor);
	}

};

Bola criaBolinha() {
	int x, y, vx, vy, raio;
	raio = 10 + rand() % 60; // gera um numero entre 10 e 60 (sem o 60)
	x = rand() % 800; // gera um numero entre 0 e 800
	y = rand() % 600; // gera um numero entre 0 e 600
	vx = 1 + rand() % 5; // gera um numero entre 1 e 5 (sem o 5)
	vy = 1 + rand() % 5; // gera um numero entre 1 e 5 (sem o 5)

	int r, g, b, alpha;
	r = rand() % 256; // gera um numero entre 0 e 255
	g = rand() % 256; // gera um numero entre 0 e 255
	b = rand() % 256; // gera um numero entre 0 e 255
	alpha = 200 + rand() % 56; // gera um numero entre 200 e 255

	sf::Color cor(r, g, b, alpha); //https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Color.php
	Bola bola(x, y, vx, vy, cor, raio);
	return bola;
}

int mainBola() {

	std::srand(std::time(0)); // incializa a semente de  rand com tempo atual.

	//Define a janela de desenho.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Programação é Legal !!!");
	window.setFramerateLimit(60); // Limita o frame hate.

	//Bem mais Facil criar uma bolinha!
	Bola *vetorBolas = new Bola[10];

	for(int i=0; i<10; i++){
		vetorBolas[i] = criaBolinha();
	}


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


		for(int i=0; i<10; i++){
			vetorBolas[i].mover();
		}

		//Desenha a tela.
		window.clear(sf::Color::White);

		for(int i=0; i<10; i++){
			vetorBolas[i].draw(window);
		}

		window.display();
	} //Fim do loop do jogo.

	return 0;
}
