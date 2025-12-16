

#ifndef _LISTARESERVAS_H
#define _LISTARESERVAS_H

#include <stdlib.h>
#include "reserva.h"


#define TAM_LISTA_INICIAL 10


/**
 * Este tipo contem um vetor de ponteiro de reservas
 * Quantidade máxima que cabe na lista
 * Quantidade de reservas adicionadas na lista. 
 */
typedef struct ListaReservas ListaReservas;


/**
 *  Inicializa um vetor de reservas com tamanho inicial TAM_LISTA_INICIAL
 */
ListaReservas * inicializaListaReservas();


/**
 * Função que verifica se é possível realizar uma reserva solicitada com os dados informados.
 * Essa verificação é baseada em todas as regras de reserva de áreas comuns descritas na especificação.
 * 
 *
 * agendaReservas: ListaReserva que armazena todas as reservas de áreas comuns já realizadas
 * morRes: Morador que está solicitando a reserva
 * aRes: Área que está sendo solicitada
 * dRes: Data da reserva solicitada
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 *
 * Retorna 1 se a reserva pode ser realizada e 0 caso contrário
 */
int verificaSolicitacaoReserva(ListaReservas *agendaReservas, Morador *morRes, Area *aRes, Data *dRes, int qtdConvidados);

/**
 * Adiciona uma reserva válida a lista de reservas.  Caso a nova reserva ultrapasse a quantidade máxima,
 * o tamanho do vetor deve ser duplicado.
 */
ListaReservas * adicionaReserva(ListaReservas * lista, Reserva * r);


/**
 * Imprime todas as reservas armazenadas. 
 */
void imprimeListaReserva(ListaReservas * lista);


/**
 * Libera da memória todas as alocações do vetor de reservas e a própria estrutura. 
 */
void liberaListaReserva(ListaReservas * lista);


#endif