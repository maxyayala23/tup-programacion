#include <stdio.h>

int main() {
/*DECLARACION DE VARIABLES*/
	int a,b,opcion,valido,salir;
	int suma,resta,mult,resto;
	float div;
	
/*INGRESO DE DATOS*/
	do{
	do{
		printf("*********************************************\n");
		printf("\n          INGRESE LOS VALORES                ");
		printf("\n********************************************\n");
		printf("Ingrese el primer entero:");
		valido = scanf("%d",&a);
			if(valido != 1){
				while(getchar() != '\n');
			}
	} while(valido !=1);
	
	do{    
		printf("\nIngrese el segundo entero:");
		valido = scanf("%d",&b);
			if(valido != 1){
				while(getchar() != '\n');
			}
    } while(valido !=1);
	
	/*PROCESOS*/

	printf("*********************************************\n");
	printf("\n               CALCULADORA                    ");
	printf("\n********************************************\n");
	
	printf("1-Suma\n");
	printf("2-Resta\n");
	printf("3-Producto\n");
	printf("4-Division\n");
	printf("5-Resto\n");
	printf("SELECION:");
	scanf("%d",&opcion);
	
	switch(opcion){
		case 1:
			suma = a + b;
			printf("a + b = %d",suma);
			break;
		case 2:
			resta = a - b;
			printf("a - b = %d",resta);
			break;
		case 3:
			mult = a * b;
			printf("a x b = %d",mult);
			break;
		case 4:
			div = (float)a / b;
			printf("a / b = %.2f", div);
			break;
		case 5:
			resto = a % b;
			printf("El resto entre a y b es: %d",resto);
			break;
		default:printf("INVALIDO");
	}
	printf("\nSi desea seguir calculando presione cualquier tecla, si decea salir presione 0: ");
	scanf("%d",&salir);
	
	} while(salir != 0);
	return 0;
}

/* Escribe un programa en C que:

Lea dos números enteros ingresados por el usuario (llámalos a y b).

Utilizando operadores matemáticos, calcule y muestre:

La suma (a + b)

La resta (a - b)

La multiplicación (a * b)

La división entera (a / b, considerando que b no es cero)

El resto de la división entera (a % b)

Utilizando operadores relacionales, compare a y b y muestre el resultado (1 si es verdadero, 0 si es falso) de:

a == b

a != b

a > b

a < b

a >= b

a <= b

Utilizando operadores lógicos, calcule y muestre el resultado (1 o 0) de:

(a > b) && (b != 0)

(a > b) || (b != 0)

Demuestre el uso de operadores de asignación combinados:

A la variable a asígnele el valor original de a más b usando += y luego muestre el nuevo valor de a.

A la variable b asígnele el valor original de b multiplicado por 2 usando *= y luego muestre el nuevo valor de b.

Restricción: No uses estructuras de decisión (como if). Solo utiliza expresiones con operadores y muestra los resultados con printf. Recuerda incluir #include <stdio.h> y usar scanf para la entrada.*/