#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedido.h"
#include "cliente.h"
#define QTY_ARRAY_CLI 100
#define QTY_ARRAY_PED 100

void menu(Cliente arrayCliente[],Pedido arrayPedido[],int sizeCli,int sizePed)
{
    int opcion;
    int contadorIdcliente=0;
    int contadorIdpedido=0;
    char opcionB;

    cliente_inicializar(arrayCliente,QTY_ARRAY_CLI);
    pedido_inicializar(arrayPedido,QTY_ARRAY_PED);
    cargarDatos(arrayCliente, arrayPedido, &contadorIdcliente, &contadorIdpedido);


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
                cliente_listar(arrayCliente,QTY_ARRAY_CLI);
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
               imprimir_clientes(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                break;

            case 7://Listar
                system("cls");
              imprimir_pendientes(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                break;


            case 8 ://Listar
                system("cls");
               imprimir_procesados(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                break;


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
                                    system("cls");
                                    informe_cliente_pedientes(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'B':
                                system("cls");

                                case 'C':
                                    system("cls");

                                    break;

                                case 'D':
                                    system("cls");

                                    break;

                                case 'E':
                                    system("cls");

                                    break;

                                case 'F':
                                    system("cls");
                                    break;

                                case 'G':
                                    system("cls");

                                    break;

                                case 'H':
                                    system("cls");

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

}

// INFORMES



int imprimir_clientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int pedidosPend = 0;
    int posicion;
    int i;

    if(arrayCliente!=NULL && sizeCli>0)
    {
    	for(i=0;i<sizeCli;i++)
    	    {
    			if(arrayCliente[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(arrayCliente[i].isEmpty==0 && arrayCliente[i].idCli > 0)
    	            {
    	            	printf( "\n ID: %d"
    	            	        "\n Cuit: %s"
    	            			"\n Nombre: %s"
    	            			"\n Localidad: %s"
    	                		"\n Calle: %s"
    	   	            		"\n Altura: %d",
								arrayCliente[i].idCli,
								arrayCliente[i].cuit,
								arrayCliente[i].nombre,
								arrayCliente[i].localidad,
								arrayCliente[i].direccion,
    	            		    arrayCliente[i].altura);
    	            	for(posicion=0;posicion<sizePed;posicion++)
    	            	{
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli
    	            			&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==0)
    	            		{
    	            			pedidosPend++;
    	            		}
    	            	}
    	            printf("\nCantidad de pendientes: %d",pedidosPend);
    	            pedidosPend=0;

    	            }

    	        }
    	        retorno=0;
    }
    return retorno;
}


int imprimir_pendientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int posicion;
    int i;

    if(arrayPedido!=NULL && sizePed>0)
    {
    	for(i=0;i<sizePed;i++)
    	    {
    			if(arrayPedido[i].isEmpty==0 && arrayPedido[i].estado == 0)
    	          {
    				for(posicion=0;posicion<sizeCli;posicion++)
    				{
    					if(arrayPedido[i].idCli == arrayCliente[posicion].idCli
    							&& arrayCliente[posicion].isEmpty == 0
								&& arrayCliente[posicion].idCli > 0)
    					{
    						printf( "\n ID: %d"
    						    	"\n Cuit: %s"
    						    	"\n Calle: %s"
    						    	"\n Altura: %d"
    								"\n Kilos a recolectar: %.2f"
									"\n Estado: Pendiente",
									arrayPedido[i].idPed,
    								arrayCliente[posicion].cuit,
 									arrayCliente[posicion].direccion,
    		               		    arrayCliente[posicion].altura,
									arrayPedido[i].kilo);

    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}


int imprimir_procesados(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{

    int retorno=-1;
    int posicion;
    int i;

    if(arrayPedido!=NULL && sizePed>0)
    {
    	for(i=0;i<sizePed;i++)
    	    {
    			if(arrayPedido[i].isEmpty==0 && arrayPedido[i].estado == 1)
    	          {
    				for(posicion=0;posicion<sizeCli;posicion++)
    				{
    					if(arrayPedido[i].idCli == arrayCliente[posicion].idCli
    							&& arrayCliente[posicion].isEmpty == 0
								&& arrayCliente[posicion].idCli > 0)
    					{
    						printf( "\n ID: %d"
    						    	"\n Cuit: %s"
    						    	"\n Calle: %s"
    						    	"\n Altura: %d"
    								"\n Kilos de HDPE: %.2f"
    								"\n Kilos de LDPE: %.2f"
    								"\n Kilos de PP: %.2f"
									"\n Estado: Completado",
									arrayPedido[i].idPed,
    								arrayCliente[posicion].cuit,
 									arrayCliente[posicion].direccion,
    		               		    arrayCliente[posicion].altura,
									arrayPedido[i].kilHDPE,
									arrayPedido[i].kilLDPE,
									arrayPedido[i].kilPP);

    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}


int informe_cliente_pedientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int pedidosPend = 0;
    int pedidosPendMax = 0;
    int posicion;
    int i;
    int posPendMax;
    int flag = 0;

    if(arrayCliente!=NULL && sizeCli>0)
    {
    	for(i=0;i<sizeCli;i++)
    	    {
    			if(arrayCliente[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(arrayCliente[i].isEmpty==0 && arrayCliente[i].idCli > 0)
    	            {
    	            	for(posicion=0;posicion<sizePed;posicion++)
    	            	{
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli
    	            			&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==0)
    	            		{
    	            			pedidosPend++;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		pedidosPendMax = pedidosPend;
    	            		posPendMax = i;
    	            		flag++;
    	            	}

    	            	if(pedidosPend>pedidosPendMax)
    	            	{
    	            		pedidosPendMax = pedidosPend;
    	            		posPendMax = i;
    	            	}

    	            	pedidosPend=0;

    	            }

    	        }

    	printf("\nCliente con mas pedidos pendientes: %s"
    			"\nCantidad de de pedidos pendientes: %d",
    			arrayCliente[posPendMax].nombre,
				pedidosPendMax);
        retorno=0;
    }
    return retorno;
}
