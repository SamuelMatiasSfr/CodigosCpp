# Namespaces

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

## Tecnologias Usadas

- C++
- Programação Orientada a Objetos
- SFML
- Eclipse IDE

## Como Executar

### Requisitos
- Ter o compilador `g++` instalado e configurado no PATH
- Ter a SFML instalada e configurada (include, lib e DLLs)

### Execução
1. Baixe e extraia o arquivo `.zip` do repositório
2. Entre na pasta `14-namespaces` no terminal
3. Compile com: `g++ .\src\main.cpp .\src\game.cpp .\src\bola.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system`
4. Execute com: `.\app.exe`
5. Consulte `Descrição da tarefa.txt` para acompanhar as etapas propostas da atividade
