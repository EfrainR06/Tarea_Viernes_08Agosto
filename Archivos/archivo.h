//Efrain Retana & Daniel Villarroel Estructura de Datos UNA
#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int carnet;
    char curso[10]; //10 caracteres permitidos max
    int nota;
    int grupo;
}Archivo;

//Lo siguiente a continuacion es una prueba
//Quiero o voy a intentar asignar otro typedef struct para guardar
//exclusivamente el curso y el costo de creditos esto por que este
//se representa como el tercer archivo

typedef struct {
    char curso[10]; //misma variable
    int credits; // o coste
}Curso;

//El abrir archivo tuve que investigarlo, aparentemente existe la forma FILE *, de esta manera se abre un archivo .bin
//un ejemplo es como lo implementare aqui

FILE * abrirArchivo(const char* nombreArchivo); // Primer cuadro de diagrama

Curso leerCurso(const char* curso);

Archivo leerRegistro(const char* curso); // Segundo cuadro de diagrama

void esEscribirRegistro(FILE * archivo, Archivo reg); // El write al registro, esto puede ser el tercer cuadro, y luego el final de cerrarlo

void esEscribirCurso(FILE* archivo,Curso reg);
void cerrarArchivo(FILE * archivo); //Ultimo cuadro (el cerrar Archivo);

void organizarArchivosDani(const char* nombreArchivo1, const char* nombreArchivo2);

//Cree otro organizarArchivos para que lo viera
void organizarArchivosEfra(const char* nombreArchivo1, const char* nombreArchivo2);
//El print de toda la vida
void imprimirLista(const char* archivo);

void imprimirCursos(const char* curso);
#endif //ARCHIVO_H
