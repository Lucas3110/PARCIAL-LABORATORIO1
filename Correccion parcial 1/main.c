#include "cliente.h"
#include "pedido.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int primerParcial(void);


int main(void)
{
	primerParcial();
}

int primerParcial(void)
	{
		int opcion;
		int reintentos = 3;
		int idClie = 0,idPedi = 0, flag1 = 0, flag2 = 0;
		Cliente listaCliente[CANT_CLIENTE];
		Pedidos listaPedidos[CANT_PEDIDO];
		cliente_Inicializar(listaCliente,CANT_CLIENTE);
		pedidos_Inicializar(listaPedidos,CANT_PEDIDO);
		imprimeMenu();
		do
		{

			scanf("%d",&opcion);
			switch(opcion)
			{
				case 1:
					cliente_alta(listaCliente,CANT_CLIENTE,&idClie);
					flag1++;
					imprimeMenu();
					break;

				case 2:
					if(flag1<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						cliente_modificar(listaCliente, CANT_CLIENTE,idClie);
						imprimeMenu();
					}
					break;

				case 3:
					if(flag1<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						cliente_baja(listaCliente,listaPedidos,idClie,&flag1);
						printf("\nBaja correcta");
						imprimeMenu();
					}
					break;

				case 4:
					if(flag1<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						cliente_listar(listaCliente,CANT_CLIENTE);
						pedidos_alta(listaPedidos,CANT_PEDIDO,&idPedi,idClie);
						flag2++;
						imprimeMenu();
					}
					break;

				case 5:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						pedidos_listar(listaPedidos,CANT_PEDIDO);
						pedidos_procesar(listaPedidos,CANT_PEDIDO,idPedi);
						imprimeMenu();
					}
					break;

				case 6:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						imprimir_clientes(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
						imprimeMenu();
					}
					break;

				case 7:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						imprimir_pendientes(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
						imprimeMenu();
					}
					break;

				case 8:
					if(flag1<1 || flag2<1)
					{
						printf("\nNo hay datos cargados");
						imprimeMenu();
					}
					else
					{
						imprimir_procesados(listaCliente,listaPedidos,CANT_CLIENTE,CANT_PEDIDO);
						imprimeMenu();
					}
					break;

				case 9:
					printf("Hasta pronto!");
					break;
				default:
					reintentos--;
					printf("Opcion incorrecta, cantidad de reintentos: %d \n",reintentos);
					imprimeMenu();
					break;
				}

			}while(opcion != 11 && reintentos > 1);
			if(reintentos <= 1)
			{
				printf("Cantidad de reintentos agotada\n");
			}
				return 0;
	}
