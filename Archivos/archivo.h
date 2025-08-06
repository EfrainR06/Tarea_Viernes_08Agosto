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

//El abrir archivo tuve que investigarlo, aparentemente existe la forma FILE *, de esta manera se abre un archivo .bin
//un ejemplo es como lo implementare aqui

FILE * abrirArchivo(const char* nombreArchivo); // Primer cuadro de diagrama

Archivo leerRegistro(); // Segundo cuadro de diagrama

void esEscribirRegistro(FILE * archivo, Archivo reg); // El write al registro, esto puede ser el tercer cuadro, y luego el final de cerrarlo

void cerrarArchivo(FILE * archivo); //Ultimo cuadro (el cerrar Archivo);
#endif //ARCHIVO_H
