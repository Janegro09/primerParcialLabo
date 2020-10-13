#ifndef INFORMES
#define INFORMES

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "clientes.h"
#include "publicacion.h"

typedef struct {
	int id;
	int cant;
	int isEmpty;
} Rubro;

//void informes_masivo(Cliente arrayClientes, int sizeC,Publicacion arrayPublicaciones, int sizeP,char* clienteAvisos,int* cantAvisosPausados,int* rubroMayor);
int informes_clienteMasAvisos(Cliente* arrayClientes, int sizeC,Publicacion* arrayPublicaciones, int sizeP, int* id);
int informes_cantAvisosPausados(Publicacion* arrayPublicaciones, int sizeP, int* cantAvisosPausados);
void inicializar_rubros(Rubro* pArray,int size);

#endif
