#ifndef UTN
#define UTN

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


int utn_getEntero(char* pTexto, char* pTextoError, int intentos, int maximo, int minimo, int* pOperador);
int utn_getFloat(char* pTexto, char* pTextoError, int intentos, float maximo, float minimo, float* pOperador);
int utn_getEnteroSinMaxMin(char* pTexto, char* pTextoError, int reintentos, int* pOperador);
int utn_getCadenaValida(char* pTexto, char* pTextoError, int reintentos, int sizeOperador, char* pOperador);
int utn_getCuit(char* pTexto, char* pTextoError, int reintentos, int sizeOperador, char* pOperador);
int utn_getEnteroLargo(char* pTexto, char* pTextoError, int reintentos, int maximo, int minimo, long* pOperador);
int utn_getCadena (char* texto, char* textoError, int longitud, char* cadena);

#endif
