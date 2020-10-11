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
	int numRubro;
	char texto[SIZE_TEXTO];
	int estado;
	int idCliente;
} Publicacion;

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
int cliente_baja(Cliente* arrayCliente, int size, Publicacion *arrayPublicaciones);
void cliente_harcodear(Cliente* array);
void cliente_imprimir(Cliente* array, int size);
