/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024

¿Que aprendi al desarrollar esta clase?
Lo que aprendi con esta clase fue que podemos lograr utilizar herencias de la clase Video para que esta clase hija pueda tener una diferencia propia,
la cual es los oscares que tiene la pelicula.

*/

#ifndef Pelicula_h
#define Pelicula_h


#include <string>
#include <iostream>
#include "Video.h"
using namespace std;

// Clase Pelicula es derivada de Video
class Pelicula : public Video{
private:
    int oscares;

public:
    // Constructores: vacio y con paremetros
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Metodo modificador - set
    void setOscares(int _oscares);

    // Metodo de acceso
    int getOscares();

    // Otros metodos
    string str();

};

#endif /* Pelicula_h */