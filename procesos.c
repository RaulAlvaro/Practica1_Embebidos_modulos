#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "defs.h"
#include "procesamiento.h"

void proceso_hijo(int np, int *datos){
	int mayor, menor, promedio, frecuencia;
	//printf("El np es: %d\n", np);
	if (np == 0){
		mayor = buscar_mayor( datos );
		exit(mayor);
	}
	else if(np == 1){
		menor = buscar_menor( datos );
		exit(menor);
	}
	else if(np == 2){
		promedio = calcula_promedio( datos );
		exit(promedio);
	}
	else if(np == 3){
		frecuencia = calcular_frecuencia( datos );
		//printf("La frecuencia que llega al proceso hijo es: %i\n", frecuencia);
		exit(frecuencia);
	}	
}

void proceso_padre(){
	pid_t pid;
	register int np;
	int estado;
	printf("\nProceso padre con pid: %d\n", getpid());
	for (np = 0; np < NUM_PROC; np++){
		pid = wait(&estado);
		//printf("Proceso hijo con pid: %d y retorna %d terminado \n", pid, estado>>8);
		if (np == 0){
			printf("Proceso mayor con pid: %d y retorna %d terminado \n", pid, estado>>8);
		}
		if (np == 1){
			printf("Proceso menor con pid: %d y retorna %d terminado \n", pid, estado>>8);	
		}
		if (np == 2){
			printf("Proceso promedio con pid: %d y retorna %d terminado \n", pid, estado>>8);
		}
		if (np == 3){
			if (estado >> 8 == 255){
				printf("Proceso frecuencia con pid: %d y retorna que más de dos numeros tienen la misma frecuencia \n", pid);
			}
			else{
				printf("Proceso frecuencia con pid: %d y retorna %d terminado \n", pid, estado>>8);	
			}
		}		
	}
}