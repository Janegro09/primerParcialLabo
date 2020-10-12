#ifndef PUBLICACION
#define PUBLICACION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define SIZE_TEXTO 65
#define SIZE_PUBLICACIONES 1000
#define MAX_RUBRO 30000
#define MIN_RUBRO 1
#define MIN_ID_PUBLICACION 1
#define MAX_ID_PUBLICACION 1000
typedef struct {
	int id;
	int isEmpty;
	int numRubro;
	char texto[SIZE_TEXTO];
	int estado;
	int idCliente;
} Publicacion;

void publicacion_inicializar(Publicacion* array, int size);
void publicacion_harcodear(Publicacion* array);
int publicacion_alta(Publicacion* array,int size, int id);
int publicacion_pausar_reanudar(Publicacion* array, int size, int accion);
int publicacion_modificacion();

#endif
