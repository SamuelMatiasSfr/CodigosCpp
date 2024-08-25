//============================================================================
// Name        : LP1-016-SFML-SimpleGame.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <cstdlib>
#include <cstdio>
#include <ctime>

sf::Sprite spawnRaindrop(sf::Texture &texture) {
	sf::Sprite raindrop(texture);
	int x = rand() % (800 - 64);
	x = x > 32 ? x : 32;
	int y = -32;
	raindrop.setPosition(x, y);
	raindrop.setOrigin(raindrop.getLocalBounds().width / 2.,
			raindrop.getLocalBounds().height / 2.);
	return raindrop;
}

sf::Sprite spawnBola(sf::Texture &texture) {
	sf::Sprite bola(texture);
	int largura = 800 - bola.getLocalBounds().width;
	int x = rand() % largura;
	x = x > bola.getLocalBounds().width ? x : bola.getLocalBounds().width;
	int y = 600 - bola.getLocalBounds().height;
	bola.setPosition(x, y);
	bola.setOrigin(bola.getLocalBounds().width / 2.,
			bola.getLocalBounds().height / 2.);
	return bola;
}

void moverBalde(int *velY, int *velX){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		*velX = -5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		*velX = 5;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		*velY = -5;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		*velY = 5;
	}
}

void testarLimiteNuvem(int *velX, sf::Sprite sprite){
	if(sprite.getPosition().x == (0 + 0.5f*2)){
		*velX = -*velX;
	}else if(sprite.getPosition().x == (800 - 0.5f*2)){
		*velX = -*velX;
	}
}

