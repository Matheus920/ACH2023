#include <stdio.h>
#include <malloc.h>

typedef struct aux {
    aux* prox;
    aux* ant;
    int chave;
} NO;

typedef struct {
    NO* cabeca;
} DEQUE;

void inicializarDeque(DEQUE* d){
    d->cabeca = (NO*) malloc(sizeof(NO));
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

int tamanho(DEQUE* d){
    NO* atual = d->cabeca->prox;

    int tamanho = 0;

    while(atual != d->cabeca){
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}

void exibirDequeFim(DEQUE* d){
    NO* atual = d->cabeca->ant;

    while(atual != d->cabeca){
        printf("%i ", atual->chave);
        atual = atual->ant;
    }
}

bool inserirDequeFim(DEQUE* d, NO no){
    NO* novo = (NO*) malloc(sizeof(NO));
    *novo = no;

    novo->prox = d->cabeca;
    novo->ant = d->cabeca->ant;
    d->cabeca->ant = novo;
    novo->ant->prox = novo;
    return true;
}

bool excluirElementoDequeInicio(DEQUE* d, NO* no){
    if(d->cabeca->prox == d->cabeca) return false;

    NO* apagar = d->cabeca->prox;

    no->chave = apagar->chave;

    d->cabeca->prox = apagar->prox;
    d->cabeca->prox->ant = d->cabeca;
    free(apagar);

    return true;
}

void reinicializarDeque(DEQUE* d){
    NO* atual = d->cabeca->prox;

    while(atual != d->cabeca){
        NO* apagar = atual;
        free(apagar);
        atual = atual->prox;
    }

    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

int main(){
    DEQUE d;
    NO elemento1;
    NO elemento2;
    NO elemento3;

    elemento1.chave = 20;
    elemento2.chave = 30;
    elemento3.chave = 40;

    inicializarDeque(&d);

    inserirDequeFim(&d, elemento1);
    inserirDequeFim(&d, elemento2);
    inserirDequeFim(&d, elemento3);

    exibirDequeFim(&d);

    NO elementoTeste;

    excluirElementoDequeInicio(&d, &elementoTeste);

    printf("\n%i", elementoTeste.chave);

    printf("\n");

    exibirDequeFim(&d);

}
