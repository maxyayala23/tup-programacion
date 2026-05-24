#include <stdio.h>
#include <windows.h>
int main() {
/*DECLARACION DE VARIABLES*/
	int edad,valido;
	char inicial;
	float altura;
/*INGRESO DE DATOS*/
	printf("Ingrese la inical de su nombre:");
	scanf(" %c",&inicial);
	
	do{
		printf("\nIngrese su edad:");
		valido = scanf("%d",&edad);
			if(valido != 1){
				printf("Ingrese un valor correcto\n");
				while(getchar() == '\n');
			}
	} while(valido != 1);
	
	do{
		printf("\nIngrese su altura en metros:");
		valido = scanf("%f",&altura);
			if(valido != 1){
				printf("Ingrese un valor correcto\n");
				while(getchar() == '\n');
				
			}
		
	} while(valido != 1);
	/*IMPRECION EN CONSOLA*/
	printf("*************************************\n");
	printf("Cargando datos con IA...\n");
	printf(".\n");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	printf(".\n");
	Sleep(1000);
	printf("\nPreparando resultados");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf("\n**************************************\n");
	printf("La primer letra de su nombre es:%c",inicial);
	printf("\nSu edad es:%d",edad);
	printf("\nSu altura en mertos es: %.2f",altura);
	printf("\n**************************************");
	
	
	
	
	
	
	return 0;
}