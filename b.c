#include <stdio.h>
#include <string.h>

#define MAX_CADENAS 100
#define MAX_FECHA 11
#define MAX_CONCEPTO 100

typedef struct {
    char fecha[MAX_FECHA];
    char concepto[MAX_CONCEPTO];
} Actividad;

int validarActividad(Actividad actividad, char fechaHoy[MAX_FECHA]) {
    if (strcmp(actividad.fecha, fechaHoy) == 0) {
        return 1; // Actividad válida
    } else {
        return 0; // Actividad no válida
    }
}

int main() {
    Actividad actividades[MAX_CADENAS];
    int numActividades;

    char fechaHoy[MAX_FECHA];

    printf("Ingrese la fecha de hoy (dd/mm/yyyy): ");
    scanf("%s", fechaHoy);

    printf("Ingrese el numero de actividades: ");
    scanf("%d", &numActividades);

    for (int i = 0; i < numActividades; i++) {
        printf("Fecha de la actividad %d: ", i + 1);
        fflush(stdin);
        gets(actividades[i].fecha);
        printf("Actividad: ");
        fflush(stdin);
        gets(actividades[i].concepto);
    }

    FILE *archivo = fopen("resultado.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    fprintf(archivo, "Fecha de hoy: %s\n\n", fechaHoy);

    for (int i = 0; i < numActividades; i++) {
        fprintf(archivo, "Cadena: %s %s\n", actividades[i].fecha, actividades[i].concepto);

        int esValida = validarActividad(actividades[i], fechaHoy);

        if (esValida) {
            fprintf(archivo, "Resultado: Actividad válida\n\n");
        } else {
            fprintf(archivo, "Resultado: Actividad no válida\n\n");
        }
    }

    fclose(archivo);

    printf("Los resultados se han guardado en el archivo 'resultado.txt'.\n");

    return 0;
}
