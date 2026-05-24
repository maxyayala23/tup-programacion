#include <stdio.h>

int main() {
/*DECLARACION DE VARIABLES*/
int arreglo [5] = {1,2,3,4,5};
int i;
int mayor = arreglo[0];

/*PROCESO*/
for(i=1 ; i<5; i+1){
    if(arreglo[i] > mayor){
        mayor= arreglo[i];
       
    }

}
/*IMPRECION EN CONSOLA*/

printf("El numero mayor es:%d",mayor);
    
    	return 0;
}
