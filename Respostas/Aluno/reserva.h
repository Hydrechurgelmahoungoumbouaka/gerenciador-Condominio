

#ifndef _RESERVA_H
#define _RESERVA_H

#include <stdlib.h>
#include "data.h"
#include "morador.h"
#include "area.h"


/**
 * Struct que deve ser definido em reserva.c
 * 
 * A reserva deve conter um morador, a area reservada, a data da reserva e a quantidade de convidados. 
 * 
 */
typedef struct Reserva Reserva;

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
Reserva * criaReserva(Morador *morRes, Area *aRes, Data *dRes, int qtdConvidados);


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
    Area *aRes, Data *dRes);
/**
 * Função que imprime todas as informações de uma Reserva conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeReserva(Reserva *r);

/**
 * Libera a memória reserva para a estrutura Reserva
 */
void liberaReserva(Reserva *r);

#endif