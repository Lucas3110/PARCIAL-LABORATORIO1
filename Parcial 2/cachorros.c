#include <stdio.h>
#include <stdlib.h>
#include "cachorros.h"
#include "utn.h"
#include <string.h>


/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Cachorro* posición de memoria de cachorro.
 *
 */


Cachorro* cachorro_new(void)
{
    return (Cachorro*) malloc(sizeof(Cachorro));
}

/** \brief Crea un nuevo empleado con posicion de memoria y contenido basado en strings.
 *
 * \param1 char* ID
 * \param2 char* nombre
 * \param3 char* cantidad
 * \param4 char* importe
 * \return retorno Cachorro*. Devuelve el empleado si todo salio bien, o NULL si se pasaron mal parametros o no se pudo completar la operacion.
 *
 */


Cachorro* Cachorro_newParametros(char* id,char* nombre,char* dias,char* raza, char* reservado,char* genero)
{
    Cachorro* retorno = NULL;
    Cachorro*  pAuxCachorro;
    if(id != NULL && nombre != NULL && dias != NULL && raza != NULL && reservado != NULL && genero != NULL)
    {
         pAuxCachorro = cachorro_new();
        if( pAuxCachorro != NULL)
        {
            if( !cachorro_setIdAsString( pAuxCachorro, id) && !cachorro_setNombre( pAuxCachorro, nombre) &&
                !cachorro_setDiasAsString( pAuxCachorro, dias) && !cachorro_setRaza( pAuxCachorro, raza) &&
                !cachorro_setReservado( pAuxCachorro, reservado) && !cachorro_setGenero( pAuxCachorro, genero))
            {
                retorno =  pAuxCachorro;
            }else
            {
                cachorro_delete( pAuxCachorro);
            }
        }
    }
    return retorno;
}

/** \brief Elimina un empleado.
 *
 * \param1 this Cachorro* Empleado a eliminar.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */


int cachorro_delete(Cachorro* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 id int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int cachorro_setId(Cachorro* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el ID de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado int* ID donde se encuentra.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int cachorro_getId(Cachorro* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado como string.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 id char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */


int cachorro_setIdAsString(Cachorro* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        if(isValidNumber(id))
        {
            retorno = cachorro_setId(this, atoi(id));
        }

    }
    return retorno;
}

/** \brief Obtiene el ID de un empleado como string.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int cachorro_getIdAsString(Cachorro* this, char* resultado)
{
    int retorno = -1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        cachorro_getId(this, &bufferId);
        sprintf(resultado, "%d", bufferId);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el nombre de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 nombre char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

int cachorro_setNombre(Cachorro* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidName(nombre))
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int cachorro_getNombre(Cachorro* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->nombre, sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

////// HASTA ACA ORIGI
int cachorro_setRaza(Cachorro* this, char* raza)
{
    int retorno = -1;
    if(this != NULL && isValidName(raza))
    {
        strncpy(this->raza, raza, sizeof(this->raza));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el raza de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int cachorro_getRaza(Cachorro* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->raza, sizeof(this->raza));
        retorno = 0;
    }
    return retorno;
}


int cachorro_setReservado(Cachorro* this, char* reservado)
{
    int retorno = -1;
    if(this != NULL && isValidName(reservado))
    {
        strncpy(this->reservado, reservado, sizeof(this->reservado));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el reservado de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int cachorro_getReservado(Cachorro* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->reservado, sizeof(this->reservado));
        retorno = 0;
    }
    return retorno;
}


int cachorro_setGenero(Cachorro* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && isValidName(genero))
    {
        strncpy(this->genero, genero, sizeof(this->genero));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el genero de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int cachorro_getGenero(Cachorro* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->genero, sizeof(this->genero));
        retorno = 0;
    }
    return retorno;
}
/** \brief Define las horas trabajadas de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 cantidad int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int cachorro_setDias(Cachorro* this, int dias)
{
    int retorno = -1;
    if(this != NULL && dias >= 0)
    {
        this->dias = dias;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int cachorro_getDias(Cachorro* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->dias;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado como string.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 dias char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int cachorro_setDiasAsString(Cachorro* this, char* dias)
{
    int retorno = -1;
    if(this != NULL && dias >= 0)
    {
        if(isValidNumber(dias))
        {
            retorno = cachorro_setDias(this, atoi(dias));
        }
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param1 this Cachorro* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int cachorro_getDiasAsString(Cachorro* this, char* resultado)
{
    int retorno = -1;
    int bufferDias;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferDias = this->dias;
        sprintf(resultado, "%d", bufferDias);
        retorno = 0;
    }
    return retorno;
}



int cachorro_filtrarCallejero(void* this)
{
    int retorno = -1;
    Cachorro* auxCachorro = (Cachorro*)this;
    int comparison = strcmp(auxCachorro->raza, "Callejero");
    if(!comparison)
        retorno = 1;

    return retorno;
}

int cachorro_filtrarDias(void* this)
{
    int retorno = -1;
    Cachorro* auxCachorro = (Cachorro*)this;
    int comparison = auxCachorro->dias;
    if(comparison>45)
        retorno = 1;

    return retorno;
}



