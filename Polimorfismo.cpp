/*
Diego Saldaña Gómez
A01571609
ITC
Junio 2, 2024
*/

#include "Polimorfismo.h"


//Constructor default - vacio
Polimorfismo :: Polimorfismo(){ 
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    //Inicializar cantidad de Videos
    cantidad = 0;
}

//Metodods modificadores - setters
void Polimorfismo::setPtrVideo(int index, Video *video){
    //Validar index - >=0 && < cantidad
    if(index >= 0 && index < cantidad){
        // cambiar modificar el apuntador
        arrPtrVideos[index] = video;
    }
}
// Cambia el valor del atributo cantidad
// cantidad deber ser entre 0 .. MAX_VIDEOS -1 , de lo contrario NO se modifica el valor del atributo
void Polimorfismo::setCantidadVideo(int _cantidad){
    //Validar el valor de cantidad
    if(_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
        cantidad = _cantidad;
    }
}

//Metodos de acceso - getters
Video* Polimorfismo::getPtrVideo(int index){
    //Validar que exista el index
    if(index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }
    //si no existe
    return nullptr;
}

int Polimorfismo::getCantidad(){
    return cantidad;
}

//Otros metodos
/*

*/
void Polimorfismo::reporteInventario(){
    //Declaracion de contadores
    int contPeliculas, contSeries;

    //Inicializar
    contPeliculas = 0;
    contSeries = 0;

    //recorrer todo el arreglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){
        cout << arrPtrVideos[index] -> str() << endl;
        // * indireccion (ptr) genera el objeto
        if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            contPeliculas++;
        }
        else if(typeid(*arrPtrVideos[index]) == typeid(Serie)){
            contSeries++;
        }
    }
    //Fuera del for - desplegar los totales
    cout << "Peliculas = " << contPeliculas << endl;
    cout << "Series = " << contSeries << endl;
}
void Polimorfismo::reporteCalificacion(double _calificacion){
    //contador totaol
    int total;

    //inicializar el contador
    total = 0;

   for(int index = 0; index < cantidad; index++){
        //Verificar si tiene la calificacion == _calificacion
        //si es un apuntador se usa la notacion ->
        if(arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
   }
   // desplegar el total fuera del for 
   cout << "Total = " << total << endl;
}

void Polimorfismo::reporteGenero(string _genero){
    //contador totaol
    int total;

    //inicializar el contador
    total = 0;

    for(int index = 0; index < cantidad; index++){
        //Verificar si tiene el genero == _genero
        //si es un apuntador se usa la notacion ->
        if(arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    // desplegar el total fuera del for 
    cout << "Total = " << total << endl;
}
void Polimorfismo::reportePeliculas(){
    //Declaracion de contadores
    int contPeliculas;

    //Inicializar
    contPeliculas = 0;

    //recorrer todo el arreglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){
        // * indireccion (ptr) genera el objeto
        if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index] -> str() << endl;
            contPeliculas++;
        }
    }
    if (contPeliculas == 0){
        cout << "No peliculas" << endl;
    } else{
        //Fuera del for - desplegar los totales
        cout << "Total Peliculas = " << contPeliculas << endl;
    }
}
void Polimorfismo::reporteSeries(){
    //Declaracion de contadores
    int contSeries;

    //Inicializar
    contSeries = 0;

    //recorrer todo el arreglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){
        // * indireccion (ptr) genera el objeto
        if(typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index] -> str() << endl;
            contSeries++;
        }
    }
    if (contSeries == 0){
        cout << "No series" << endl;
    } else{
        //Fuera del for - desplegar los totales
        cout << "Total Series = " << contSeries << endl;
    }
}

void Polimorfismo::leerArchivo(string nombre){
    //todas las declaraciones se hacen abajo del encabezado estandar c++ ITESM
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7]; //row - arreglo de 7 elementos de strings, para almacenar los datos de la linea del archivo ya separados
    string line, word; // line - almacena la linea leida, y word la palabra que se saca de line
    int cantidadPeliculas = 0; // Contadores de peliculas y series, inicialmente son 0
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in); // Abrir archivo de entrada

    while (getline(entrada, line)){ // Lee una linea del archivo y la almacena en line
        stringstream s(line); // usado para separar las palabras split()
        iR = 0; // Cada vez que inicia una nueva linea inicializar iR = 0

        //Ciclo que extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while(getline(s,word,',')){
            row[iR++] = word; // añade word al arreglo row e incrementa iR p/la proxima palabra
        }

        //Determinar si la linea es P-Pelicula, S-Serie, E-Episocio
        if(row[0] == "P"){
            // Se crea un apuntador usando el operador new y el constructor con parametros y se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            //cout << "Pelicula" << arrPtrPeliculas[cantidadPeliculas] -> str() << endl;
            cantidadPeliculas++; //inc la cantidad de peliculas
        }
        else if(row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            //cout << "Serie" << arrPtrSeries[cantidadSeries] -> str() << endl;
            cantidadSeries++;
        }
        else if(row[0] == "E"){
            // Calcular a que Serie le pertenece el episodio?
            index = stoi(row[1]) - 500;
            // Se agrega el episodio usando el metodo agregaEpisodio
            // Se crea el apuntador y se convierte a objeto usando el operador de indireccion
            arrPtrSeries[index] -> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
             //cout << "Episodio" << arrPtrSeries[index] -> str() << endl;
        }
    }

    // fuera del ciclo
    // ya se termino de leer todo el archivo ahora se guardan los 
    // todos los apuntadores de Pelicula y Serie en el arrPtrVideo
    // copiar todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video calculando su calificacionPromedio
    // ya que tiene todos los episodios

    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index] -> calculaPromedio(); // calcula la calificacion de la Serie
        arrPtrSeries[index] -> setCalificacion(promedio); // cambia la calificacion de la Serie
        // añade el calcular la duracion de la serie
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
     }

     // copiar todos los apuntadores del arreglo de Peliculas al arre3glo de apuntadores de Video
     for(int index = 0; index < cantidadPeliculas; index++){
         arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
     }
    /* Desplegar todo el contenido del arreglo de apuntadores de la clase Video (Base)
     - se da el POLIMORFISMO - SUPER SUPER SUPER !!,
     se ejecuta el metodo str() que corresponde al tipo del apuntador almacenado,
     no el correspondiente al tipo del arreglo
    */
 //  for(int index = 0; index < cantidad; index++){
  //  cout << index << " " << arrPtrVideos[index]->str() << endl;
 //  }

   entrada.close(); // cerrar el archivo
}