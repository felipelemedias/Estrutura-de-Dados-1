#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUTOS 10

typedef struct produto
{
    int cod;
    float valorUnitario;
    int quantidade;
} Produto;

typedef struct no
{
    Produto produto;
    struct no *proximo;
} No;

typedef struct fila
{
    No *inicio;
    No *fim;
} Fila;

void iniciar(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void cadastrarProduto(Fila *fila)
{
    Produto produto;
    printf("Digite o codigo do produto: ");
    scanf("%d", &produto.cod);
    printf("Digite o valor unitario: ");
    scanf("%f", &produto.valorUnitario);
    printf("Digite a quantidade: ");
    scanf("%d", &produto.quantidade);
    inserirNaFila(fila, produto);
}

void inserirNaFila(Fila *fila, Produto produto)
{
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->produto = produto;
    novoNo->proximo = NULL;

    if (filaVazia(fila))
    {
        fila->inicio = novoNo;
    }
    else
    {
        fila->fim->proximo = novoNo;
    }

    fila->fim = novoNo;
}

Produto removerDaFila(Fila *fila)
{
    if (filaVazia(fila))
    {
        printf("Erro: Fila vazia\n");
        exit(1);
    }

    No *no = fila->inicio;
    Produto produto = no->produto;
    fila->inicio = no->proximo;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(no);
    return produto;
}

void alterarProduto(Fila *fila, int cod, float novoValor, int novaQuantidade)
{
    No *no = fila->inicio;
    while (no != NULL)
    {
        if (no->produto.cod == cod)
        {
            no->produto.valorUnitario = novoValor;
            no->produto.quantidade = novaQuantidade;
            break;
        }
        no = no->proximo;
    }
}

void removerProdutosSemEstoque(Fila *fila) {
    Fila novaFila;
    iniciar(&novaFila);

    No *no = fila->inicio;
    while (no != NULL) {
        if (no->produto.quantidade > 0) {
            inserirNaFila(&novaFila, no->produto);
        }
        no = no->proximo;
    }
    fila->inicio = novaFila.inicio;
    fila->fim = novaFila.fim;
    novaFila.inicio = NULL;
    novaFila.fim = NULL;
}

void imprimirFila(Fila *fila)
{
    No *no = fila->inicio;
    while (no != NULL)
    {
        printf("Codigo: %d, Valor unitario: %.2f, Quantidade: %d\n", no->produto.cod, no->produto.valorUnitario, no->produto.quantidade);
        no = no->proximo;
    }
}

int main() {
    Fila fila;
    iniciar(&fila);

    int opcao;
    do
    {
        printf("\nEscolha a opcao:\n1 - Cadastrar produto\n2 - Alterar produto\n3 - Remover produtos sem estoque\n4 - Imprimir fila\n5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarProduto(&fila);
            break;
        case 2:
        {
            int cod;
            float novoValor;
            int novaQuantidade;
            printf("Digite o codigo do produto: ");
            scanf("%d", &cod);
            printf("Digite o novo valor unitario: ");
            scanf("%f", &novoValor);
            printf("Digite a nova quantidade: ");
            scanf("%d", &novaQuantidade);
            alterarProduto(&fila, cod, novoValor, novaQuantidade);
            break;
        }
        case 3:
            removerProdutosSemEstoque(&fila);
            break;
        case 4:
            imprimirFila(&fila);
            break;
        case 5:
            break;
        default:
            printf("Opcao invalida\n");
        }
    }while (opcao != 5);

    return 0;
}
