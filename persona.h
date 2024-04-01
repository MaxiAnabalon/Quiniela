#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "carton.h"


struct PersonaE{ //.nombre

    int dni;
    char nombre[15];

    //Un solo carton
    CartonPtr cartonDeLaPersona;
};

typedef struct PersonaE * PersonaPtr; //->nombre


//Constructores
//crear persona por parametro
PersonaPtr crearPersonaTeclado(); //Teclado

//crear persona por teclado
PersonaPtr crearPersona(int d, char n[15]);

//Destructor
void destruirPersona(PersonaPtr p);

//Mostrar
void mostrarPersona(PersonaPtr p);

//decir tipo de carton CARGA AUTOMATICO o CARGA MANUAL
int decidirTipoCarton();



#endif // PERSONA_H_INCLUDED
