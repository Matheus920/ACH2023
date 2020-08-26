#include <stdio.h>

int verificarOrdem(int vetor[], int N)
{
    int resultado;
    int crescente = 0;
    int decrescente = 0;
    int igual = 0;

    for(int i = 0; i < N-1; i++)
    {
        if(vetor[i] < vetor[i+1])
        {
            crescente++;
        }
        else if(vetor[i] > vetor[i+1])
        {
            decrescente++;
        }
        else if(vetor[i] == vetor[i+1])
        {
            igual++;
        }
    }

    if(igual == (N-1))
    {
        resultado = 0;
    }
    else if((crescente+igual) == (N-1))
    {
        resultado = 1;
    }
    else if((decrescente+igual) == (N-1))
    {
        resultado = -1;
    }
    else
    {
        resultado = 99;
    }

    return resultado;

}

int main()
{
    int vetor[] = {0};
    printf("Resultado: %i", verificarOrdem(vetor, 1));
}
