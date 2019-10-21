#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "pedido.h"
#include "listar.h"

#define QTY_ARRAY_CLI 100
#define QTY_ARRAY_PED 100
#define SORT_UP 1
#define SORT_DOWN 0

cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[],int *contadorIdcliente,int *contadorIdpedido);

int main()
{
    Cliente arrayCliente[QTY_ARRAY_CLI];
    cliente_inicializar(arrayCliente,QTY_ARRAY_CLI);

    Pedido arrayPedido[QTY_ARRAY_CLI];
    pedido_inicializar(arrayPedido,QTY_ARRAY_PED);

    menu(arrayCliente,arrayPedido,QTY_ARRAY_CLI,QTY_ARRAY_PED);


        return 0;


}


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
    arrayPedido[i].estado=0;
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

