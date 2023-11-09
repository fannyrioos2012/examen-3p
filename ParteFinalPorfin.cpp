#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNAS 50
#define FILAS_A_PROCESAR 50
#define LONGITUD_MAXIMA_LINEA 30000

int main() {
    FILE *archivo_csv = fopen("emails.csv", "r");
    if (!archivo_csv) {
        perror("Error al abrir el archivo CSV");
        return 1;
    }

    char buffer[LONGITUD_MAXIMA_LINEA];
    char *nombres_palabras[MAX_COLUMNAS];
    int conteo_palabras[MAX_COLUMNAS] = {0};
    int id_numero = 680;

    if (fgets(buffer, sizeof(buffer), archivo_csv)) {
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna <= MAX_COLUMNAS) {
            nombres_palabras[columna] = strdup(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    for (int fila_actual = 0; fila_actual <= id_numero && fgets(buffer, sizeof(buffer), archivo_csv); ++fila_actual) {
        // Procesar las filas hasta el id_numero
    }

    for (int fila_actual = 0; fila_actual < FILAS_A_PROCESAR && fgets(buffer, sizeof(buffer), archivo_csv); ++fila_actual) {
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < MAX_COLUMNAS) {
            conteo_palabras[columna] += atoi(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    fclose(archivo_csv);

    FILE *archivo_salida = fopen("180680.txt", "w");
    if (!archivo_salida) {
        perror("Error al abrir el archivo de salida");
        for (int i = 0; i < MAX_COLUMNAS; i++) {
            free(nombres_palabras[i]);
        }
        return 1;
    }

    for (int i = 0; i < MAX_COLUMNAS && nombres_palabras[i] != NULL; i++) {
        fprintf(archivo_salida, "%s, %d\n", nombres_palabras[i], conteo_palabras[i]);
        free(nombres_palabras[i]);
    }

    fclose(archivo_salida);
    printf("El contenido est� en 180680.txt\n");

    return 0;
}

