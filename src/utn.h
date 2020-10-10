#define SIZE_NAME 50
#define SIZE_LASTNAME 50
#define MAX_SALARIO 500000.00
#define MIN_SALARIO 0.00
#define MAX_ID 999
#define MIN_ID 0

#define ID_MAXIMO 1000
#define ID_MINIMO 1
#define SIZE_ARRAY 1000
#define BARRA_SEPARADORA "*********************************************\n"

int utn_getEntero(char* pTexto, char* pTextoError, int intentos, int maximo, int minimo, int* pOperador);
int utn_getFloat(char* pTexto, char* pTextoError, int intentos, float maximo, float minimo, float* pOperador);
int utn_getEnteroSinMaxMin(char* pTexto, char* pTextoError, int reintentos, int* pOperador);
int utn_getCadenaValida(char* pTexto, char* pTextoError, int reintentos, int sizeOperador, char* pOperador);
