

#include <stdio.h>
#include "reserva.h"


struct Reserva
{
    Morador * morador;
    Area *area;
    Data *data;
    int qtdConvidados;
};



/**
 * Função que recebe os dados necessários para criar uma reserva
 * e retorna a reserva criada.
 * morRes: Morador que está fazendo a reserva
 * aRes: Área que está sendo reservada
 * dRes: Data da reserva
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 *
 * Retorna uma Reserva com os dados informados
 */
Reserva *criaReserva(Morador * morRes, Area* aRes, Data *dRes, int qtdConvidados)
{
    Reserva *r = malloc(sizeof(Reserva));
    r->morador = morRes;
    r->area = aRes;
    r->data = dRes;
    r->qtdConvidados = qtdConvidados;
    return r;
}



/**
 * Função que compara uma reserva já agendada com dados de solicitação de uma nova reserva
 * 
 * Essa verificação é baseada nas regras de reserva de áreas comuns descritas na especificação:
    * Um morador só pode ter uma reserva por dia, mesmo que o condomínio
disponha de múltiplas áreas;
    *Uma área só pode ter uma reserva por dia;
 
    
 * reservaAgendada: Recebe uma agenda já inserida no vetor de agendamentos
  * morRes: Morador que está solicitando a reserva
 * aRes: Área que está sendo solicitada
 * dRes: Data da reserva solicitada
 *
 * Retorna 1 se a reserva pode ser realizada e 0 caso contrário
 */
int comparaReserva(Reserva *reservaAgendada, Morador *morRes,
    Area *aRes, Data *dRes)
{



    if (comparaMorador(reservaAgendada->morador, morRes) && comparaData(reservaAgendada->data, dRes))
    {
    return 0;
    }

    if (comparaArea(reservaAgendada->area, aRes) && comparaData(reservaAgendada->data, dRes))
    {
    return 0;
    }
  

return 1;
}

/**
 * Função que imprime todas as informações de uma reserva conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeReserva(Reserva *r)
{
    printf("--------- RESERVA -----------\n");

    printf("Morador: \n");
    imprimeMorador(r->morador);

    printf("\nArea reservada: \n");
    imprimeArea(r->area);
    printf("Data da reserva: ");
    imprimeData(r->data);

    printf("\nQuantidade de convidados: %d\n", r->qtdConvidados);
    int taxa = 100 * r->qtdConvidados / getCapacidadeArea(r->area);
    printf("Taxa de ocupação: %d%%\n", taxa);

    printf("------------------------------\n");
}


void liberaReserva(Reserva * r){
    if(r != NULL)
    {
        //liberaMorador(r->morador);
        liberaData(r->data);
        //liberaArea(r->area);
        free(r);

    }   
        

   r =  NULL;
}