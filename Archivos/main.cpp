#include "archivo.h"
#include <string.h>
#include <stdio.h>

int main() {

    //  Paso 1: Abrir y crear archivos para los grupos y cursos
    int numCursos;
    printf("Cuantos cursos desea ingresar? ");
    scanf("%d", &numCursos);

    FILE* archivoGrupo1 = abrirArchivo("1group.bin");
    FILE* archivoGrupo2 = abrirArchivo("2group.bin");
    FILE* archivoCursos = abrirArchivo("cursos.bin");

    for (int c = 0; c < numCursos; c++) {
        Archivo reg;
        Curso cursoInfo;
        char curso[10];
        int cantidad;

        printf("\n--- Curso #%d ---\n", c + 1);
        printf("Ingresa el nombre del curso (maximo 9 letras): ");
        scanf("%9s", curso);

        // Save course info to cursos.bin
        cursoInfo = leerCurso(curso);
        fwrite(&cursoInfo, sizeof(Curso), 1, archivoCursos);

        printf("Cuantos estudiantes para este curso? ");
        scanf("%d", &cantidad);

        for (int i = 0; i < cantidad; i++) {
            printf("\n--- Estudiante #%d ---\n", i + 1);
            reg = leerRegistro(curso);

            if (reg.grupo == 1) {
                esEscribirRegistro(archivoGrupo1, reg);
            } else if (reg.grupo == 2) {
                esEscribirRegistro(archivoGrupo2, reg);
            } else {
                printf("Grupo invalido. Solo grupo 1 o 2 permitido.\n");
            }
        }
    }

    cerrarArchivo(archivoGrupo1);
    cerrarArchivo(archivoGrupo2);
    cerrarArchivo(archivoCursos);

    printf("\nTodos los grupos y cursos han sido guardados exitosamente.\n");

    //  Paso 2: Ordenamiento de los archivos
    //  Paso 2: Ordenamiento de los archivos
    organizarArchivos("1group.bin", "2group.bin");

    return 0;
}