#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

struct CartonE{

    int vec[8];
    char direccion[15];
    //fecha tiene que ser domingo!!!

};

typedef struct CartonE * CartonPtr;

//crear caarton por teclado
CartonPtr crearCartonTeclado(); //Comprador seleccione los numeros

//crear cartor automatico
CartonPtr crearCarton1(char d[15]); //ingreso por parametros

//destruir carton
void destruirCarton(CartonPtr c);

//mostrar carton
void mostrarCarton(CartonPtr c);

//Cargar vector aleatorio sin repetir
void cargarVector(int vec[]);

//Funci�n para verificar si un n�mero ya est� en el vector
int numeroRepetido(int numero, int vec[], int longitud);

//ordena el carton
void ordenarCarton(int vec[]);

//carga vector del carton por teclado sin repetir
void cargarVectorPorTeclado(int vec[]);

#endif // CARTON_H_INCLUDED