int main() {
	/**********************Inicializa Objetos do Jogo**********************/
	srand(time(NULL));
	setbuf(stdout, NULL);

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!",
			sf::Style::Close | sf::Style::Titlebar);
	// Opções de abertura da janela: sf::Style::Close + sf::Style::Titlebar + sf::Style::Resize

	//Declara variávieis para SFML
	sf::Texture texturaBola;
	sf::Sprite bolaImage;

	sf::Texture textureFundo;
	sf::Sprite fundoImage;

	sf::Texture textureDropImage;
	sf::Sprite dropImage;

	sf::Texture texturebucketImage;
	sf::Sprite bucketImage;

	sf::Texture texturaNuvemImage;
	sf::Sprite nuvemImage;

	sf::SoundBuffer bufferDropSound;
	sf::Sound dropSound;

	sf::SoundBuffer bufferOver;
	sf::Sound overSound;

	sf::Music rainMusic;

	sf::Font font;

	//Declara variávieis para o jogo
	int pontos = 0;
	int vidas = 5;

	int velBucketX = 0;
	int velBucketY = 0;
	int velDrop = 5;
	int velBola = 5;
	int velNuvemX = 5;
	int velNuvemY = 0;

	bool pausado = false;

	//Inicializa as variávies.
	window.setFramerateLimit(60); // Limita os frames
	window.setVerticalSyncEnabled(true);//limita a sincronização

	//Icone da janela.
	sf::Image image = sf::Image { };
	image.loadFromFile("assets/cogumelo.png");
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	// load the images for the droplet and the bucket, 64x64 pixels each
	textureFundo.loadFromFile("assets/fundo.png");
	textureDropImage.loadFromFile("assets/droplet.png");
	texturebucketImage.loadFromFile("assets/bucket.png");
	texturaNuvemImage.loadFromFile("assets/nuvem.png");
	texturaBola.loadFromFile("assets/ball.png");

	nuvemImage.setTexture(texturaNuvemImage);
	fundoImage.setTexture(textureFundo);
	bucketImage.setTexture(texturebucketImage);

	bucketImage.setOrigin(bucketImage.getLocalBounds().width / 2.,
			bucketImage.getLocalBounds().height / 2.);
	bucketImage.setPosition(400, 550);

	nuvemImage.setScale(0.5f, 0.5f);
	nuvemImage.setOrigin(0,-50);

	bufferDropSound.loadFromFile("assets/drop.wav");
	dropSound.setBuffer(bufferDropSound);

	bufferOver.loadFromFile("assets/Sonic-Game-Over.ogg");
	overSound.setBuffer(bufferOver);

	rainMusic.openFromFile("assets/rain.ogg");
	// start the playback of the background music immediately
	rainMusic.setLoop(true);
	rainMusic.play();

	font.loadFromFile("assets/x-files.ttf");

	sf::Text txtVidas("Vidas:\t5", font, 24);
	sf::Text txtPontos("Pontos:\t0", font, 24);
	sf::Text txtGameOver("", font, 96);

	txtPontos.setColor(sf::Color::Blue);
	txtVidas.setColor(sf::Color::Red);

	txtVidas.setPosition(600, 10);
	txtPontos.setPosition(600, 40);

	// a função cria a gota de chuva como um sprite.
	dropImage = spawnRaindrop(textureDropImage);
	bolaImage = spawnBola(texturaBola);

	/**********************Loop do jogo**********************/
	while (window.isOpen()) {
		sf::Event event;
		velBucketX = 0;
		velBucketY = 0;

		//Trata as interações.
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) { //Tecla pressionada.
				if (event.key.code == sf::Keyboard::Space) {
					pausado = !pausado; // Inverte pausa ou despausa.
				}
			}

			if (event.type == sf::Event::KeyReleased) { //Tecla Solta.

			}
			if (event.type == sf::Event::MouseButtonPressed) {
				int x = sf::Mouse::getPosition(window).x;
				int y = sf::Mouse::getPosition(window).y;
				bucketImage.setPosition(x, y);
			}
		}
		//Fim do loop de eventos.

		//Verifica teclas individualmente independente do loop de eventos.
		moverBalde(&velBucketY, &velBucketX);
		testarLimiteNuvem(&velNuvemX, nuvemImage);

		/**********************Atualiza o mundo**********************/
		if (!pausado) { //Pausa a atualização do mundo (barra de espaço)

			//Move objetos.
			bucketImage.setPosition(bucketImage.getPosition().x + velBucketX,
					bucketImage.getPosition().y + velBucketY);

			dropImage.setPosition(dropImage.getPosition().x,
					dropImage.getPosition().y + velDrop);

			bolaImage.setPosition(bolaImage.getPosition().x,
								bolaImage.getPosition().y + velBola);


			nuvemImage.setPosition(nuvemImage.getPosition().x + velNuvemX,
					nuvemImage.getPosition().y + velNuvemY);


			if (bolaImage.getPosition().y > 0 - bolaImage.getLocalBounds().height) {
				bolaImage = spawnBola(texturaBola);
			}

			if (dropImage.getPosition().y > 600 + 64) {
				dropImage = spawnRaindrop(textureDropImage);
				vidas--;
				char str[5];
				sprintf(str, "Vidas:\t%d", vidas);
				txtVidas.setString(str);
			}

			/**********************Testa colisões **********************/
			if (bucketImage.getGlobalBounds().intersects(
					dropImage.getGlobalBounds())) {
				pontos++;
				dropSound.play();
				char str[5];
				sprintf(str, "Pontos:\t%d", pontos);
				txtPontos.setString(str);
				dropImage = spawnRaindrop(textureDropImage);
			}

			//Verifica o fim do jogo.
			if (vidas == 0) {
				overSound.play(); //Se a condição não mudar (vidas==0) isso é
								  //chamado 60 vezes por segundo.
								  //Se não puder mudar a condição use um clock
								  //dar um tempo entre uma chamada e outra.
				rainMusic.pause();
				velDrop = 0;
				dropImage.setPosition(dropImage.getPosition().x, 0 - 64);
				txtGameOver.setString("Game Over!");
				sf::FloatRect bounds(txtGameOver.getLocalBounds());
				txtGameOver.setPosition(
						window.getSize().x / 2
								- (bounds.left + bounds.width / 2),
						window.getSize().y / 2
								- (bounds.top + bounds.height / 2));
				vidas = -1;
			}

		} // Fim do bloco de pause

		/**********************Pinta o mundo**********************/

		window.clear(sf::Color::White);
		window.draw(fundoImage); 	// Desenha backgroud
		window.draw(bucketImage);	// Desenha Balde
		window.draw(nuvemImage);    //desenha nuvem
		window.draw(bolaImage);
		window.draw(dropImage);		// Desenha gota de chuva
		window.draw(txtPontos);		// Desenha potuação
		window.draw(txtVidas);		// Desenha vidas
		window.draw(txtGameOver);	// Desenha gameOver
		window.display();		 	// Mostra na tela.
		sf::sleep(sf::milliseconds(10.0f));

	} //Fim do loop do jogo (janela aberta).

	return 0;
}
