#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define SIZE_APELLIDO 20
#define SIZE_NOMBRE 20
#define SIZE_CUIT 20
#define SIZE_PUBLICACIONES 1000


typedef struct {
	int id;
	int isEmpty;
	int numRubro;
	char texto[64];
	int estado;
	int idCliente;
} Publicacion;

