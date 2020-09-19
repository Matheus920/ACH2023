#include <malloc.h>
#include <stdio.h>

typedef struct estrutura {
    int chave;
    struct estrutura* prox;
} NO;

typedef struct {
    NO* inicio;
} LISTA;

void inicializarLista(LISTA* l){
    l->inicio = NULL;
}

int tamanho(LISTA* l){
    NO* endereco = l->inicio;
    int tamanho = 0;

    while(endereco){
        tamanho++;
        endereco = endereco->prox;
    }

    return tamanho;
}

void exibirLista(LISTA*l ){
    NO* endereco = l->inicio;

    while(endereco){
        printf("%d ", endereco->chave);
        endereco = endereco->prox;
    }
}

NO* buscaSequencial(LISTA* l, int chave){
    NO* endereco = l->inicio;

    while(endereco){
        if(endereco->chave == chave) return endereco;
        endereco = endereco->prox;
    }

    return NULL;
}

NO* buscaSequencialOrdenada(LISTA* l, int chave){
    NO* endereco = l->inicio;

    while(endereco && endereco->chave < chave) endereco = endereco->prox;
    if(endereco && endereco->chave == chave) return endereco;

    return NULL;
}

NO* buscaSequencialAnterior(LISTA* l, int chave, NO** ant){
    *ant = NULL;
    NO* endereco = l->inicio;

    while(endereco && endereco->chave < chave){
        *ant = endereco;
        endereco = endereco->prox;
    }

    if(endereco && endereco->chave == chave) return endereco;

    return NULL;
}

bool inserirElementoListaOrdenada(LISTA*l, NO no){
    int chave = no.chave;

    NO* ant;
    NO* i;

    i = buscaSequencialAnterior(l, chave, &ant);

    if(i) return false;

    i = (NO*) malloc(sizeof(NO));

    i->chave = chave;

    if(!ant){
        i->prox = l->inicio;
        l->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }
}

bool excluirElementoListaOrdenada(LISTA* l, int chave){
    NO* ant;
    NO* i;

    i = buscaSequencialAnterior(l, chave, &ant);

    if(!i) return false;

    if(!ant) l->inicio = i->prox;
    else ant->prox = i->prox;

    free(i);
}

void reinicializarLista(LISTA* l){
    NO* elemento = l->inicio;

    while(elemento){
        NO* auxiliar = elemento;
        elemento = elemento->prox;
        free(auxiliar);
    }

    l->inicio = NULL;
}

int ocorrencias (LISTA* l, int x){
    int ocorrencias = 0;
    NO* elemento = l->inicio;

    while(elemento){
        if(elemento->chave == x)
            ocorrencias++;
        elemento = elemento->prox;
    }

    return ocorrencias;
}

bool identicas (LISTA* l1, LISTA* l2){
    NO* elemento1 = l1->inicio;
    NO* elemento2 = l2->inicio;

    bool verificador = true;

    if(!elemento1 && !elemento2) return true;

    while(elemento1 || elemento2){
        if(!verificador) return false;

        if(!elemento1 || !elemento2) return false;

        verificador = elemento1->chave == elemento2->chave;

        elemento1 = elemento1->prox;

        elemento2 = elemento2->prox;
    }

    return verificador;
}

int main() {
    LISTA l;
    NO elemento1;
    NO elemento2;
    NO elemento3;

    elemento1.chave = 20;
    elemento2.chave = 10;
    elemento3.chave = 5;

    inicializarLista(&l);

    inserirElementoListaOrdenada(&l, elemento2);
    inserirElementoListaOrdenada(&l, elemento1);
    inserirElementoListaOrdenada(&l, elemento3);

    exibirLista(&l);

    LISTA l2;

    NO elementoA;
    NO elementoB;
    NO elementoC;

    elementoA.chave = 20;
    elementoB.chave = 10;
    elementoC.chave = 5;

    inicializarLista(&l2);

    inserirElementoListaOrdenada(&l2, elementoA);
    inserirElementoListaOrdenada(&l2, elementoB);
    inserirElementoListaOrdenada(&l2, elementoC);

    printf("\n");
    exibirLista(&l2);
    printf("\n");

    printf("%d ", identicas(&l, &l2));
}
