#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedido.h"
#include "cliente.h"
#include "listar.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array pedido Array of pedido
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int pedido_inicializar(Pedido array[], int size)                                    //cambiar pedido
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int pedido_buscarEmpty(Pedido array[], int size, int* posicion)                    //cambiar pedido
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pedido_buscarID(Pedido array[], int size, int valorBuscado, int* posicion)                    //cambiar pedido
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPed==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pedido_buscarInt(Pedido array[], int size, int valorBuscado, int* posicion)                    //cambiar pedido
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idCli==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int pedido_alta(Pedido array[], int size, int* contadorID)                          //cambiar pedido
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(pedido_buscarEmpty(array,size,&posicion)==-1)                          //cambiar pedido
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            utn_getUnsignedInt("\nID cliente: ","\nError",1,sizeof(int),1,100,1,&id);     //cambiar si no se busca por ID
            if(cliente_buscarID(array,100,id,&posicion)==-1)               //cambiar si no se busca por ID
            {
                printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
            }

        else
        {

            array[posicion].isEmpty=0;
            array[posicion].estado=0;
            utn_getFloat("\nKilos: ","\nError",1,sizeof(float),0,1,1,&array[posicion].kilo);
             //PENDIENTE
            (*contadorID)++;
            array[posicion].idPed=*contadorID;
            printf("\n ID: %d\n kilos: %.2f\n estado: pendiente",
                   array[posicion].idPed,array[posicion].kilo);
            retorno=0;
        }
        }
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array pedido Array de pedido
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int pedido_listar(Pedido array[], int size)                      //cambiar pedido
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n kilos: %.2f",
                       array[i].idPed,array[i].kilo);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

int pedido_alta2(Pedido array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {

        utn_getUnsignedInt("\nID pedido: ","\nError",1,sizeof(int),1,sizeArray,1,&id);     //cambiar si no se busca por ID
        if(pedido_buscarID(array,sizeArray,id,&posicion)==-1)               //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
        }
        else
        {
            printf("\n ID: %d\n kilos: %.2f",array[posicion].idPed,array[posicion].kilo);
            if(!utn_getFloat("\nHDPE: ","\nError",1,sizeof(float),0,1,1,&array[posicion].kilHDPE));
            {
                array[posicion].kilo = array[posicion].kilo - array[posicion].kilHDPE;
            }
            if(!utn_getFloat("\nLDPE: ","\nError",1,sizeof(float),0,1,1,&array[posicion].kilLDPE));
            {
                array[posicion].kilo = array[posicion].kilo - array[posicion].kilLDPE;
            }
            if(!utn_getFloat("\nPP: ","\nError",1,sizeof(float),0,1,1,&array[posicion].kilPP));
            {
                array[posicion].kilo = array[posicion].kilo - array[posicion].kilPP;
            }
            printf("\n ID: %d\nkilHDPE: %.2f\n kilLDPE: %.2f\n kilPP: %.2f\n kilos desechados: %.2f",array[posicion].idPed,
            array[posicion].kilHDPE,array[posicion].kilLDPE,array[posicion].kilPP,array[posicion].kilo);

             array[posicion].kilo=0; //desecho residuos

            retorno=0;
        }
    }
    return retorno;
}


