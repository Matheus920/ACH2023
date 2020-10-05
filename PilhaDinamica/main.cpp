#include <stdio.h>
#include <malloc.h>

typedef struct aux {
    int chave;
    aux* prox;
} NO;

typedef struct {
    NO* topo;
} PILHA;

void inicializarPilha(PILHA* p){
    p->topo = NULL;
}

int tamanho(PILHA* p){
    NO* atual = p->topo;
    int tamanho = 0;

    while(atual){
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}

void exibirPilha(PILHA* p){
    NO* atual = p->topo;

    while(atual){
        printf(" %i", atual->chave);
        atual = atual->prox;
    }
}

bool push(PILHA* p, NO elemento){
    NO* novo = (NO*) malloc(sizeof(NO));
    *novo = elemento;
    novo->prox = p->topo;
    p->topo = novo;

    return true;
}

bool pop(PILHA* p, NO* elemento){
    if(!p->topo) return false;

    *elemento = *(p->topo);
    NO* apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);

    return true;
}

void reinicializarPilha(PILHA* p){
    NO* atual = p->topo;
    NO* auxiliar;

    while(atual){
        auxiliar = atual;
        atual = atual->prox;
        free(auxiliar);
    }

    p->topo = NULL;
}

int main(){
    PILHA p;

    inicializarPilha(&p);

    NO elemento1;
    NO elemento2;
    NO elemento3;

    elemento1.chave = 10;
    elemento2.chave = 20;
    elemento3.chave = 30;

    push(&p, elemento1);
    push(&p, elemento2);
    push(&p, elemento3);

    exibirPilha(&p);

    NO teste;

    pop(&p, &teste);

    printf("\n %i\n", teste.chave);

    exibirPilha(&p);

}
