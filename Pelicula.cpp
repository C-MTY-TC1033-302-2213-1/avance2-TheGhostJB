/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024
*/


#include "Pelicula.h"
using namespace std;

// Constructores: vacio y con paremetros
Pelicula::Pelicula():Video(){
    oscares = 100;
}
Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion){
    oscares = _oscares;
}

// Metodo modificador - set
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}

// Metodo de acceso
int Pelicula::getOscares(){
    return oscares;
}

// Otros metodos
string Pelicula::str(){
    // Tenemos acceso directo a los atributos de la clase Padre porque son protected
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " " + to_string(oscares);
}

