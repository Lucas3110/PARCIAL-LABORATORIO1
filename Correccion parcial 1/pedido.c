#include "pedido.h"
#include "cliente.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int pedidos_Inicializar(Pedidos array[], int size)
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

int pedidos_buscarEmpty(Pedidos array[], int size, int* posicion)
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


int pedidos_buscarID(Pedidos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPedido==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pedidos_alta(Pedidos array[], int size, int* contadorID, int contadorCliente)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID>0)
    {
        if(pedidos_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	if(utn_getInt(&array[posicion].idCliente,"\n:Ingrese ID de cliente: ","\nError",1,contadorCliente,2)==0)
        	{
        	array[posicion].isEmpty=0;
            array[posicion].estado=0;
            utn_getFloat(&array[posicion].cantKilos,"\n:Ingrese cantidad de kilos: ","\nError",1,10000,2);
            (*contadorID)++;
            array[posicion].idPedido = *contadorID;
            printf("\n_ID: %d _Cantidad de kilos: %f _Estado: Pendiente",array[posicion].idPedido,array[posicion].cantKilos);
            retorno=0;
        	}
        	else
        	{
        		printf("Numero de ID incorrecto");
        	}
        }
    }
    return retorno;
}

//*****************************************


int pedidos_procesar(Pedidos array[], int sizeArray, int contadorID)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && sizeArray>0)
    {
    	utn_getInt(&id,"\nID de pedido: ","\nError",1,contadorID,1);
    	if(pedidos_buscarID(array,sizeArray,id,&posicion)==-1)
    	{
    		printf("No existe el ID del pedido");
    	}
    	else
    	{
    		if(array[posicion].estado==0)
    		 {
    			utn_getInt(&array[posicion].kilosHDPE,"\nCantidad de kilos de HDPE ","\nError",1,3000,1);
    			utn_getInt(&array[posicion].kilosLDPE,"\nCantidad de kilos de LDPE ","\nError",1,3000,1);
    			utn_getInt(&array[posicion].kilosPP,"\nCantidad de kilos de PP ","\nError",1,3000,1);
    			array[posicion].estado=1;
    		    printf("\n ID: %d"
    		    		"\n Cantidad de kilos: %f"
    		    		"\n Cantidad de kilosHDPE: %d"
    		    		"\n Cantidad de kilosLDPE: %d"
    		    		"\n Cantidad de kilosPP: %d"
    		    		"\n Estado: Completado",
						array[posicion].idPedido,
						array[posicion].cantKilos,
						array[posicion].kilosHDPE,
						array[posicion].kilosLDPE,
						array[posicion].kilosPP);

    		 }

    		else
    		{
    			printf("El pedido ya fue procesado");
    		}
    	}

    }


    return retorno;
}

//*****************************************

int pedidos_listar(Pedidos array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
            	printf("\n ID: %d"
            	       "\n Cantidad de kilos: %f",
            	        array[i].idPedido,
            	        array[i].cantKilos);
            	if(array[i].estado==0)
            	{
            		printf("\n Estado: Pendiente");
            	}
            	else
            	{
            		printf("\n Estado: Completado");
            	}
            }
        }
        retorno=0;
    }
    return retorno;
}


//*****************************************
