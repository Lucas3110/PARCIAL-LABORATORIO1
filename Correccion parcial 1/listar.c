#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedido.h"
#include "cliente.h"
#include "listar.h"
#define QTY_ARRAY_CLI 100
#define QTY_ARRAY_PED 100


/** \brief Funcion que muestra un menu principal con las opciones del programa y llama al resto de las funciones
 * \param Cliente arayCliente[] Cliente Estructura que se le pasa al resto de las funciones
 * \param Pedido arrayPedido[] Pedido Estructura que se le pasa al resto de las funciones
 * \param sizeCli int Tamaño de la estructura Cliente
 * \param sizePed int Tamaño de la estructura Pedido
 * \return void
 *
 */


void menu(Cliente arrayCliente[],Pedido arrayPedido[],int sizeCli,int sizePed)
{
    int opcion;
    int contadorIdcliente=0;
    int contadorIdpedido=0;
    int flagCli = 1; //lo dejo en 1 por el hardcodeo de datos
    int flagPed = 1;
    char opcionB;

    cliente_inicializar(arrayCliente,QTY_ARRAY_CLI);
    pedido_inicializar(arrayPedido,QTY_ARRAY_PED);
    cargarDatos(arrayCliente, arrayPedido, &contadorIdcliente, &contadorIdpedido);


    do
    {
        utn_getUnsignedInt("\n\n1) Alta de cliente \n2) Modificar datos de cliente \n3) Baja de cliente"
                           "\n4) Crear pedido de recoleccion \n5) Procesar residuos \n6) Imprimir clientes"
                           "\n7) Imprimir pedidos pendientes \n8) Imprimir pedidos completados \n9) informes \n11) Salir\n",                   //cambiar
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
                 if(flagCli==0)
                    {
                        printf("\nTodavia no se dio alta ningun cliente");
                    }
                    else
                    {
                        cliente_listar(arrayCliente,QTY_ARRAY_CLI);
                        if(!cliente_modificar(arrayCliente,QTY_ARRAY_CLI));
                        {
                             printf("\n----Se modifico exitosamente----\n");
                        }
                   }

                break;

            case 3: //Baja
                system("cls");
                 if(flagCli==0)
                    {
                        printf("\nTodavia no se dio alta ningun cliente");
                    }
                    else
                    {
                        if(!cliente_baja(arrayCliente,QTY_ARRAY_CLI));
                        {
                            printf("\n----Se dio de BAJA exitosamente!----\n");
                        }
                    }
                break;

            case 4: //Alta PEDIDO
                system("cls");
                 if(flagCli==0)
                    {
                        printf("\nTodavia no se dio alta ningun cliente");
                    }
                    else
                    {
                        cliente_listar(arrayCliente,QTY_ARRAY_CLI);
                        printf("\n");

                        if(!pedido_alta(arrayPedido,QTY_ARRAY_PED,&contadorIdpedido));                   //cambiar
                        {   flagPed=1;
                            printf("\n----Se dio de ALTA exitosamente!----\n");
                        }
                    }
                break;
            case 5://alta residuo
                system("cls");
                 if(flagPed==0)
                    {
                        printf("\nTodavia no se dio alta ningun pedido");
                    }
                        else
                        {
                            pedido_alta2(arrayPedido,QTY_ARRAY_PED);
                        }
                break;

            case 6://Listar
                system("cls");
                if(flagPed==0 && flagCli == 0)
                    {
                        printf("\nTodavia no se dio alta ningun pedido o cliente");
                    }
                     else
                        {
                           imprimir_clientes(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                        }
                break;

            case 7://Listar
                system("cls");
                if(flagPed==0 && flagCli == 0)
                    {
                        printf("\nTodavia no se dio alta ningun pedido o cliente");
                    }
                     else
                        {
                            imprimir_pendientes(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                        }
                break;


            case 8 ://Listar
                system("cls");
                if(flagPed==0 && flagCli == 0)
                    {
                        printf("\nTodavia no se dio alta ningun pedido o cliente");
                    }
                     else
                        {
                            imprimir_procesados(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);

                        }
                break;


          case 9://Informes
                system("cls");
                if(flagPed==0 && flagCli == 0)
                    {
                        printf("\nTodavia no se dio alta ningun pedido o cliente");
                    }
                     else
                        {
                   do
                    {
                        if(utn_getLetra("\n\nInformes:\nA) Cliente con mas pedidos pendientes"
                                        "\nB) Cliente con mas pedidos completados\nC)"
                                        "Cliente con mas pedidos\nD) Cliente que reciclo"
                                        "mas kilos\nE) Cliente que reciclo menos kilos"
                                        "\nF) Cantidad de clientes que reciclaron mas de 1000 kilos"
                                        "\nG) Cantidad de clientes que reciclaron menos de 100 kilos\nH)"
                                        " Imprimir pedidos completados\nI) Pedidos pendientes por localidad"
                                        " \nJ) Promedio de PP \nK) Ingresar cuit e informar cant total tipo\n"
                                        "L) Volver\n","\nError",1,&opcionB)!=0)
                            opcionB='K';   //Salir
                        else
                        {
                            switch(opcionB)
                            {
                                case 'A':
                                    system("cls");
                                    listar_cliente_pendientes(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'B':
                                system("cls");
                                listar_cliente_completados(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                 break;

                                case 'C':
                                    system("cls");
                                listar_cliente_pedidos(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'D':
                                    system("cls");
                                listar_cliente_maxReciclado(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'E':
                                    system("cls");
                                listar_cliente_minReciclado(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'F':
                                    system("cls");
                                listar_cliente_masDeMil(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'G':
                                    system("cls");
                                listar_cliente_menosDeCien(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'H':
                                    system("cls");
                                listar_procesados_porcentaje(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'I':
                                    system("cls");
                               localidad_pendientes(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'J':
                                    system("cls");
                               listar_cliente_pp_promedio(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;

                                case 'K':
                                    system("cls");
                               listar_tipo_plastico(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);
                                    break;


                                case 'L'://Salir
                                    break;
                                default:
                                    printf("\nOpcion no valida");
                            }
                        }
                    }while(opcionB!='L');
                   //saque break
                }
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


























/////////// INFORMES



/** \brief Lista los elementos de dos arrays vinculados
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/


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
    	            	printf( "\n ID: %d\n Cuit: %s\n Nombre: %s\n Localidad: %s\n Calle: %s\n Altura: %d",
								arrayCliente[i].idCli,arrayCliente[i].cuit,arrayCliente[i].nombre,arrayCliente[i].localidad,
								arrayCliente[i].direccion,arrayCliente[i].altura);
    	            	for(posicion=0;posicion<sizePed;posicion++)
    	            	{
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
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



/** \brief Lista los elementos de dos arrays vinculados
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

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
    					if(arrayPedido[i].idCli == arrayCliente[posicion].idCli	&& arrayCliente[posicion].isEmpty == 0
								&& arrayCliente[posicion].idCli > 0)
    					{
    						printf( "\n ID: %d\n Cuit: %s\n Calle: %s\n Altura: %d\n Kilos a recolectar: %.2f\n Estado: Pendiente",
									arrayPedido[i].idPed,arrayCliente[posicion].cuit,arrayCliente[posicion].direccion,
    		               		    arrayCliente[posicion].altura,arrayPedido[i].kilo);
    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}


/** \brief Lista los elementos de dos arrays vinculados
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

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
    					if(arrayPedido[i].idCli == arrayCliente[posicion].idCli	&& arrayCliente[posicion].isEmpty == 0
								&& arrayCliente[posicion].idCli > 0)
    					{
    						printf( "\n ID: %d\n Cuit: %s\n Calle: %s\n Altura: %d\n Kilos de HDPE: %.2f\n Kilos de LDPE: %.2f"
    								"\n Kilos de PP: %.2f\n Estado: Completado",
									arrayPedido[i].idPed,arrayCliente[posicion].cuit,arrayCliente[posicion].direccion,
    		               		    arrayCliente[posicion].altura,arrayPedido[i].kilHDPE,arrayPedido[i].kilLDPE,arrayPedido[i].kilPP);
    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}


/** \brief Lista los clientes con mas pedidos pendientes
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_cliente_pendientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
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
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
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

    	printf("\nCliente con mas pedidos pendientes: %s\nCantidad de de pedidos pendientes: %d",
    			arrayCliente[posPendMax].nombre,pedidosPendMax);
        retorno=0;
    }

    return retorno;
}


/** \brief Lista los clientes con mas pedidos completados
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_cliente_completados(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int pedidosProc = 0;
    int pedidosProcMax = 0;
    int posicion;
    int i;
    int posProcMax;
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
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==1)
    	            		{
    	            			pedidosProc++;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		pedidosProcMax = pedidosProc;
    	            		posProcMax = i;
    	            		flag++;
    	            	}

    	            	if(pedidosProc>pedidosProcMax)
    	            	{
    	            		pedidosProcMax = pedidosProc;
    	            		posProcMax = i;
    	            	}

    	            	pedidosProc=0;

    	            }

    	        }

    	printf("\nCliente con mas pedidos procesados: %s\nCantidad de de pedidos completados: %d",
    			arrayCliente[posProcMax].nombre,pedidosProcMax);
        retorno=0;
    }

    return retorno;
}



/** \brief Lista los clientes con mas pedidos
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_cliente_pedidos(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int pedidos = 0;
    int pedidosMax = 0;
    int posicion;
    int i;
    int posMax;
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
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
								&& (arrayPedido[posicion].estado==1 || arrayPedido[posicion].estado==0))
    	            		{
    	            			pedidos++;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		pedidosMax = pedidos;
    	            		posMax = i;
    	            		flag++;
    	            	}

    	            	if(pedidos>pedidosMax)
    	            	{
    	            		pedidosMax = pedidos;
    	            		posMax = i;
    	            	}

    	            	pedidos=0;

    	            }

    	        }

    	printf("\nCliente con mas pedidos: %s\nCantidad de pedidos: %d",
    			arrayCliente[posMax].nombre,pedidosMax);
        retorno=0;
    }
    return retorno;
}


/** \brief Lista el cliente que reciclo mas kilos
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_cliente_maxReciclado(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int kilosRecic = 0;
    int kilosRecicMax = 0;
    int posicion;
    int i;
    int posMax;
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
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==1)
    	            		{
    	            			kilosRecic=0;
    	            			kilosRecic = kilosRecic + arrayPedido[posicion].kilHDPE
    	            									+ arrayPedido[posicion].kilLDPE
														+ arrayPedido[posicion].kilPP;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		kilosRecicMax = kilosRecic;
    	            		posMax = i;
    	            		flag++;
    	            	}

    	            	if(kilosRecic>kilosRecicMax)
    	            	{
    	            		kilosRecicMax = kilosRecic;
    	            		posMax = i;
    	            	}

    	            }

    	        }

    	printf("\nCliente que mas reciclo: %s\nCantidad de kilos: %d",
    			arrayCliente[posMax].nombre,kilosRecicMax);
        retorno=0;
    }

    return retorno;
}

/** \brief Lista el cliente que reciclo menos kilos
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_cliente_minReciclado(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int kilosRecic = 0;
    int kilosRecicMin = 0;
    int posicion;
    int i;
    int posMin;
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
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==1)
    	            		{
    	            			kilosRecic = 0;
    	            			kilosRecic = kilosRecic + arrayPedido[posicion].kilHDPE
    	            									+ arrayPedido[posicion].kilLDPE
														+ arrayPedido[posicion].kilPP;
    	            		}
    	            	}

    	            	if(flag==0)
    	            	{
    	            		kilosRecicMin = kilosRecic;
    	            		posMin = i;
    	            		flag++;
    	            	}

    	            	if(kilosRecic<kilosRecicMin)
    	            	{
    	            		kilosRecicMin = kilosRecic;
    	            		posMin = i;
    	            	}


    	            }

    	        }

    	printf("\nCliente que menos reciclo: %s\nCantidad de kilos: %d",
    			arrayCliente[posMin].nombre,kilosRecicMin);
        retorno=0;
    }

    return retorno;
}


/** \brief Lista los clientes que reciclaron mas de 1000 kilos
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/


int listar_cliente_masDeMil(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int kilosRecic = 0;
    int cantCliente = 0;
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
    	            	for(posicion=0;posicion<sizePed;posicion++)
    	            	{
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==1)
    	            		{
    	            			kilosRecic=0;
    	            			kilosRecic = kilosRecic + arrayPedido[posicion].kilHDPE
    	            									+ arrayPedido[posicion].kilLDPE
														+ arrayPedido[posicion].kilPP;
    	            		}
    	            	}

    	            	if(kilosRecic>1000)
    	            	{
    	            		cantCliente++;
    	            	}

    	            }

    	        }

    	printf("\nCantidad de clientes que reciclaron mas de 1000: %d",cantCliente);
        retorno=0;
    }

    return retorno;
}


/** \brief Lista los clientes que reciclaron menos de 100 kilos
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/


int listar_cliente_menosDeCien(Cliente arrayCli[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int kilosRecic=0;
    int cantCliente = 0;
    int posicion;
    int i;

    if(arrayCli!=NULL && sizeCli>0)
    {
    	for(i=0;i<sizeCli;i++)
    	    {
    			if(arrayCli[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else if(arrayCli[i].isEmpty==0 && arrayCli[i].idCli > 0)
    	            {
    	            	for(posicion=0;posicion<sizePed;posicion++)
    	            	{
    	            		if(arrayCli[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==1)
    	            		{
    	            			kilosRecic = 0;
    	            			kilosRecic = kilosRecic + arrayPedido[posicion].kilHDPE
    	            									+ arrayPedido[posicion].kilLDPE
														+ arrayPedido[posicion].kilPP;
    	            		}
    	            	}

    	            	if(kilosRecic<100)
    	            	{
    	            		cantCliente++;
    	            		kilosRecic=100;
    	            	}

    	            }

    	        }

    	printf("\nCantidad de clientes que reciclaron menos de 100: %d",cantCliente);
        retorno=0;
    }

    return retorno;
}


/** \brief Lista los pedidos completados con % de kilos reciclados
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int listar_procesados_porcentaje(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int posicion;
    int i;
    float porcentaje;
    float acumulador;

    if(arrayPedido!=NULL && sizePed>0)
    {
    	for(i=0;i<sizePed;i++)
    	    {
    			if(arrayPedido[i].isEmpty==0 && arrayPedido[i].estado == 1)
    	          {
    				for(posicion=0;posicion<sizeCli;posicion++)
    				{
    					if(arrayPedido[i].idCli == arrayCliente[posicion].idCli	&& arrayCliente[posicion].isEmpty == 0
								&& arrayCliente[posicion].idCli > 0)
    					{
    						printf( "\n ID: %d\n Cuit: %s",arrayPedido[i].idPed,arrayCliente[posicion].cuit);
    						acumulador = 0;
    						porcentaje = 0;

							acumulador = acumulador +
										arrayPedido[i].kilHDPE +
										arrayPedido[i].kilLDPE +
										arrayPedido[i].kilPP;
							porcentaje = acumulador / arrayPedido[i].kilo;
							porcentaje = porcentaje * 100;
							printf("Porcentaje de plastico reciclado: %.2f",porcentaje);


    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}


/** \brief Lista la cantidad de pedidos pendientes para la localidad indicada
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/

int localidad_pendientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int posicion;
    int cantPedidos = 0;
    char localidad2[20];

    if(arrayCliente!=NULL && sizeCli>0)
    {
    	getString("\nIngrese localidad2: ","\nError",1,20,2,localidad2);
    	for(int i=0;i<sizeCli;i++)
    	{
    	    if(arrayCliente[i].isEmpty==0 && strcmp(arrayCliente[i].localidad,localidad2)==0)
    	    {
    	    	for(posicion=0;posicion<sizePed;posicion++)
    	    	{
    	    		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty == 0
							&& arrayPedido[posicion].estado == 0)
    	    		{
    	    			cantPedidos++;
    	    		}
    	    	}

    	    }
    	}
    	printf("\nLocalidad: %s\nPedidos pendientes: %d",
  				localidad2,cantPedidos);
      	retorno=0;
    }
    return retorno;
}
/** \brief Lista la cantidad de kilos PP reciclados promedio por cliente
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int listar_cliente_pp_promedio(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    float kilosRecic = 0;
    float cantClientes = 0;
    float promedio = 0;
    int posicion;
    int i;
    int idAnterior = 0;

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
    	            		if(arrayCliente[i].idCli == arrayPedido[posicion].idCli	&& arrayPedido[posicion].isEmpty==0
								&& arrayPedido[posicion].estado==1)
    	            		{
    	            			if(idAnterior!=arrayPedido[posicion].idCli)
    	            			{
    	            				idAnterior = arrayPedido[posicion].idCli;
    	            				cantClientes++;
    	            			}
    	            			kilosRecic = kilosRecic + arrayPedido[posicion].kilPP;
    	            		}

    	            	}

    	            	promedio = kilosRecic/cantClientes;

    	            }

    	        }

    	printf("\nPromedio de kilos de PP por cliente: %.2f",
    			promedio);
        retorno=0;
    }

    return retorno;
}
/** \brief Lista la cantidad de kilos tipo que se indique luego de ingresar un cuit cliente
* \param arrayA Cliente Array de Cliente
* \param arrayB Pedido Array de Pedido
* \param sizeCli int Tamaño del arrayA
* \param sizePed int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int listar_tipo_plastico(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed)
{
    int retorno=-1;
    int kilosRecic = 0;
    int i;
    int h;
    int l;
    int p;
    char cuitA[14];
    char opcion;

    if(arrayCliente!=NULL && sizeCli>0)
    {
    	utn_getCUIT("\nIngrese cuit: ","\nError",2,cuitA);
    	for(i=0;i<sizeCli;i++)
    	{
    	    if(arrayCliente[i].isEmpty==0 && strcmp(arrayCliente[i].cuit,cuitA)==0)
    	    {
    	    	utn_getChar("\nIngrese tipo: _HDPE(A) _LDPE(B) _PP(C)","\nError",'A','C',2,&opcion);
    	    	switch(opcion)
    	    	{
    	    	case 'A':
    	    		for(h=0;h<sizePed;h++)
    	    		{
       	    			if(arrayCliente[i].idCli == arrayPedido[h].idCli && arrayPedido[h].isEmpty == 0	&& arrayPedido[h].estado == 1)
    	    		    {
       	    				kilosRecic = kilosRecic + arrayPedido[h].kilHDPE;
    	    		    }
    	    		}
    	    		printf("\nKilos reciclados de HDPE: %d",kilosRecic);
    	    		break;

    	    	case 'B':
    	    		for(l=0;l<sizePed;l++)
    	       		{
    	      			if(arrayCliente[i].idCli == arrayPedido[l].idCli && arrayPedido[l].isEmpty == 0	&& arrayPedido[l].estado == 1)
    	    		    {
    	    		    	kilosRecic = kilosRecic + arrayPedido[l].kilLDPE;
    	    		    }
    	       		}
    	       		printf("\nKilos reciclados de LDPE: %d",kilosRecic);
    	    	    break;

    	    	case 'C':
    	    		for(p=0;p<sizePed;p++)
    	      		{
    	       			if(arrayCliente[i].idCli == arrayPedido[p].idCli && arrayPedido[p].isEmpty == 0	&& arrayPedido[p].estado == 1)
    	       		    {
    	       				kilosRecic = kilosRecic + arrayPedido[p].kilPP;
    	       		    }
    	       		}
    	       		printf("\nKilos reciclados de PP: %d",kilosRecic);
    	    	    break;

    	    	default:
    	    		printf("\nOpcion invalida");
    	    		break;
    	    	}
    		}
        	retorno=0;
    	}
    }
    return retorno;
}




































//CARGA DATOS



int cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[], int *contadorIdcliente, int *contadorIdpedido)

{
    int i=0;

    (*contadorIdcliente)++;
    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"Telefonica");
    strcpy(arrayCliente[i].cuit,"30-11223344-5");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Lima");
    arrayCliente[i].altura=1234;
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"DATASOFT");
    strcpy(arrayCliente[i].cuit,"30-44556677-6");
    strcpy(arrayCliente[i].localidad,"CABA");
    strcpy(arrayCliente[i].direccion,"Corrientes");
    arrayCliente[i].altura=2547;
    (*contadorIdcliente)++;
    i++;


    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"NESTLE");
    strcpy(arrayCliente[i].cuit,"30-88995521-9");
    strcpy(arrayCliente[i].localidad,"LANUS");
    strcpy(arrayCliente[i].direccion,"cucha");
    arrayCliente[i].altura=555;
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"TERRABUSI");
    strcpy(arrayCliente[i].cuit,"30-56781423-5");
    strcpy(arrayCliente[i].localidad,"QUILMES");
    strcpy(arrayCliente[i].direccion,"rocha");
    arrayCliente[i].altura=784;
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"DIA");
    strcpy(arrayCliente[i].cuit,"31-54581253-3");
    strcpy(arrayCliente[i].localidad,"AVELLANEDA");
    strcpy(arrayCliente[i].direccion,"Mitre");
    arrayCliente[i].altura=750;
    (*contadorIdcliente)++;
    i++;



    arrayCliente[i].isEmpty=0;
    arrayCliente[i].idCli=*contadorIdcliente;
    strcpy(arrayCliente[i].nombre,"QUILMES");
    strcpy(arrayCliente[i].cuit,"30-51485759-6");
    strcpy(arrayCliente[i].localidad,"QUILMES");
    strcpy(arrayCliente[i].direccion,"rocha");
    arrayCliente[i].altura=741;


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
    arrayPedido[i].kilHDPE=0;
    arrayPedido[i].kilLDPE=0;
    arrayPedido[i].kilPP=0;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=2;
    arrayPedido[i].estado=0;
    arrayPedido[i].kilo=300;
    arrayPedido[i].kilHDPE=0;
    arrayPedido[i].kilLDPE=0;
    arrayPedido[i].kilPP=0;
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
    arrayPedido[i].idCli=4;
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
    arrayPedido[i].kilo=200;
    arrayPedido[i].kilHDPE=0;
    arrayPedido[i].kilLDPE=0;
    arrayPedido[i].kilPP=0;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=5;
    arrayPedido[i].estado=1;
    arrayPedido[i].kilo=30;
    arrayPedido[i].kilHDPE=10;
    arrayPedido[i].kilLDPE=5;
    arrayPedido[i].kilPP=3;
    (*contadorIdpedido)++;
    i++;

     arrayPedido[i].isEmpty=0;
    arrayPedido[i].idPed=*contadorIdpedido;
    arrayPedido[i].idCli=6;
    arrayPedido[i].estado=0;
    arrayPedido[i].kilo=456;
    arrayPedido[i].kilHDPE=0;
    arrayPedido[i].kilLDPE=0;
    arrayPedido[i].kilPP=0;




       return 0;
}

