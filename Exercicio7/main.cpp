#include <stdio.h>
#include <malloc.h>

typedef struct aux {
    aux* prox;
    aux* ant;
    int chave;
} NO;

typedef struct {
    NO* cabeca;
} LISTA;

void inicializarLista(LISTA* l){
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;
    l->cabeca->ant = l->cabeca;
}

// Vou imaginar que você quis dizer void no enunciado, já que não vejo sentido em retornar um NO* aqui
void exibirInvertida(LISTA* l){
    NO* atual = l->cabeca->ant;

    while(atual != l->cabeca){
        printf("%i ", atual->chave);
        atual = atual->ant;
    }
}

void inserirAntes(LISTA* l, int ch, NO* atual){
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;

    novo->prox = atual;
    novo->ant = atual->ant;
    atual->ant->prox = novo;
    atual->ant = novo;
}

int main(){
    LISTA l;

    inicializarLista(&l);

    NO* elemento1 = (NO*) malloc(sizeof(NO));
    elemento1->chave = 10;

    l.cabeca->prox = elemento1;
    l.cabeca->ant = elemento1;
    elemento1->ant = l.cabeca;

    exibirInvertida(&l);

    inserirAntes(&l, 20, elemento1);

    printf("\n");

    exibirInvertida(&l);
}
