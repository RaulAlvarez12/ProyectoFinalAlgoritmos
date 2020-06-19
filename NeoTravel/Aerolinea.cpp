/* 
 * File:   Aerolinea.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:50 PM
 */

#include "Aerolinea.h"

Aerolinea::Aerolinea(string nombre) {
    this->nombreAerolinea = nombre;
    this->posicion = 0;
    vueloData = new VueloData();
}

Aerolinea::Aerolinea() {
    this->nombreAerolinea = "";
    this->posicion = 0;
}

Aerolinea::~Aerolinea() {
}

string Aerolinea::getNombre() {
    return this->nombreAerolinea;
}

string Aerolinea::toString() {
    stringstream s;
    s << "Nombre: " << this->nombreAerolinea;
//    for (int i = 0; i < this->vuelos.size(); i++) {
//        s << this->vuelos[i]->toString() << "\n";
//    }
    s<< this->vueloData->toString();
    return s.str();
}
//######USAN VECTOR#######//
//void Aerolinea::agregarVuelo(Vuelo* vuelo) {
//    this->vuelos.push_back(vuelo);
//}
//
//vector<Vuelo*> Aerolinea::getVuelos() {
//    return this->vuelos;
//}
//
//Vuelo* Aerolinea::primerVuelo() {
//    return this->vuelos[0];
//}
//
//Vuelo* Aerolinea::vueloActual(int posicion) {
//    
//}