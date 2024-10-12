#include "bola.hpp"

lp1::Bola::Bola() {
	x = y = vx = vy = 0;
	this->raio = 30;
	cor = sf::Color::White;
	this->shape.setRadius(raio);
	this->shape.setPosition(x, y);
	this->shape.setFillColor(cor);
	//Define a borda da bolinha para torná-la visível se ela for da mesma cor do fundo.
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(0.6f);
	std::cout << toString() << std::endl;
}

//Construtor que cria bolinha com
//Parametros fornecidos.
lp1::Bola::Bola(int x, int y, int vx, int vy, sf::Color cor, int raio) {
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
	std::cout << toString() << std::endl;
}

//Move a bolinho com o valor de sua velocidade.
//Testa os limites da tela.
void lp1::Bola::mover() {

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

void lp1::Bola::draw(sf::RenderWindow &window) {
	//Desenha ao shape na janela.
	window.draw(shape);
}

//Um extra!
void lp1::Bola::testaColisao(Bola *outra) {
	if (shape.getGlobalBounds().intersects(
			outra->shape.getGlobalBounds())) {
		this->vx *= -1;
		this->vy *= -1;
		outra->vx *= -1;
		outra->vy *= -1;
	}
}

void lp1::Bola::testaColisaoCircular(Bola *outra) {
	int distanciaAtual = sqrt ((outra->x-x *outra->x-x) + (outra->y-y *outra->y-y));
	int distanciaMinima = 2*raio + 2*outra->raio;
	if (distanciaAtual < distanciaMinima) {
			this->vx *= -1;
			this->vy *= -1;
			outra->vx *= -1;
			outra->vy *= -1;
		}
	}

void lp1::Bola::setColor(sf::Color novaCor) {
	this->cor = novaCor;
	shape.setFillColor(novaCor);
}

string lp1::Bola::toString() {

	stringstream ss;
	ss << x;
	ss << ";" << y;
	ss << ";" << vx;
	ss << ";" << vy;
	ss << ";[" << (int) cor.r;
	ss << "," << (int) cor.b;
	ss << "," << (int) cor.g << "]";
	ss << ";" << raio;
	return ss.str();
}

/**Função estática para criação de uma bolinha
**Com dados aleatórios.
**/

lp1::Bola* lp1::Bola::criaBolinha() {
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
	Bola *bola = new Bola(x, y, vx, vy, cor, raio);
	return bola;
}
