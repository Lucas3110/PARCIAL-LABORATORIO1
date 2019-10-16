#ifndef CLIENTE_H_
#define CLIENTE_H_
#define TEXT_SIZE 20
#define CANT_CLIENTE 100

typedef struct
{
    char calle[TEXT_SIZE];
    int altura;

}Direccion;

typedef struct
{
    int idCliente;
    int isEmpty;
    char nombreCliente[TEXT_SIZE];
    char localidadCliente[TEXT_SIZE];
    char cuitCliente[14];
    Direccion direccion;

}Cliente;

void imprimeMenu();
//imprime menu del ABM

int cliente_Inicializar(Cliente array[], int size);
//inicializa el array de Cliente

int cliente_buscarEmpty(Cliente array[], int size, int* posicion);
//busca la primera posicion vacia que encuentre en el array Cliente

int cliente_buscarID(Cliente array[], int size, int valorBuscado, int* posicion);
//busca el ID de un cliente en el array y devuelve la posicion

int cliente_alta(Cliente array[], int size, int* contadorID);
//da de alta un cliente y se le asigna un ID

int cliente_baja(Cliente clieArray[], int sizeClieArray,int contadorID, int* flag);
//se ingresa un ID de Cliente y se da de baja a ese cliente

int cliente_modificar(Cliente array[], int sizeArray,int contadorID);
//se ingresa un ID de Cliente y se permite modifica la direccion y/o localidad del cliente

int cliente_listar(Cliente array[], int size);
//imprime un listado del array de Cliente

#endif // CLIENTE_H_INCLUDED
