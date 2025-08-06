//Efrain Retana Segura & Daniel Villaroeal

//Pruebas del guardado binario

#include  "archivo.h"

int main() {
    Archivo reg;
    const int cantidad = 3; //Máximo que se solicita en el diagrama, prueba con 3 para que no fuera tanto

    FILE * archivo = abrirArchivo("registros");

    for (int i = 0; i < cantidad; i++) {
        printf("\n--- Estudiante #%d ---\n", i + 1);
        reg = leerRegistro(); //Funcion en archivo de leer y registrar
        esEscribirRegistro(archivo,reg);
    }
    cerrarArchivo(archivo);

    printf("\nSe han guardado los 15 registros exitosamente.\n");
    return 0;
}