// Incluir la biblioteca estándar de entrada/salida
#include <stdio.h>

// Definir constantes del programa
#define MAX_TEXTO 50           // Máximo de caracteres para textos (nombres, ciudades)
#define CANT_EQUIPOS 8         // Total de equipos en el campeonato
#define CANT_JUGADORES 5       // Cantidad de jugadores por categoría (titulares/suplentes)
#define EQUIPOS_SEMIFINAL 4    // Cantidad de equipos que clasifican a semifinales

// Estructura para representar un jugador
struct Jugador {
  char nombre[MAX_TEXTO];  // Nombre del jugador
  int posicion;            // Posición en la que juega (ej: 1=arquero, 2=defensa, etc.)
};

// Estructura para representar un equipo
struct Equipo {
  char nombre[MAX_TEXTO];                      // Nombre del equipo
  char ciudad[MAX_TEXTO];                      // Ciudad del equipo
  struct Jugador titulares[CANT_JUGADORES];    // Arreglo de jugadores titulares
  struct Jugador suplentes[CANT_JUGADORES];    // Arreglo de jugadores suplentes
  int cantLibertadores;                        // Cantidad de Copas Libertadores ganadas
  int puntos;                                  // Puntos obtenidos en la fase de grupos
};

// Función principal
int main() {
  // Declarar un arreglo para almacenar los 8 equipos del campeonato
  struct Equipo equipos[CANT_EQUIPOS];
  
  // Declarar un arreglo para almacenar solo los 4 equipos semifinalistas
  struct Equipo semifinalistas[EQUIPOS_SEMIFINAL];
  
  // ==========================================
  // SECCIÓN 1: INGRESAR DATOS DE LOS EQUIPOS
  // ==========================================
  
  // Bucle para recorrer cada uno de los 8 equipos
  for (int i = 0; i < CANT_EQUIPOS; i++) {
    // Mostrar encabezado del equipo actual
    printf("\n=== EQUIPO %d ===\n", i + 1);
    
    // Pedir el nombre del equipo
    printf("Ingrese el nombre del equipo %d: ", i + 1);
    fgets(equipos[i].nombre, MAX_TEXTO, stdin);  // Leer cadena completa (permite espacios)
    
    // Pedir la ciudad del equipo
    printf("Ingrese la ciudad del equipo %d: ", i + 1);
    fgets(equipos[i].ciudad, MAX_TEXTO, stdin);  // Leer cadena completa
    
    // Pedir cantidad de Libertadores ganadas
    printf("Ingrese la cantidad de libertadores ganadas por el equipo %d: ", i + 1);
    scanf("%d", &equipos[i].cantLibertadores);   // Leer número entero
    getchar();                                   // Limpiar el buffer (consume el '\n' que dejó scanf)
    
    // Pedir puntos obtenidos en la fase de grupos
    printf("Ingrese los puntos obtenidos en la fase de grupos: ");
    scanf("%d", &equipos[i].puntos);             // Leer número entero
    getchar();                                   // Limpiar el buffer
    
    // Ingresar datos de los jugadores titulares
    printf("Ingrese los titulares del equipo %d:\n", i + 1);
    // Bucle para recorrer cada jugador titular
    for (int j = 0; j < CANT_JUGADORES; j++) {
      // Pedir nombre del jugador
      printf("Jugador %d - Nombre: ", j + 1);
      fgets(equipos[i].titulares[j].nombre, MAX_TEXTO, stdin);  // Leer nombre
      
      // Pedir posición del jugador
      printf("Jugador %d - Posición: ", j + 1);
      scanf("%d", &equipos[i].titulares[j].posicion);           // Leer posición
      getchar();                                                // Limpiar el buffer
    }
    
    // Ingresar datos de los jugadores suplentes
    printf("Ingrese los suplentes del equipo %d:\n", i + 1);
    // Bucle para recorrer cada jugador suplente
    for (int j = 0; j < CANT_JUGADORES; j++) {
      // Pedir nombre del jugador
      printf("Jugador %d - Nombre: ", j + 1);
      fgets(equipos[i].suplentes[j].nombre, MAX_TEXTO, stdin);  // Leer nombre
      
      // Pedir posición del jugador
      printf("Jugador %d - Posición: ", j + 1);
      scanf("%d", &equipos[i].suplentes[j].posicion);           // Leer posición
      getchar();                                                // Limpiar el buffer
    }
  }
  
  // ==========================================
  // SECCIÓN 2: ORDENAR EQUIPOS POR PUNTOS
  // ==========================================
  
  // Algoritmo de ordenamiento de burbuja (Bubble Sort)
  // Ordena los equipos de mayor a menor según sus puntos
  
  // Bucle externo: controla cuántas pasadas se hacen
  for (int i = 0; i < CANT_EQUIPOS - 1; i++) {
    // Bucle interno: compara elementos adyacentes
    for (int j = 0; j < CANT_EQUIPOS - i - 1; j++) {
      // Si el equipo actual tiene menos puntos que el siguiente
      if (equipos[j].puntos < equipos[j + 1].puntos) {
        // Intercambiar los equipos usando una variable temporal
        struct Equipo temp = equipos[j];      // Guardar equipo j en temporal
        equipos[j] = equipos[j + 1];          // Poner equipo j+1 en posición j
        equipos[j + 1] = temp;                // Poner el temporal en posición j+1
      }
    }
  }
  
  // ==========================================
  // SECCIÓN 3: SELECCIONAR SEMIFINALISTAS
  // ==========================================
  
  // Copiar los primeros 4 equipos (los de mayor puntaje) al arreglo de semifinalistas
  for (int i = 0; i < EQUIPOS_SEMIFINAL; i++) {
    semifinalistas[i] = equipos[i];  // Copiar equipo completo
  }
  
  // ==========================================
  // SECCIÓN 4: MOSTRAR TABLA GENERAL
  // ==========================================
  
  // Mostrar encabezado de la tabla
  printf("\n========================================\n");
  printf("  TABLA GENERAL (ORDENADA POR PUNTOS)\n");
  printf("========================================\n");
  
  // Recorrer todos los equipos para mostrar la tabla completa
  for (int i = 0; i < CANT_EQUIPOS; i++) {
    // Mostrar posición y nombre del equipo
    printf("%d. %s", i + 1, equipos[i].nombre);
    
    // Mostrar ciudad del equipo
    printf("   Ciudad: %s", equipos[i].ciudad);
    
    // Mostrar puntos obtenidos
    printf("   Puntos: %d\n", equipos[i].puntos);
    
    // Mostrar cantidad de libertadores
    printf("   Libertadores: %d\n", equipos[i].cantLibertadores);
    
    // Verificar si el equipo clasificó a semifinales (primeros 4 lugares)
    if (i < EQUIPOS_SEMIFINAL) {
      printf("   *** CLASIFICADO A SEMIFINALES ***\n");  // Equipo clasificado
    } else {
      printf("   (Eliminado)\n");                        // Equipo eliminado
    }
    
    // Línea en blanco para separar equipos
    printf("\n");
  }
  
  // ==========================================
  // SECCIÓN 5: MOSTRAR DETALLE DE SEMIFINALISTAS
  // ==========================================
  
  // Mostrar encabezado de semifinalistas
  printf("\n========================================\n");
  printf("  EQUIPOS CLASIFICADOS A SEMIFINALES\n");
  printf("========================================\n");
  
  // Recorrer los 4 equipos semifinalistas
  for (int i = 0; i < EQUIPOS_SEMIFINAL; i++) {
    // Mostrar encabezado del semifinalista
    printf("\n=== SEMIFINALISTA %d ===\n", i + 1);
    
    // Mostrar datos del equipo
    printf("Equipo: %s", semifinalistas[i].nombre);
    printf("Ciudad: %s", semifinalistas[i].ciudad);
    printf("Puntos: %d\n", semifinalistas[i].puntos);
    printf("Cantidad de Libertadores: %d\n", semifinalistas[i].cantLibertadores);
    
    // Mostrar jugadores titulares
    printf("Titulares:\n");
    // Recorrer cada jugador titular
    for (int j = 0; j < CANT_JUGADORES; j++) {
      printf("- %s", semifinalistas[i].titulares[j].nombre);         // Nombre
      printf("  Posición: %d\n", semifinalistas[i].titulares[j].posicion);  // Posición
    }
    
    // Mostrar jugadores suplentes
    printf("Suplentes:\n");
    // Recorrer cada jugador suplente
    for (int j = 0; j < CANT_JUGADORES; j++) {
      printf("- %s", semifinalistas[i].suplentes[j].nombre);         // Nombre
      printf("  Posición: %d\n", semifinalistas[i].suplentes[j].posicion);  // Posición
    }
  }
  
  // Retornar 0 para indicar que el programa terminó correctamente
  return 0;
}