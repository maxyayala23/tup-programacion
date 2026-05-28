#include <stdio.h>
#include <string.h>

int main() {

    char cadena[100];

    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    /* Eliminar el salto de linea */
    cadena[strcspn(cadena, "\n")] = '\0';

    int longitud = strlen(cadena);

    printf("\n%s tiene %d letras.\n",
           cadena,
           longitud);

    printf("%s escrita al reves es: ",
           cadena);

    /* Mostrar al reves */
    for (int i = longitud - 1; i >= 0; i--) {

        printf("%c", cadena[i]);
    }

    printf("\n");

    return 0;
}