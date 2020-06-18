/* 
 * File:   Aerolinea.h
 * Author: geraldi
 *
 * Created on 3 de junio de 2020, 04:50 PM
 */

#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <string>
#include <sstream>
#include <vector>

#include "Vuelo.h"

using namespace std;

class Aerolinea {
public:
    Aerolinea(string nombre);
    Aerolinea();
    virtual ~Aerolinea();
    string getNombre();
    vector<Vuelo*> getVuelos();
    void agregarVuelo(Vuelo* vuelo);
    Vuelo* vueloActual(int posicion);
    Vuelo* primerVuelo(); //Devuelve el primer vuelo que tiene el vector de vuelos
    string toString();

private:
    int posicion;
    string nombreAerolinea;
    vector<Vuelo*> vuelos;

};

#endif /* AEROLINEA_H */