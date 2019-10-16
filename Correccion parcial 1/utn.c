#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/*
getString       <<<<< antes &reintentos -- modificado a reintentos como variables(chequear que no crashee)
utn_getName
utn_getNumero
utn_getNumeroConSigno
utn_getNumeroConDecimales
utn_getTelefono
utn_getDNI
utn_getCUIT
utn_getEmail
utn_getTexto
utn_getAlfanumerico
utn_getFecha
*/


int getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}
//------------------------------
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==0)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


//-----------------------------------------
int utn_getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	char input[50];
	int length;
	do
	{
		printf("%s",pMensaje);
		fgets(input,sizeof(input),stdin);
		length = strlen(input);
		length--;
		if(isValidNumber(input,length)==0)
		{
			buffer = atoi(input);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
				reintentos--;
			}

		}
		else
		{
			printf("No es un numero");
			reintentos--;
		};

	}while(reintentos >= 0);
	return retorno;
}


//-------------------------------------------------
/*int utn_getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];
    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidSignedNumber(bufferStr)==0)
                {
                    *input=atoi(bufferStr);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}*/


//*******************************************************
int utn_getFloat(float *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	float buffer;
	char input[50];
	int length;
	do
	{
		printf("%s",pMensaje);
		fgets(input,sizeof(input),stdin);
		length = strlen(input);
		length--;
		if(isValidFloatNumber(input,length)==0)
		{
			buffer = atof(input);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",pMensajeError);
				reintentos--;
			}

		}
		else
		{
			printf("No es un numero");
			reintentos--;
		};

	}while(reintentos >= 0);
	return retorno;
}

//*************************************************************
/*int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];
    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidTelephone(bufferStr)==0)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}*/

//***************************************
/*int utn_getDNI(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    maxSize=11; //con puntos
    minSize=8;  // sin puntos
    int retorno=-1;
    char bufferStr[maxSize];
    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidDNI(bufferStr)==0)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}*/



//***************************************
int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=14;
    int minSize=12;
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,reintentos,bufferStr))
            {
            	if(isValidCUIT(bufferStr)==0)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


//*************************************************************
/*int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];
    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidEmail(bufferStr)==0)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}*/


//*************************************************************
/*int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];
    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidTexto(bufferStr)==0)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}*/


//*************************************************************
/*int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];
    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr))
            {
                if(isValidAlphanumeric(bufferStr)==0)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}*/


int utn_getChar(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferChar[256];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,1,3,reintentos,bufferChar))
            {
                if(isValidChar(bufferChar[0])==0)
                {
                    printf("OK");
                    *resultado=bufferChar[0];
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}



int isValidName(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {

        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

int isValidNumber(char* stringRecibido,int limite)
{
	int retorno = -1;
		int i;
		if(stringRecibido != NULL && limite > 0)
		{
			for(i=0;i<limite;i++)
			{
				if(stringRecibido[i]>='0' && stringRecibido[i]<='9')
				{
					retorno = 0;
				}
				else
				{
					retorno = -1;
					break;
				}
			}

		}

    return retorno;
}

/*int isValidSignedNumber(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='+' && stringRecibido[0]!='-'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

int isValidFloatNumber(char* stringRecibido, int limite)
{
    int retorno=0;
    int i;
    for(i=0;i<limite;i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

/*int isValidTelephone(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

/*int isValidDNI(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

int isValidCUIT(char* stringRecibido)
{
    int retorno=0;
    int i;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if(buffer[i]!='-' && (i == 2 || i == 11))
        {
        	retorno=-1;
        	break;
        }

        if((buffer[i]<'0' || buffer[i]>'9') && (i > 2 && i < 11))
        {
            retorno=-2;
            break;
        }

        if((buffer[i]<'0' || buffer[i]>'9') && i==12)
		{
        	retorno=-3;
        	break;
		}
    }

    return retorno;
}

/*int isValidEmail(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

/*int isValidTexto(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

/*int isValidAlphanumeric(char* stringRecibido)
{
    int retorno=0;
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}*/

int isValidChar(char charRecibido)
{
    int retorno=0;
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
        retorno=-1;
    return retorno;
}

int imprimir_clientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int pedidosPend = 0;
    int posicion,i;

    if(clieArray!=NULL && sizeClieArray>0)
    {
    	for(i=0;i<sizeClieArray;i++)
    	    {
    			if(clieArray[i].isEmpty==1)
    	          {
    	            continue;
    	          }
                else
    	            {
    	            	printf( "\n ID: %d"
    	            	        "\n Cuil: %s"
    	            			"\n Nombre: %s"
    	            			"\n Localidad: %s"
    	                		"\n Calle: %s",
								clieArray[i].idCliente,
								clieArray[i].cuitCliente,
								clieArray[i].nombreCliente,
								clieArray[i].localidadCliente,
								clieArray[i].direccion.calle);
    	            	for(posicion=0;posicion<sizePediArray;posicion++)
    	            	{
    	            		if(clieArray[i].idCliente == pediArray[posicion].idCliente
    	            			&& pediArray[posicion].isEmpty==0
								&& pediArray[posicion].estado==0)
    	            		{
    	            			pedidosPend++;
    	            		}
    	            	}
    	            printf("\nCantidad de pendientes: %d",pedidosPend);
    	            pedidosPend=0;

    	            }

    	        }
    	        retorno=0;
    }
    return retorno;
}

int imprimir_pendientes(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int posicion,i;

    if(pediArray!=NULL && sizePediArray>0)
    {
    	for(i=0;i<sizePediArray;i++)
    	    {
    			if(pediArray[i].isEmpty==0 && pediArray[i].estado == 0)
    	          {
    				for(posicion=0;posicion<sizeClieArray;posicion++)
    				{
    					if(pediArray[i].idCliente == clieArray[posicion].idCliente
    							&& clieArray[posicion].isEmpty == 0)
    					{
    						printf( "\n ID: %d"
    						    	"\n Cuit: %s"
    						    	"\n Calle: %s"
    								"\n Kilos a recolectar: %f"
									"\n Estado: Pendiente",
									pediArray[i].idPedido,
    								clieArray[posicion].cuitCliente,
 									clieArray[posicion].direccion.calle,
									pediArray[i].cantKilos);

    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}

int imprimir_procesados(Cliente clieArray[],Pedidos pediArray[], int sizeClieArray, int sizePediArray)
{
    int retorno=-1;
    int posicion,i;

    if(pediArray!=NULL && sizePediArray>0)
    {
    	for(i=0;i<sizePediArray;i++)
    	    {
    			if(pediArray[i].isEmpty==0 && pediArray[i].estado == 1)
    	          {
    				for(posicion=0;posicion<sizeClieArray;posicion++)
    				{
    					if(pediArray[i].idCliente == clieArray[posicion].idCliente
    							&& clieArray[posicion].isEmpty == 0)
    					{
    						printf( "\n ID: %d"
    						    	"\n Cuit: %s"
    						    	"\n Calle: %s"
    								"\n Kilos de HDPE: %d"
    								"\n Kilos de LDPE: %d"
    								"\n Kilos de PP: %d"
									"\n Estado: Completado",
									pediArray[i].idPedido,
    								clieArray[posicion].cuitCliente,
 									clieArray[posicion].direccion.calle,
									pediArray[i].kilosHDPE,
									pediArray[i].kilosLDPE,
									pediArray[i].kilosPP);

    					}
    				}
    	          }


    	    }
    	        retorno=0;
    }
    return retorno;
}
