#ifndef PEDIDO_H_
#define PEDIDO_H_

#define TEXT_SIZE 20
#define CANT_PEDIDO 1000

#include "Cliente.h"

typedef struct
{
    int idPedido;
    int isEmpty;
    int idCliente;
    float cantKilos;
    int estado; //0-pendiente/1-completado
    int kilosHDPE;
    int kilosLDPE;
    int kilosPP;

}Pedidos;

int pedidos_Inicializar(Pedidos array[], int size);
//inicializa el array de Pedidos

int pedidos_buscarEmpty(Pedidos array[], int size, int* posicion);
//busca la primera posicion vacia que encuentre en el array Pedidos

int pedidos_buscarID(Pedidos array[], int size, int valorBuscado, int* posicion);
//busca el ID de un pedido en el array y devuelve la posicion

int pedidos_alta(Pedidos array[], int size, int* contadorID, int contadorCliente);
//da de alta un pedido y se le asigna un ID

int pedidos_procesar(Pedidos array[], int sizeArray, int contadorID);
//se imprimen los pedidos pendientes por pantalla y se ingresan en kilos la cantidad de plastico reciclado de los 3 tipos diferentes. El resto es deshechado

int pedidos_listar(Pedidos array[], int size);
//imprime un listado del array de Pedidos

#endif /* PEDIDO_H_ */
