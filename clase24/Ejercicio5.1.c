#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

struct Cliente {
    int nroCliente;
    char tipoCliente;
    char nombre[50];
    char nroContacto[20];
};

/* Prototipos */
void ordenarClientes(struct Cliente clientes[], int n);
void mostrarClientes(struct Cliente clientes[], int n);
int busquedaBinaria(struct Cliente clientes[], int n, int nroCliente);

void separarClientes(struct Cliente clientes[],
                     int n,
                     struct Cliente tipoE[],
                     struct Cliente tipoP[]);

int main() {

    struct Cliente clientes[MAX_CLIENTES];
    struct Cliente tipoE[MAX_CLIENTES];
    struct Cliente tipoP[MAX_CLIENTES];

    int n;

    printf("Ingrese la cantidad de clientes (max %d): ", MAX_CLIENTES);
    scanf("%d", &n);

    /* Validar cantidad */
    if (n <= 0 || n > MAX_CLIENTES) {

        printf("Cantidad invalida.\n");
        return 1;
    }

    /* Carga de datos */
    for (int i = 0; i < n; i++) {

        printf("\n===== CLIENTE %d =====\n", i + 1);

        printf("Numero de Cliente: ");
        scanf("%d", &clientes[i].nroCliente);

        printf("Tipo de Cliente (E/P): ");
        scanf(" %c", &clientes[i].tipoCliente);

        getchar();

        printf("Nombre del Cliente: ");
        fgets(clientes[i].nombre,
              sizeof(clientes[i].nombre),
              stdin);

   

        printf("Numero de Contacto: ");
        fgets(clientes[i].nroContacto,
              sizeof(clientes[i].nroContacto),
              stdin);


    }

    /* Ordenar */
    ordenarClientes(clientes, n);

    /* Mostrar */
    mostrarClientes(clientes, n);

    /* Busqueda binaria */
    int nroBusqueda;

    printf("\nIngrese el numero de cliente a buscar: ");
    scanf("%d", &nroBusqueda);

    int posicion = busquedaBinaria(clientes, n, nroBusqueda);

    if (posicion != -1) {

        printf("\n===== CLIENTE ENCONTRADO =====\n");

        printf("Numero: %d\n", clientes[posicion].nroCliente);
        printf("Tipo: %c\n", clientes[posicion].tipoCliente);
        printf("Nombre: %s\n", clientes[posicion].nombre);
        printf("Contacto: %s\n", clientes[posicion].nroContacto);

    } else {

        printf("\nCliente no encontrado.\n");
    }

    /* Separar clientes */
    separarClientes(clientes, n, tipoE, tipoP);

    return 0;
}



void ordenarClientes(struct Cliente clientes[], int n) {

    struct Cliente aux;
    for (int i = 0; i < n - 1 ; i++) {

        for (int j = 0; j < n -i -1; j++) {

            if (clientes[j].nroCliente >
                clientes[j + 1].nroCliente) {

                aux = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = aux;
            }
        }
    }
}



void mostrarClientes(struct Cliente clientes[], int n) {

    int totalE = 0;
    int totalP = 0;

    printf("\n========================================================\n");
    printf("                LISTADO DE CLIENTES\n");
    printf("========================================================\n");

    printf("%-12s %-10s %-20s %-15s\n",
           "NroCliente",
           "Tipo",
           "Nombre",
           "Contacto");

    for (int i = 0; i < n; i++) {

        printf("%-12d %-10c %-20s %-15s\n",
               clientes[i].nroCliente,
               clientes[i].tipoCliente,
               clientes[i].nombre,
               clientes[i].nroContacto);

        if (clientes[i].tipoCliente == 'E' ||
            clientes[i].tipoCliente == 'e') {

            totalE++;

        } else if (clientes[i].tipoCliente == 'P' ||
                   clientes[i].tipoCliente == 'p') {

            totalP++;
        }
    }

    printf("\nTotal de Clientes: %d\n", n);
    printf("Total Tipo E: %d\n", totalE);
    printf("Total Tipo P: %d\n", totalP);
}



int busquedaBinaria(struct Cliente clientes[],
                    int n,
                    int nroCliente) {

    int izquierda = 0;
    int derecha = n - 1;

    while (izquierda <= derecha) {

        int medio = (izquierda + derecha) / 2;

        if (clientes[medio].nroCliente == nroCliente) {

            return medio;

        } else if (clientes[medio].nroCliente < nroCliente) {

            izquierda = medio + 1;

        } else {

            derecha = medio - 1;
        }
    }

    return -1;
}



void separarClientes(struct Cliente clientes[],
                     int n,
                     struct Cliente tipoE[],
                     struct Cliente tipoP[]) {

    int j = 0;
    int k = 0;

    for (int i = 0; i < n; i++) {

        if (clientes[i].tipoCliente == 'E' ||
            clientes[i].tipoCliente == 'e') {

            tipoE[j] = clientes[i];
            j++;

        } else if (clientes[i].tipoCliente == 'P' ||
                   clientes[i].tipoCliente == 'p') {

            tipoP[k] = clientes[i];
            k++;
        }
    }

    printf("\n===== CLIENTES TIPO E =====\n");

    for (int i = 0; i < j; i++) {

        printf("%d - %s\n",
               tipoE[i].nroCliente,
               tipoE[i].nombre);
    }

    printf("\n===== CLIENTES TIPO P =====\n");

    for (int i = 0; i < k; i++) {

        printf("%d - %s\n",
               tipoP[i].nroCliente,
               tipoP[i].nombre);
    }
}