#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sorteo.h"
#include "persona.h"


//realizar sorteo
SorteoPtr realizarSorteo() {
    SorteoPtr s = (SorteoPtr) malloc(sizeof(struct SorteoE));

    for(int i=0; i<20; i++){
        s->juego[i] = rand()%100;
    }

    return s;
};

//mostrar sorteo
void mostrarSorteo(SorteoPtr s){

    printf("\n\n\t\t   ------------------ SORTEO ---------------- \n\n{{{ ");
    //mostrarSorteo
    for (int i =0 ; i<20; i++){

        printf(" %d ", s->juego[i]);

    }
    printf(" }}}\n------------------------------------------------------------------------------------- \n");
}

//buscar cantidad aciertos y devuelve un numero segun el caso
int buscarCantidadAciertos(PersonaPtr p, SorteoPtr s){
    int x=0;
    int aciertosRegistrados[20] = {0};

    FILE *archivo = fopen("numeros_ganadores.txt", "w");

    printf("\nVERIFICAMOS CARTON, NUMEROS ACERTADOS: ");
    for(int i=0; i<8; i++){
        int encontrado = 0;
        for(int j=0; j<20; j++){

            if(p->cartonDeLaPersona->vec[i] == s->juego[j] && !aciertosRegistrados[j]){
                x = x + 1;
                encontrado = 1;
                aciertosRegistrados[j] = 1;// Marcar el acierto como registrado
                break;
            }
        }
        if (encontrado) {
            printf(" *{{ %d }}* ", p->cartonDeLaPersona->vec[i]); // Imprimir el número entre llaves si es un acierto
            fprintf(archivo, "{%d}\n", p->cartonDeLaPersona->vec[i]);
        } else {
            printf(" %d ", p->cartonDeLaPersona->vec[i]); // Imprimir el número sin llaves si no es un acierto
            //fprintf(archivo, " %d ", carton->vec[i]);
        }

    }
    printf("\n\nCANTIDAD DE ACIERTOS: %d", x);
    fclose(archivo);
    return x;
};

//realizar verificacion triunfo Y premio
void verificarTriunfo(int num){

    if (num == 2){printf("\n\n###  FELICIDAD SE GANO LA LOTERIA, PREMIO MAXIMO, GANO 10 MILLONES DE PESOS .....!!!\n");}
    else if (num == 7){printf("\n\n###  FELICIDAD SE GANO SEGUNDO PREMIO, GANO 3 MILLONES DE PESOS .....!!!\n\n");}
    else if (num == 6){printf("\n\n###  FELICIDAD SE GANO TERCER PREMIO, GANO 1 MILLON DE PESOS .....!!!\n\n");}
    else {printf("\n\nPERDIO, TUVO MENOS DE 6 ACIERTOS, VUELVA A INTENTARLO ..... !!!!\n\n");};
};

//destruir sorteo
void destruirSorteo(SorteoPtr s){
    free(s);
};

// procedimiento que llama a saber cantidad de sorteos para ganar
void consultaProbalidadGanar(PersonaPtr p) {
    char cond = 's';
    printf("\nDesea saber cauntos sorteos necesitaria aprox. para ganar con este carton? (s/n): ");
    scanf(" %c", &cond);

    if(cond == 's' || cond == 'S'){
        jugarHastaGanar(p);
    }
}

// Procedimiento para simular jugar hasta lograr 8 aciertos
void jugarHastaGanar(PersonaPtr p) {
    int intentos = 0;

    while (1) {
        intentos++;
        int aciertos = 0;
        int aciertosRegistrados[20] = {0};
        int sorteo[20]; // Sorteo de 20 números
        // Generar el sorteo
        for (int i = 0; i < 20; i++) {
            sorteo[i] = rand()%100; // Números aleatorios entre 0 y 99
        }
        // Verificar si los números sorteados coinciden con algún número del cartón
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 20; j++) {
                if (sorteo[j] == p->cartonDeLaPersona->vec[i] && !aciertosRegistrados[j]) {
                    aciertos++;
                    aciertosRegistrados[j] = 1;
                    break; // Salir del bucle interno si hay un acierto
                }
            }
        }
        if (aciertos == 6) {
            printf("\nSe necesitaron %d sorteos para ganar con el mismo carton.\n", intentos);
            break; // Salir del bucle si hay 8 aciertos
        }
    }
}

