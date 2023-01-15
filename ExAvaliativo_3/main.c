#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct no
{
    char placa_veiculo[15];
    int vaga_oc,contagem;
    float hora_entrada;
    struct no *prox;
    float tempo_estacionado;

} noptr;

typedef struct des
{
    char placa_veiculo[15];
    int desconto;
    struct des *prox;

} desc;



/*
void atualizar(noptr **lista)
{

    noptr *aux1,*aux;
    noptr *aux2;

    aux = NULL;
    noptr *temp;
    temp = NULL;

    aux1 = *lista;
    aux2 = *lista;


    if(*lista == NULL)
    {
        printf("\nNao a veiculos no estacionamento");
        return;
    }





    while (aux1 != NULL)
    {

        noptr *aux2 = aux1->prox;

        while (aux2 != NULL)
        {

            if (aux1->tempo_estacionado > aux2->tempo_estacionado)  //se maior troca o conteudo das duas pessoas
            {

                troca(aux1->prox, aux2->prox);
                aux = aux1->prox;
                aux1->prox = aux2->prox;
                aux2->prox = aux;
            }
            aux2 = aux2->prox;
        }

        aux1 = aux1->prox;
    }


}

*/
void bubble_sort(noptr **lista)
{
    noptr *novo = malloc(sizeof(noptr));
    noptr *aux;


    if(novo)
    {
        novo->tempo_estacionado = (*lista)->tempo_estacionado;

        if(*lista == NULL)
        {
            printf("\nNao a veiculos no estacionamento");
            return;
        }
        else if(novo->tempo_estacionado < (*lista)->tempo_estacionado)
        {
            novo->prox = *lista;
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while(aux->prox && novo->tempo_estacionado > aux->prox->tempo_estacionado)
            {
                aux = aux->prox;
                novo->prox = aux->prox;
                aux->prox = novo;
            }
        }
    }

}

noptr *insere_lista(noptr *lista,noptr *novo, char placa[],float hora,int vaga,int numero,float hora_saida)
{

    strcpy(novo->placa_veiculo,placa);
    novo->hora_entrada = hora;
    novo->vaga_oc = vaga;
    novo->contagem = numero;
    novo->tempo_estacionado = hora_saida - hora;

    if(lista == NULL)
        novo->prox = NULL;
    else
    {
        novo->prox = lista;
    }
    lista = novo;
    return lista;
}

void lista_todos(noptr *lista)
{
    if(lista == NULL)
    {
        printf("\nLista vazia\n");
        return;
    }
    noptr *p;
    p = lista;

    while(p)
    {
        printf("\nVeiculo: %s",p->placa_veiculo);
        printf("\nHora de entrada: %.2f",p->hora_entrada);
        printf("\nVaga ocupada: %d",p->vaga_oc);
        p = p->prox;

        printf("\n");
    }

}

void lista_descontos(desc *lista)
{
    if(lista == NULL)
    {
        printf("\nLista vazia\n");
        return;
    }
    desc *p;
    p = lista;

    while(p)
    {
        printf("\nVeiculo: %s",p->placa_veiculo);
        setbuf(stdin,NULL);
        printf("\n%d",p->desconto);
        setbuf(stdin,NULL);


        p = p->prox;

        printf("\n");
    }

}

desc *selecionado(noptr *carro,desc *novo,desc *lista2,int num)
{

    char placa_[15];
    noptr *aux;
    aux = carro;


    while(aux->contagem != num)
    {
        aux = aux->prox;
    }

    if(aux->contagem == num)
    {
        strcpy(placa_,aux->placa_veiculo);
        strcpy(novo->placa_veiculo,placa_);

        novo->desconto = 1;

        if(lista2 == NULL)
            novo->prox = NULL;
        else
            novo->prox = lista2;

        lista2 = novo;
        return lista2;
    }
    else
    {
        return NULL;
    }


}
int descontar(noptr **carros,int vaga,desc **lista2 )
{
    noptr *p;
    desc *k,*aux;


    p = *carros;

    k = *lista2;

    aux = *lista2;

    if(k == NULL)
    {
        printf("\nNao possui desconto\n");
        return 0;
    }

    while(k)
    {

        if(strcmp(p->placa_veiculo, k->placa_veiculo) == 0)
        {
            if(k = *lista2)
            {
                *lista2 = k->prox;
            }
            else
            {

                aux->prox = k->prox;
            }
            free(k);
            return 1;

        }
        aux = k;
        k = k->prox;
    }
    return 0;

}

float retirar_veiculo(noptr **carros,int vaga,desc **lista2 )
{
    float valor;
    int desconto;
    noptr *aux,*remover = NULL;
    noptr *p;
    desc *k;
    aux = *carros;



    while(*carros)
    {

        if((*carros)->vaga_oc == vaga)
        {
            k= *lista2;
            p = *carros;
            desconto = descontar(carros,vaga,lista2);

            if(desconto == 1)
            {

                valor = p->tempo_estacionado*8 - ((p->tempo_estacionado*8) *0.1);

            }
            else
            {
                valor = p->tempo_estacionado*8 ;

            }

            if(*carros == aux)
            {


                *carros = aux->prox;
                free(p);
            }
            else
            {

                remover->prox = (*carros)->prox;

                *carros = aux;
                free(p);

            }

            return valor;

        }
        remover = *carros;
        *carros = (*carros)->prox;

    }
    return 0;
}

int main()
{
    int cont = 0,aux_cont = 0,op,i;
    char placa[15];
    int vaga,sorteio;
    float hora,horario_saida,valor_pago,lucro = 0.0;

    noptr *lista1;
    desc *Veiculos_selecionados;

    lista1 = NULL;
    Veiculos_selecionados = NULL;

    noptr *info;
    desc *info_aux;



    do
    {
        printf("\n1-Novo veiculo\n2-Veiculos no estacionamento: \n3-Sortear desconto\n4-Retirar veiculo\n5-Atualizar\n0-sair\n");
        scanf("%d",&op);

        switch(op)
        {

        case 1:
            printf("\nPlaca do veiculo: ");
            scanf("%s",&placa);
            printf("\nHora de entrada ( hora.minutos ): ");
            scanf("%f",&hora);
            printf("\nVaga preenchida: ");
            scanf("%d",&vaga);
            printf("\nHorario da retirada (fechamento 23h)");
            scanf("%f",&horario_saida);

            info=(struct no *)malloc(sizeof(noptr));
            lista1 = insere_lista(lista1,info,placa,hora,vaga,cont,horario_saida);

            cont++;

            break;
        case 2 :
            lista_todos(lista1);
            printf("===========");
            lista_descontos(Veiculos_selecionados);
            break;

        case 3:
            //funcão que aplica desconto
            aux_cont = cont/2;
            for(i=0; i<aux_cont; i++)
            {
                sorteio = rand() % cont;
                info_aux=(struct des *)malloc(sizeof(desc));
                Veiculos_selecionados = selecionado(lista1,info_aux,Veiculos_selecionados,sorteio);
            }

            break;
        case 4:

            printf("\nVaga liberada: ");
            scanf("%d",&vaga);

            valor_pago = retirar_veiculo(&lista1,vaga,&Veiculos_selecionados);
            printf("O valor pago eh: %.2f",valor_pago);
            printf("\nVaga %d está livre",vaga);

            lucro = lucro + valor_pago;
            break;
        case 5:
            bubble_sort(&lista1);
            break;
        }

    }
    while(op!=0);

}
