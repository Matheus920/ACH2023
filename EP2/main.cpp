#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796490");
}


// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Matheus Moreira da Silva");
}

// elemento da pilha
typedef struct estrutura {
	struct estrutura *prox;
       	int tipo; // 1=operador e 2=float e 3=parenteses
       	union {
              	char simbolo;
              	float valor;
       	};
} NO;




// funcao principal (retorna float e int)
float calcular(char* expressao, int* codigo);
NO* push(NO* topo, NO insercao);
NO* pop(NO** topo);
void anexar(NO** elemento, NO anexo);
bool verificaPrecedencia(char operador1, char operador2);
NO* converterExpressao(char* expressao, int* codigo);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
float calcular(char* expressao, int* codigo){

	float resp = 0.0;
	*codigo = 1;

	NO* saida = converterExpressao(expressao, codigo);

	if(*codigo == -1){
        return resp;
	}

	NO* pilha = NULL;

	while(saida){
        if(saida->tipo == 2){
            if(!pilha){
                pilha = (NO*) malloc(sizeof(NO));
                pilha->tipo = 2;
                pilha->valor = saida->valor;
                pilha->prox = NULL;
            } else {
                NO* novo = (NO*) malloc(sizeof(NO));
                novo->tipo = 2;
                novo->valor = saida->valor;
                novo->prox = NULL;
                pilha = push(pilha, *novo);
            }
        } else if(saida->tipo == 1){
            float resultado = 0;

            if(!pilha){
                *codigo = -1;
                return resp;
            }

            NO* valor1 = pop(&pilha);

            if(!valor1 || valor1->tipo != 2){
                *codigo = -1;
                return resp;
            }

            if(!pilha){
                *codigo = -1;
                return resp;
            }

            NO* valor2 = pop(&pilha);

            if(!valor2 || valor2->tipo != 2){
                *codigo = -1;
                return resp;
            }

            float numero1 = valor1->valor;
            float numero2 = valor2->valor;

            switch(saida->simbolo){
                case '+': {
                    resultado = numero2 + numero1;
                    break;
                }
                case '-': {
                    resultado = numero2 - numero1;
                    break;
                }
                case '/': {
                    if(numero1 == 0){
                        *codigo = 0;
                        return resp;
                    }
                    resultado = numero2 / numero1;
                    break;
                }
                case '*': {
                    resultado = numero2 * numero1;
                    break;
                }
            }
            NO* novo = (NO*) malloc(sizeof(NO));
            novo->tipo = 2;
            novo->valor = resultado;
            novo->prox = NULL;
            pilha = push(pilha, *novo);
        }
        saida = saida->prox;
	}

	if(!pilha || pilha->prox){
        *codigo = -1;
        return resp;
    }

	resp = pilha->valor;

	return resp;
}

NO* converterExpressao(char* expressao, int* codigo){
    NO* saida = NULL;

    NO* pilhaTemporaria = NULL;

    int tamanhoExpressao = strlen(expressao);

    int numeroAbreParenteses = 0;
    int numeroFechaParenteses = 0;
    int numeroOperandos = 0;

    for(int i = 0; i < tamanhoExpressao; i++){
       if(expressao[i] >= '0' && expressao[i] <= '9'){
            if(!saida){
                saida = (NO*) malloc(sizeof(NO));
                saida->tipo = 2;
                saida->valor = expressao[i] - 48;
                saida->prox = NULL;
            } else {
                NO* novo = (NO*) malloc(sizeof(NO));
                novo->tipo = 2;
                novo->valor = expressao[i] - 48;
                novo->prox = NULL;
                anexar(&saida, *novo);
            }
        } else if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/') {
            numeroOperandos++;
            if(!pilhaTemporaria){
                pilhaTemporaria = (NO*) malloc(sizeof(NO));
                pilhaTemporaria->tipo = 1;
                pilhaTemporaria->simbolo = expressao[i];
                pilhaTemporaria->prox = NULL;
            } else {
                NO* aux = pilhaTemporaria;
                while(aux && aux->tipo==1){
                    if(verificaPrecedencia(expressao[i], aux->simbolo)){
                        NO* temp = pop(&pilhaTemporaria);
                        anexar(&saida, *temp);
                    }
                    aux = aux->prox;
                }

                NO* novo = (NO*) malloc(sizeof(NO));
                novo->tipo = 1;
                novo->simbolo = expressao[i];
                novo->prox = NULL;
                pilhaTemporaria = push(pilhaTemporaria, *novo);
            }
        }
        else if(expressao[i] == '('){
            numeroAbreParenteses++;
            if(!pilhaTemporaria){
                pilhaTemporaria = (NO*) malloc(sizeof(NO));
                pilhaTemporaria->tipo = 3;
                pilhaTemporaria->simbolo = expressao[i];
                pilhaTemporaria->prox = NULL;
            }
            else {
                NO* novo = (NO*) malloc(sizeof(NO));
                novo->tipo = 3;
                novo->simbolo = expressao[i];
                novo->prox = NULL;
                pilhaTemporaria = push(pilhaTemporaria, *novo);
            }
        } else if(expressao[i] == ')'){
            numeroFechaParenteses++;
            NO* aux = pilhaTemporaria;
            while(aux){
                if(aux->tipo == 1){
                    aux = aux->prox;
                    NO* temp = pop(&pilhaTemporaria);
                    anexar(&saida, *temp);
                } else if(aux->tipo == 3 && aux->simbolo == '('){
                    aux = aux->prox;
                    pop(&pilhaTemporaria);
                    break;
                }
            }
        }
	}

	while(pilhaTemporaria){
        NO* temp = pop(&pilhaTemporaria);
        anexar(&saida, *temp);
	}

    if(numeroAbreParenteses != numeroFechaParenteses || numeroAbreParenteses != numeroOperandos){
        *codigo = -1;
    }

	return saida;
}

NO* push(NO* topo, NO insercao){
    NO* novo = (NO*) malloc(sizeof(NO));
    *novo = insercao;
    novo->prox = topo;

    return novo;
}

NO* pop(NO** topo){
    NO* auxiliar = *topo;
    NO* copia = (NO*) malloc(sizeof(NO));

    *copia = *auxiliar;

    *topo = auxiliar->prox;

    free(auxiliar);

    copia->prox = NULL;

    return copia;
}

void anexar(NO** elemento, NO anexo){
    NO* aux = *elemento;

    while(aux->prox){
        aux = aux->prox;
    }

    NO* novo = (NO*) malloc(sizeof(NO));
    *novo = anexo;
    novo->prox = NULL;

    aux->prox = novo;
}

bool verificaPrecedencia(char operador1, char operador2){
    if(operador1 == '+' || operador1 == '-'){
        if(operador2 == '/' || operador2 == '*') return true;
        else return false;
    }

    if(operador1 == '/' || operador1 == '*') return false;
}


//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {


	// o EP sera testado com chamadas deste tipo

	char exp[200];
	strcpy(exp, "(1/3)");

	int codigo;

	float resp = calcular(exp,&codigo);

	printf("Resposta eh: %0.2f\nO codigo eh: %i", resp, codigo);


}

// por favor nao inclua nenhum código abaixo da função main()
