# SFML Alocação Dinâmica de Bolas

Projeto que combina alocação dinâmica de memória com simulação gráfica de bolas em queda.

## Objetivos

- Praticar alocação dinâmica com ponteiros
- Trabalhar com matriz e vetor alocados em tempo de execução

## Funcionalidades

- Alocar vetor dinâmico e preencher valores
- Alocar matriz dinâmica e preencher por regra de índices
- Atualizar movimento de bola com aceleração gravitacional
- Alterar velocidade de queda por entrada de teclado
- Renderizar bola em janela SFML

## Tecnologias usadas

- C++
- Programação Orientada a Objetos
- SFML

## Como executar

1. Baixe e extraia este repositorio para uma pasta local
2. Instale e configure a SFML no seu ambiente (include, lib e DLLs no PATH ou junto ao executavel)
3. Abra o terminal (PowerShell) na pasta extraida do repositorio
4. Entre na pasta do projeto com: `cd 13-sfml-alocacao-dinamica-bolas`
5. Compile com: `g++ .\src\main.cpp -o app.exe -lsfml-graphics -lsfml-window -lsfml-system`
6. Execute com: `.\app.exe`
