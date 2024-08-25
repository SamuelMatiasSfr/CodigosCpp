#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	sf::RenderWindow renderWindow(sf::VideoMode(300, 200), "SFML Demo");
	sf::Event event; //Variável para armazenar o evento a ser tratado.
	sf::CircleShape shape(30.f);
	int x = 100, y = 50, botao = 0;
	shape.setOrigin(shape.getRadius() / 2., shape.getRadius() / 2.);

	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				x = sf::Mouse::getPosition(renderWindow).x;
				y = sf::Mouse::getPosition(renderWindow).y;
				botao = event.mouseButton.button;
				printf("Button %d @ (%d,%d)\n", botao, x, y);
				fflush (stdout);
			}
		}
		shape.setPosition(x, y);
		renderWindow.clear();
		renderWindow.draw(shape);
		renderWindow.display();
	}
	return 0;
}
