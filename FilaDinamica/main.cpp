#include <stdio.h>
#include <malloc.h>

typedef struct aux {
    aux* prox;
    int chave;
} NO;

typedef struct {
    NO* inicio;
    NO* fim;
} FILA;

void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanhoFila(FILA* f){
    NO* atual = f->inicio;
    int tamanho = 0;

    while(atual){
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}

void exibirFila(FILA* f){
    NO* atual = f->inicio;

    while(atual){
        printf("%i ", atual->chave);
        atual = atual->prox;
    }
}

bool inserirElemento(FILA* f, NO elemento){
    NO* novo = (NO*) malloc(sizeof(NO));

    novo->chave = elemento.chave;

    novo->prox = NULL;

    if(!f->inicio) f->inicio = novo;
    else f->fim->prox = novo;

    f->fim = novo;

    return true;

}

bool excluirElemento (FILA* f, NO* elemento){
    if(!f->inicio) return false;

    elemento->chave = f->inicio->chave;

    NO* apagar = f->inicio;

    f->inicio = f->inicio->prox;

    free(apagar);

    if(!f->inicio) f->fim = NULL;

    return true;
}

void reinicializarFila(FILA* f){
    NO* atual = f->fim;

    while(atual){
        NO* apagar = atual;
        free(apagar);
        atual = atual->prox;
    }

    f->fim = NULL;
    f->inicio = NULL;
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
