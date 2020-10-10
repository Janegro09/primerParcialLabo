#include "clientes.h"

int cliente_inicializar(Cliente* array, int size)
{
	int retorno=-1;
	if(array!=NULL && size>0)
	{
		for (int i=0;i<size;i++)
		{
			array[i].isEmpty=1;
		}
	} else {
		printf("Cliente/Tamaño invalido\n");
	}
	return retorno;
}
