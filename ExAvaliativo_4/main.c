#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VALOR_HORA 8.00

typedef struct veiculo
{
    char nomeMotorista[50];
    char placa[8];
    int horaEntrada;
    int horaSaida;
    int vaga;
    float valorTotal;
    struct veiculo *proximo;
    struct veiculo *anterior;
} Veiculo;

Veiculo* criarVeiculo(char *nomeMotorista, char *placa, int horaEntrada, int vaga)
{
    Veiculo *veiculo = malloc(sizeof(Veiculo));
    strcpy(veiculo->nomeMotorista, nomeMotorista);
    strcpy(veiculo->placa, placa);
    veiculo->horaEntrada = horaEntrada;
    veiculo->vaga = vaga;
    veiculo->valorTotal = 0.00;
    veiculo->proximo = NULL;
    veiculo->anterior = NULL;
    return veiculo;
}

Veiculo* inserirVeiculo(Veiculo *topo, Veiculo *veiculo)
{
    if (topo == NULL || strcmp(topo->nomeMotorista, veiculo->nomeMotorista) > 0)
    {
        veiculo->proximo = topo;
        veiculo->anterior = NULL;
        if (topo != NULL)
        {
            topo->anterior = veiculo;
        }
        return veiculo;
    }
    Veiculo *atual = topo;
    while (atual->proximo != NULL && strcmp(atual->proximo->nomeMotorista, veiculo->nomeMotorista) < 0)
    {
        atual = atual->proximo;
    }
    veiculo->proximo = atual->proximo;
    if (atual->proximo != NULL)
    {
        atual->proximo->anterior = veiculo;
    }
    atual->proximo = veiculo;
    veiculo->anterior = atual;
    return topo;
}

Veiculo* calcularValor(Veiculo *topo, float *valorTotal)
{
    Veiculo *atual = topo;
    while (atual != NULL)
    {
        printf("Digite a hora de saida do veiculo %s: ", atual->placa);
        scanf("%d", &atual->horaSaida);
        int horasEstacionado = (atual->horaSaida - atual->horaEntrada);
        atual->valorTotal = horasEstacionado * VALOR_HORA;
        *valorTotal += atual->valorTotal;
        atual = atual->proximo;
    }
    return topo;
}

Veiculo* removerVeiculo(Veiculo *topo, char *placa, float *valorTotal)
{
    Veiculo *atual = topo;
    while (atual != NULL && strcmp(atual->placa, placa) != 0)
    {
        atual = atual->proximo;
    }
    if (atual == NULL)
    {
        return topo;
    }
    calcularValor(atual, valorTotal);
    if (atual->anterior == NULL)
    {
        topo = atual->proximo;
    }
    else
    {
        atual->anterior->proximo = atual->proximo;
    }
    if (atual->proximo != NULL)
    {
        atual->proximo->anterior = atual->anterior;
    }
    free(atual);
    return topo;
}

void imprimirAZ(Veiculo *topo)
{
    printf("Veiculos no estacionamento(A-Z):\n");
    Veiculo *atual = topo;
    while (atual != NULL)
    {
        printf("Nome do motorista: %s\n", atual->nomeMotorista);
        printf("Placa: %s\n", atual->placa);
        printf("Hora de entrada: %d\n", atual->horaEntrada);
        printf("Vaga: %d\n", atual->vaga);
        printf("Valor total: R$%.2f\n", atual->valorTotal);
        atual = atual->proximo;
    }
}

void imprimirZA(Veiculo *topo)
{
    printf("Veiculos no estacionamento(Z-A):\n");
    Veiculo *atual = topo;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    while (atual != NULL)
    {
        printf("Nome do motorista: %s\n", atual->nomeMotorista);
        printf("Placa: %s\n", atual->placa);
        printf("Hora de entrada: %d\n", atual->horaEntrada);
        printf("Vaga: %d\n", atual->vaga);
        printf("Valor total: R$%.2f\n", atual->valorTotal);
        atual = atual->anterior;
    }
}

int main()
{
    Veiculo *topo = NULL;
    int opcao;
    char nome[50], placa[8];
    int hora, vaga;
    float valorTotal = 0.00;
    while (1)
    {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Cadastrar veiculo\n");
        printf("2 - Remover veiculo\n");
        printf("3 - Imprimir veiculos(A-Z)\n");
        printf("4 - Imprimir veiculos(Z-A)\n");
        printf("5 - Ver valor total arrecadado no dia.\n");
        printf("6 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o nome do motorista: ");
            scanf("%s", nome);
            printf("Digite a placa do veiculo: ");
            scanf("%s", placa);
            printf("Digite a hora de entrada: ");
            scanf("%d", &hora);
            printf("Digite a vaga: ");
            scanf("%d", &vaga);
            Veiculo *veiculo = criarVeiculo(nome, placa, hora, vaga);
            topo = inserirVeiculo(topo, veiculo);
            break;
        case 2:
            printf("Digite a placa do veiculo a ser removido: ");
            scanf("%s", placa);
            topo = removerVeiculo(topo, placa, &valorTotal);
            printf("\nValor pago: %f", valorTotal);
            break;
        case 3:
            imprimirAZ(topo);
            break;
        case 4:
            imprimirZA(topo);
            break;
        case 5:
            printf("Valor total arrecadado: R$%.2f\n", valorTotal);
            break;
        case 6:
            return 0;
        default:
            printf("Opção invalida!\n");
            break;
        }
    }
    return 0;
}
