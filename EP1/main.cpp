// Matheus Moreira da Silva
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP()
{
    return("11796490");
}


// ######### ESCREVA SEU NOME AQUI
char* nome()
{
    return("Matheus Moreira da Silva");
}

// elemento da lista
typedef struct estr
{
    int valor;
    struct estr* prox;
} NO;


// funcao principal
NO* uniao(NO* p1, NO* p2);

void copia(NO** listaBase, NO* listaACopiar);

void inserirElemento(NO** lista, int valor);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* uniao(NO* p1, NO* p2)
{

    NO* resp;
    resp = NULL;

    if(!p1 && !p2) return resp;

    else if(!p1) copia(&resp, p2);
    else if(!p2) copia(&resp, p1);
    else
    {
        if(p1->valor >= p2->valor){
            copia(&resp, p2);
            copia(&resp, p1);
        } else {
            copia(&resp, p1);
            copia(&resp, p2);
        }
    }

    return resp;
}

void copia(NO** listaBase, NO* listaACopiar)
{
    while(listaACopiar)
    {
        inserirElemento(listaBase, listaACopiar->valor);
        listaACopiar = listaACopiar->prox;
    }

}

void inserirElemento(NO** lista, int valor)
{
    if(!(*lista))
    {
        *lista = (NO*) malloc(sizeof(NO));
        (*lista)->valor = valor;
        (*lista)->prox = NULL;
    }
    else
    {
        NO* aux = *lista;
        NO* ant = NULL;
        while(aux->prox && aux->valor < valor)
        {
            ant = aux;
            aux = aux->prox;
        }
        if(aux->valor != valor)
        {
            if(ant && aux->valor > valor)
            {
                ant->prox = (NO*) malloc(sizeof(NO));
                ant->prox->valor = valor;
                ant->prox->prox = aux;
            }
            else
            {
                aux->prox = (NO*) malloc(sizeof(NO));
                aux->prox->valor = valor;
                aux->prox->prox = NULL;
            }
        }
    }
}


// por favor nao inclua nenhum código abaixo da função main()
