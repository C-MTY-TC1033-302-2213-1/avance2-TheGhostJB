/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024

¿Que aprendi al desarrollar esta clase?
Lo que aprendi al desarrollar esta clase fue que aprendi a utilizar la forma de acceso Protected y sus beneficios de no hacer todas los miembros de la clase publicos
y en vez, ser posibles de llmar cuando sean necesarios. Tambien esta clase logro acordarme acerca de nuestra clase del semestre pasado, ya que me ayudo a recordar
a como aclarar los miembros en la clase.
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Video{
protected:
    // Atributos
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

public:
    // Metodos Constructores
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    // Metodos modificadores - setters - cambiar el valor de un atributo
    void setID (string _iD);
    void setTitulo (string _titulo);
    void setDuracion (int _duracion);
    void setGenero (string _genero);
    void setCalificacion (double _calificacion);

    //Metodos de acceso - getters  - retorna el valor del atributo
    string getID();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    // Otros metodos
    virtual string str();

};

#endif /* Video.hpp */