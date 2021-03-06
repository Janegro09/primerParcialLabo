#include "utn.h"

int utn_validarCadena(char array[]);
static int utn_esLetra(char letra);
static int utn_esNumero(char numero);

/**
 * \brief Solicita un entero al usuario y valida un rango max y min
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int maximo, valor maximo admitido
 * \param int minimo, valor minimo admitido
 * \return (1) Error / (0) Tomo el entero ok
 */

int utn_getEntero(char* pTexto, char* pTextoError, int reintentos, int maximo, int minimo, int* pOperador)
{
	int retorno=-1;
	int operadorBuffer;
	int resultadoScan;

	if(
		pTexto!=NULL &&
		pTextoError!=NULL &&
		minimo<maximo &&
		reintentos>=0
		)
		{
			do {
				printf("%s",pTexto);
				resultadoScan=scanf("%d",&operadorBuffer);
				__fpurge(stdin);
				if((resultadoScan==1) && operadorBuffer<=maximo && minimo<=operadorBuffer)
				{
					retorno=0;
					*pOperador=operadorBuffer;
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}

/**
 * \brief Solicita un entero largo al usuario y valida un rango max y min
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int maximo, valor maximo admitido
 * \param int minimo, valor minimo admitido
 * \return (1) Error / (0) Tomo el entero ok
 */

int utn_getEnteroLargo(char* pTexto, char* pTextoError, int reintentos, int maximo, int minimo, long* pOperador)
{
	int retorno=-1;
	long operadorBuffer;
	int resultadoScan;

	if(
		pTexto!=NULL &&
		pTextoError!=NULL &&
		minimo<maximo &&
		reintentos>=0
		)
		{
			do {
				printf("%s",pTexto);
				resultadoScan=scanf("%ld",&operadorBuffer);
				__fpurge(stdin);
				if((resultadoScan==1) && operadorBuffer<=maximo && minimo<=operadorBuffer)
				{
					retorno=0;
					*pOperador=operadorBuffer;
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}
/**
 * \brief Solicita un float al usuario y valida un rango max y min
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int maximo, valor maximo admitido
 * \param int minimo, valor minimo admitido
 * \return (1) Error / (0) Tomo el entero ok
 */

int utn_getFloat(char* pTexto, char* pTextoError, int reintentos, float maximo, float minimo, float* pOperador)
{
	int retorno=-1;
	float operadorBuffer;
	int resultadoScan;

	if(
		pTexto!=NULL &&
		pTextoError!=NULL &&
		minimo<maximo &&
		reintentos>=0
		)
		{
			do {
				printf("%s",pTexto);
				resultadoScan=scanf("%f",&operadorBuffer);
				__fpurge(stdin);
				if((resultadoScan==1) && operadorBuffer<=maximo && minimo<=operadorBuffer)
				{
					retorno=0;
					*pOperador=operadorBuffer;
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}
/**
 * \brief Solicita una cadena
 * \param char* cadena, es la cadena a procesar, puede tener letras, caracteres especiales, numeros.
 * \param int longitud, tamaño de la cadena
 */
int utn_getCadena (char* texto, char* textoError, int longitud, char* cadena)
{
	int retorno=-1;
	//int continuar;
	//int resultado;
	if(texto!=NULL && textoError!=NULL && longitud>0)
	{
		//do{
			printf("%s",texto);
			__fpurge(stdin);
			fgets(cadena,longitud,stdin);
			cadena[strlen(cadena)-1]='\0';
			//resultado=utn_getEntero("¿Desea confirmar este texto?\n Si=1-Cambiar=0", "Error\n", 2, 1, 0, &continuar);
//			if(resultado==0 && strlen(cadena)<longitud)	{
			retorno=0;
//				break;
//			}
		//} while(resultado==0 && continuar==0);
	}
	return retorno;
}

/**
 * \brief Recibe un char
 * \param char letra, letra a verificar
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_esLetra(char letra)
{
	int retorno=-1;
	if(('a'<=letra && letra<='z')||('A'<=letra && letra<='Z'))
	{
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Recibe un char
 * \param char numero, a verificar
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_esNumero(char numero)
{
	int retorno=-1;
	if(('0'<=numero && numero<='9'))
	{
		retorno=0;
	}
	return retorno;
}
/**
 * \brief Recibe una cadena de caracteres y confirma que no tenga numeros
 * \param array de char, a verificar
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_validarCadena(char array[])
{
	int retorno=0;
	int i;
	if(array!=NULL)
	{
		for (i=0;i<strlen(array)-1;i++)
		{
			if(utn_esLetra(array[i])!=0)
			{
				retorno=-1;
				break;
			}
		}
		//para eliminar el \n final que agrega fgets
		array[i]='\0';
	}
	return retorno;
}
/**
 * \brief Recibe una cadena de caracteres y confirma que tenga numeros
 * \param array de char, a verificar
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_validarCuit(char array[])
{
	int retorno=0;
	int i;
	if(array!=NULL)
	{
		for (i=0;i<strlen(array)-1;i++)
		{
			if(utn_esNumero(array[i])!=0)
			{
				retorno=-1;
				break;
			}
		}
		//para eliminar el \n final que agrega fgets
		array[i]='\0';
	}
	return retorno;
}
/**
 * \brief Solicita una cadena de caracteres al usuario y valida
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int maximo, tamaño maximo permitido para la cadena
 * \param int minimo, tamaño minimo permitido para la cadena
 * \param int cadena, puntero al espacio de memoria donde se dejarà la cadena obtenida
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_getCadenaValida(char* pTexto, char* pTextoError, int reintentos, int sizeOperador, char* cadena)
{
	int retorno=-1;
	char operadorBuffer[sizeOperador];
	if(
		cadena!=NULL &&
		pTexto!=NULL &&
		pTextoError!=NULL &&
		sizeOperador>1 &&
		reintentos>0
		)
		{
			do {
				printf("%s",pTexto);
				fgets(operadorBuffer,sizeOperador,stdin);
				__fpurge(stdin);
				if(utn_validarCadena(operadorBuffer)==0)
				{
					retorno=0;
					strncpy(cadena,operadorBuffer,sizeOperador-1);
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}
/**
 * \brief Solicita una cadena de caracteres al usuario y valida
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int maximo, tamaño maximo permitido para la cadena
 * \param int minimo, tamaño minimo permitido para la cadena
 * \param int cadena, puntero al espacio de memoria donde se dejarà la cadena obtenida
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_getCuit(char* pTexto, char* pTextoError, int reintentos, int sizeOperador, char* cadena)
{
	int retorno=-1;
	char operadorBuffer[sizeOperador];
	if(
		cadena!=NULL &&
		pTexto!=NULL &&
		pTextoError!=NULL &&
		sizeOperador>1 &&
		reintentos>0
		)
		{
			do {
				printf("%s",pTexto);
				fgets(operadorBuffer,sizeOperador,stdin);
				__fpurge(stdin);
				if(utn_validarCuit(operadorBuffer)==0)
				{
					retorno=0;
					strncpy(cadena,operadorBuffer,sizeOperador-1);
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}
