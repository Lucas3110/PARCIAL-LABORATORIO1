#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "cachorros.h"
#include "utn.h"


int main()
{
    int option = 0;
    //Employee* pEmpleado;
    int flag = 0;
    int respuesta;
    LinkedList* registro = ll_newLinkedList();
    LinkedList* registroCallejero = ll_newLinkedList();
    LinkedList* registroDias = ll_newLinkedList();

    do{
        utn_getUnsignedInt("\n1) Cargar desde el archivo en modo texto\n4) Listar Empleados\n5) Listar Callejero\n5) Listar Dias\n9) Guardar el archivo en modo texto\n10) Salir\n", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &option);

        switch(option)
        {
            case 1:
                if(!flag)
                {
                    controller_loadFromText("cachorros.csv",registro);
                    registroCallejero = ll_filter(registro, cachorro_filtrarCallejero);
                    registroDias = ll_filter(registro, cachorro_filtrarDias);

                }else{
                    utn_getUnsignedInt("Ya se han cargado los datos. Desea volver a cargarlos? Esto borrara todo el contenido sin guardar. \n 1) Si - 2) No", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &respuesta);
                    fflush(stdin);
                    if(respuesta == 1)
                    {
                        ll_clear(registro);
                        controller_loadFromText("cachorros.csv",registro);
                        registroCallejero = ll_filter(registro, cachorro_filtrarCallejero);
                        registroDias = ll_filter(registro, cachorro_filtrarDias);
                    }
                }
                break;
            case 4:
                controller_ListCachorro(registro);
                break;
            case 5:
                controller_ListCachorro(registroCallejero);
                break;
            case 6:
                controller_ListCachorro(registroDias);
                break;
           /* case 7:
                controller_sortEmployee(registro);
                break;
            case 9:
                controller_saveAsText("cachorros2.csv", registro);
                break;*/
        }
    }while(option != 10);
    return 0;
}
