#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

#define TEXT_SIZEA 20
#define TEXT_SIZEB 15
#define TEXT_SIZEC 40

typedef struct
{
    int idPed;
    int isEmpty;

    int idCli;
    int estado; //0 pendiente 1 completado
    float kilo;
    float kilHDPE;
    float kilLDPE;
    float kilPP;


}Pedido;


#endif // PEDIDO_H_INCLUDED

int pedido_inicializar(Pedido array[], int size);                                    //cambiar pedido
int pedido_buscarEmpty(Pedido array[], int size, int* posicion);                    //cambiar pedido
int pedido_buscarID(Pedido array[], int size, int valorBuscado, int* posicion);                    //cambiar pedido
int pedido_buscarInt(Pedido array[], int size, int valorBuscado, int* posicion);                    //cambiar pedido
int pedido_buscarString(Pedido array[], int size, char* valorBuscado, int* indice);                    //cambiar pedido
int pedido_alta(Pedido array[], int size, int* contadorID);                          //cambiar pedido
int pedido_baja(Pedido array[], int sizeArray);                                      //cambiar pedido
int pedido_bajaValorRepetidoInt(Pedido array[], int sizeArray, int valorBuscado);
int pedido_modificar(Pedido array[], int sizeArray);                                //cambiar pedido
int pedido_ordenarPorDobleCriterio(Pedido array[],int size, int orderFirst, int orderSecond);                                  //cambiar pedido
int pedido_listar(Pedido array[], int size);                      //cambiar pedido
int pedido_alta2(Pedido array[], int sizeArray);
