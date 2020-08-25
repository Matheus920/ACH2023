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

int numeroElementos(LISTA l){
    return l.nroElementos;
}

void exibirElementos(LISTA l){
    for(int i = 0; i < l.nroElementos; i++){
        printf("%i ", l.lista[i].chave);
    }
}

int buscaSequencial(LISTA l, int chave){
    int resultado = -1;

    for(int i = 0; i < l.nroElementos; i++){
        if(l.lista[i].chave == chave) {
            resultado = i;
            break;
        }
    }

    return resultado;
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

bool excluirElemento(LISTA* l, int chave){
    int pos = buscaSequencial(*l, chave);
    if(pos == -1) return false;

    for(int i = pos; i < l->nroElementos-1; i++){
        l->lista[i] = l->lista[i+1];
    }

    l->nroElementos--;
    return true;
}

int main()
{
    LISTA l;
    REGISTRO elemento1;
    REGISTRO elemento2;
    REGISTRO elemento3;

    inicializarLista(&l);
    elemento1.chave = 200;
    elemento2.chave = 300;
    elemento3.chave = 400;
    inserirElemento(&l, elemento1, 0);
    exibirElementos(l);
    inserirElemento(&l, elemento2, 0);
    printf("\n");
    exibirElementos(l);
    excluirElemento(&l, 300);
    printf("\n");
    exibirElementos(l);
}
