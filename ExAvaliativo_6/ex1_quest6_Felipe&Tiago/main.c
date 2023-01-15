#include<stdio.h>
#include<stdlib.h>

int SomaSerie(int i, int j, int k)
{
    int soma = 0;

    if(i < j)
    {
        soma = soma + SomaSerie(i + k, j, k);
    }
    else
    {
        soma = soma + j;
    }
    return soma;
}

int main()
{
    int i, j, k;

    printf("\nInforme o INICIO do intervalo: ");
    scanf("%d", &i);
     printf("\nInforme o FIM do intervalo: ");
    scanf("%d", &j);

    printf("\nInforme o INCREMENTO: ");
    scanf("%d", &k);

    printf("\nSoma = %d", SomaSerie(i, j, k));

    return 0;
}
