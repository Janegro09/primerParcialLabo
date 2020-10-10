#include "clientes.h"

static int cliente_altaForzada(Cliente* array, int limite, char* nombre, char* apellido, char* cuit);
static int cliente_generarId(void);
static int noEsCuitRepetido(Cliente* pArray,char* cuit, int size);

/*\brief inicializa los isEmpty de cliente en 1
 * \param array el array de tipo cliente
 * \param size el tamanio del array
 * \return -1 si hubo error, 0 ok
 * */
int cliente_inicializar(Cliente* array, int size)
{
	int retorno=0;
	if(array!=NULL && size>0)
	{
		for (int i=0;i<size;i++)
		{
			array[i].isEmpty=1;
		}
	} else {
		printf("Cliente/Tamaño invalido\n");
		retorno=-1;
	}
	return retorno;
}
/* \brief genera id de forma secuencial
 * \return devuelve el id
 * */
int cliente_generarId(void)
{
	static int id=0;
	id++;
	return id;
}
/* \brief genera id de forma secuencial
 * \param array de cliente
 * \param tamaño del array
 * \return -1 si hubo un error, 0 ok
 */
int cliente_alta(Cliente* pArray, int limite)
{
	{
		int retorno=-1;
		int rNombre;
		int rApellido;
		int rCuit;
		Cliente aux;

		if(pArray!=NULL && limite >0)
		{
			rNombre=utn_getCadenaValida("Ingrese nombre\n", "Error\n", 3, SIZE_NOMBRE, aux.nombre);
			rApellido=utn_getCadenaValida("Ingrese Apellido\n", "Error\n", 3, SIZE_APELLIDO, aux.apellido);
			rCuit=utn_getCuit("Ingrese cuit\n", "Error\n", 3, SIZE_CUIT, aux.cuit);

			if(rNombre==0 && rApellido==0 && rCuit==0 && noEsCuitRepetido(pArray,aux.cuit, SIZE_CLIENTES)==0)
			{
				retorno=cliente_altaForzada(pArray, limite, aux.nombre, aux.apellido, aux.cuit);
			}
		}
		return retorno;
	}
}

int noEsCuitRepetido(Cliente* pArray,char* cuit, int size)
{
	int retorno=0;
	for (int i=0;i<size;i++)
	{
		if(strncmp(pArray[i].cuit,cuit,SIZE_CUIT)==0)
		{
			retorno=-1;
			break;
		}
	}
	return retorno;
}


/* \brief genera el alta en el array de clientes
 * \param Clientes array de cliente
 * \param int limite del array
 * \param *char nombre,
 * \param *char apellido,
 * \param *char cuit,
 * \return -1 si hubo un error, 0 ok
 */
int cliente_altaForzada(Cliente* pArray, int limite, char* nombre, char* apellido, char* cuit)
{
	int retorno=-1;
	Cliente aux;

	if(pArray!=NULL && limite>0 && nombre!=NULL && apellido!=NULL && cuit!=NULL)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty !=0)
			{
				aux.isEmpty=0;
				aux.id=cliente_generarId();
				strncpy(aux.nombre,nombre,SIZE_NOMBRE);
				strncpy(aux.apellido,apellido,SIZE_APELLIDO);
				strncpy(aux.cuit,cuit,SIZE_CUIT);
				pArray[i]=aux;
				printf("Se creo el cliente con el id %d\n",aux.id);
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

void cliente_harcodear(Cliente* array)
{
	char nombre[][SIZE_NOMBRE] = {"Juan","Jose","Maria","Ana","Luis"};
	char apellido[][SIZE_APELLIDO] = {"Gomez","Garcia","Perez","Ale","Bre"};
	char cuit[][SIZE_CUIT] = {"20348003845","20348003846","20348003745","20348083845","20348903845"};
	for(int i=0;i<5;i++)
	{
		strncpy(array[i].nombre,nombre[i],SIZE_NOMBRE);
		strncpy(array[i].apellido,apellido[i],SIZE_APELLIDO);
		strncpy(array[i].cuit,cuit[i],SIZE_CUIT);
		array[i].isEmpty=0;
		array[i].id=cliente_generarId();
	}

}
