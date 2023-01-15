#include <stdio.h>
#include <stdlib.h>

void ImprimeVetor(int vetor[], int tamanho)
{
    if(tamanho == 1)
    {
        printf("%d ", vetor[tamanho - 1]);
    }
    else
    {
        ImprimeVetor(vetor, tamanho - 1);
        printf("%d ", vetor[tamanho - 1]);
    }
}

void InverteVetor(int vetor[], int inicio, int fim)
{
    int aux;

    if(inicio  < fim)
    {
        aux = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = aux;
        InverteVetor(vetor, inicio + 1, fim - 1);
    }
}

int main()
{
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ImprimeVetor(vet, 10);
    printf("\n");
    InverteVetor(vet, 0, 9); //troca indice do começo e fim
    ImprimeVetor(vet, 10);
    return 0;
}
