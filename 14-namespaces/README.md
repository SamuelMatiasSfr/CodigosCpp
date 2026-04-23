# 14 - Namespaces

Projeto em SFML com separação de classes em arquivos distintos e organização via namespace.

## Objetivos

- Separar o código em arquivos de cabeçalho e implementação
- Aplicar namespace comum para evitar conflitos de nomes
- Manter o jogo funcionando durante a refatoração

## Funcionalidades

- Inicializar estado do jogo em classe dedicada
- Atualizar a lógica de movimentação das bolinhas
- Desenhar cena e objetos em cada frame
- Detectar colisão entre bolinhas
- Encapsular classes dentro de namespace

## Tecnologias usadas

- C++
- Programação Orientada a Objetos
- SFML

## Como executar

1. Baixe e extraia este repositorio para uma pasta local
2. Instale e configure a SFML no seu ambiente (include, lib e DLLs no PATH ou junto ao executavel)
3. Abra o terminal (PowerShell) na pasta extraida do repositorio
4. Entre na pasta do projeto com: `cd 14-namespaces`
5. Compile com: `g++ .\src\main.cpp .\src\game.cpp .\src\bola.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system`
6. Execute com: `.\app.exe`
7. Consulte `Descrição da tarefa.txt` para acompanhar as etapas propostas da atividade
