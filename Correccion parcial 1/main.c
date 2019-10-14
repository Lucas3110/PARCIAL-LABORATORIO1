#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "fantasma.h"

#define QTY_ARRAY_TIPO 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{

    int opcion;
    int contadorIdfantasma=0;

    fantasma arrayFantasma[QTY_ARRAY_TIPO];
    fantasma_inicializar(arrayFantasma,QTY_ARRAY_TIPO);



    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                system("cls");
                if(!fantasma_alta(arrayFantasma,QTY_ARRAY_TIPO,&contadorIdfantasma));                   //cambiar
                {
                    printf("\n----Se dio de ALTA exitosamente!----\n");
                }
                break;

            case 2: //Modificar
                system("cls");
                if(!fantasma_modificar(arrayFantasma,QTY_ARRAY_TIPO));
                {
                     printf("\n----Se modifico exitosamente----\n");
                }
                break;

            case 3: //Baja
                system("cls");
                if(!fantasma_baja(arrayFantasma,QTY_ARRAY_TIPO));
                {
                    printf("\n----Se dio de BAJA exitosamente!----\n");
                }
                break;

            case 4://Listar
                system("cls");
                fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);
                break;

            case 5://Ordenar
                system("cls");
                fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
        printf("\n");
        system("pause");
        system("cls");

    } while(opcion!=6);

    return 0;
}


