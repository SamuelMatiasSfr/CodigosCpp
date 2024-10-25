//============================================================================
// Name        : samuel_matias_shellsort.cpp
// Author      : Samuel Matias
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <climits>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

double gerarRand(int tam){
	double resultado= (double) rand()/ tam; /* Dividir pelo maior inteiro */
	if(resultado>1.0) resultado= 1.0;
	return resultado;
}

//FUNÇÕES PARA INTEIROS
void shellsort(int vetor[], int tam){
	int i, j, h = 1, x, quantTrocas=0;

	do h = h * 3 + 1; while (h < tam);

	do{
	  h /= 3;

      for (i = h + 1; i <= tam; i++){
    	  x = vetor[i];
    	  j = i;

          while (vetor[j - h] > x){
			  vetor[j] = vetor[j - h];
			  j -= h;

			  quantTrocas++;
			  if(vetor[j-h] >= 0 and vetor[j-h] < tam){
				  cout << "Troca " << quantTrocas << ": " << vetor[j] << " foi trocada com " << vetor[j-h] << endl;
			  }else if(vetor[j-h] >= tam){
				  quantTrocas--;
			  }

			  if (j <= h){
				  goto L999;
			  }
          }
          L999: vetor[j] = x;
      }

   }while (h != 1);
}

void permut( int vetor[], int tam){
	int i,j;
	int temp;

	for(i = tam-1; i>0; i --){
		j = (i * gerarRand(tam)) + 1 ;
		temp = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = temp;
	}
}

void imprime(int vetor[], int tam){
	for(int i=0; i<tam; i++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}

//FUNÇÕES PARA STRINGS
void shellsortString(string &palavra, int tam){
	int j, h=1, quantTrocas=0;

	char temp;

	do h = h*3 + 1; while(h < tam);

	do{
		h /= 3;

		for(int i=h; i<tam; i++){
			temp = palavra[i];
			j = i;

			while(palavra[j-h] > temp){
				palavra[j] = palavra[j-h];
				j -= h;

				if(palavra[j-h] >= 0){
					cout << "Troca " << quantTrocas << ": " << palavra[j] << " foi trocada com " << palavra[j-h] << endl;
				}
				quantTrocas++;

				if(j >= h){
					goto L999;
				}
				L999: palavra[j] = temp;
			}

		}

	}while(h != 1);
}

void permutString(string &palavra, int tam){
	int j;
	char temp;

	for(int i=tam-1; i>0; i--){
		j = rand() % (i+1);
		temp = palavra[i];
		palavra[i] = palavra[j];
		palavra[j] = temp;
	}
}

void imprimeString(string palavra, int tam){
	cout << palavra << endl;
}

//ATIVIDADE USANDO INTEIROS
void atividade1(){
	int vetor[20];

	for(int i=0; i<20; i++){
		vetor[i] = i+1;
	}

	int tam=20;

	permut(vetor, tam);

	cout << "\nDesordenado: ";
	imprime(vetor, tam);

	cout << "\nShellsort:\n";
	shellsort(vetor, tam);
	cout << "\nVetor: ";
	imprime(vetor, tam);
}

//ATIVIDADE USANDO STRING
void atividade2(){
	string palavra;

	cout << "\n\nDigite a palavra: ";
	cin >> palavra;

	int tam = palavra.length();

	permutString(palavra, tam);

	cout << "\nDesordenado: ";
	imprimeString(palavra, tam);

	cout << "\nShellsort:\n";
	shellsortString(palavra, tam);
	cout << "\nPalavra: ";
	imprimeString(palavra, tam);
}


int main() {
	atividade1();
	atividade2();

	return 0;
}
