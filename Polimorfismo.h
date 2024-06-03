/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024
*/
/*¿Que aprendi en el desarrollo de la clase Polimorfismo?
Lo que aprendi al hacer esta clase fue como implementar los arreglos y los Ptr para lograr tener una eficaz que me ayudara a poder mejorar mi codigo con solo 
utilizar lo que aprendi en la clase y tambien a como implementar metodos y funciones que me ayuden a leer los archivos y ordenarlos por como el usuario los 
quiera
*/
#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>
using namespace std;

const int MAX_VIDEOS = 100;

class Polimorfismo{
private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

public:
    Polimorfismo();
    void leerArchivo(string _nombre);
    
    //Metodods modificadores - setters
    void setPtrVideo(int index, Video *video);
    void setCantidadVideo(int _cantidad);
    
    //Metodos de acceso - getters
    Video* getPtrVideo(int index);
    int getCantidad();
    
    //Otros metodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif /*  Polimorfismo_h */

