#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedido.h"
#include "listar.h"
#define QTY_ARRAY_CLI 100
#define QTY_ARRAY_PED 100


int cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[],int *contadorIdcliente,int *contadorIdpedido);

int main()
{
    Cliente arrayCliente[QTY_ARRAY_CLI];
    cliente_inicializar(arrayCliente,QTY_ARRAY_CLI);

    Pedido arrayPedido[QTY_ARRAY_CLI];
    pedido_inicializar(arrayPedido,QTY_ARRAY_PED);

    menu(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);

        return 0;
}


