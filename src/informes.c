#include "informes.h"

int informes_clienteMasAvisos(Cliente* arrayClientes, int sizeC,Publicacion* arrayPublicaciones, int sizeP, int* id)
{
	int retorno=-1;
	int idMaximo;
	int cantMaxima=0;
	int cantAvisos=0;
	int esPrimero=0;

	if(arrayClientes!=NULL && arrayPublicaciones!=NULL && sizeC>0 && sizeP>0 && id!=NULL)
	{
		for (int i=0; i<sizeC;i++)
			{
				for (int j=0;j<sizeP;j++)
				{
					if(arrayClientes[i].id==arrayPublicaciones[j].idCliente)
					{
						cantAvisos++;
					}
				}
				if(esPrimero==0)
				{
					idMaximo=arrayClientes[i].id;
					cantMaxima=cantAvisos;
					retorno=0;
				} else {
					if(cantAvisos>cantMaxima)
					{
						idMaximo=arrayClientes[i].id;
						cantMaxima=cantAvisos;
					}
				}
			}
		*id=idMaximo;
	}
	return retorno;
}
