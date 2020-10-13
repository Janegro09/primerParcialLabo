#ifndef CLIENTES
#define CLIENTES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "publicacion.h"
#define SIZE_APELLIDO 20
#define SIZE_NOMBRE 20
#define SIZE_CUIT 20
#define SIZE_CLIENTES 100


typedef struct {
	int id;
	int isEmpty;
	char nombre[SIZE_NOMBRE];
	char apellido[SIZE_APELLIDO];
	char cuit[SIZE_CUIT];
} Cliente;

int cliente_inicializar(Cliente* arrayCliente, int size);
int cliente_alta(Cliente* arrayCliente, int size);
int cliente_modificacion(Cliente* arrayCliente, int size);
int cliente_baja(Cliente* pArray, int sizeC, Publicacion* pArrayPublicaciones, int sizeP);
void cliente_harcodear(Cliente* array);
void cliente_imprimir(Cliente* array, int size, Publicacion* arrayPublicaciones, int sizePublicaciones);
int cliente_existeId(Cliente* array, int size,int id, int* indice);
int clientes_imprimirDatos(Cliente* array, int size,int id);
int clientes_publicaciones(Publicacion* arrayPublicaciones, int sizePublic, int id);

#endif
