#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

#include "defs.h"
#include "arreglo.h"
#include "procesamiento.h"
#include "procesos.h"


int main(){
	int *datos;
	pid_t pid;
	register int np;

	printf("--- Probando procesos--- \n");
	srand( getpid() );
	datos = reservar_memoria();
	llenar_arreglo( datos );
	imprimir( datos );

	for (np = 0; np < NUM_PROC; np++){
		pid = fork();
		if ( pid == - 1){
			perror("Error al crear el proceso");
			exit(EXIT_FAILURE);
		}
		if (!pid){
			proceso_hijo(np, datos);
		}
	}
	proceso_padre();

	free(datos);
	return 0;	
}

//int dato_con
// TAREAS
// - Calcular promedio (debe ser un entero)
// - Calcular la frecuencia (moda)

// - Programa con principal.c --> tendra la función main
// - Programa procesos.c --> tendrá el código del proceso padre y del hijo

// - Programa arreglos.c --> función que reserva memoria para el arreglo, 
//   llena el arreglo, y la función que improime el arreglo

// - Programa procesamiento.c --> se encontraran las 4 funciones (busca mayor, busca menor, promedio, frecuencia)

// Mecanismo IPC para comunicar procesos (exit y wait para numeros de 8 bits)
// Cuando necesitamos regresar un bloque de datos se agrega una funcion de ordenamiento