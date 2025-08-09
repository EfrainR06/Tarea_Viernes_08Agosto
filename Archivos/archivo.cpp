//Efrain Retana & Daniel Villarroel Estructura de Datos UNA

#include "archivo.h"
#include <string.h>
#include <functional>

//Funciones del h

//Función para abrir un archivo binario (append) sin la necesidad de usar el ".bin" que mencione en clase
//Existen varias formas de poder guardar este, espero que sea esta la que le guste al profe
//NOTA: Tuve que buscar una forma de mandar el bin a la carpeta Archivos
//se estaba desviando a la carpeta del builder.
//Lo unico raro seria como ver el char ruta que es un areglo de 256 caracteres para poder poner la ruta del guardado.
// Y el snprintf que es para construir hacia esa ruta que llamamos.

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

Archivo leerRegistro(const char* curso) {
    Archivo reg;

    printf("Ingrese el carnet: ");
    scanf("%d", &reg.carnet);

    // printf("Ingrese el curso (máx 9 letras): ");
    // scanf("%s", reg.curso); // No se pone & por que como es un arreglo [10] ya actua como un puntero entonces no hay que referenciarlo.

    //Use para poder copiar de un curso a otro la función strncpy, la busque y su fucnion es esta
    //prompt(Retanaefrain42@gmail.com):
    //Strncpy copia una cantidad limitada de caracteres de una cadena a otra,
    //evitando desbordamientos y asegurando que no se sobrapese el tamaño del
    //destino. ideal para copiar strings de forma segura.

    //Lo que hice fue un copy paste del formato char del nombre del curso al otro
    // Esto debido a que cuando toque hacer el ordenamiento hay que ordenar por cursos
    // el mejor promedio y tambien por grupo, entonces con facilidad ya lo tiene

    strncpy(reg.curso, curso, sizeof(reg.curso));
    reg.curso[sizeof(reg.curso) - 1] = '\0';

    printf("Ingrese la nota: ");
    scanf("%d", &reg.nota);

    printf("Ingrese el grupo: ");
    scanf("%d",&reg.grupo);

    return reg;
}

Curso leerCurso(const char* curso) {
    Curso reg;

    strncpy(reg.curso, curso, sizeof(reg.curso));
    reg.curso[sizeof(reg.curso)-1] = '\0';

    printf("Ingrese los créditos del curso: ");
    scanf("%d", &reg.credits);

    return reg;
}

//Funcion para escribir el registro en el archivo
void esEscribirRegistro(FILE *archivo, Archivo reg) {
    fwrite(&reg, sizeof(Archivo),1,archivo);
}

void esEscribirCurso(FILE* archivo, Curso reg) {
    fwrite(&reg, sizeof(Archivo), 1, archivo);
}

//Funcion para cerrar el archivo
void cerrarArchivo(FILE *archivo) {

    if (archivo != NULL) {
        fclose(archivo);
    }
}
//Dani si ve esto, cambie su metodo xddd
void organizarArchivosDani(const char* nombreArchivo1, const char* nombreArchivo2) {
    
    FILE* A = abrirArchivo(nombreArchivo1);
    FILE* B = abrirArchivo(nombreArchivo2);
    FILE* Combinado = abrirArchivo("Combinado");
    Archivo array[100];
    int a = 0, b = 0, c;


    Archivo archiA;
    Archivo archiB;
    Archivo archiC;


    while (fread(&archiA, sizeof(Archivo), 1, A) == 1) {
        a++;
    }

    while (fread(&archiB, sizeof(Archivo), 1, B) == 1) {
        b++;
    }

    c = a + b;

    for (int i = 0; i < c - 1; i++) {
        for (int j = 0; j < c - 1 - i; j++) {
            if (array[j].nota < array[j + 1].nota) {
                archiC = array[j];
                array[j] = array[j + 1];
                array[j + 1] = archiC;
            }
        }
    }

    for (int i = 0; i < c; i++) {
        esEscribirRegistro(Combinado, array[i]);
    }
}
void organizarArchivosEfra(const char *nombreArchivo1, const char *nombreArchivo2) {
    Archivo array[200];
    int count = 0;

    //Abrir archivos para leerlos
    char ruta1[256], ruta2[256], rutaOut[256];
    snprintf(ruta1, sizeof(ruta1),"../Archivos/%s", nombreArchivo1);
    snprintf(ruta2, sizeof(ruta2), "../Archivos/%s", nombreArchivo2);
    snprintf(rutaOut, sizeof(rutaOut), "../Archivos/Combinado.bin");

    FILE * A = fopen(ruta1, "rb");
    FILE * B = fopen(ruta2, "rb");
    FILE * Combinado = fopen(rutaOut, "wb");
    if (!A || !B || !Combinado) {
        printf("Error abriendo archivos \n");
        if (A) fclose(A);
        if (B) fclose(B);
        if (Combinado) fclose(Combinado);
        return;
    }
    //Va a leer archivo 1 grupo 1.bin
    while (fread(&array[count],sizeof(Archivo),1,A) == 1) {
        count++;
    }
    //Va a leer archivo 2 grupo2.bin
    while (fread(&array[count], sizeof(Archivo),1,B) == 1) {
        count++;
    }
    //Sort by nota descending
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (array[j].nota < array[j + 1].nota) {
                Archivo temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    //Escribe el orden grabado para tirarlo al output
    for (int i = 0 ; i < count; i++) {
        fwrite(&array[i],sizeof(Archivo),1,Combinado);
    }
    fclose(A);
    fclose(B);
    fclose(Combinado);
}

void imprimirLista(const char* archivo) {
    char ruta[256];
    snprintf(ruta, sizeof(ruta), "../Archivos/%s", archivo);
    FILE* f = fopen(ruta, "rb");
    if (!f) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        return;
    }

    Archivo reg;
    int i = 1;
    printf("Lista de registros en %s:\n", archivo);
    while (fread(&reg, sizeof(Archivo), 1, f) == 1) {
        printf("Registro #%d:\n", i++);
        printf("  Carnet: %d\n", reg.carnet);
        printf("  Curso: %s\n", reg.curso);
        printf("  Nota: %d\n", reg.nota);
        printf("  Grupo: %d\n", reg.grupo);
    }
    fclose(f);
}

void imprimirCursos(const char* curso) {
    char ruta[256];
    snprintf(ruta, sizeof(ruta), "../Archivos/%s",curso);
    FILE * f = fopen(ruta,"rb");
    if (!f) {
        printf(" No se pudo abrir el archivo %s\n", curso);
        return;
    }
    Curso reg;
    int i = 1;
    printf("Lista de registros en %s:\n", curso);
    while (fread(&reg, sizeof(Curso), 1, f) == 1) {
        printf("Curso #%d:\n", i++);
        printf("Curso: %s\n", reg.curso);
        printf("Creditos: %d\n",reg.credits);
    }
    fclose(f);
}