#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int topo;
    char palavra[20];
} Pilha;

Pilha pilha; //porque tem que declarar aqui tbm?

void empilha(char palavra)  //empilhar string
{
    pilha.palavra[pilha.topo] = palavra;
    pilha.topo++;
}

int desempilha()  //desempilhar para comparar
{
    pilha.topo--;
    return(pilha.palavra[pilha.topo]);

}

void definicao()  //definicao
{
    printf("\nDefinicao: Palíndromo é uma frase ou palavra que se pode ler, indiferentemente, da esquerda para direita ou vice-versa.\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha pilha; //tive que declarar Pilha pilha; na main tbm. porque?

    char string[20];

    definicao();

    printf("\nDigite uma palavra(ate 20 caracteres): ");
    //fgets(string, 19, stdin); porque o fgets nao da certo?
    scanf("%s", string);

    pilha.topo = -1; //iniciar a pilha pegando todos os valores

    for (int i = 0; i < strlen(string); i++)
    {
        empilha(string[i]);
    }

    char *resultado = "\nA palavra é um Palíndromo."; //guarda info pra nao printar mais vezes

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] != desempilha())
        {
            resultado = "\nA palavra não é um Palíndromo.";
        }
    }

    printf("%s\n", resultado);

    return 0;
}
