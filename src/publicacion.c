#include "publicacion.h"

static int publicacion_generarId(void);
static int publicacion_altaForzada(Publicacion* array, int limite, char* texto, int rubro, int id);
static int existeId(Publicacion* pArray,int size,int id,int* indice);

void publicacion_inicializar(Publicacion* pArray, int size)
{
	for(int i=0;i<size;i++)
	{
		pArray[i].isEmpty=1;
	}
}

int publicacion_alta(Publicacion* pArray,int size, int id)
{
	int retorno=-1;
	int rTexto;
	int rRubro;
	Publicacion aux;
	aux.idCliente=id;
	if(pArray!=NULL && size >0)
	{
		rTexto=utn_getCadena("Ingrese el texto:\n", "Error\n", SIZE_TEXTO, aux.texto);
		rRubro=utn_getEntero("Ingrese el rubro:\n", "Error\n", 3, MAX_RUBRO, MIN_RUBRO, &aux.numRubro);
		if(rTexto==0 && rRubro==0)
		{
			retorno=publicacion_altaForzada(pArray, size, aux.texto, aux.numRubro, aux.idCliente);
		}
	}
	return retorno;
}

int publicacion_generarId(void)
{
	static int id=0;
	id++;
	return id;
}

int publicacion_altaForzada(Publicacion* pArray, int limite, char* texto, int rubro, int id)
{
	int retorno=-1;
	Publicacion aux;

		if(pArray!=NULL && limite>0 && texto!=NULL && rubro>MIN_RUBRO && rubro<MAX_RUBRO)
		{
			for(int i=0;i<limite;i++)
			{
				if(pArray[i].isEmpty !=0)
				{
					aux.isEmpty=0;
					aux.id=publicacion_generarId();
					strncpy(aux.texto,texto,SIZE_TEXTO);
					aux.idCliente=id;
					aux.numRubro=rubro;
					aux.estado=1;
					pArray[i]=aux;
					printf("Se creo el aviso con el id %d\n",aux.id);
					retorno=0;
					break;
				}
			}
		}
	return retorno;
}

void publicacion_harcodear(Publicacion* array)
{
	char texto[][SIZE_TEXTO] = {"texto de Juan","texto de Jose","text de Maria","texto de Ana","texto de Luis","texto de Juan 2","texto de Jose 2","text de juan 3","texto de Ana 2","texto de juan 33"};
	int ids[10]={1,2,3,4,5,1,2,1,4,1};
	int rubros[10]={3,4,2,1,4,1,3,2,1,2};
	for(int i=0;i<9;i++)
	{
		strncpy(array[i].texto,texto[i],SIZE_TEXTO);
		array[i].estado=1;
		array[i].numRubro=rubros[i];
		array[i].idCliente=ids[i];
		array[i].isEmpty=0;
		array[i].id=publicacion_generarId();
	}
}

int publicacion_pausar_reanudar(Publicacion* pArray, int size, int accion)
{
	int retorno=-1;
	int resultado;
	int id;
	int indice;
	if(pArray!=NULL && size>0)
	{
		resultado=utn_getEntero("Ingrese un id\n", "Error\n", 3, MAX_ID_PUBLICACION, MIN_ID_PUBLICACION, &id);
		if(resultado==0 && existeId(pArray,size,id,&indice)==0)
		{
			if(utn_getEntero("¿Seguro que desea cambiar el estado?\n"
					"1) Si\n"
					"2) No\n", "Error\n", 1, 2, 1, &id)== 0 && id==1)
			{
				pArray[indice].estado=accion;
				retorno=0;
			}
		}
	}
	return retorno;
}

int existeId(Publicacion* pArray,int size,int id,int* indice)
{
	int retorno=-1;
	for(int i=0;i<size;i++)
	{
		if(pArray[i].id==id)
		{
			*indice=i;
			retorno=0;
			break;
		}
	}
	return retorno;
}

int publicacion_bajar(Publicacion* pArray,int size,int id)
{
	int retorno=-1;
	if(pArray!=NULL && size>0)
	{
		for(int i=0;i<size;i++)
		{
			if(pArray[i].idCliente==id)
			{
				pArray[i].isEmpty=1;
			}
		}
		retorno=0;
	//printf("chau publicacion");
	}
	return retorno;
}
