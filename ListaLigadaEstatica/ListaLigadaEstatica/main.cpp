#include <stdio.h>
#define MAX 50
#define INVALIDO -1

typedef struct{
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO reg;
    int proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO A[MAX];
    int dispo;
    int inicio;
} LISTA;

void inicializarLista(LISTA* l){

    for(int i = 0; i < MAX-1; i++){
        l->A[i].proximo = i + 1;
    }

    l->dispo = 0;
    l->A[MAX-1].proximo = INVALIDO;
    l->inicio = INVALIDO;
}

int tamanho(LISTA* l){
    int resultado = 0;

    int i = l->inicio;

    while(i != INVALIDO){
        resultado++;
        i = l->A[i].proximo;
    }

    return resultado;
}

void exibirLista(LISTA* l){
    printf("LISTA: ");

    int i = l->inicio;

    while(i != INVALIDO){
        printf("%i ", l->A[i].reg.chave);
        i = l->A[i].proximo;
    }

    printf("\n");
}

int buscaSequencialOrdenada(LISTA* l, int chave){
    int i = l->inicio;

    while(i != INVALIDO && l->A[i].reg.chave < chave)
        i = l->A[i].proximo;

    if(i != INVALIDO && l->A[i].reg.chave == chave)
        return i;

    return INVALIDO;
}

int obterDisponivel(LISTA* l){
    int i = l->dispo;

    if(i != INVALIDO)
        l->dispo = l->A[l->dispo].proximo;

    return i;
}

int devolverElemento(LISTA* l, int pos){
    l->A[pos].proximo = l->dispo;
    l->dispo = pos;
}

bool inserirElementoListaOrdenada(LISTA* l, REGISTRO reg){
    if(l->dispo == INVALIDO) return false;

    int ant = INVALIDO;
    int i = l->inicio;

    int chave = reg.chave;

    while(i != INVALIDO && l->A[i].reg.chave < chave){
        ant = i;
        i = l->A[i].proximo;
    }

    if(i != INVALIDO && l->A[i].reg.chave == chave) return false;

    i = obterDisponivel(l);
    l->A[i].reg = reg;

    if(ant == INVALIDO){
        l->A[i].proximo = l->inicio;
        l->inicio = i;
    } else {
        l->A[i].proximo = l->A[ant].proximo;
        l->A[ant].proximo = i;
    }

    return true;
}

bool excluirElementoLista(LISTA* l, int chave){
    int ant = INVALIDO;
    int i = l->inicio;

    while(i != INVALIDO && l->A[i].reg.chave < chave){
        ant = i;
        i = l->A[i].proximo;
    }

    if( (i==INVALIDO) || (l->A[i].reg.chave != chave)) return false;
    if(ant == INVALIDO) l->inicio = l->A[i].proximo;
    else l->A[ant].proximo = l->A[i].proximo;

    devolverElemento(l, i);
    return true;
}

int main() {
    LISTA l;
    REGISTRO elemento1;
    REGISTRO elemento2;
    REGISTRO elemento3;

    elemento1.chave = 5;
    elemento2.chave = 2;
    elemento3.chave = 3;

    inicializarLista(&l);

    inserirElementoListaOrdenada(&l, elemento1);
    inserirElementoListaOrdenada(&l, elemento3);

    exibirLista(&l);

    excluirElementoLista(&l, 3);
    inserirElementoListaOrdenada(&l, elemento2);

    exibirLista(&l);

}
