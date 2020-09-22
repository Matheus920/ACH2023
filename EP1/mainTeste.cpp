// Matheus Moreira da Silva
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

void exibirLista(NO* lista);

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
        copia(&resp, p1);
        copia(&resp, p2);
    }

    return resp;
}

void copia(NO** listaBase, NO* listaACopiar)
{

    if(!(*listaBase))
    {
        inserirElemento(listaBase, listaACopiar->valor);
        listaACopiar = listaACopiar->prox;
    }

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

void exibirLista(NO* lista)
{
    while(lista)
    {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
}

void inserirElementoTeste(NO** lista, int valor)
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
        if(ant && aux->valor > valor)
        {
            NO* novoNo = (NO*) malloc(sizeof(NO));
            novoNo->valor = valor;
            ant->prox = novoNo;
            novoNo->prox = aux;
        }
        else
        {
            aux->prox = (NO*) malloc(sizeof(NO));
            aux->prox->valor = valor;
            aux->prox->prox = NULL;
        }
    }
}

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main()
{

    NO* p1 = NULL;
    NO* p2 = NULL;
    // aqui vc pode incluir codigo para inserir elementos
    // de teste nas listas p1 e p2
    inserirElementoTeste(&p1, 1);
    inserirElementoTeste(&p1, 2);
    inserirElementoTeste(&p1, 2);
    inserirElementoTeste(&p1, 6);
    inserirElementoTeste(&p1, 8);
    inserirElementoTeste(&p1, 9);

    inserirElementoTeste(&p2, 1);
    inserirElementoTeste(&p2, 2);
    inserirElementoTeste(&p2, 4);
    inserirElementoTeste(&p2, 5);
    inserirElementoTeste(&p2, 7);
    inserirElementoTeste(&p2, 7);

    printf("\nLista P1 - Antes: \n");

    exibirLista(p1);

    printf("\nLista P2 - Antes: \n");

    exibirLista(p2);

    // o EP sera testado com chamadas deste tipo
    NO* teste = NULL;

    teste = uniao(p1,p2);

    printf("\nLista P1: \n");

    exibirLista(p1);

    printf("\nLista P2: \n");

    exibirLista(p2);

    printf("\nResultado: \n");

    exibirLista(teste);

    NO* teste2 = uniao(p2, teste);

    printf("\nResultado: \n");

    exibirLista(teste2);

    return 0;

}

// por favor nao inclua nenhum código abaixo da função main()
