#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    estrutura* esq;
    estrutura* dir;
} NO;

void novoEsquerdo(NO* p){
    if(!p->esq){
        NO* novo = (NO*) malloc(sizeof(NO));
        if(p->dir) novo->chave = p->chave + p->dir->chave;
        else novo->chave = p->chave;
        novo->esq = NULL;
        novo->dir = NULL;
        p->esq = novo;
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

    novoEsquerdo(raiz);

    printf("%i ", raiz->esq->chave);
}
