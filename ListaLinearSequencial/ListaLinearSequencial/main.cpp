#include <stdio.h>

#define MAX 50

typedef struct {
    int chave;
} REGISTRO;

typedef struct {
    REGISTRO lista[MAX+1];
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

int buscaComSentinela(LISTA l, int chave){

    l.lista[l.nroElementos].chave = chave;

    int i = 0;

    while(l.lista[i].chave != chave) i++;

    if(i != l.nroElementos) return i;

    return -1;
}

int buscaBinaria(LISTA l, int chave){
    int esq, meio, dir;

    esq = 0;
    dir = l.nroElementos - 1;

    while(esq<=dir){

        meio = (esq+dir) / 2;
        if(l.lista[meio].chave == chave) return meio;
        else {
            if(l.lista[meio].chave > chave) dir = meio - 1;
            else esq = meio + 1;
        }
    }

    return -1;
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

bool inserirElementoOrdenado(LISTA* l, REGISTRO elemento){
    if(l->nroElementos >= MAX) return false;

    int pos = l->nroElementos;

    while(pos > 0 && l->lista[pos-1].chave > elemento.chave){
        l->lista[pos] = l->lista[pos-1];
        pos--;
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

    inserirElementoOrdenado(&l, elemento3);
    inserirElementoOrdenado(&l, elemento1);
    inserirElementoOrdenado(&l, elemento2);

    exibirElementos(l);

    printf("\n%i", buscaBinaria(l, 300));
    printf("\n%i", buscaComSentinela(l, 400));

}
