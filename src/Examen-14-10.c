/*
 ============================================================================
 Name        : Examen-14-10.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "clientes.h"
#define BARRA "****************************************\n"
#define SIZE_PUBLICACIONES 1000

int main(void) {
	int opcion;
	int resultadoOpcion;
	int resultadoAlta;
	Cliente arrayClientes[SIZE_CLIENTES];


	cliente_inicializar(arrayClientes, SIZE_CLIENTES);

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
					resultadoAlta=cliente_alta(arrayClientes,SIZE_CLIENTES);
					if(resultadoAlta != 0)
					{
						printf("Error con el alta del cliente");
					}
					break;
				case 2:
					printf("Elegiste modificar datos de cliente\n");
					break;
				case 3:
					printf("Elegiste baja de cliente\n");
					break;
				case 4:
					printf("Elegiste publicar\n");
					break;
				case 5:
					printf("Elegiste pausar publicacion\n");
					break;
				case 6:
					printf("Elegiste reanudar publicacion\n");
					break;
				case 7:
					printf("Elegiste imprimir clientes\n");
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
