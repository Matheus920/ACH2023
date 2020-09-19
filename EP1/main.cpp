#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11796490");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Matheus Moreira da Silva");
}

// elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;


// funcao principal
NO* uniao(NO* p1, NO* p2);

void copia(NO* listaBase, NO* listaACopiar);

void inserirElemento(NO* lista, int valor);

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* uniao(NO* p1, NO* p2) {

	NO* resp;
	resp = NULL;

	if(!p1 && !p2) return resp;

	else if(!p1) copia(resp, p2);
	else if(!p2) copia(resp, p1);
	else {
        copia(resp, p1);
        copia(resp, p2);
	}

	return resp;
}

void copia(NO* listaBase, NO* listaACopiar) {

    if(!listaBase){
            inserirElemento(listaBase, listaACopiar->valor);
            listaACopiar = listaACopiar->prox;
    }

    while(listaACopiar){
        while(listaBase && listaBase->valor > listaACopiar->valor){
            listaBase = listaBase->prox;
        }

        if(listaBase->valor != listaACopiar->valor){
            inserirElemento(listaBase, listaACopiar->valor);
        }

        listaACopiar = listaACopiar->prox;
    }

}

void inserirElemento(NO* lista, int valor){

    if(!lista){
        lista = (NO*) malloc(sizeof(NO*));
        lista->valor = valor;
        lista->prox = NULL;
    } else {
        while(lista->prox){
            lista = lista->prox;
        }
        lista->prox = (NO*) malloc(sizeof(NO*));
        lista->prox->valor = valor;
        lista->prox->prox = NULL;
    }
}

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

	NO* p1 = null;
	NO* p2 = null;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste nas listas p1 e p2
    inserirElemento(p1, 1);
    inserirElemento(p1, 2);
    inserirElemento(p1, 2);
    inserirElemento(p1, 3);

	// o EP sera testado com chamadas deste tipo
	NO* teste = null;

	teste = uniao(p1,p2);


	printf("Lista P1: ");

	while(p1){
        printf("%d", &p1->valor);
        p1 = p1->prox;
	}


	printf("\nLista P2: ");

	while(p2){
        printf("%d", &p2->valor);
        p2 = p2->prox;
	}

	printf("\n Resultado: ");

	while(teste){
        printf("%d", &teste->valor);
        teste = teste->prox;
	}

}

// por favor nao inclua nenhum código abaixo da função main()
