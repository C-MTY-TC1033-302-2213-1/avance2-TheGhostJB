/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024

¿Que aprendi al desarrollar esta clase?
Lo que aprendi al desarrollar esta clase fue como declarar una lista dentro de la clase y como con un for loop, agregar datos a la lista para poder completar nuestra
clase, como podemos ver que agrega y despliega los datos que estan en la lista sobre los episodios. 
*/

#ifndef Serie_h
#define Serie_h

// Para la herrencia
#include "Video.h"

// Para la composición
#include "Episodio.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Serie: public Video{
private:
    Episodio episodios[5];
    int cantidad;

public:
    // Metodo Constructor
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    void calculaDuracion();

    // Metodo Modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad); 

    // Metodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad(); 

    // Otros Metodos
    double calculaPromedio();

    string str();

    void agregaEpisodio(Episodio episodio);
};
#endif /* Serie.h */