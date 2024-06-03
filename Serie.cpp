/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024
*/
#include "Serie.h"

 // Metodo Constructor
    Serie::Serie():Video(){
        // Solo vamos a inicializar cantidad
        cantidad = 0;
    }
    Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion):Video(_iD, _titulo, _duracion, _genero, _calificacion){
    cantidad = 0;
        
    }
    void Serie::calculaDuracion(){
        int contador = 0;
        for (int index = 0; index < cantidad; index++) {
            contador += episodios[index].getTemporada();
        }
        duracion = contador;
    }

    // Metodo Modificadores
    void Serie::setEpisodio(int posicion, Episodio episodio){
        // primero validar que exista ese episodio
        if (posicion >= 0 && posicion < cantidad){
            episodios[posicion] = episodio;
        }
    }
    void Serie::setCantidad(int _cantidad){
        // cambiar el valor del atributo cantidad con el nuevo valor recibido _cantidad
            cantidad = _cantidad;
    }

    // Metodos de acceso
    Episodio Serie::getEpisodio(int posicion){
        // Esto crea un objeto del tipo Episodio y lo inicializa con el constructor default
        Episodio epi;
        // Validar que exista el episodio solicitado (posicion)
        if (posicion >= 0 && posicion < cantidad){
            return episodios[posicion];
        } 
        // Si no existe se retorna un Episodio default
        return epi;
    }
    int Serie::getCantidad(){
        // retorna el valor del atributo cantidad
        return cantidad;
    }

    // Otros Metodos
    double Serie::calculaPromedio(){
        double acum = 0;

        for (int index = 0; index < cantidad; index++){
            acum = acum + episodios[index].getCalificacion();
        }

        // Validar que tenga episodios
        if (cantidad > 0){
            return acum / cantidad;
        } 
        else {
            return 0;
        }
    }

    string Serie::str(){
        //
        calculaDuracion();
        string resultado=(iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + 
        genero + ' ' + to_string(calculaPromedio()) + ' ' + to_string(cantidad) + "\n");
        if (cantidad > 0){
            for (int index = 0; index < cantidad; index++){
                resultado += episodios[index].str() + '\n';
        }
        return resultado;
        }
        else {
            return resultado;
        }
    }
        //agrega un episodio solo si existe espacio
    void Serie::agregaEpisodio(Episodio episodio){
        if (cantidad < 5){
            episodios[cantidad++] = episodio;
        }
    }