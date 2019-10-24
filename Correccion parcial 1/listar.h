#include "pedido.h"
#include "cliente.h"

void menu(Cliente arrayCliente[],Pedido arrayPedido[],int sizeCli,int sizePed);
int cargarDatos(Cliente arrayCliente[],Pedido arrayPedido[], int *contadorIdcliente, int *contadorIdpedido);


int imprimir_clientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int imprimir_pendientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int imprimir_procesados(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);


int listar_cliente_pendientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_cliente_completados(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_cliente_pedidos(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_cliente_maxReciclado(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_cliente_minReciclado(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_cliente_masDeMil(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_cliente_menosDeCien(Cliente arrayCli[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_procesados_porcentaje(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int localidad_pendientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int listar_cliente_pp_promedio(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
