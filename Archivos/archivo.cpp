//Efrain Retana & Daniel Villarroel Estructura de Datos UNA

#include "archivo.h"

#include <functional>

//Funciones del h

//Función para abrir un archivo binario (append) sin la necesidad de usar el ".bin" que mencione en clase
//Existen varias formas de poder guardar este, espero que sea esta la que le guste al profe
//NOTA: Tuve que buscar una forma de mandar el bin a la carpeta Archivos
//se estaba desviando a la carpeta del builder.
//Lo unico raro seria como ver el char ruta que es un areglo de 256 caracteres para poder poner la ruta del guardado.
// Y el snprintf que es para consturir hacia esa ruta que llamamos.
FILE *abrirArchivo(const char *nombreArchivo) {
    char ruta[256];
    snprintf(ruta, sizeof(ruta), "../Archivos/%s", nombreArchivo);
    FILE* archivo = fopen(ruta, "ab");
    if (archivo == NULL) {
        printf("Error al abrir.\n");
        exit(1);
    }
    return archivo;
}
//Prompt (Retanaefrain42@gmail.com):
//¿Para que sirve el scanf?
//El scanf() en C y C++ sirve para leer datos desde la entrada estándar (generalmente el teclado) y almacenarlos en variables.
//Formato comunes:
//%d	Entero (int)	scanf("%d", &x);
//%f	Real (float)	scanf("%f", &precio);
//%lf	Doble (double)	scanf("%lf", &grande);
//%s	Cadena (char[])	scanf("%s", nombre);
//%c	Caracter (char)	scanf(" %c", &letra);

Archivo leerRegistro() {
    Archivo reg;

    printf("Ingrese el carnet: ");
    scanf("%d", &reg.carnet);

    printf("Ingrese el curso (máx 9 letras): ");
    scanf("%s", reg.curso); // No se pone & por que como es un arreglo [10] ya actua como un puntero entonces no hay que referenciarlo.

    printf("Ingrese la nota: ");
    scanf("%d", &reg.nota);

    printf("Ingrese el grupo: ");
    scanf("%d",&reg.grupo);

    return reg;
}

//Funcion para escribir el registro en el archivo
void esEscribirRegistro(FILE *archivo, Archivo reg) {
    fwrite(&reg, sizeof(Archivo),1,archivo);
}

//Funcion para cerrar el archivo
void cerrarArchivo(FILE *archivo) {

    if (archivo != NULL) {
        fclose(archivo);
    }
}


