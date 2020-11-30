#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <climits>



// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796490");
}


// no da arvore
typedef struct estr {
        int chave;
        struct estr *esq;
        struct estr *dir;
} NO;

typedef struct aux {
    int chave;
    int nivel;
    aux* prox;
} NOLISTA;


void organizar(NO* *raiz);
int verificaArvoreBinaria(NO* raiz);
NO* deletar(NO* raiz, int chave);
NO* menorValor(NO* raiz);
int percorreEmOrdem(NO* raiz, NOLISTA** lista);
bool verificaOrdenacao(NOLISTA* lista);
int nivelDoNo(int chave, NO* raiz, int nivel);
int menorValorNivel(NOLISTA* lista);

void print2DUtil(NO* raiz, int space)
{
    // Base case
    if (raiz == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(raiz->dir, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", raiz->chave);

    // Process left child
    print2DUtil(raiz->esq, space);
}


//------------------------------------------
// O EP consiste em implementar esta funcao
//------------------------------------------
void organizar(NO** raiz) {

    NO* p = *raiz;

    int chaveADeletar = verificaArvoreBinaria(p);

    if(chaveADeletar != -1){
        *raiz = deletar(*raiz, chaveADeletar);
    }
}


NO* deletar(NO* raiz, int chave){
    if(!raiz) return raiz;

    if(raiz->chave != chave){
        raiz->dir = deletar(raiz->dir, chave);
        raiz->esq = deletar(raiz->esq, chave);
    } else {
        if(!raiz->esq){
            NO* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if(!raiz->dir){
            NO* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        NO* temp = menorValor(raiz->dir);
        raiz->chave = temp->chave;
        raiz->dir = deletar(raiz->dir, temp->chave);
    }
    return raiz;
}

NO* menorValor(NO* raiz){
    NO* atual = raiz;

    while(atual && atual->esq){
        atual = atual->esq;
    }

    return atual;
}

int verificaArvoreBinaria(NO* raiz){
    NOLISTA* lista = NULL;
    percorreEmOrdem(raiz, &lista);
    bool estaOrdenada = verificaOrdenacao(lista);
    if(estaOrdenada) return -1;
    else {
        NOLISTA* erros = NULL;
        NOLISTA* aux = lista;
        while(aux){
            NOLISTA* aux2 = lista;
            NOLISTA* copia = NULL;
            while(aux2){
                if(aux2->chave != aux->chave){
                    if(!copia){
                        copia = (NOLISTA*) malloc(sizeof(NOLISTA));
                        copia->chave = aux2->chave;
                        copia->prox = NULL;
                    }else {
                        NOLISTA* aux3 = copia;
                        while(aux3->prox){
                            aux3 = aux3->prox;
                        }
                        NOLISTA* novo = (NOLISTA*) malloc(sizeof(NOLISTA));
                        novo->chave = aux2->chave;
                        novo->prox = NULL;
                        aux3->prox = novo;
                    }
                }
                aux2 = aux2->prox;
            }
            NOLISTA* temp = copia;
            bool estaCorrigida = verificaOrdenacao(copia);
            if(estaCorrigida){
                if(!erros){
                    erros = (NOLISTA*) malloc(sizeof(NOLISTA));
                    erros->chave = aux->chave;
                    erros->nivel = 0;
                    erros->prox = NULL;
                } else {
                    NOLISTA* auxErros = erros;
                    while(auxErros->prox){
                        auxErros = auxErros->prox;
                    }
                    NOLISTA* novo = (NOLISTA*) malloc(sizeof(NOLISTA));
                    novo->chave = aux->chave;
                    novo->nivel = 0;
                    novo->prox = NULL;
                    auxErros->prox = novo;
                }
            }
            aux = aux->prox;
        }
        if(erros->prox){
            NOLISTA* errosNivel = erros;
            while(errosNivel){
                errosNivel->nivel = nivelDoNo(errosNivel->chave, raiz, 1);
                errosNivel = errosNivel->prox;
            }
            return menorValorNivel(erros);
        }
        else return erros->chave;
    }
}

int percorreEmOrdem(NO* raiz, NOLISTA** lista){
    if(raiz){
        percorreEmOrdem(raiz->esq, lista);
        if(!(*lista)){
            *lista = (NOLISTA*) malloc(sizeof(NOLISTA));
            (*lista)->chave = raiz->chave;
            (*lista)->prox = NULL;
        } else {
            NOLISTA* aux = *lista;
            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = (NOLISTA*) malloc(sizeof(NOLISTA));
            aux->prox->chave = raiz->chave;
            aux->prox->prox = NULL;
        }
        percorreEmOrdem(raiz->dir, lista);
    }
}

bool verificaOrdenacao(NOLISTA* lista){
    if(!lista || !lista->prox) return true;

    return(lista->chave < lista->prox->chave && verificaOrdenacao(lista->prox));
}

int nivelDoNo(int chave, NO* raiz, int nivel){
    if(!raiz) return 0;

    if(raiz->chave == chave) return nivel;

    int nivelBaixo = nivelDoNo(chave, raiz->esq, nivel+1);

    if(nivelBaixo != 0) return nivelBaixo;

    nivelBaixo = nivelDoNo(chave, raiz->dir, nivel+1);

    return nivelBaixo;
}

int menorValorNivel(NOLISTA *lista){
    int minimo = INT_MAX;
    int chave = 0;

    while(lista){
        if(lista->nivel <= minimo){
            minimo = lista->nivel;
            chave = lista->chave;
        }
        lista = lista->prox;
    }
    return chave;
}


//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {

	NO* arv = NULL;
    arv = (NO*) malloc(sizeof(NO));
    arv->chave = 7;
    NO* dir = (NO*) malloc(sizeof(NO));
    dir->chave = 11;
    dir->esq = NULL;
    dir->dir = NULL;

    NO* dirFilho = (NO*) malloc(sizeof(NO));
    dirFilho->chave = 13;
    dirFilho->esq = NULL;
    dirFilho->dir = NULL;

    NO* dirEsqFilho = (NO*) malloc(sizeof(NO));
    dirEsqFilho->chave = 10;
    dirEsqFilho->esq = NULL;
    dirEsqFilho->dir = NULL;

    dir->esq = dirEsqFilho;

    dir->dir = dirFilho;

    NO* esq = (NO*) malloc(sizeof(NO));
    esq->chave = 2;
    esq->esq = NULL;
    esq->dir = NULL;

    NO* esqDirFilho = (NO*) malloc(sizeof(NO));
    esqDirFilho->chave = 4;
    esqDirFilho->esq = NULL;
    esqDirFilho->dir = NULL;


    NO* esqEsqFilho = (NO*) malloc(sizeof(NO));
    esqEsqFilho->chave = 3;
    esqEsqFilho->esq = NULL;
    esqEsqFilho->dir = NULL;

    esq->esq = esqEsqFilho;
    esq->dir = esqDirFilho;

    arv->dir = dir;
    arv->esq = esq;

    print2DUtil(arv, 0);
    printf("\n\n APÓS DELEÇÃO");
	// serao realizadas chamadas como esta:
	organizar(&arv);
	print2DUtil(arv, 0);

}

// por favor nao inclua nenhum código abaixo da função main()
