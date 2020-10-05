#include <stdio.h>
#define MAX 50

typedef struct {
    int chave;
} NO;

typedef struct {
    NO A[MAX];
    int topo;
} PILHA;

void inicializarPilha(PILHA* p){
    p->topo = -1;
}

int tamanho(PILHA* p){
    return p->topo + 1;
}

void exibirPilha(PILHA* p){
    for(int i = p->topo; i >= 0; i--){
        printf(" %i", p->A[i].chave);
    }
}

bool push(PILHA* p, NO elemento){
    if(p->topo == MAX-1) return false;

    p->topo = p->topo+1;
    p->A[p->topo] = elemento;

    return true;
}

bool pop(PILHA* p, NO* elemento){
    if(p->topo == -1) return false;

    *elemento = p->A[p->topo];
    p->topo = p->topo - 1;

    return true;
}

void reinicializarPilha(PILHA* p){
    p->topo = -1;
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

    NO elementoTeste;

    pop(&p, &elementoTeste);

    printf("\n %i\n", elementoTeste.chave);

    exibirPilha(&p);
}
