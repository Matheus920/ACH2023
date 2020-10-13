#include <stdio.h>
#define MAX 50

typedef struct {
    int chave;
} NO;

typedef struct {
    NO A[MAX];
    int nroElementos;
    int inicio;
} FILA;

void inicializarFila(FILA* f){
    f->inicio = 0;
    f->nroElementos = 0;
}

int tamanhoFila(FILA* f){
    return f->nroElementos;
}

void exibirFila(FILA* f){
    int i = f->inicio;

    for(int j = 0; j < f->nroElementos; j++){
        printf(" %i", f->A[i].chave);
        i = (i + 1) % MAX;
    }
}

bool inserirElemento(FILA* f, NO elemento){
    if(f->nroElementos == MAX) return false;

    int posicao = (f->inicio + f->nroElementos) % MAX;

    f->A[posicao] = elemento;

    f->nroElementos++;

    return true;
}

bool excluirElemento(FILA* f, NO* elemento){
    if(f->nroElementos == 0) return false;

    *elemento = f->A[f->inicio];

    f->inicio = (f->inicio + 1) % MAX;

    f->nroElementos = f->nroElementos - 1;

    return true;

}

void reinicializarFila(FILA* f){
    inicializarFila(f);
}

int main() {
    FILA f;
    NO elemento1;
    NO elemento2;
    NO elemento3;

    elemento1.chave = 20;
    elemento2.chave = 30;
    elemento3.chave = 40;

    inicializarFila(&f);

    inserirElemento(&f, elemento1);
    inserirElemento(&f, elemento2);
    inserirElemento(&f, elemento3);

    exibirFila(&f);

    NO elementoTeste;

    excluirElemento(&f, &elementoTeste);

    printf("\n%i", elementoTeste.chave);

    printf("\n");

    exibirFila(&f);
}
