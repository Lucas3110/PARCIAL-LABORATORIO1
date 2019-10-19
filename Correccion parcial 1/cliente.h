#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define TEXT_SIZEA 20
#define TEXT_SIZEB 15
#define TEXT_SIZEC 40

typedef struct
{
    int idCli;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZEA];
    char direccion[TEXT_SIZEB];
    int altura;
    char localidad[TEXT_SIZEA];
    char cuit[TEXT_SIZEA]; //USAR VALI CUIT


}Cliente;


#endif // CLIENTE_H_INCLUDED

int cliente_inicializar(Cliente array[], int size);                                    //cambiar cliente
int cliente_buscarEmpty(Cliente array[], int size, int* posicion);                    //cambiar cliente
int cliente_buscarID(Cliente array[], int size, int valorBuscado, int* posicion);                    //cambiar cliente
int cliente_buscarInt(Cliente array[], int size, int valorBuscado, int* posicion);                    //cambiar cliente
int cliente_buscarString(Cliente array[], int size, char* valorBuscado, int* indice);                    //cambiar cliente
int cliente_alta(Cliente array[], int size, int* contadorID);                          //cambiar cliente
int cliente_baja(Cliente array[], int sizeArray);                                      //cambiar cliente
int cliente_bajaValorRepetidoInt(Cliente array[], int sizeArray, int valorBuscado);
int cliente_modificar(Cliente array[], int sizeArray);                                //cambiar cliente
int cliente_ordenarPorDobleCriterio(Cliente array[],int size, int orderFirst, int orderSecond);                                  //cambiar cliente
int cliente_listar(Cliente array[], int size);                      //cambiar cliente

