#include "informes.h"

static void existeRubro(Rubro* pArray,int sizeP,int numRubro);

void inicializar_rubros(Rubro* pArray,int size){
	for(int i=0;i<size;i++)
	{
		pArray[i].isEmpty=1;
		pArray[i].cant=0;
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
			if(pArray[i].estado==0)
			{
				cant++;
			}
		}
		*cantAvisosPausados=cant;
	}
	return retorno;
}

int informes_rubroConMasAvisos(Publicacion* pArray, int sizeP, Rubro* pArrayRubro, int* rubroMasUsado)
{
	int retorno=-1;
	int resultado;
	int rubro;
	if(pArray!=NULL && sizeP>0 && rubroMasUsado!=NULL)
	{
		inicializar_rubros(pArrayRubro, sizeP);
		for(int i=0;i<sizeP;i++)
		{
			if(pArray[i].estado==0)
			{
				existeRubro(pArrayRubro,sizeP,pArray[i].numRubro);
			}
		}
		resultado=obtenerRubroMasUsado(pArrayRubro,sizeP,&rubro);
		if(resultado==0)
		{

		}
		*rubroMasUsado=rubro;
	}
	return retorno;
}

void existeRubro(Rubro* pArray,int sizeP,int numRubro)
{
	for(int i=0;i<sizeP;i++)
	{
		if(pArray[i].isEmpty!=0 && pArray[i].id==numRubro)
		{
			pArray[i].cant++;
			break;
		} else {
			if(pArray[i].isEmpty==0){
				pArray[i].isEmpty=0;
				pArray[i].id=numRubro;
				pArray[i].cant++;
				break;
			}
		}
	}
}

int obtenerRubroMasUsado(Rubro* pArray,int sizeP,int* rubroMasUsado)
{
	int retorno=-1;
	int maximo;
	int rubroMaximo;
	int bandera=0;
	if(pArray!=NULL && sizeP>0 && rubroMasUsado!=NULL)
	{
		for(int i=0;i<sizeP;i++)
		{
			if(pArray[i].isEmpty==0 )
			{
				if(bandera==0)
				{
					bandera=1;
					retorno=0;
					maximo=pArray[i].cant;
					rubroMaximo=pArray[i].id;
				} else {
					if(maximo<pArray[i].cant)
					{
						maximo=pArray[i].cant;
						rubroMaximo=pArray[i].id;
					}
				}
			}
//			else { break }
		}
		*rubroMasUsado=rubroMaximo;
	}
	return retorno;
}



