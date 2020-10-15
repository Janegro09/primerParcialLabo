#include "clientes.h"

static int cliente_altaForzada(Cliente* array, int limite, char* nombre, char* apellido, char* cuit);
static int cliente_generarId(void);
static int noEsCuitRepetido(Cliente* pArray,char* cuit, int size);
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
int cliente_modificacion(Cliente* array, int size)
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
		if(resultadoGet==0 && cliente_existeId(array, size,idModificar,&indice)==0)
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
int cliente_existeId(Cliente* array, int size,int id,int* pIndice)
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

int clientes_imprimirDatos(Cliente* array, int size,int id)
{
	int retorno=-1;
	int resultado;
	int indice;
	resultado=cliente_existeId(array, size, id, &indice);
	if(resultado==0)
	{
		retorno=0;
		printf("id: %d, %s, %s. Cuit: %s, ",array[indice].id,array[indice].nombre, array[indice].apellido, array[indice].cuit);
	} else {
		printf("No se encontro cliente");
	}
	return retorno;

}


/* \brief pide un id, si està en el array le da la baja logica
 * \param array de cliente
 * \param tamaño del array
 * \return -1 si hubo un error, 0 ok
 */
int cliente_baja(Cliente* pArray, int sizeC, Publicacion* pArrayPublicaciones, int sizeP)
{
	int retorno=-1;
	int id;
	int indice;
	int resultadoGet;
	resultadoGet=utn_getEntero("Ingresa el id a dar de baja\n", "error\n", 3, SIZE_CLIENTES, 1, &id);
		if(cliente_existeId(pArray,sizeC,id,&indice)==0 && resultadoGet==0)
		{
			clientes_imprimirDatos(pArray, sizeP, id);
			clientes_publicaciones(pArrayPublicaciones, sizeP, id);
			if(confirmarBaja(pArray,indice)==0)
			{
				pArray[indice].isEmpty=1;
				retorno=publicacion_bajar(pArrayPublicaciones, sizeP, id);
			}
		}
	return retorno;
}

static int confirmarBaja(Cliente* pArray,int id)
{
	int opcion;
	int resultado;
	int retorno=-1;
	resultado=utn_getEntero("¿Estas seguro de eliminarlo?\n "
			"1) No\n"
			"2) Si\n", "Error\n", 0, 2,1, &opcion);
	if(resultado==0 && opcion==2)
	{
		retorno=0;
	}
	return retorno;
}
void cliente_imprimir(Cliente* array, int size, Publicacion* arrayPublicaciones, int sizePublic)
{
	for(int i=0;i<size;i++)
	{
		if(array[i].isEmpty==0)
		{
		clientes_imprimirDatos(array, size,array[i].id);
		clientes_publicaciones(arrayPublicaciones,sizePublic,array[i].id);
		}
	}
}

int clientes_publicaciones(Publicacion* arrayPublicaciones, int sizePublic, int id)
{
	int retorno=-1;
	printf("Publicaciones: ");
	for (int j=0; j<sizePublic;j++)
	{
		if(arrayPublicaciones[j].idCliente==id && arrayPublicaciones[j].estado==1)
		{
			retorno=0;
			printf("%d,",arrayPublicaciones[j].id);
		}
	}
	if(retorno!=0)
	{
		printf("No posee publicaciones\n");
	} else {
		printf("\n");

	}
	return retorno;

}

