/*
 ============================================================================
 Name        : Examen-14-10.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "clientes.h"
#include "publicacion.h"
#define BARRA "\n****************************************\n"


int main(void) {
	int opcion;
	int idCliente;
	int indiceCliente;
	int idPublicacion;
	int resultadoOpcion;
	int resultadoGet;

	Cliente arrayClientes[SIZE_CLIENTES];
	Publicacion arrayPublicaciones[SIZE_PUBLICACIONES];

	cliente_inicializar(arrayClientes, SIZE_CLIENTES);
	cliente_harcodear(arrayClientes);
	publicacion_inicializar(arrayPublicaciones, SIZE_PUBLICACIONES);

	do {
		printf("Ingrese una opcion:\n"
					"1) Alta de cliente\n"
					"2) Modificar datos de cliente\n"
					"3) Baja de cliente\n"
					"4) Publicar\n"
					"5) Pausar publicacion\n"
					"6) Reanudar publicacion\n"
					"7) Imprimir clientes\n"
					"8) Informar\n"
					"9) Salir\n");
		resultadoOpcion=utn_getEntero("Opcion Elegida:\n", "Error\n", 3, 9, 1, &opcion);
		if(resultadoOpcion==0)
		{
			switch (opcion){
				case 1:
					resultadoGet=cliente_alta(arrayClientes,SIZE_CLIENTES);
					if(resultadoGet != 0)
					{
						printf("Error con el alta del cliente\n");
					}
					break;
				case 2:
					resultadoGet=cliente_modificacion(arrayClientes,SIZE_CLIENTES);
					if(resultadoGet != 0)
					{
						printf("Error con la modificacion del cliente\n");
					}
					break;
				case 3:
					resultadoGet=cliente_baja(arrayClientes,SIZE_CLIENTES,arrayPublicaciones);
					if(resultadoGet != 0)
					{
						printf("Error con la baja del cliente\n");
					}
					break;
				case 4:
					resultadoGet=utn_getEntero("Ingrese un id\n", "Error\n", 3, SIZE_CLIENTES, 1, &idCliente);
					if(resultadoGet==0 && cliente_existeId(arrayClientes, SIZE_CLIENTES, idCliente, &indiceCliente)==0)
					{
						publicacion_alta(arrayPublicaciones, SIZE_PUBLICACIONES, idCliente);
					} else {
						printf("ID invalido o intentos fallidos\n");
					}
					break;
				case 5:
					printf("Elegiste pausar publicacion\n");
					break;
				case 6:
					printf("Elegiste reanudar publicacion\n");
					break;
				case 7:
					cliente_imprimir(arrayClientes, SIZE_CLIENTES);
					break;
				case 8:
					printf("Elegiste opcion de informes\n");
					break;
				case 9:
					printf("Gracias vuelva pronto\n");
					break;
				default:
					break;
			}
		} else {
			printf("Error con la opcion elegida - Fin\n");
		}
		printf(BARRA);
	} while(resultadoOpcion==0 && opcion!=9);
	return EXIT_SUCCESS;
}
