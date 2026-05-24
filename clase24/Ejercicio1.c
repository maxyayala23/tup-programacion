#include <stdio.h>

int main() {
	int anio;
	float precio,valido1;
	char inicial;
	

	
	printf("*************************************\n");
	printf("**********INGRESO DE DATOS***********\n");
	printf("*************************************\n");
	do{                         
	printf("Ingrese el precio de su bicicleta:");
	valido1 = scanf("%f",&precio);
		if(valido1!=1){              
			printf("Invalido, intente nuevamente\n");
		
			while(getchar()!='\n');
	}
	
	}while(valido1 != 1);
	

	printf("\nIngrese la inicial de la marca de su bicicileta:");
	scanf(" %c",&inicial);
    
	do{
	printf("\nIngrese el anio de fabricacion de su bicicleta:");
	valido1 = scanf("%d",&anio);
		if(valido1!=1){              
		printf("Invalido, intente nuevamente\n");
		
		while(getchar()!='\n');
	}
	}while(valido1 != 1);
	
	printf("********DATOS DE LA BICICLETA********\n");
	printf("*************************************\n");
	printf("*   El anio de fabricion es:%d       ",anio);
	printf("\n*   La inicial de la marca es:%c     ",inicial);
	printf("\n*   El precio es:$%2.f                ",precio);
	printf("\n*************************************");
	
	return 0;
}


/*Enunciado del problema: Registro básico de una bicicleta Escribí un programa en C que declare e inicialice las variables necesarias para guardar la información de una bicicleta. 

El programa debe almacenar: la cantidad de ruedas (dato fijo que no cambia) el precio de la bicicleta la letra inicial de la marca el año de fabricación Requisitos La cantidad de ruedas debe guardarse como constante. 

El precio debe guardarse en una variable de tipo float. La inicial de la marca debe guardarse en una variable de tipo char. 

El año de fabricación debe guardarse en una variable de tipo int. Asigná valores válidos a cada dato al momento de declarar las variables.*/
