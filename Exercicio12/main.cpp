#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    estrutura* esq;
    estrutura* dir;
} NO;

int altura(NO* p){
    if(!p) return 0;

    int alturaEsquerda = altura(p->esq);
    int alturaDireita = altura(p->dir);

    if(alturaEsquerda > alturaDireita) return alturaEsquerda+1;

    else return alturaDireita+1;
}

int menorChave(NO* p){
    if(!p) return -1;
    else {
        int valorMinimo = p->chave;
        if(p->esq){
            int menorEsquerda = menorChave(p->esq);
            if(menorEsquerda <= valorMinimo) valorMinimo = menorEsquerda;
        }
        if(p->dir){
            int menorDireita = menorChave(p->dir);
            if(menorDireita <= valorMinimo) valorMinimo = menorDireita;
        }
        return valorMinimo;
    }
}



int main(){
    NO* raiz = (NO*) malloc(sizeof(NO));
    raiz->chave = 5;
    raiz->esq = NULL;
    raiz->dir = NULL;

    NO* direito = (NO*) malloc(sizeof(NO));
    direito->chave = 10;
    direito->esq = NULL;
    direito->dir = NULL;

    raiz->dir = direito;

    NO* esquerdo = (NO*) malloc(sizeof(NO));
    esquerdo->chave = 2;
    esquerdo->esq = NULL;
    esquerdo->dir = NULL;

    NO* esquerdoFilho = (NO*) malloc(sizeof(NO));
    esquerdoFilho->chave = 20;
    esquerdoFilho->esq = NULL;
    esquerdoFilho->dir = NULL;

    esquerdo->esq = esquerdoFilho;

    raiz->esq = esquerdo;

    printf("Altura: %i", (altura(esquerdoFilho)));
    printf("Menor chave: %i", menorChave(raiz));
}
