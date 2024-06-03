/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024
*/

#include "Episodio.h"
using namespace std;

// Metodos Constructores
Episodio::Episodio(){
    titulo = "Titulo";
    temporada = 000;
    calificacion = 000;
}
Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Metodos modificadores - setters - cambiar el valor de un atributo
void Episodio::setTitulo (string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada (int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion (int _calificacion){
    calificacion = _calificacion;
}

//Metodos de acceso - getters  - retorna el valor del atributo
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}

// Otros metodos
string Episodio::str(){
    return titulo + " " + to_string(temporada) + " " + to_string(calificacion);
}