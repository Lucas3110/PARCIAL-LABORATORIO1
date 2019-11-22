#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cachorros.h"
#include "parser.h"
#include "utn.h"
/*
int controller_cantidadEntregada(LinkedList* pArrayListEntrega)
{
    Entrega* pAux;
    int length;
    int contadorCantidad = 0;
    int cantidadActual;
    int i;
    if(pArrayListEntrega != NULL)
    {
        length = ll_len(pArrayListEntrega);
        for(i=0;i<length;i++)
        {
            pAux = ll_get(pArrayListEntrega, i);
            if(!entrega_getCantidad(pAux, &cantidadActual))
            {
                contadorCantidad += cantidadActual;
            }
        }
    }
    return contadorCantidad;
}

int controller_importeEntregado(LinkedList* pArrayListEntrega)
{
    Entrega* pAux;
    int length;
    float contadorImporte = 0;
    float importeActual;
    int i;
    if(pArrayListEntrega != NULL)
    {
        length = ll_len(pArrayListEntrega);
        for(i=0;i<length;i++)
        {
            pAux = ll_get(pArrayListEntrega, i);
            if(!entrega_getImporte(pAux, &importeActual))
            {
                contadorImporte += importeActual;
            }
        }
    }
    return contadorImporte;
}
*/
int controller_loadFromText(char* path , LinkedList* pArrayListCachorro)
{
    int retorno = -1;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListCachorro != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if(!parser_CachorroFromText(pFile, pArrayListCachorro))
            {
                printf("Carga exitosa.");
                retorno = 0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}
/*
int controller_saveAsText(char* path, LinkedList* registro)
{
    int retorno = -1;
    int cantidadDeEntregas;
    int cantidadDeBultos = 0;
    int totalRegular, totalPlus, totalGold;
    float promedioDeBultos = 0;
    float importeTotal = 0;
    float promedioDeImporte = 0;
    LinkedList* registroGold = ll_newLinkedList();
    LinkedList* registroPlus = ll_newLinkedList();
    LinkedList* registroRegular = ll_newLinkedList();

    FILE *pFile = NULL;
    if(path != NULL && registro != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            //Cantidad total de Entregas
            cantidadDeEntregas = ll_len(registro);
            //Calculo de Entregas por Tipo
            registroGold = ll_filter(registro, entrega_filtrarGold);
            registroPlus = ll_filter(registro, entrega_filtrarPlus);
            registroRegular = ll_filter(registro, entrega_filtrarRegular);
            totalGold = ll_len(registroGold);
            totalPlus = ll_len(registroPlus);
            totalRegular = ll_len(registroRegular);
            //Cantidad y Promedio de Bultos
            cantidadDeBultos = controller_cantidadEntregada(registro);
            promedioDeBultos = (float)cantidadDeBultos / cantidadDeEntregas;
            //Importe promedio
            importeTotal = controller_importeEntregado(registro);
            promedioDeImporte = importeTotal / cantidadDeEntregas;
            //Carga al archivo
            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad Total de Entregas: %d\n", cantidadDeEntregas);
            fprintf(pFile, "- Cantidad de Entregas por Tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n", totalGold, totalRegular, totalPlus);
            fprintf(pFile, "- Cantidad Total de Bultos Entregados: %d\n", cantidadDeBultos);
            fprintf(pFile, "- Promedio de Bultos por Entrega: %.2f\n", promedioDeBultos);
            fprintf(pFile, "- Importe promedio por Entrega: %.2f\n", promedioDeImporte);
            fprintf(pFile, "*****************************");
            retorno = 0;
        }
        fclose(pFile);
    }
    if(!retorno)
    {
        printf("\nInforme generado exitosamente");
    }
    return retorno;
}

*/



int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
    int retorno = -1;
    Cachorro* pCachorro;
    int auxID, auxDias;
    char bufferNombre[128];
    char bufferRaza[128];
    char bufferReservado[128];
    char bufferGenero[128];
    int length;
    int i;
    if(pArrayListCachorro != NULL)
    {
        length = ll_len(pArrayListCachorro);
        for(i=0;i<length;i++)
        {
            pCachorro = ll_get(pArrayListCachorro, i);
            cachorro_getId(pCachorro, &auxID);
            cachorro_getDias(pCachorro, &auxDias);
            cachorro_getNombre(pCachorro, bufferNombre);
            cachorro_getRaza(pCachorro, bufferRaza);
            cachorro_getReservado(pCachorro, bufferReservado);
            cachorro_getGenero(pCachorro, bufferGenero);
            printf("ID: %d - Nombre: %s - Dias: %d - Raza: %s - Reservado: %s - Genero: %s\n", auxID, bufferNombre , auxDias, bufferRaza, bufferReservado, bufferGenero);
            retorno = 0;
        }
    }
    return retorno;
}


int controller_ListCalejero(LinkedList* pArrayListCachorro)
{
    int retorno = -1;
    Cachorro* pCachorro;
    int auxID, auxDias;
    char bufferNombre[128];
    char bufferRaza[128];
    char bufferReservado[128];
    char bufferGenero[128];
    int length;
    int i;
    if(pArrayListCachorro != NULL)
    {
        length = ll_len(pArrayListCachorro);
        for(i=0;i<length;i++)
        {
            pCachorro = ll_get(pArrayListCachorro, i);
            cachorro_getId(pCachorro, &auxID);
            cachorro_getDias(pCachorro, &auxDias);
            cachorro_getNombre(pCachorro, bufferNombre);
            cachorro_getRaza(pCachorro, bufferRaza);
            cachorro_getReservado(pCachorro, bufferReservado);
            cachorro_getGenero(pCachorro, bufferGenero);
            printf("ID: %d - Nombre: %s - Dias: %d - Raza: %s - Reservado: %s - Genero: %s\n", auxID, bufferNombre , auxDias, bufferRaza, bufferReservado, bufferGenero);
            retorno = 0;
        }
    }
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListCachorro)
{
    int retorno = -1;
    int i;
    int id, dias;
    char nombre[4096];
    char raza[4096];
    char reservado[4096];
    char genero[4096];
    int lengthArray;

    FILE *pFile = NULL;
    Cachorro* pAux = NULL;
    if(path != NULL && pArrayListCachorro != NULL)
    {
        pFile = fopen("cachorros.csv", "w");
        if(pFile != NULL)
        {
            lengthArray = ll_len(pArrayListCachorro);
            for(i=0;i<lengthArray;i++)
            {
                pAux = ll_get(pArrayListCachorro, i);
                if(pAux != NULL && !cachorro_getId(pAux, &id)
                    && !cachorro_getNombre(pAux, nombre)
                   && !cachorro_getDias(pAux, &dias)
                   && !cachorro_getRaza(pAux, raza)
                   && !cachorro_getReservado(pAux, reservado)
                    && !cachorro_getGenero(pAux, genero))
                {
                    fprintf(pFile, "%d,%s,%d,%s,%s,%s,\n", id,nombre,dias,raza,reservado,genero);
                }else{
                    cachorro_delete(pAux);
                }
            }
            retorno = 0;
        }
        fclose(pFile);
    }
    if(!retorno)
    {
        printf("Archivo guardado exitosamente");
    }
    return retorno;
}



