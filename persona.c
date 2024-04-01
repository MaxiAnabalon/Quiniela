
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"




//Constructores
//crear persona por parametro
PersonaPtr crearPersona(int d, char n[15]){

    PersonaPtr p = (PersonaPtr) malloc(sizeof(struct PersonaE)); //void *

    p->dni = d;
    strcpy(p->nombre, n);

    if(decidirTipoCarton()==1){
            p->cartonDeLaPersona = crearCarton1("Av. Peron 1130");
        }
        else{
            p->cartonDeLaPersona = crearCartonTeclado();
        }



    return p;


};

//cargar persona por teclado
PersonaPtr crearPersonaTeclado(){

    PersonaPtr p = (PersonaPtr) malloc(sizeof(struct PersonaE));

        printf("\nCargar Persona:\nNombre: ");
        fflush(stdin);
        gets(p->nombre);
        printf("DNI: ");
        scanf("%d", &p->dni);
        if(decidirTipoCarton()==1){
            p->cartonDeLaPersona = crearCarton1("Av. Peron 1130");
        }
        else{
            p->cartonDeLaPersona = crearCartonTeclado();
        }


    return p;
};

//Destructor
void destruirPersona(PersonaPtr p){

    destruirCarton(p->cartonDeLaPersona);
    free(p);
};

//Mostrar
void mostrarPersona(PersonaPtr p){


    printf("\n------ PERSONA ------\n");
    printf("NOMBRE: %s\n", p->nombre);
    printf("DNI: %d\n", p->dni);

    mostrarCarton(p->cartonDeLaPersona);

};

//decir tipo de carton CARGA AUTOMATICO o CARGA MANUAL
int decidirTipoCarton(){
    int num = 0;
    printf("\nDecida el tipo de carton que desea cargar, 1 automatico, 2 ingreso manual\n");

    do{
        scanf("%d", &num);
        if (num < 1 || num >2){printf("\nERROR, Ingreso invalido, ingrese nuevamente: \n");};
    }while(num < 1 || num >2);

    return num;
};
