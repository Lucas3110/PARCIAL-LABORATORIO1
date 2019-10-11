#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define TEXT_SIZEA 20
#define TEXT_SIZEB 15
#define TEXT_SIZEC 40

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString1[TEXT_SIZEA];
    char varString2[TEXT_SIZEB];
    char varString3[TEXT_SIZEA];
    int varInt1;
    int varInt2;
    int varInt3;
    float varFloat1;
    float varFloat2;
    float varFloat3;
    char varChar1;
    char varChar2;
    char varChar3;
    char varLongString1[TEXT_SIZEC];
    char varLongString2[TEXT_SIZEC];
    char varLongString3[TEXT_SIZEC];

}Fantasma;


#endif // FANTASMA_H_INCLUDED

int fantasma_inicializar(Fantasma array[], int size);                                    //cambiar fantasma
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion);                    //cambiar fantasma
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice);                    //cambiar fantasma
int fantasma_alta(Fantasma array[], int size, int* contadorID);                          //cambiar fantasma
int fantasma_baja(Fantasma array[], int sizeArray);                                      //cambiar fantasma
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado);
int fantasma_modificar(Fantasma array[], int sizeArray);                                //cambiar fantasma
int fantasma_ordenarPorDobleCriterio(Fantasma array[],int size, int orderFirst, int orderSecond);                                  //cambiar fantasma
int fantasma_listar(Fantasma array[], int size);                      //cambiar fantasma
