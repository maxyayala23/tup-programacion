#include <stdio.h>
#include <string.h>

int main() {

    char frase[100];
    char letra;
    int contador = 0;

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Ingrese una letra: ");
    scanf("%c", &letra);

    /* Recorrer la frase */
    for (int i = 0; i < strlen(frase); i++) {

        if (frase[i] == letra) {

            contador++;
        }
    }

    printf("\nLa letra '%c' aparece %d veces.\n",
           letra,
           contador);

    return 0;
}