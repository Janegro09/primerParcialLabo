#include "informes.h"

static int ordenarRubros(Rubro* pArray,int sizeP, int orden);
static int estaEnLaLista(Rubro* pArrayRubro,int sizeP,int numRubro,int* cant);

void inicializar_rubros(Rubro* pArray,int size){
	for(int i=0;i<size;i++)
	{
		pArray[i].isEmpty=1;
	}
}

int informes_clienteMasAvisos(Cliente* arrayClientes, int sizeC,Publicacion* arrayPublicaciones, int sizeP, int* id)
{
	int retorno=-1;
	int idMaximo;
	int cantMaxima=0;
	int cantAvisos;
	int esPrimero=0;

	if(arrayClientes!=NULL && arrayPublicaciones!=NULL && sizeC>0 && sizeP>0 && id!=NULL)
	{
		for (int i=0; i<sizeC;i++)
			{
			cantAvisos=0;
				for (int j=0;j<sizeP;j++)
				{
					if(arrayClientes[i].isEmpty==0 && arrayClientes[i].id==arrayPublicaciones[j].idCliente)
					{
						cantAvisos++;
					}
				}
				if(esPrimero==0)
				{
					esPrimero=1;
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

int informes_cantAvisosPausados(Publicacion* pArray, int sizeP, int* cantAvisosPausados)
{
	int retorno=-1;
	int cant=0;
	if(pArray!=NULL && sizeP>0 && cantAvisosPausados!=NULL)
	{
		for(int i=0;i<sizeP;i++)
		{
			if(pArray[i].estado==0 && pArray[i].isEmpty==0)
			{
				cant++;
			}
		}
		*cantAvisosPausados=cant;
		retorno=0;
	}
	return retorno;
}

int informes_rubroConMasAvisos(Publicacion* pArray, int sizeP, Rubro* pArrayRubro, int* rubroMasUsado)
{
	int retorno=-1;
	int cant=0;
	int posicionRubro=0;
	for(int i=0;i<sizeP;i++)
	{
		if(pArray[i].isEmpty==0)
		{
			printf("rubro: %d\n",pArray[i].numRubro);
		}
	}
	if(pArray!=NULL && sizeP>0 && rubroMasUsado!=NULL)
	{
		inicializar_rubros(pArrayRubro, sizeP);
		for(int i=0;i<sizeP;i++)
		{
			if(pArray[i].estado==1 && pArray[i].isEmpty==0)
			{
				if(estaEnLaLista(pArrayRubro,sizeP,pArray[i].numRubro,&posicionRubro)==0)
				{
					pArrayRubro[posicionRubro].cant++;
				} else {
					printf("Se agrega %d al array rubro\n",pArray[i].numRubro);
					pArrayRubro[cant].cant=1;
					pArrayRubro[cant].isEmpty=0;
					pArrayRubro[cant].id=pArray[i].numRubro;
					cant++;
				}
			}
		}
		retorno=0;
		ordenarRubros(pArrayRubro,sizeP,1);
		*rubroMasUsado=pArrayRubro[0].id;
	}
	return retorno;
}

int estaEnLaLista(Rubro* pArrayRubro,int sizeP,int numRubro,int* posicion)
{
	int retorno=-1;
	for(int i=0;i<sizeP;i++)
	{
		if(pArrayRubro[i].isEmpty==0 && pArrayRubro[i].id==numRubro)
		{
			retorno=0;
			*posicion=i;
			break;
		}
	}
	return retorno;
}

int ordenarRubros(Rubro* pArrayRubro,int sizeP, int orden)
{
	for(int i=0;i<sizeP;i++)
	{
		if(pArrayRubro[i].isEmpty==0)
		{
			printf("%d tiene %d avisos\n",pArrayRubro[i].id, pArrayRubro[i].cant);
		}
	}
	int swap;
	int limite=0;
	Rubro aux;
	int retorno=-1;
	if(pArrayRubro!=NULL && sizeP>0 && (orden==1||orden==0))
	{
		do{
			swap=1;
			for(int i=0;i<sizeP-limite;i++)
			{
				limite++;
				if((orden==1 && pArrayRubro[i].cant<pArrayRubro[i+1].cant)
						||
					(orden==0 && pArrayRubro[i].cant>pArrayRubro[i+1].cant))
				{
					swap=0;
					aux=pArrayRubro[i];
					pArrayRubro[i]=pArrayRubro[i+1];
					pArrayRubro[i+1]=aux;
				}
			}
			retorno=0;
		} while(swap==0);
	}
	printf("ORDENADO\n");
	for(int i=0;i<sizeP;i++)
	{
		if(pArrayRubro[i].isEmpty==0)
		{
			printf("%d tiene %d avisos\n",pArrayRubro[i].id, pArrayRubro[i].cant);
		}
	}

	return retorno;
}
