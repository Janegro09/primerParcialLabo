#include "publicacion.h"

static int publicacion_generarId(void);
static int publicacion_altaForzada(Publicacion* array, int limite, char* texto, int rubro, int id);

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
					pArray[i]=aux;
					printf("Se creo el aviso con el id %d\n",aux.id);
					retorno=0;
					break;
				}
			}
		}
	return retorno;
}
