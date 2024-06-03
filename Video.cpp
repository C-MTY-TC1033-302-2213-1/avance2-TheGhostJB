/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024
*/

#include "Video.h"
using namespace std;

// Metodos Constructores
Video::Video(){
    iD = "0000";
    titulo = "Batman";
    duracion = 1000;
    genero = "accion";
    calificacion = 9.9999;
}
Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

// Metodos modificadores - setters - cambiar el valor de un atributo
void Video::setID (string _iD){
    iD = _iD;
}
void Video::setTitulo (string _titulo){
    titulo = _titulo;
}
void Video::setDuracion (int _duracion){
    duracion = _duracion;
}
void Video::setGenero (string _genero){
    genero = _genero;
}
void Video::setCalificacion (double _calificacion){
    calificacion = _calificacion;
}

//Metodos de acceso - getters  - retorna el valor del atributo
string Video::getID(){
    return iD;
}
string Video::getTitulo(){
    return titulo;
}
int Video::getDuracion(){
    return duracion;
}
string Video::getGenero(){
    return genero;
}
double Video::getCalificacion(){
    return calificacion;
}

// Otros metodos
string Video::str(){
    return iD + " " + titulo + " " +  to_string(duracion) + " " +  genero + " " +  to_string(calificacion);
}