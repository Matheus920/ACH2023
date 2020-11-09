#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    estrutura* esq;
    estrutura* dir;
} NO;

void excluirFolha(NO** raiz, int ch){
    if(*raiz){
        excluirFolha(&((*raiz)->esq), ch);
        excluirFolha(&((*raiz)->dir), ch);
        if((*raiz)->chave == ch && !((*raiz)->esq) && !((*raiz)->dir)){
            *raiz = NULL;
            free(*raiz);
            return;
        }
    }
}

void exibirFolha(NO* p){
    if(p){
        printf("%i ", p->chave);
        exibirFolha(p->esq);
        exibirFolha(p->dir);
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
    esquerdo->chave = 15;
    esquerdo->esq = NULL;
    esquerdo->dir = NULL;

    NO* esquerdoFilho = (NO*) malloc(sizeof(NO));
    esquerdoFilho->chave = 20;
    esquerdoFilho->esq = NULL;
    esquerdoFilho->dir = NULL;

    esquerdo->esq = esquerdoFilho;

    raiz->esq = esquerdo;

    exibirFolha(raiz);

    excluirFolha(&raiz, 20);

    printf("\n");

    exibirFolha(raiz);
}
