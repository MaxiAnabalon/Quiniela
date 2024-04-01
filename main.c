#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "persona.h"
#include "carton.h"
#include "sorteo.h"

///Docentes, Nico, Javi Vescio y Diego Ca�ete
//Usamos mucho el SLACK para las preguntas r�pidas
//Todo estar� siempre disponible en el material digital
///Tienen una guia de TPs, con los ejercicios que les iremos pidiendo
//Y en caso que no esten cancheros u olvidaron C, les dejamos un repaso de programaci�n
///Hay un total de 8 clases antes del parcial, en cada clase habr� 1 tarea o 2,para entregar
///Adem�s tienen un TP final individual.




///repaso - Unidad 0
//Tp de nivelaci�n, quiniela Plus
//Un jugador (nombre y dni) compra un cart�n (8 numeros del 0 al 99 sin repetir y ordenados)
//Se sortean 20 numeros, del 0 al 99, ac� si se pueden repetir, si adivinaste los 8 tenes el primer premio
//con 7 o 6 aciertos premios inferiores.


int main()
{
    srand(time(0));
    printf("------ Clase 1 - AYED - REPASO -------\n");

    char continuar = 's'; // Variable para almacenar la respuesta del usuario

    while (continuar == 's' || continuar == 'S') {
    system("cls");
    PersonaPtr jugador = crearPersonaTeclado();
    //PersonaPtr jugador = crearPersona(123, "Nico");

    mostrarPersona(jugador);


    SorteoPtr sort = realizarSorteo();
    mostrarSorteo(sort);

    verificarTriunfo(buscarCantidadAciertos(jugador, sort));

    consultaProbalidadGanar(jugador);

    destruirPersona(jugador);
    destruirSorteo(sort);

    printf("\nDesea seguir jugando? (s/n): ");
    scanf(" %c", &continuar); // Leer la respuesta del usuario

    }

    return 0;
}
