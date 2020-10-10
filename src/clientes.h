#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
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
int cliente_modificar(Cliente* arrayCliente, int size);
int cliente_baja();
int cliente_generarID();
void cliente_harcodear(Cliente* array);
