#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <string.h>

#define MAX 50

typedef char TipoChave;

typedef struct TipoRegistro {
    TipoChave Chave;
} TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
    TipoRegistro Reg;
    TipoApontador Esq, Dir;
} TipoNo;

typedef TipoApontador TipoDicionario;

void Pesquisa(TipoRegistro *x, TipoApontador *p) {
    if (*p == NULL) {
        printf("Erro: Registro nao esta presente na arvore\n");
        return;
    }
    if (x->Chave < (*p)->Reg.Chave) {
        Pesquisa(x, &(*p)->Esq);
        return;
    }
    if (x->Chave > (*p)->Reg.Chave) {
        Pesquisa(x, &(*p)->Dir);
    } else {
        *x = (*p)->Reg;
        printf("O registro foi encontrado\n");
    }
}

void Insere(TipoRegistro x, TipoApontador *p) {
    if (*p == NULL) {
        *p = (TipoApontador)malloc(sizeof(TipoNo));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave) {
        Insere(x, &(*p)->Dir);
    } else {
        printf("Erro : Registro ja existe na arvore\n");
    }
}

void Inicializa(TipoApontador *Dicionario) {
    *Dicionario = NULL;
}

void Antecessor(TipoApontador q, TipoApontador *r) {
    if ((*r)->Dir != NULL) {
        Antecessor(q, &(*r)->Dir);
        return;
    }
    q->Reg = (*r)->Reg;
    TipoApontador Aux = *r;
    *r = (*r)->Esq;
    free(Aux);
}

void Retira(TipoRegistro x, TipoApontador *p) {
    TipoApontador Aux;
    if (*p == NULL) {
        printf("Erro : Registro nao esta na arvore\n");
        return;
    }
    if (x.Chave < (*p)->Reg.Chave) {
        Retira(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave) {
        Retira(x, &(*p)->Dir);
        return;
    }
    if ((*p)->Dir == NULL) {
        Aux = *p;
        *p = (*p)->Esq;
        free(Aux);
        return;
    }
    if ((*p)->Esq != NULL) {
        Antecessor(*p, &(*p)->Esq);
        return;
    }
    Aux = *p;
    *p = (*p)->Dir;
    free(Aux);
}

void Central(TipoApontador p) {
    if (p == NULL) return;
    Central(p->Esq);
    printf("%c\n", p->Reg.Chave);
    Central(p->Dir);
}

void TestaI(TipoNo *p, int pai) {
    if (p == NULL) return;
    if (p->Esq != NULL) {
        if (p->Reg.Chave < p->Esq->Reg.Chave) {
            printf("Erro: Pai %c menor que filho a esquerda %c\n", p->Reg.Chave, p->Esq->Reg.Chave);
            exit(1);
        }
    }
    if (p->Dir != NULL) {
        if (p->Reg.Chave > p->Dir->Reg.Chave) {
            printf("Erro: Pai %c maior que filho a direita %c\n", p->Reg.Chave, p->Dir->Reg.Chave);
            exit(1);
        }
    }
    TestaI(p->Esq, p->Reg.Chave);
    TestaI(p->Dir, p->Reg.Chave);
}

void Testa(TipoNo *p) {
    if (p != NULL) {
        TestaI(p, p->Reg.Chave);
    }
}

double rand0a1() {
    double resultado = (double)rand() / RAND_MAX;
    if (resultado > 1.0) resultado = 1.0;
    return resultado;
}

void Permut(TipoChave A[], int n) {
    int i, j;
    TipoChave b;
    for (i = n; i > 0; i--) {
        j = (i * rand0a1());
        b = A[i];
        A[i] = A[j];
        A[j] = b;
    }
}

int main(int argc, char *argv[]) {
    struct timeval t;
    TipoNo *Dicionario;
    TipoRegistro x;
    int i, k, tam;
    TipoChave vetor[MAX];
    char n, pesquisado;

    Inicializa(&Dicionario);

    // Usu�rio entra com a string e uma permuta��o aleat�ria de chaves
    std::cout << "Digite uma string: ";
    std::cin >> vetor;

    tam = strlen(vetor);

    std::cout << std::endl;
    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);
    Permut(vetor, tam - 1);

    // Insere cada chave na �rvore e testa sua integridade ap�s cada inser��o
    for (i = 0; i < tam; i++) {
        x.Chave = vetor[i];
        Insere(x, &Dicionario);
        printf("Inseriu chave: %c\n", x.Chave);
        Testa(Dicionario);
    }
    std::cout << std::endl;

    std::cout << "Digite um elemento que sera pesquisado: ";
    std::cin >> pesquisado;
    std::cout << std::endl;

    // Retira uma chave aleatoriamente e realiza a pesquisa necess�ria
    for (i = 0; i <= tam; i++) {
        k = (int)(5.0 * rand() / (RAND_MAX + 1.0));
        n = vetor[k];
        x.Chave = n;
        Retira(x, &Dicionario);
        Testa(Dicionario);
        printf("Retirou chave: %c\n", x.Chave);

        x.Chave = pesquisado;
		if (x.Chave != n) {
			printf("Pesquisando chave: %c\n", x.Chave);
			Pesquisa(&x, &Dicionario);

			x.Chave = n;
			Insere(x, &Dicionario);
			printf("Inseriu chave: %c\n", x.Chave);
			Testa(Dicionario);

			break;
		}
    }

    return 0;
}
