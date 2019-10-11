#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedido.h"
#include "residuo.h"

#define QTY_ARRAY_CLI 100
#define QTY_ARRAY_PED 1000


int main()
{

    int opcion;
    int contadorIdcliente=0;
    int flagCli=0;

    Cliente arrayCliente[QTY_ARRAY_CLI];
    cliente_inicializar(arrayCliente,QTY_ARRAY_CLI);

    Pedido arrayPedido[QTY_ARRAY_PED];
    pedido_inicializar(arrayPedido,QTY_ARRAY_PED);

    Residuo arrayResiduo[QTY_ARRAY_CLI];
    residuo_inicializar(arrayResiduo,QTY_ARRAY_CLI);

    //********************************************************************

    do
    {
        utn_getUnsignedInt("\n\n1) Alta de cliente \n2) Modificar datos de cliente \n3) Baja de cliente"
                            "\n4) Crear pedido de recoleccion \n5) Procesar residuos   \n6) Imprimir clientes "
                            " \n7) Imprimir pedidos pendientes  \n8) Imprimir pedidos procesados \n9) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,9,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta cliente
                system("cls");
                if(!cliente_alta(arrayCliente,QTY_ARRAY_CLI,&contadorIdcliente));                   //cambiar
                {   flagCli=1;
                    printf("\n----Se dio de ALTA exitosamente!----\n");
                }
                break;

            case 2: //Modificar cliente
                system("cls");
                if(flagCli==0)
                    {
                        printf("\nTodavia no se dio alta ningun cliente");
                    }
                    else
                   {
                    cliente_modificar(arrayCliente,QTY_ARRAY_CLI);
                   }

                break;

            case 3: //Baja cliente
                system("cls");
                  if(flagCli==0)
                    {
                        printf("\nTodavia no se dio alta ningun cliente");
                    }
                    else
                   {
                    cliente_baja(arrayCliente,QTY_ARRAY_CLI);
                   }

                break;

            case 6://imprimir clientes
                system("cls");
                if(flagCli==0)
                    {
                        printf("\nTodavia no se dio alta ningun cliente");
                    }
                    else
                   {
                    cliente_listar(arrayCliente,QTY_ARRAY_CLI);
                   }
                break;

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


