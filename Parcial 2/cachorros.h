#ifndef CACHORROS_H_INCLUDED
#define CACHORROS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128]; //TIPO
    int dias; //CANTIDAD
    char raza[128]; //TIPO
    char reservado[128]; //TIPO
    char genero[128]; //TIPO    //CHAU IMPORTE
}Cachorro;

Cachorro* Cachorro_new();
Cachorro* Cachorro_newParametros(char* id,char* nombre,char* dias,char* raza, char* reservado,char* genero);
int cachorro_delete(Cachorro* this);

int cachorro_setId(Cachorro* this,int id);
int cachorro_getId(Cachorro* this,int* resultado);
int cachorro_setIdAsString(Cachorro* this, char* id);
int cachorro_getIdAsString(Cachorro* this, char* resultado);

int cachorro_setNombre(Cachorro* this,char* nombre);
int cachorro_getNombre(Cachorro* this,char* resultado);

int cachorro_setRaza(Cachorro* this,char* raza);
int cachorro_getRaza(Cachorro* this,char* resultado);

int cachorro_setReservado(Cachorro* this,char* reservado);
int cachorro_getReservado(Cachorro* this,char* resultado);

int cachorro_setGenero(Cachorro* this,char* genero);
int cachorro_getGenero(Cachorro* this,char* resultado);

int cachorro_setDias(Cachorro* this,int dias);
int cachorro_getDias(Cachorro* this,int* resultado);
int cachorro_setDiasAsString(Cachorro* this, char* dias);
int cachorro_getDiasAsString(Cachorro* this, char* resultado);


int cachorro_filtrarCallejero(void* this);
int cachorro_filtrarDias(void* this);
int cachorro_filtrarHembras(void* this);

#endif // cachorro_H_INCLUDED
