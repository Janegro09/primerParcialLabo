#include "clientes.h"

static int cliente_altaForzada(Cliente* array, int limite, char* nombre, char* apellido, char* cuit);
static int cliente_generarId(void);
static int noEsCuitRepetido(Cliente* pArray,char* cuit, int size);
static int existeId(Cliente* array, int size,int id, int* indice);
static void listarPublicaciones(int id,Publicacion* pArrayPublicaciones);
static int confirmarBaja(Cliente* pArray,int id);

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
/* \brief pide un id, si està en el array lo modifica
 * \param array de cliente
 * \param tamaño del array
 * \return -1 si hubo un error, 0 ok
 */
int cliente_modificar(Cliente* array, int size)
{
	int retorno=-1;
	int idModificar;
	int resultadoGet;
	int rNombre;
	int rCuit;
	int rApellido;
	int indice;

	Cliente aux;

	if(array!=NULL && size>0)
	{
		resultadoGet=utn_getEntero("Ingrese un id\n", "error\n", 3, SIZE_CLIENTES, 1, &idModificar);
		if(resultadoGet==0 && existeId(array, size,idModificar,&indice)==0)
		{
			rNombre=utn_getCadenaValida("Ingrese el nuevo nombre\n", "error\n", 3, SIZE_NOMBRE, aux.nombre);
			rApellido=utn_getCadenaValida("Ingrese el nuevo apellido\n", "error\n", 3, SIZE_APELLIDO, aux.apellido);
			rCuit=utn_getCuit("Ingrese el nuevo cuit\n", "error\n", 3, SIZE_CUIT, aux.cuit);
			if(rNombre==0 && rApellido==0 && rCuit==0)
			{
				aux.isEmpty=0;
				aux.id=idModificar;
				array[indice]=aux;
				retorno=0;
			}
		}
	}
	return retorno;
}
/* \brief consulta la base de clientes si existe el cuit y si no està dado de baja
 * \param Cliente* array de cliente
 * \param int tamaño del array
 * \param int id a buscar
 * \param int* pIndice si està el id, aloja el indice
 * \return -1 si hubo un error, 0 ok
 */
int existeId(Cliente* array, int size,int id,int* pIndice)
{
	int retorno=-1;
	for (int i=0;i<size;i++)
	{
		if(array[i].id==id && array[i].isEmpty==0)
		{
			*pIndice=i;
			retorno=0;
			break;
		}
	}
	return retorno;
}
/* \brief pide un id, si està en el array le da la baja logica
 * \param array de cliente
 * \param tamaño del array
 * \return -1 si hubo un error, 0 ok
 */
int cliente_baja(Cliente* pArray, int size, Publicacion* pArrayPublicaciones)
{
	int retorno=-1;
	int id;
	int indice;
	int resultadoGet;
	resultadoGet=utn_getEntero("Ingresa el id a dar de baja\n", "error\n", 3, SIZE_CLIENTES, 1, &id);
		if(existeId(pArray,size,id,&indice)==0 && resultadoGet==0)
		{
			listarPublicaciones(id,pArrayPublicaciones);
			if(confirmarBaja(pArray,indice)==0)
			{
				retorno=0;
				pArray[indice].isEmpty=1;
			}
		}
	return retorno;
}

static void listarPublicaciones(int id,Publicacion* pArrayPublicaciones)
{
	printf("Hola, aca irian las publicaciones\n");
}
static int confirmarBaja(Cliente* pArray,int id)
{
	int opcion;
	int resultado;
	int retorno;
	resultado=utn_getEntero("¿Confirmar la eliminacion?\n 0(No) - 1(Si)\n", "Error\n", 0, 1,0, &opcion);
	if(resultado==0 && opcion==1)
	{
		pArray[id].isEmpty=1;
		retorno=0;
	}
	return retorno;
}
void cliente_imprimir(Cliente* array, int size)
{
	for(int i=0;i<size;i++)
	{
		if(array[i].isEmpty==0)
		{
		printf("%d) %s\n",i,array[i].nombre);
		}
	}
}

