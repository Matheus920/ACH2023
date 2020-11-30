#include <stdio.h>
#include <malloc.h>

typedef struct estrutura {
    int chave;
    estrutura* esq;
    estrutura* dir;
} NO;

void exibirFolhas(NO* p){
    if(p){
        exibirFolhas(p->esq);
        if(!p->dir && !p->esq){
            printf("%i ", p->chave);
        }
        exibirFolhas(p->dir);
    }
}

bool exibeAncestrais(NO* p, int chave){
    if(!p) return false;

    if(p->chave == chave) return true;

    if(exibeAncestrais(p->esq, chave) || exibeAncestrais(p->dir, chave)){
        printf("%i ", p->chave);
        return true;
    }

    return false;
}

int main(){
    NO* raiz = (NO*) malloc(sizeof(NO));
    raiz->chave = 5;
    raiz->esq = NULL;
    raiz->dir = NULL;

    NO* direito = (NO*) malloc(sizeof(NO));
    direito->chave = 10;
    direito->esq = NULL;
    direito->dir = NULL;

    raiz->dir = direito;

    NO* esquerdo = (NO*) malloc(sizeof(NO));
    esquerdo->chave = 2;
    esquerdo->esq = NULL;
    esquerdo->dir = NULL;

    NO* esquerdoFilho = (NO*) malloc(sizeof(NO));
    esquerdoFilho->chave = 20;
    esquerdoFilho->esq = NULL;
    esquerdoFilho->dir = NULL;

    esquerdo->esq = esquerdoFilho;

    raiz->esq = esquerdo;

    printf("Altura: %i", (altura(esquerdoFilho)));
    printf("Menor chave: %i", menorChave(raiz));
}
