#include <stdio.h>
#include <malloc.h>

typedef struct aux {
    aux* prox;
    aux* ant;
    int chave;
} NO;

typedef struct {
    NO* inicio;
} LISTA;

void inicializarLista(LISTA* l){
    l->inicio = NULL;
}

NO* listaNumerada(int n){
    NO* inicio = NULL;

    NO* atual = NULL;
    NO* anterior = NULL;

    for(int i = 1; i <= n; i++){
        atual = (NO*) malloc(sizeof(NO));
        atual->chave = i;
        if(anterior){
            atual->ant = anterior;
            anterior->prox = atual;
        } else {
            inicio = atual;
        }
        anterior = atual;
    }

    return inicio;

}

void moverParaFim(LISTA* l, NO* p){
    NO* atual = l->inicio;

    while(atual != p){
        atual = atual->prox;
    }

    if(atual->prox){
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;

        NO* fim = atual;

        while(fim->prox){
            fim = fim->prox;
        }

        fim->prox = atual;
        atual->ant = fim;
        atual->prox = NULL;
    }

}

int main(){
    LISTA l;

    inicializarLista(&l);

    NO* teste = listaNumerada(8);
    l.inicio = teste;

    NO* aux = l.inicio;

    while(aux){
        printf("%i ", aux->chave);
        aux = aux->prox;
    }

    NO* moverParaOFim = l.inicio->prox;

    moverParaFim(&l, moverParaOFim);

    aux = l.inicio;

    while(aux->prox){
        aux = aux->prox;
    }

    printf("\n");

    while(aux){
        printf("%i ", aux->chave);
        aux = aux->ant;
    }
}
