#include <stdio.h>
#include <malloc.h>

typedef struct aux {
    int chave;
    aux* prox;
} NO;

typedef struct {
    NO* topo;
} PILHA;

NO* copiaInvertida(NO* p){
    if(!p) return NULL;
    PILHA* pilha = (PILHA*) malloc(sizeof(PILHA));
    pilha->topo = NULL;

    while(p){
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = p->chave;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        p = p->prox;
    }

    NO* auxiliar = pilha->topo;
    NO* inicio = NULL;
    NO* fim = NULL;

    while(auxiliar){
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = auxiliar->chave;
        novo->prox = NULL;

        if(fim){
            fim->prox = novo;
        }else {
            inicio = novo;
        }

        fim = novo;
        auxiliar = auxiliar->prox;
    }

    return inicio;
}

int main(){
    NO* elemento1 = (NO*) malloc(sizeof(NO));
    NO* elemento2 = (NO*) malloc(sizeof(NO));
    NO* elemento3 = (NO*) malloc(sizeof(NO));

    elemento1->chave = 10;
    elemento2->chave = 20;
    elemento3->chave = 30;

    elemento1->prox = elemento2;
    elemento2->prox = elemento3;
    elemento3->prox = NULL;

    NO* elementoTeste;

    elementoTeste = copiaInvertida(elemento1);

    while(elementoTeste){
        printf(" %i", elementoTeste->chave);
        elementoTeste = elementoTeste->prox;
    }
}
