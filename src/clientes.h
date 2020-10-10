#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int id;
	int isEmpty;
	char nombre[20];
	char apellido[20];
	char cuit[20];
} Cliente;

int cliente_inicializar(Cliente* arrayCliente, int size);
int cliente_alta();
int cliente_baja();
int cliente_modificar();
int cliente_generarID();
int cliente_alta_obligada();
