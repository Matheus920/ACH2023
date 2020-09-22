#include <stdlib.h>
#include <stdio.h>

typedef struct temp {
    temp* prox;
    int valor;
} NO;

typedef struct {
    NO* cabeca;
} LISTA;

void inicializarLista(LISTA* l){
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA* l){
    NO* endereco = l->cabeca->prox;
    int tamanho = 0;

    while(endereco != l->cabeca){
        tamanho++;
        endereco = endereco->prox;
    }

    return tamanho;
}

void exibirLista(LISTA* l){
    NO* endereco = l->cabeca->prox;

    while(endereco != l->cabeca){
        printf("%i ", endereco->valor);
        endereco = endereco->prox;
    }
}

NO* buscaSentinela(LISTA* l, int chave){
    NO* pos = l->cabeca->prox;
    l->cabeca->valor = chave;

    while(pos->valor != chave) pos = pos->prox;
    if(pos != l->cabeca) return pos;

    return NULL;
}

NO* buscaSentinelaOrdenada(LISTA* l, int chave){
    NO* pos = l->cabeca->prox;
    l->cabeca->valor = chave;

    while(pos->valor < chave) pos = pos->prox;
    if(pos != l->cabeca && pos->valor == chave) return pos;

    return NULL;
}

NO* buscaSequencialExclusao(LISTA*l, int chave, NO** ant){
    *ant = l->cabeca;
    NO* atual = l->cabeca->prox;
    l->cabeca->valor = chave;

    while(atual->valor < chave){
        *ant = atual;
        atual = atual->prox;
    }

    if(atual != l->cabeca && atual->valor == chave) return atual;

    return NULL;
}

bool insercaoOrdenada(LISTA*l, int chave){
    NO* ant;
    NO* i;

    i = buscaSequencialExclusao(l, chave, &ant);

    if(i) return false;

    i = (NO*) malloc(sizeof(NO));
    i->valor = chave;
    i->prox = ant->prox;
    ant->prox = i;
}

bool excluirElemento(LISTA*l, int chave){
    NO* ant;
    NO* i;

    i = buscaSequencialExclusao(l, chave, &ant);

    if(!i) return false;

    ant->prox = i->prox;

    free(i);

    return true;
}

void reinicializarLista(LISTA*l){
    NO* endereco = l->cabeca->prox;

    while(endereco != l->cabeca){
        NO* apagar = endereco;
        endereco = endereco->prox;
        free(apagar);
    }

    l->cabeca->prox = l->cabeca;
}


int main(){
    LISTA l;
    inicializarLista(&l);
    insercaoOrdenada(&l, 20);
    insercaoOrdenada(&l, 10);
    insercaoOrdenada(&l, 2);
    exibirLista(&l);
}
