#include <malloc.h>
#include <stdio.h>

typedef struct estrutura {
    int chave;
    struct estrutura* prox;
} NO;

typedef struct {
    NO* inicio;
} LISTA;

void inicializarLista(LISTA* l){
    l->inicio = NULL;
}

int tamanho(LISTA* l){
    NO* endereco = l->inicio;
    int tamanho = 0;

    while(endereco){
        tamanho++;
        endereco = endereco->prox;
    }

    return tamanho;
}

void exibirLista(LISTA*l ){
    NO* endereco = l->inicio;

    while(endereco){
        printf("%d ", endereco->chave);
        endereco = endereco->prox;
    }
}

NO* buscaSequencial(LISTA* l, int chave){
    NO* endereco = l->inicio;

    while(endereco){
        if(endereco->chave == chave) return endereco;
        endereco = endereco->prox;
    }

    return NULL;
}

NO* buscaSequencialOrdenada(LISTA* l, int chave){
    NO* endereco = l->inicio;

    while(endereco && endereco->chave < chave) endereco = endereco->prox;
    if(endereco && endereco->chave == chave) return endereco;

    return NULL;
}

NO* buscaSequencialAnterior(LISTA* l, int chave, NO** ant){
    *ant = NULL;
    NO* endereco = l->inicio;

    while(endereco && endereco->chave < chave){
        *ant = endereco;
        endereco = endereco->prox;
    }

    if(endereco && endereco->chave == chave) return endereco;

    return NULL;
}

bool inserirElementoListaOrdenada(LISTA*l, NO no){
    int chave = no.chave;

    NO* ant;
    NO* i;

    i = buscaSequencialAnterior(l, chave, &ant);

    //if(i) return false;

    i = (NO*) malloc(sizeof(NO));

    i->chave = chave;

    if(!ant){
        i->prox = l->inicio;
        l->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }
}

bool excluirElementoListaOrdenada(LISTA* l, int chave){
    NO* ant;
    NO* i;

    i = buscaSequencialAnterior(l, chave, &ant);

    if(!i) return false;

    if(!ant) l->inicio = i->prox;
    else ant->prox = i->prox;

    free(i);
}

void reinicializarLista(LISTA* l){
    NO* elemento = l->inicio;

    while(elemento){
        NO* auxiliar = elemento;
        elemento = elemento->prox;
        free(auxiliar);
    }

    l->inicio = NULL;
}

void ExcluirOcorrencias(LISTA* l, int x){
    NO* elemento = l->inicio;
    NO* ant = NULL;

    while(elemento){
        NO* auxiliar = elemento;

        if(elemento->chave == x){
            if(!ant) l->inicio = elemento->prox;
            else ant->prox = elemento->prox;

            elemento = elemento->prox;

            free(auxiliar);
        } else {
            ant = elemento;
            elemento = elemento->prox;
        }
    }
}

NO* copia(NO* p){
    NO* inicio;
    inicio = NULL;

    if(!p) return inicio;

    NO* aux;
    aux = NULL;

    while(p){
        if(!inicio){
            inicio = (NO*) malloc(sizeof(NO));
            inicio->chave = p->chave;
            aux = inicio;
        }else {
            aux->prox = (NO*) malloc(sizeof(NO));
            aux = aux->prox;
            aux->chave = p->chave;
        }
        p = p->prox;
    }

    return inicio;
}

int main() {
    LISTA l;
    NO elemento1;
    NO elemento2;
    NO elemento3;
    NO elemento4;

    elemento1.chave = 20;
    elemento2.chave = 10;
    elemento3.chave = 10;
    elemento4.chave = 30;

    inicializarLista(&l);

    inserirElementoListaOrdenada(&l, elemento2);
    inserirElementoListaOrdenada(&l, elemento1);
    inserirElementoListaOrdenada(&l, elemento3);
    inserirElementoListaOrdenada(&l, elemento4);

    NO* teste = copia(l.inicio);

    while(teste){
        printf("%i \n", teste->chave);
        teste = teste->prox;
    }

    ExcluirOcorrencias(&l, 10);

    exibirLista(&l);

}
