#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int fantasma_inicializar(Fantasma array[], int size)                                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion)                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
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
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
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
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
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

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int fantasma_alta(Fantasma array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(fantasma_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                         //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\ngetUnsignedInt1: ","\nError",1,sizeof(int),1,10,1,&array[posicion].varInt1);
            utn_getUnsignedInt("\ngetUnsignedInt2: ","\nError",1,sizeof(int),1,10,1,&array[posicion].varInt2);
            utn_getUnsignedInt("\ngetUnsignedInt3: ","\nError",1,sizeof(int),1,10,1,&array[posicion].varInt3);      //mensaje + cambiar campo varInt
            utn_getFloat("\ngetFloat1: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat1);
            utn_getFloat("\ngetFloat2: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat2);
            utn_getFloat("\ngetFloat3: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat3);    //mensaje + cambiar campo varFloat
            utn_getName("\ngetName3: ","\nError",1,TEXT_SIZEA,1,array[posicion].varString1);
            utn_getName("\ngetName2: ","\nError",1,TEXT_SIZEB,1,array[posicion].varString2);
            utn_getName("\ngetName1: ","\nError",1,TEXT_SIZEA,1,array[posicion].varString3);    //mensaje + cambiar campo varString
            utn_getTexto("\ngetTexto1: ","\nError",1,TEXT_SIZEC,1,array[posicion].varLongString1);
            utn_getTexto("\ngetTexto2: ","\nError",1,TEXT_SIZEC,1,array[posicion].varLongString2);
            utn_getTexto("\ngetTexto3: ","\nError",1,TEXT_SIZEC,1,array[posicion].varLongString3);        //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n varInt1: %d\n varInt2: %d\n varInt3: %d\n varFloat1: %.2f"
                   "\n varFloat2: %.2f\n varFloat3: %.2f\n varString1: %s\n varString2: %s\n varString3: %s"
                   "\n varLongString1: %s\n varLongString2: %s\n varLongString3: %s",
                   posicion,array[posicion].idUnico,array[posicion].varInt1,array[posicion].varInt2,array[posicion].varInt3,
                   array[posicion].varFloat1,array[posicion].varFloat2,array[posicion].varFloat3,array[posicion].varString1,
                   array[posicion].varString2,array[posicion].varString3,array[posicion].varLongString1,array[posicion].varLongString2,
                   array[posicion].varLongString3);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(Fantasma array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);   //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                          //cambiar campo id
            array[posicion].varInt1=0;
            array[posicion].varInt2=0;
            array[posicion].varInt3=0;                                         //cambiar campo varInt
            array[posicion].varFloat1=0;
            array[posicion].varFloat2=0;
            array[posicion].varFloat3=0;                                       //cambiar campo varFloat
            strcpy(array[posicion].varString1,"");
            strcpy(array[posicion].varString2,"");
            strcpy(array[posicion].varString3,"");                            //cambiar campo varString
            strcpy(array[posicion].varLongString1,"");
            strcpy(array[posicion].varLongString2,"");
            strcpy(array[posicion].varLongString3,"");                        //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                           //cambiar campo id
                array[i].varInt1=0;
                array[i].varInt2=0;
                array[i].varInt3=0;                                           //cambiar campo varInt
                array[i].varFloat1=0;
                array[i].varFloat2=0;
                array[i].varFloat3=0;                                         //cambiar campo varFloat
                strcpy(array[i].varString1,"");
                strcpy(array[i].varString2,"");
                strcpy(array[i].varString3,"");                               //cambiar campo varString
                strcpy(array[i].varLongString1,"");
                strcpy(array[i].varLongString2,"");
                strcpy(array[i].varLongString3,"");                           //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int fantasma_modificar(Fantasma array[], int sizeArray)                       //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                   //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);     //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)               //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                    //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                 printf("\n Posicion: %d\n ID: %d\n varInt1: %d\n varInt2: %d\n varInt3: %d\n varFloat1: %f"
                   "\n varFloat2: %f\n varFloat3: %f\n varString1: %s\n varString2: %s\n varString3: %s"
                   "\n varLongString1: %s\n varLongString2: %s\n varLongString3: %s",
                   posicion,array[posicion].idUnico,array[posicion].varInt1,array[posicion].varInt2,array[posicion].varInt3,
                   array[posicion].varFloat1,array[posicion].varFloat2,array[posicion].varFloat3,array[posicion].varString1,
                   array[posicion].varString2,array[posicion].varString3,array[posicion].varLongString1,array[posicion].varLongString2,
                   array[posicion].varLongString3);
                utn_getChar("\nModificar: A B C D E F G H I J K L S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        system("cls");
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,1,1,&array[posicion].varInt1);  //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        system("cls");
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,1,1,&array[posicion].varInt2);  //mensaje + cambiar campo varInt
                        break;
                    case 'C':
                        system("cls");
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,1,1,&array[posicion].varInt3);  //mensaje + cambiar campo varInt
                        break;
                    case 'D':
                        system("cls");
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat1);    //mensaje + cambiar campo varFloat
                        break;
                    case 'E':
                        system("cls");
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat2);    //mensaje + cambiar campo varFloat
                        break;
                    case 'F':
                        system("cls");
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat3);  //mensaje + cambiar campo varFloat
                        break;
                    case 'G':
                        system("cls");
                        utn_getName("\n: ","\nError",1,TEXT_SIZEA,1,array[posicion].varString1);   //mensaje + cambiar campo varString
                        break;
                    case 'H':
                        system("cls");
                        utn_getName("\n: ","\nError",1,TEXT_SIZEB,1,array[posicion].varString2);   //mensaje + cambiar campo varString
                        break;
                    case 'I':
                        system("cls");
                        utn_getName("\n: ","\nError",1,TEXT_SIZEA,1,array[posicion].varString3);  //mensaje + cambiar campo varString
                        break;
                    case 'J':
                        system("cls");
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZEC,1,array[posicion].varLongString1); //mensaje + cambiar campo varLongString
                        break;
                    case 'K':
                        system("cls");
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZEC,1,array[posicion].varLongString2); //mensaje + cambiar campo varLongString
                        break;
                    case 'L':
                        system("cls");
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZEC,1,array[posicion].varLongString3);  //mensaje + cambiar campo varLongString
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

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int fantasma_ordenarPorDobleCriterio(Fantasma array[],int size, int orderFirst, int orderSecond)  //cambiar fantasma
{
    int retorno=-1;
    int i;
    Fantasma buffer;
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

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tama�o del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma array[], int size)                      //cambiar fantasma
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
                printf("\n ID: %d\n varInt1: %d\n varInt2: %d\n varInt3: %d\n varFloat1: %f\n varFloat2: %f\n varFloat3: %f"
                       "\n varString1: %s\n varString2: %s\n varString3: %s\n varLongString1: %s\n varLongString2: %s\n varLongString3: %s",
                       array[i].idUnico,array[i].varInt1,array[i].varInt2,array[i].varInt3,array[i].varFloat1,array[i].varFloat2
                       ,array[i].varFloat3,array[i].varString1,array[i].varString2,array[i].varString3
                       ,array[i].varLongString1,array[i].varLongString2,array[i].varLongString3);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}



