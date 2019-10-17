#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedido.h"

#define QTY_ARRAY_CLI 100
#define QTY_ARRAY_PED 100
#define SORT_UP 1
#define SORT_DOWN 0

cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[],int *contadorIdcliente,int *contadorIdpedido);

int main()
{

    int opcion;
    int contadorIdcliente=0;
    int contadorIdpedido=0;


    Cliente arrayCliente[QTY_ARRAY_CLI];
    cliente_inicializar(arrayCliente,QTY_ARRAY_CLI);

    Pedido arrayPedido[QTY_ARRAY_CLI];
    pedido_inicializar(arrayPedido,QTY_ARRAY_PED);

    cargarDatos(arrayCliente,arrayPedido, &contadorIdcliente, &contadorIdpedido);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta de cliente \n2) Modificar datos de cliente \n3) Baja de cliente"
                           "\n4) Crear pedido de recoleccion \n5) Procesar residuos \n6) Imprimir clientes"
                           "\n7) Imprimir pedidos pendientes \n8) Imprimir pedidos procesados \n9) Salir\n",                   //cambiar
                           "\nError",1,sizeof(int),1,9,2,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                system("cls");
                if(!cliente_alta(arrayCliente,QTY_ARRAY_CLI,&contadorIdcliente));                   //cambiar
                {
                    printf("\n----Se dio de ALTA exitosamente!----\n");
                }
                break;

            case 2: //Modificar
                system("cls");
                if(!cliente_modificar(arrayCliente,QTY_ARRAY_CLI));
                {
                     printf("\n----Se modifico exitosamente----\n");
                }
                break;

            case 3: //Baja
                system("cls");
                if(!cliente_baja(arrayCliente,QTY_ARRAY_CLI));
                {
                    printf("\n----Se dio de BAJA exitosamente!----\n");
                }
                break;

            case 4: //Alta PEDIDO
                system("cls");
                cliente_listar(arrayCliente,QTY_ARRAY_PED);
                printf("\n");

                if(!pedido_alta(arrayPedido,QTY_ARRAY_PED,&contadorIdpedido));                   //cambiar
                {
                    printf("\n----Se dio de ALTA exitosamente!----\n");
                }

                break;
            case 5://alta residuo
                system("cls");

                 pedido_alta2(arrayPedido,QTY_ARRAY_PED);                   //cambiar


                break;

            case 6://Listar
                system("cls");
                cliente_listar(arrayCliente,QTY_ARRAY_CLI);
                break;
/*
            case 5://Ordenar
                system("cls");
                cliente_ordenarPorDobleCriterio(arrayCliente,QTY_ARRAY_CLI,SORT_UP,SORT_DOWN);                   //cambiar
                break;
*/
            case 9://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
        printf("\n");
        system("pause");
        system("cls");

    } while(opcion!=9);

    return 0;
}


int cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[], int *contadorIdcliente, int *contadorIdpedido)

{
    int i=0;

    (*contadorIdcliente)++;
    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    //arrayCliente[i].tipo=1;
    strcpy(arrayCliente[i].nombre,"Telefonica");
    strcpy(arrayCliente[i].cuit,"30-11223344-5");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    //arrayCliente[i].tipo=1;
    strcpy(arrayCliente[i].nombre,"DATASOFT");
    strcpy(arrayCliente[i].cuit,"30-44556677-6");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    (*contadorIdcliente)++;
    i++;


    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    //arrayCliente[i].tipo=1;
    strcpy(arrayCliente[i].nombre,"NESTLE");
    strcpy(arrayCliente[i].cuit,"30-11223344-5");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    //arrayCliente[i].tipo=1;
    strcpy(arrayCliente[i].nombre,"Telefonica");
    strcpy(arrayCliente[i].cuit,"30-11223344-5");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    //arrayCliente[i].tipo=1;
    strcpy(arrayCliente[i].nombre,"Telefonica");
    strcpy(arrayCliente[i].cuit,"30-11223344-5");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    //arrayCliente[i].tipo=1;
    strcpy(arrayCliente[i].nombre,"Telefonica");
    strcpy(arrayCliente[i].cuit,"30-11223344-5");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");


    i=0;
    //PEDIDO

/*

    (*contadorIdpedido)++;
    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    //arrayCliente[i].tipo=1;
    strcpy(arrayPedido[i].nombre,"Telefonica");
    strcpy(arrayPedido[i].cuit,"30-11223344-5");
    strcpy(arrayPedido[i].localidad,"CABA");
    strcpy(arrayPedido[i].direccion,"Corrientes");
    (*contadorIdpedido)++;
    i++;



    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    //arrayCliente[i].tipo=1;
    strcpy(arrayPedido[i].nombre,"Telefonica");
    strcpy(arrayPedido[i].cuit,"30-11223344-5");
    strcpy(arrayPedido[i].localidad,"CABA");
    strcpy(arrayPedido[i].direccion,"Corrientes");
    (*contadorIdpedido)++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    //arrayCliente[i].tipo=1;
    strcpy(arrayPedido[i].nombre,"Telefonica");
    strcpy(arrayPedido[i].cuit,"30-11223344-5");
    strcpy(arrayPedido[i].localidad,"CABA");
    strcpy(arrayPedido[i].direccion,"Corrientes");
    (*contadorIdpedido)++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    //arrayCliente[i].tipo=1;
    strcpy(arrayPedido[i].nombre,"Telefonica");
    strcpy(arrayPedido[i].cuit,"30-11223344-5");
    strcpy(arrayPedido[i].localidad,"CABA");
    strcpy(arrayPedido[i].direccion,"Corrientes");
    (*contadorIdpedido)++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    //arrayCliente[i].tipo=1;
    strcpy(arrayPedido[i].nombre,"Telefonica");
    strcpy(arrayPedido[i].cuit,"30-11223344-5");
    strcpy(arrayPedido[i].localidad,"CABA");
    strcpy(arrayPedido[i].direccion,"Corrientes");
    (*contadorIdpedido)++;

    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    //arrayCliente[i].tipo=1;
    strcpy(arrayPedido[i].nombre,"Telefonica");
    strcpy(arrayPedido[i].cuit,"30-11223344-5");
    strcpy(arrayPedido[i].localidad,"CABA");
    strcpy(arrayPedido[i].direccion,"Corrientes");

*/
       return 0;
}
