#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "arreglo.h"

int buscar_menor(int *datos){
	register int i;
	int menor;
	menor = datos[0];
	for (i = 0; i < N; i++){
		if (datos[i] < menor){
			menor = datos[i];
		}
	}
	return menor;
}

int buscar_mayor(int *datos){
	register int i;
	int mayor;
	mayor = datos[0];
	for (i = 0; i < N; i++){
		if (datos[i] > mayor){
			mayor = datos[i];
		}
	}
	return mayor;
}

int calcula_promedio(int *datos){
	register int i;
	int sum = 0;
	for (i = 0; i < N; i++){
		sum = sum + datos[i];
	}
	sum = (int)sum/N;
	return sum;
}

int calcular_frecuencia(int *datos){
	int frecuencia=0, numfrec=0, repeat=0;
	register int i,j,k;
	int *vsoporte;
	
	vsoporte = reservar_memoria();
	
	for (i = 0; i < 255; i++){
		vsoporte[i] = 0;
	}

	for (j = 0; j < N; j++){
		vsoporte[datos[j]] = vsoporte[datos[j]] + 1;
		if (vsoporte[datos[j]] > frecuencia){
			frecuencia = vsoporte[datos[j]];
			numfrec = datos[j];
		}
	}

	for (k = 1; k < 255; k++){
		if (vsoporte[k] == frecuencia){
			repeat = repeat + 1;
		}
	}

	if (frecuencia < 1 || repeat > 1)
		numfrec = 255;
	free(vsoporte);
	return numfrec;
}