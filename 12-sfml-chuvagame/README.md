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

## Tecnologias usadas

- C++
- SFML

## Como executar

1. Baixe e extraia este repositorio para uma pasta local
2. Instale e configure a SFML no seu ambiente (include, lib e DLLs no PATH ou junto ao executavel)
3. Abra o terminal (PowerShell) na pasta extraida do repositorio
4. Entre na pasta do projeto com: `cd 12-sfml-chuvagame`
5. Compile com: `g++ .\src\main.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio`
6. Execute com: `.\app.exe`
7. Mantenha a pasta `assets` ao lado do executável para carregar recursos do jogo
