/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024

¿Que aprendi al desarrollar esta clase?
Lo que aprendi de esta clase fue algo similar a la de video, que fue declarar los miembros en la clase y recordar mi clase pasada, pero tambien para esta entrega, 
aprendi sobre como hacer diferentes formas de calificacion, ya que en esta clase, es la unica que utliza calificacion como un int, en vez de double.

*/

#ifndef Episodio_h
#define Episodio_h

#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

class Episodio{
private: 
    string titulo;
    int temporada;
    int calificacion;
public: 
    // Metodos Constructores
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    // Metodos modificadores - setters - cambiar el valor de un atributo
    void setTitulo (string _titulo);
    void setTemporada (int _temporada);
    void setCalificacion (int _calificacion);

    //Metodos de acceso - getters  - retorna el valor del atributo
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    // Otros metodos
    string str();

};


#endif /* Episodio.h */