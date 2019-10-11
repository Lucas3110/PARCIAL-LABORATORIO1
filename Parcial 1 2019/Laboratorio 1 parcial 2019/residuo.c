#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "residuo.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array residuo Array of residuo
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int residuo_inicializar(Residuo array[], int size)                                    //cambiar residuo
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
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int residuo_buscarEmpty(Residuo array[], int size, int* posicion)                    //cambiar residuo
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
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int residuo_buscarID(Residuo array[], int size, int valorBuscado, int* posicion)                    //cambiar residuo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idResiduo==valorBuscado)                                                   //cambiar campo ID
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
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int residuo_buscarInt(Residuo array[], int size, int valorBuscado, int* posicion)                    //cambiar residuo
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPedido==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/*
//String
/** \brief Busca un string en un array
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*

int residuo_buscarString(Residuo array[], int size, char* valorBuscado, int* indice)                    //cambiar residuo
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString1,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
*/
//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int residuo_alta(Residuo array[], int size, int* contadorID)                          //cambiar residuo
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(residuo_buscarEmpty(array,size,&posicion)==-1)                          //cambiar residuo
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idResiduo=*contadorID;                         //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\ngetUnsignedInt1: ","\nError",1,sizeof(int),1,10,1,&array[posicion].idPedido);
            utn_getUnsignedInt("\ngetUnsignedInt2: ","\nError",1,sizeof(int),1,10,1,&array[posicion].tipo);
            utn_getUnsignedInt("\ngetUnsignedInt3: ","\nError",1,sizeof(int),1,10,1,&array[posicion].estado);      //mensaje + cambiar campo varInt
            utn_getFloat("\ngetFloat1: ","\nError",1,sizeof(float),0,1,1,&array[posicion].kilo);         //mensaje + cambiar campo varFloat


            printf("\n ID: %d\n idPedido: %d\n tipo: %d\n estado: %d\n kilo: %.2f",
                   array[posicion].idResiduo,array[posicion].idPedido,array[posicion].tipo,array[posicion].estado,
                   array[posicion].kilo);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int residuo_baja(Residuo array[], int sizeArray)                                      //cambiar residuo
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);   //cambiar si no se busca por ID
        if(residuo_buscarID(array,sizeArray,id,&posicion)==-1)                //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idResiduo=0;                                          //cambiar campo id
            array[posicion].idPedido=0;
            array[posicion].tipo=0;
            array[posicion].estado=0;                                         //cambiar campo varInt
            array[posicion].kilo=0;
                                                   //cambiar campo varFloat
                                //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int residuo_bajaValorRepetidoInt(Residuo array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idResiduo==valorBuscado)                                //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idResiduo=0;                                           //cambiar campo id
                array[i].idPedido=0;
                array[i].tipo=0;
                array[i].estado=0;                                           //cambiar campo varInt
                array[i].kilo=0;
                                                     //cambiar campo varFloat
                                     //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int residuo_modificar(Residuo array[], int sizeArray)                       //cambiar residuo
{
    int retorno=-1;
    int posicion;
    int id;                                                                   //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);     //cambiar si no se busca por ID
        if(residuo_buscarID(array,sizeArray,id,&posicion)==-1)               //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                 printf("\n ID: %d\n idPedido: %d\n tipo: %d\n estado: %d\n kilo: %f",
                   array[posicion].idResiduo,array[posicion].idPedido,array[posicion].tipo,array[posicion].estado,
                   array[posicion].kilo);
                utn_getChar("\nModificar: A B C D E F G H I J K L S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        system("cls");
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,1,1,&array[posicion].idPedido);  //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        system("cls");
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,1,1,&array[posicion].tipo);  //mensaje + cambiar campo varInt
                        break;
                    case 'C':
                        system("cls");
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,1,1,&array[posicion].estado);  //mensaje + cambiar campo varInt
                        break;
                    case 'D':
                        system("cls");
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].kilo);    //mensaje + cambiar campo varFloat
                        break;


                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}
/*
//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*

int residuo_ordenarPorDobleCriterio(Residuo array[],int size, int orderFirst, int orderSecond)  //cambiar residuo
{
    int retorno=-1;
    int i;
    Residuo buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].varString1,array[i+1].varString1) < 0) && orderFirst) ||
                    ((strcmp(array[i].varString1,array[i+1].varString1) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].varString1,array[i+1].varString1) == 0)
                {
                    if( ((array[i].kilo < array[i+1].kilo) && orderSecond) ||
                        ((array[i].kilo > array[i+1].kilo) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}
*/
//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array residuo Array de residuo
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int residuo_listar(Residuo array[], int size)                      //cambiar residuo
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
                printf("\n ID: %d\n idPedido: %d\n tipo: %d\n estado: %d\n kilo: %f",
                       array[i].idResiduo,array[i].idPedido,array[i].tipo,array[i].estado,array[i].kilo);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

