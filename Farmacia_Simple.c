#include <stdio.h>
#include <string.h>

#define NOMBRE 50

int main() {
    char Nombre_med[NOMBRE];
    int cantidad;
    float precio, descuento;
    char caducidad[NOMBRE];
    int Num_med;

    printf("---------Bienvenido a MediStor----------\n");
    printf("Ingreso de Stock:\n");

    printf("Cuantos medicamentos se va a ingresar: ");
    scanf("%d", &Num_med);

    for (int i = 0; i < Num_med; i++) {
        printf(" Medicamento %d :\n", i + 1);
        printf("Nombre: ");
        scanf("%s", Nombre_med);
        printf("Cantidad: ");
        scanf("%d", &cantidad);
        printf("Precio unitario: ");
        scanf("%f", &precio);
        printf("Porcentaje Descuento (Ingrese -1 si no lo tiene): ");
        scanf("%f", &descuento);
        printf("Fecha de caducidad (DD/MM/AAAA): ");
        scanf("%s", caducidad);

        printf("\n----------------------Informacion del Medicamento ----------------------\n");
        printf("%-15s %8s %10s %11s %-10s %10s\n", "Nombre", "Cantidad", "Precio", "Descuento", "Caducidad", "Precio Final");
        printf("------------------------------------------------------------------------\n");

        float precioFinal = precio * (1 - descuento / 100);
        printf("%-15s %8d %10.2f %10.2f %-10s %10.2f\n", Nombre_med, cantidad, precio, descuento, caducidad, precioFinal);
    }

    int buscar;
    printf("Desea buscar medicamentos (Si = 1, No = 0): ");
    scanf("%d", &buscar);
    if (buscar == 1) {
        char Buscar[NOMBRE];
        printf("Ingrese el nombre a buscar: ");
        scanf("%s", Buscar);

        int encontrado = 0;
        for (int i = 0; i < Num_med; i++) {
            if (strcmp(Nombre_med, Buscar) == 0) {
                printf("Encontrado\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("No Encontrado\n");
        }
    }

    return 0;
}
