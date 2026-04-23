# SFML Eventos de Mouse

Aplicação gráfica com SFML que reage ao clique do mouse movendo um círculo.

## Objetivos

- Praticar criação de janela gráfica com SFML  
- Tratar eventos de mouse em tempo real  
- Atualizar e desenhar objetos no loop principal  

## Funcionalidades

- Criar janela gráfica para renderização  
- Detectar clique do mouse  
- Exibir coordenadas do clique no terminal  
- Mover o círculo para a posição clicada  
- Renderizar o objeto a cada frame  

## Tecnologias usadas

- C++  
- SFML 
- Eclipse IDE

## Como executar

1. Baixe e extraia este repositório para uma pasta local  
2. Instale e configure a SFML no seu ambiente (include, lib e DLLs no PATH ou junto ao executável)
3. Abra o terminal (PowerShell) na pasta extraída do repositório
4. Entre na pasta do projeto com: `cd 04-sfml-eventos-mouse` 
5. Compile com: `g++ .\main.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system`.
6. Execute com: `.\app.exe`