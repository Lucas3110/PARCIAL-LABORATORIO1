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

//cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[],int *contadorIdcliente,int *contadorIdpedido);

int main()
{

    int opcion;
    int contadorIdcliente=0;
    int contadorIdpedido=0;
    char opcionB;


    Cliente arrayCliente[QTY_ARRAY_CLI];
    cliente_inicializar(arrayCliente,QTY_ARRAY_CLI);

    Pedido arrayPedido[QTY_ARRAY_CLI];
    pedido_inicializar(arrayPedido,QTY_ARRAY_PED);

    //cargarDatos(arrayCliente,arrayPedido, &contadorIdcliente, &contadorIdpedido);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta de cliente \n2) Modificar datos de cliente \n3) Baja de cliente"
                           "\n4) Crear pedido de recoleccion \n5) Procesar residuos \n6) Imprimir clientes"
                           "\n7) Imprimir pedidos pendientes \n8) Imprimir pedidos procesados \n9) informes \n11) Salir\n",                   //cambiar
                           "\nError",1,sizeof(int),1,11,2,&opcion);
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
          case 9://Informes
                system("cls");
                   do
                    {
                        if(utn_getLetra("\n\nInformes:\nA) Cliente con mas pedidos pendientes"
                                        "\nB) Cliente con mas pedidos completados\nC)"
                                        "Cliente con mas pedidos\nD) Cliente que reciclo"
                                        "mas kilos\nE) Cliente que reciclo menos kilos"
                                        "\nF) Cantidad de clientes que reciclaron mas de 1000 kilos"
                                        "\nG) Cantidad de clientes que reciclaron menos de 100 kilos\nH)"
                                        " Imprimir pedidos completados\nI) Cant kil PP promedio por cliente"
                                        " \nJ) Ingresar cuit e informar cant total tipo\nK) Volver\n","\nError",1,&opcionB)!=0)
                            opcionB='K';   //Salir
                        else
                        {
                            switch(opcionB)
                            {
                                case 'A':

                                    break;

                                case 'B':


                                case 'C':

                                    break;

                                case 'D':

                                    break;

                                case 'E':

                                    break;

                                case 'F':
                                    break;

                                case 'G':

                                    break;

                                case 'H':

                                    break;

                                case 'K'://Salir
                                    break;
                                default:
                                    printf("\nOpcion no valida");
                            }
                        }
                    }while(opcionB!='K');
                   //saque break

                case 11:
                    break;

                default:
                    printf("\nOpcion no valida");
            }
             printf("\n");
             system("pause");
             system("cls");


    }while(opcion!=11);

        return 0;


}
/*

int cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[], int *contadorIdcliente, int *contadorIdpedido)

{
    int i=0;

    (*contadorIdcliente)++;
    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"Telefonica");
    strcpy(arrayCliente[i].cuit,"30-11223344-5");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"DATASOFT");
    strcpy(arrayCliente[i].cuit,"30-44556677-6");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    (*contadorIdcliente)++;
    i++;


    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"NESTLE");
    strcpy(arrayCliente[i].cuit,"30-88995521-9");
    strcpy(arrayCliente[i].localidad,"LANUS");
    strcpy(arrayCliente[i].direccion,"cucha");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"TERRABUSI");
    strcpy(arrayCliente[i].cuit,"30-56781423-5");
    strcpy(arrayCliente[i].localidad,"QUILMES");
    strcpy(arrayCliente[i].direccion,"rocha");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"DIA");
    strcpy(arrayCliente[i].cuit,"31-54581253-3");
    strcpy(arrayCliente[i].localidad,"AVELLANEDA");
    strcpy(arrayCliente[i].direccion,"Mitre 750");
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"QUILMES");
    strcpy(arrayCliente[i].cuit,"30-51485759-6");
    strcpy(arrayCliente[i].localidad,"QUILMES");
    strcpy(arrayCliente[i].direccion,"rocha 741");


    i=0;
    //PEDIDO



    (*contadorIdpedido)++;
    arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=1;
    arrayPedido[i].estado=1;
    arrayPedido[i].kilo=1000;
    arrayPedido[i].kilHDPE=200;
    arrayPedido[i].kilLDPE=145;
    arrayPedido[i].kilPP=230;
    (*contadorIdpedido)++;
    i++;



     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=1;
    arrayPedido[i].estado=1;
    arrayPedido[i].kilo=800;
    arrayPedido[i].kilHDPE=210;
    arrayPedido[i].kilLDPE=45;
    arrayPedido[i].kilPP=30;
    (*contadorIdpedido)++;
    i++;


   arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=2;
    arrayPedido[i].estado=0;
    arrayPedido[i].kilo=100;
    arrayPedido[i].kilHDPE=200;
    arrayPedido[i].kilLDPE=145;
    arrayPedido[i].kilPP=230;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=2;
    arrayPedido[i].estado=0;
    arrayPedido[i].kilo=100;
    arrayPedido[i].kilHDPE=200;
    arrayPedido[i].kilLDPE=145;
    arrayPedido[i].kilPP=230;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=3;
    arrayPedido[i].estado=1;
    arrayPedido[i].kilo=1500;
    arrayPedido[i].kilHDPE=500;
    arrayPedido[i].kilLDPE=150;
    arrayPedido[i].kilPP=270;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=1;
    arrayPedido[i].estado=1;
    arrayPedido[i].kilo=1500;
    arrayPedido[i].kilHDPE=500;
    arrayPedido[i].kilLDPE=150;
    arrayPedido[i].kilPP=270;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=1;
    arrayPedido[i].estado=1;
    arrayPedido[i].kilo=750;
    arrayPedido[i].kilHDPE=100;
    arrayPedido[i].kilLDPE=50;
    arrayPedido[i].kilPP=70;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=1;
    arrayPedido[i].estado=0;
    arrayPedido[i].kilo=1000;
    arrayPedido[i].kilHDPE=200;
    arrayPedido[i].kilLDPE=145;
    arrayPedido[i].kilPP=230;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=1;
    arrayPedido[i].estado=0;
    arrayPedido[i].kilo=1000;
    arrayPedido[i].kilHDPE=200;
    arrayPedido[i].kilLDPE=145;
    arrayPedido[i].kilPP=230;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=1;
    arrayPedido[i].estado=1;
    arrayPedido[i].kilo=1000;
    arrayPedido[i].kilHDPE=200;
    arrayPedido[i].kilLDPE=145;
    arrayPedido[i].kilPP=230;





       return 0;
}
*/
