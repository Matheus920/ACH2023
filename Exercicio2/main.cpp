#include <stdio.h>

#define MAX 50

typedef struct {
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO lista[MAX];
    int nroElementos;
} LISTA;

void inicializarLista(LISTA* l){
    l->nroElementos = 0;
}

int ocorrencias(LISTA* l, int x){
    int resultado = 0;

    for(int i = 0; i < l->nroElementos; i++){
        if(l->lista[i].chave == x) resultado++;
    }

    return resultado;
}

bool comparacao(LISTA* l1, LISTA* l2){
    if(l1->nroElementos != l2->nroElementos) return false;

    if(l1->nroElementos == 0 && l2->nroElementos == 0) return true;

    bool igual = false;

    for(int i = 0; i < l1->nroElementos; i++){
        igual = l1->lista[i].chave == l2->lista[i].chave;
        if(!igual) break;
    }

    return igual;
}

bool inserirElemento(LISTA* l, REGISTRO elemento, int pos){
    if(pos < 0 || l->nroElementos == MAX && pos > l->nroElementos){
        return false;
    }

    for(int i = l->nroElementos; i > pos; i--){
        l->lista[i] = l->lista[i-1];
    }

    l->lista[pos] = elemento;
    l->nroElementos++;
    return true;
}

int main()
{
    LISTA l1;
    LISTA l2;
    REGISTRO elemento1;
    REGISTRO elemento2;
    REGISTRO elemento3;

    inicializarLista(&l1);
    inicializarLista(&l2);
    elemento1.chave = 200;
    elemento2.chave = 200;
    elemento3.chave = 400;
    inserirElemento(&l1, elemento1, 0);
    inserirElemento(&l1, elemento2, 0);
    inserirElemento(&l1, elemento3, 0);
    inserirElemento(&l2, elemento1, 0);
    inserirElemento(&l2, elemento2, 0);
    inserirElemento(&l2, elemento3, 0);
    printf("%i ", comparacao(&l1, &l2));
}
