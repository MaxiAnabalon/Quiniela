#ifndef SORTEO_H_INCLUDED
#define SORTEO_H_INCLUDED


#include "persona.h"

struct SorteoE{
    int juego[20];
};

typedef struct SorteoE * SorteoPtr;

//realizar sorteo
SorteoPtr realizarSorteo();

//mostrar sorteo
void mostrarSorteo(SorteoPtr s);

//buscar cantidad aciertos y devuelve un numero segun el caso
int buscarCantidadAciertos(PersonaPtr p, SorteoPtr s);

//realizar verificacion triunfo Y premio
void verificarTriunfo(int num);

//destruir sorteo
void destruirSorteo(SorteoPtr s);

// procedimiento que llama a saber cantidad de sorteos para ganar
void consultaProbalidadGanar(PersonaPtr p);

// Procedimiento para simular jugar hasta lograr 8 aciertos
void jugarHastaGanar(PersonaPtr p);


#endif // SORTEO_H_INCLUDED
