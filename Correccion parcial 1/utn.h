#ifndef INPUTS_H_
#define INPUTS_H_
#include "pedido.h"
#include "cliente.h"



int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
//pide al usuario que ingrese un texto

int utn_getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
//pide al usuario que ingrese un nombre

int utn_getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
//pide al usuario que ingrese un numero

//int utn_getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input);

int utn_getFloat(float *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
//pide al usuario que ingrese un numero float

//int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input);

//int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);

int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input);
//pide al usuario que ingrese un cuit/cuil

//int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);

//int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);

//int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);

int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
//pide al usuario que ingrese un caracter

int isValidName(char* stringRecibido);
//valida que el usuario haya ingresado un nombre

int isValidNumber(char* stringRecibido,int limite);
//valida que el usuario haya ingresado un numero

//int isValidSignedNumber(char* stringRecibido);

int isValidFloatNumber(char* stringRecibido,int limite);
//valida que el usuario haya ingresado un numero float

//int isValidTelephone(char* stringRecibido);

//int isValidDNI(char* stringRecibido);

int isValidCUIT(char* stringRecibido);
//valida que el usuario haya ingresado un cuit/cuil

//int isValidEmail(char* stringRecibido);

//int isValidTexto(char* stringRecibido);

//int isValidAlphanumeric(char* stringRecibido);

int isValidChar(char charRecibido);
//valida que el usuario haya ingresado un caracter


int imprimir_clientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime los clientes y la cantidad de pedidos pendientes de cada uno

int imprimir_pendientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime unicamente los pedidos pendientes con cuil de cliente,direccion de cliente, y cantidad de kilos a recolectar

int imprimir_procesados(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray);
//imprime unicamente los pedidos completados con cuil de cliente,direccion de cliente, y cantidad de kilos de cada tipo de plastico reciclado



#endif
