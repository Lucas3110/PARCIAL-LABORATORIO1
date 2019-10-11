#ifndef RESIDUO_H_INCLUDED
#define RESIDUO_H_INCLUDED

#define TEXT_SIZEA 20
#define TEXT_SIZEB 15
#define TEXT_SIZEC 40

typedef struct
{
    int idResiduo;
    int isEmpty;
    //-----------------
    int idPedido;
    int tipo; //3 plasticos
    int estado;
    float kilo;


}Residuo;


#endif // RESIDUO_H_INCLUDED

int residuo_inicializar(Residuo array[], int size);                                    //cambiar residuo
int residuo_buscarEmpty(Residuo array[], int size, int* posicion);                    //cambiar residuo
int residuo_buscarID(Residuo array[], int size, int valorBuscado, int* posicion);                    //cambiar residuo
int residuo_buscarInt(Residuo array[], int size, int valorBuscado, int* posicion);                    //cambiar residuo
int residuo_buscarString(Residuo array[], int size, char* valorBuscado, int* indice);                    //cambiar residuo
int residuo_alta(Residuo array[], int size, int* contadorID);                          //cambiar residuo
int residuo_baja(Residuo array[], int sizeArray);                                      //cambiar residuo
int residuo_bajaValorRepetidoInt(Residuo array[], int sizeArray, int valorBuscado);
int residuo_modificar(Residuo array[], int sizeArray);                                //cambiar residuo
int residuo_ordenarPorDobleCriterio(Residuo array[],int size, int orderFirst, int orderSecond);                                  //cambiar residuo
int residuo_listar(Residuo array[], int size);                      //cambiar residuo
