#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array cliente Array of cliente
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int cliente_inicializar(Cliente array[], int size)                                    //cambiar cliente
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
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int cliente_buscarEmpty(Cliente array[], int size, int* posicion)                    //cambiar cliente
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
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cliente_buscarID(Cliente array[], int size, int valorBuscado, int* posicion)                    //cambiar cliente
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idCliente==valorBuscado)                                                   //cambiar campo ID
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
 \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*

int cliente_buscarInt(Cliente array[], int size, int valorBuscado, int* posicion)                    //cambiar cliente
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt1==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/ \brief Busca un string en un array
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*

int cliente_buscarString(Cliente array[], int size, char* valorBuscado, int* indice)                    //cambiar cliente
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
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int cliente_alta(Cliente array[], int size, int* contadorID)                          //cambiar cliente
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(cliente_buscarEmpty(array,size,&posicion)==-1)                          //cambiar cliente
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idCliente=*contadorID;                         //campo ID
            array[posicion].isEmpty=0;
            utn_getTexto("\nIngrese el nombre de la empresa: ","\nError",1,TEXT_SIZEC,1,array[posicion].nombre);
            utn_getTexto("\nIngrese el CUIT: ","\nError",1,TEXT_SIZED,1,array[posicion].cuit);
            utn_getTexto("\nIngrese la direccion: ","\nError",1,TEXT_SIZEC,1,array[posicion].direccion);
            utn_getTexto("\nIngrese la localidad: ","\nError",1,TEXT_SIZEC,1,array[posicion].localidad);         //mensaje + cambiar campo varLongString
            printf("\n ID: %d\n nombre: %s\n cuit: %s\n direccion: %s\n localidad: %s",
                   array[posicion].idCliente,array[posicion].nombre,array[posicion].cuit,
                   array[posicion].direccion,array[posicion].localidad);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int cliente_baja(Cliente array[], int sizeArray)                                      //cambiar cliente
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);   //cambiar si no se busca por ID
        if(cliente_buscarID(array,sizeArray,id,&posicion)==-1)                //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idCliente=0;

            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].cuit,"");
            strcpy(array[posicion].direccion,"");                        //cambiar campo varLongString
            strcpy(array[posicion].localidad,"");
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int cliente_bajaValorRepetidoInt(Cliente array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idCliente==valorBuscado)                                //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idCliente=0;                                           //cambiar campo id
                                           //cambiar campo varString
                strcpy(array[i].nombre,"");
                strcpy(array[i].cuit,"");
                strcpy(array[i].direccion,"");                           //cambiar campo varLongString
                strcpy(array[i].localidad,"");
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int cliente_modificar(Cliente array[], int sizeArray)                       //cambiar cliente
{
    int retorno=-1;
    int posicion;
    int id;                                                                   //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);     //cambiar si no se busca por ID
        if(cliente_buscarID(array,sizeArray,id,&posicion)==-1)               //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                 printf("\n direccion: %s\n localidad: %s",
                   array[posicion].direccion,array[posicion].localidad);
                utn_getChar("\nModificar: A B o C(salir)","\nError",'A','C',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        system("cls");
                        utn_getTexto("\nIngrese una nueva direccion: ","\nError",1,TEXT_SIZEC,1,array[posicion].direccion);  //mensaje + cambiar campo varLongString
                        break;
                    case 'B':
                        system("cls");
                        utn_getTexto("\nIngrese una nueva localidad: ","\nError",1,TEXT_SIZEC,1,array[posicion].localidad);  //mensaje + cambiar campo varLongString
                        break;
                    case 'C':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='C');
            retorno=0;
        }
    }
    return retorno;
}
/*
/*****************************************
//Ordenar
/ \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*

int cliente_ordenarPorDobleCriterio(Cliente array[],int size, int orderFirst, int orderSecond)  //cambiar cliente
{
    int retorno=-1;
    int i;
    Cliente buffer;
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
                    if( ((array[i].varFloat1 < array[i+1].varFloat1) && orderSecond) ||
                        ((array[i].varFloat1 > array[i+1].varFloat1) && !orderSecond) )
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
* \param array cliente Array de cliente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int cliente_listar(Cliente array[], int size)                      //cambiar cliente
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
                printf("\n ID: %d\n nombre: %s\n cuit: %s\n direccion: %s\n localidad: %s",
                       array[i].idCliente,array[i].nombre,array[i].cuit,array[i].direccion,array[i].localidad);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
