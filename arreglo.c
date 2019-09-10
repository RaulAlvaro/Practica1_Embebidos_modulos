#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

void imprimir(int *datos){
	register int i;
	for (i = 0; i < N; i++){
		if ( !(i%16) )
			printf("\n");
		printf("%3d ", datos[i]);
	}
	printf("\n");
}

void llenar_arreglo(int *datos){
	register int n;	
	for (n = 0; n < N; n++){
		datos[n] = rand() % 255;
	}
}

int * reservar_memoria( void ){
	int *mem;
	mem = (int *) malloc( sizeof(int) * N );
	//printf("%p\n", mem);
	if ( mem == NULL){
		perror("Error de asignación de memoria");
		exit(EXIT_FAILURE);
	}
	return mem;
}
