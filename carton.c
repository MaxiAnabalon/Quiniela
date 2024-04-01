

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "carton.h"


//crear caarton por teclado
CartonPtr crearCartonTeclado(){

    CartonPtr c = (CartonPtr) malloc(sizeof(struct CartonE));

    printf("\n------ CARGAR CARTON -----\n");

    printf("DIRECCION:\n");
    fflush(stdin);
    gets(c->direccion);

    cargarVectorPorTeclado(c->vec);

    ordenarCarton(c->vec);

    return c;
};

//crear cartor automatico
CartonPtr crearCarton1(char d[15]){

    CartonPtr c = (CartonPtr) malloc(sizeof(struct CartonE));

    strcpy(c->direccion, d);

    cargarVector(c->vec);

    ordenarCarton(c->vec);

    return c;

};

//destruir carton
void destruirCarton(CartonPtr c){
    free(c);
};

//mostrar carton
void mostrarCarton(CartonPtr c){

    printf("\n\t------ CARTON ----\n");
    printf("\tDIRECCION: %s\n\t-------------------------------------\n\t|| ", c->direccion);
    //mostrarVector
    for (int i =0 ; i<8; i++){

        printf(" %d ", c->vec[i]);

    }
    printf(" ||\n\t-------------------------------------\n");


};

//Cargar vector aleatorio sin repetir
void cargarVector(int vec[]){
    for ( int i = 0 ; i<8; i++){
    int numero;
        do {
            numero = rand() % 100; // Genera un número aleatorio en el rango de 0 a 99
        } while (numeroRepetido(numero,vec, i)); // Verifica si el número está repetido en el vector

        vec[i] = numero; // Asigna el número al vector
    }
};

// Función para verificar si un número ya está en el vector
int numeroRepetido(int numero, int vec[], int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (vec[i] == numero) {
            return 1; // Retorna 1 si el número está repetido
        }
    }
    return 0; // Retorna 0 si el número no está repetido
};

//ordena el carton
void ordenarCarton(int vec[]){
    int aux;

    for (int i = 0; i < 8-1; i++) {
        for (int j = i+1; j < 8; j++) {
            if (vec[j] < vec[i]) {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

//carga vector del carton por teclado sin repetir
void cargarVectorPorTeclado(int vec[]){
    printf("Ingrese los 8 numeros de 0 a 99, no se pueden repetir:\n");

    for ( int i = 0 ; i<8; i++){
    int numero;
        do {
            scanf("%d", &numero);
            if ((numeroRepetido(numero,vec,i))== 1 || numero < 0 || numero > 99){printf("ERROR, numero repetido..., nuevo ingreso:\n");};
        } while (numeroRepetido(numero,vec, i) || numero < 0 || numero > 99); // Verifica si el número está repetido en el vector

        vec[i] = numero; // Asigna el número al vector
    }
};
