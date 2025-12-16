
#include <stdio.h>
#include <string.h>
#include "morador.h"
#include "area.h"
#include "reserva.h"
#include "listaReservas.h"

//#define MAX_MORADORES 100
//#define MAX_AREAS 10
//#define MAX_RESERVAS 100

int getMoradorGrupo(Morador **grupo, int nGrupo, char *cpf)
{

    for (int i = 0; i < nGrupo; i++)
    {
        if (verificaCPFMorador(grupo[i], cpf))
        {
            return i;
        }
    }

    return -1;
}

int getAreaGrupo(Area **grupo, int nGrupo, char *id)
{

    for (int i = 0; i < nGrupo; i++)
    {
        if (verificaIdArea(grupo[i], id))
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    int nMoradores, nAreas, nReservas, nReservasSol = 0;
    //Morador grupoMoradores[MAX_MORADORES];
    //Area grupoAreas[MAX_AREAS];
    //Reserva grupoReservas[MAX_RESERVAS];

    scanf("%d\n", &nAreas);
    Area **grupoAreas = malloc(sizeof(Area *)* nAreas);
    for (int i = 0; i < nAreas; i++)
    {
        grupoAreas[i] = lerArea();

        // DEBUG
        // imprimeArea(grupoAreas[i]);
    }

    scanf("%d\n", &nMoradores);

    Morador **grupoMoradores = malloc(sizeof(Morador *)*nMoradores);
    for (int i = 0; i < nMoradores; i++)
    {
        grupoMoradores[i] = lerMorador();

        // DEBUG
        // imprimeMorador(grupoMoradores[i]);
    }

   

    //Reserva **grupoReservas = malloc(sizeof(Reserva *)*nReservas);;
    char idArea[MAX_TAM_ID];
    char cpf[MAX_TAM_CPF];
    Data *data;
    int qtdConvidados;

    Morador *morador;
    Area *area;
    

    ListaReservas *grupoReservas = inicializaListaReservas();


    char c;
    scanf("%c\n", &c);
    while (c == 'R')
    {
        scanf("%s\n", idArea);
        scanf("%s\n", cpf);
        data = lerData();
        scanf("%d\n", &qtdConvidados);
        scanf("%c\n", &c);
        // DEBUG
        // printf("\n---- Pedido ----\n");
        // printf("%s\n", idArea);
        // printf("%s\n", cpf);
        // imprimeData(data);
        // printf("%d\n", qtdConvidados);
        // printf("----------------\n");

        int posMorador, posArea;
      

        posMorador = getMoradorGrupo(grupoMoradores, nMoradores, cpf);
        posArea = getAreaGrupo(grupoAreas, nAreas, idArea);

        if (posMorador == -1 || posArea == -1)
        {
            liberaData(data);
            continue;
        }
        else
        {
            morador = grupoMoradores[posMorador];
            area = grupoAreas[posArea];
        }

        if (verificaSolicitacaoReserva(grupoReservas,  morador, area, data, qtdConvidados))
        {
            Reserva *r = criaReserva(morador, area, data, qtdConvidados);
            grupoReservas = adicionaReserva(grupoReservas, r);
            //grupoReservas[nReservasSol] = r;
            //nReservasSol++;
        }
        else{
            liberaData(data);
        }

    }

    
    imprimeListaReserva(grupoReservas);


    /**
     * Liberando todos os itens da memória */    

     liberaListaReserva(grupoReservas);
    /* for (int i = 0; i < nReservasSol; i++)
    {
       liberaReserva(grupoReservas[i]);
    }*/

  for (int i = 0; i < nMoradores; i++)
    {
       liberaMorador(grupoMoradores[i]);
    }

  for (int i = 0; i < nAreas; i++)
    {
       liberaArea(grupoAreas[i]);
    }

    
    //free(grupoReservas);
    free(grupoMoradores);
    free(grupoAreas);


    return 0;
}