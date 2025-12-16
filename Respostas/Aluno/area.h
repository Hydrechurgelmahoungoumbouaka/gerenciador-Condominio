

#ifndef _AREA_H
#define _AREA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_TAM_NOME 100
#define MAX_TAM_ID 5


/**
 * Struct que deve ser definido em area.c
 * 
struct Area
{
    char nome[MAX_TAM_NOME];
    char id[MAX_TAM_ID];
    int capacidade;
};

 */

typedef struct Area Area;

/**
 * Função que lê uma área comum de acordo com o formato de entrada descrito na
 * especificação e retorna a Area lida.
 */
Area * lerArea();

/**
 * Função que imprime todas as informações de uma Area conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeArea(Area *a);

/*
 * Função que compara se duas áreas são iguais através do
 * id delas.
 * Retorna 1 se forem iguais e 0 caso contrário
 */
int comparaArea(Area *a1, Area *a2);

/*
 * Função que verifica se o id passado é igual ao id da área passada
 * Retorna 1 se for igual e 0 caso contrário
 */
int verificaIdArea(Area *a, char *id);

/**
 * Função que retorna a capacidade de uma área comum.
 */
int getCapacidadeArea(Area *a);


/**
 * Função que libera uma Struct Area da Memoria.
 */
int liberaArea(Area *a);

#endif