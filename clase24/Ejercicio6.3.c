/*Escribir un programa que solicite una cadena de caracteres 
y convierta las letras minúsculas en mayúsculas y las mayúsculas en minúsculas. Luego mostrar la cadena resultante por pantalla.*/
#include <stdio.h>

int main() {

    char texto[100];
    int i = 0, n, dif;

    dif = 'a' - 'A';

    printf("Introduzca una cadena: ");
    scanf("%s", texto);

    while (texto[i] != '\0') {

        if ((texto[i] >= 'a') && (texto[i] <= 'z'))

            texto[i] -= dif;

        else if ((texto[i] >= 'A') && (texto[i] <= 'Z'))

            texto[i] += dif;

        i++;
    }

    texto[i] = '\0';

    for (n = 0; n <= i; n++)

        printf("%c", texto[n]);

    printf("\n\n");

    return 0;
}