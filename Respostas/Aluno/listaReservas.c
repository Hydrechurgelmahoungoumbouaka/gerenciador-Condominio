
#include "listaReservas.h"

/**
 * Este tipo contem um vetor de ponteiro de reservas
 * Quantidade máxima que cabe na lista
 * Quantidade de reservas adicionadas na lista. 
 */
struct ListaReservas{
   Reserva **reservas;
   int capacidade;
   int qtde;
};




/**
 *  Inicializa um vetor de reservas com tamanho inicial TAM_LISTA_INICIAL
 */
ListaReservas * inicializaListaReservas()
{
    ListaReservas *l = malloc(sizeof(ListaReservas));
    l->capacidade = TAM_LISTA_INICIAL;
    l->qtde = 0;

    l->reservas = malloc(sizeof(Reserva **)*TAM_LISTA_INICIAL);
    
    return l;
}





/**
 * Adiciona uma reserva válida a lista de reservas.  Caso a nova reserva ultrapasse a quantidade máxima,
 * o tamanho do vetor deve ser duplicado.
 */
ListaReservas * adicionaReserva(ListaReservas * lista, Reserva * r)
{
    if (lista != NULL)
    {
        if (lista->capacidade > lista->qtde)
        {
            lista->reservas[lista->qtde] = r;
            lista->qtde++;
        }
        else
        {
            lista->reservas = realloc(lista->reservas, sizeof(Reserva**)*lista->capacidade*2);
            lista->capacidade = lista->capacidade*2;
            lista->reservas[lista->qtde] = r;
            lista->qtde++;
        }
    }
    
    return lista;
}



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
int verificaSolicitacaoReserva(ListaReservas *agendaReservas, Morador *morRes,
    Area *aRes, Data *dRes, int qtdConvidados)
{

if (calculaIdadeMorador(morRes, dRes) < 18 || qtdConvidados > getCapacidadeArea((aRes))
)
{
return 0;
}

for (int i = 0; i < agendaReservas->qtde; i++)
{
    if (!comparaReserva(agendaReservas->reservas[i], morRes, aRes, dRes))
       return 0;

}

return 1;
}

void imprimeListaReserva(ListaReservas * lista)
{
    for (int i = 0; i < lista->qtde; i++)
    {
        imprimeReserva(lista->reservas[i]);
    }
}

/**
 * Libera da memória todas as alocações do vetor de reservas e a própria estrutura. 
 */
void liberaListaReserva(ListaReservas * lista)
{
    for (int i = 0; i < lista->qtde; i++)
    {
        liberaReserva(lista->reservas[i]);
    }

    free(lista->reservas);
    free(lista);
    
    lista = NULL;
}

