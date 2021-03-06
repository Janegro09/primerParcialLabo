/*
 ============================================================================
 Name        : Examen-14-10.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "clientes.h"
#include "informes.h"
#include "publicacion.h"
#define BARRA "****************************************\n"


int main(void) {
	int opcion;
	int opcionInformes;
	int idCliente;
	int indiceCliente;
	int resultadoOpcion;
	int resultadoGet;
	int rubroMasUsado;
	int cantAvisosPausados;
	int idClienteAvisos;
	int bandera=0;

	Cliente arrayClientes[SIZE_CLIENTES];
	Publicacion arrayPublicaciones[SIZE_PUBLICACIONES];
	Rubro arrayRubros[SIZE_PUBLICACIONES];

	cliente_inicializar(arrayClientes, SIZE_CLIENTES);
	cliente_harcodear(arrayClientes);
	publicacion_inicializar(arrayPublicaciones, SIZE_PUBLICACIONES);
	publicacion_harcodear(arrayPublicaciones);

	do {
		printf(BARRA);
		if(bandera==0)
		{
			printf("Bienvenido\n");
			bandera=1;
		}
		printf("Ingrese una opcion:\n"
				BARRA
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
					if(resultadoGet == 0)
					{
						printf("Alta realizada ok\n");
					} else {
						printf("Error/Cancelada alta del cliente\n");
					}
					break;
				case 2:
					resultadoGet=cliente_modificacion(arrayClientes,SIZE_CLIENTES);
					if(resultadoGet == 0)
					{
						printf("Modificacion realizada ok\n");
					} else {
						printf("Error con la modificacion del cliente\n");
					}
					break;
				case 3:
					resultadoGet=cliente_baja(arrayClientes,SIZE_CLIENTES,arrayPublicaciones,SIZE_PUBLICACIONES);
					if(resultadoGet == 0)
					{
						printf("Baja Realizada Ok\n");
					} else {
						printf("Error/Cancelada la baja del cliente\n");
					}
					break;
				case 4:
					resultadoGet=utn_getEntero("Ingrese un id\n", "Error\n", 3, SIZE_CLIENTES, 1, &idCliente);
					if(resultadoGet==0 && cliente_existeId(arrayClientes, SIZE_CLIENTES, idCliente, &indiceCliente)==0)
					{
						publicacion_alta(arrayPublicaciones, SIZE_PUBLICACIONES, idCliente);
					} else {
						printf("Error - ID invalido o intentos fallidos\n");
					}
					break;
				case 5:
					printf("Elegiste pausar publicacion\n");
					resultadoGet=publicacion_pausar_reanudar(arrayPublicaciones,SIZE_PUBLICACIONES,0);
					if(resultadoGet!=0)
					{
						printf("Error - Publicacion inexistente o invalida\n");
					}
					break;
				case 6:
					printf("Elegiste reanudar publicacion\n");
					resultadoGet=publicacion_pausar_reanudar(arrayPublicaciones,SIZE_PUBLICACIONES,1);
					if(resultadoGet!=0)
					{
						printf("Error - Publicacion inexistente o invalida\n");
					}
					break;
				case 7:
					cliente_imprimir(arrayClientes, SIZE_CLIENTES, arrayPublicaciones, SIZE_PUBLICACIONES);
					break;
				case 8:
					printf("Elegiste opcion de informes\n");
					printf("1- Cliente con mas avisos\n"
							"2- Cantidad de avisos pausados\n"
							"3- Rubro con mas avisos\n"
							"4- Cliente con mas avisos Activos(examen)\n"
							"5- Cliente con mas avisos Pausados(examen)\n");
					resultadoGet=utn_getEntero("opcion elegida:\n", "Error\n", 2, 5, 1, &opcionInformes);
					if(resultadoGet==0)
					{

						switch (opcionInformes){
						case 1:
							resultadoGet=informes_clienteMasAvisos(arrayClientes, SIZE_CLIENTES, arrayPublicaciones, SIZE_PUBLICACIONES, &idClienteAvisos);
							if(resultadoGet==0)
							{
								printf("El cliente con mas avisos es:\n");
								clientes_imprimirDatos(arrayClientes,SIZE_CLIENTES,idClienteAvisos);
							}
							break;
						case 2:
							resultadoGet=informes_cantAvisosPausados(arrayPublicaciones, SIZE_PUBLICACIONES, &cantAvisosPausados);
							if(resultadoGet==0)
							{
								printf("La cantidad de avisos pausados es %d\n",cantAvisosPausados);
							}
							break;
						case 3:
							resultadoGet=informes_rubroConMasAvisos(arrayPublicaciones, SIZE_PUBLICACIONES, arrayRubros, &rubroMasUsado);
							if(resultadoGet==0)
							{
								printf("El rubro con mas avisos es %d\n",rubroMasUsado);
							}
							break;
						case 4:
							resultadoGet=informes_clienteMasAvisosPorEstado(arrayClientes, SIZE_CLIENTES, arrayPublicaciones, SIZE_PUBLICACIONES, &idClienteAvisos,1);
							if(resultadoGet==0)
							{
								printf("El cliente con mas avisos activos es:\n");
								clientes_imprimirDatos(arrayClientes,SIZE_CLIENTES,idClienteAvisos);
							} else {
								printf("No hay publicaciones activas:\n");
							}
							break;
						case 5:
							resultadoGet=informes_clienteMasAvisosPorEstado(arrayClientes, SIZE_CLIENTES, arrayPublicaciones, SIZE_PUBLICACIONES, &idClienteAvisos,0);
							if(resultadoGet==0)
							{
								printf("El cliente con mas avisos pausados es:\n");
								clientes_imprimirDatos(arrayClientes,SIZE_CLIENTES,idClienteAvisos);
							} else {
								printf("No hay publicaciones Pausadas\n");
							}
							break;
						default:
							break;
						}
					}
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
	} while(resultadoOpcion==0 && opcion!=9);
	return EXIT_SUCCESS;
}
