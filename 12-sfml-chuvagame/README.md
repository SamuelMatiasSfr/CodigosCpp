# SFML Chuva Game

Jogo em SFML no qual o jogador move um balde para coletar gotas e evitar obstáculos.

## Objetivos

- Praticar desenvolvimento de jogo 2D com SFML
- Trabalhar com loop de atualização e renderização
- Implementar colisão, pontuação e sistema de vidas

## Funcionalidades

- Mover o balde com o teclado
- Gerar gotas e obstáculos dinamicamente
- Detectar colisão entre balde e objetos
- Somar pontos ao coletar gotas
- Reduzir vidas ao colidir com obstáculos
- Reproduzir áudio de evento durante o jogo

## Tecnologias Usadas

- C++
- SFML
- Eclipse IDE

## Como Executar

1. Baixe e extraia o arquivo `.zip` do repositório
2. Entre na pasta `12-sfml-chuvagame` no terminal
3. Compile com: `g++ .\src\main.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio`
4. Execute com: `\.\app.exe`
5. Mantenha a pasta `assets` ao lado do executável para carregar recursos do jogo
