#include "pedido.h"
#include "cliente.h"

void menu(Cliente arrayCliente[],Pedido arrayPedido[],int sizeCli,int sizePed);
int imprimir_clientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int imprimir_pendientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int imprimir_procesados(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
int informe_cliente_pedientes(Cliente arrayCliente[],Pedido arrayPedido[], int sizeCli, int sizePed);
