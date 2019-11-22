#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cachorros.h"

int parser_CachorroFromText(FILE* pFile , LinkedList* pArrayListCachorro)
{
    int retorno = -1;
    int flag=0;
    char bufferId[50];
    char bufferNombre[128];
    char bufferDias[50];
    char bufferRaza[128];
    char bufferReservado[128];
    char bufferGenero[128];



    Cachorro* pCachorro;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferDias, bufferRaza, bufferReservado, bufferGenero);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pCachorro = Cachorro_newParametros(bufferId, bufferNombre, bufferDias, bufferRaza, bufferReservado, bufferGenero);
        if(pCachorro != NULL)
        {
            ll_add(pArrayListCachorro, pCachorro);
            retorno = 0;
        }
    }
    return retorno;
}
