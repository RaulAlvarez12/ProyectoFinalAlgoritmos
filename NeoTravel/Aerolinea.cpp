/* 
 * File:   Aerolinea.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:50 PM
 */

#include "Aerolinea.h"

Aerolinea::Aerolinea(string nombre) {
    this->nombreAerolinea = nombre;
    vueloData = new VueloData();
}

Aerolinea::Aerolinea() {
    this->nombreAerolinea = "";
}

Aerolinea::~Aerolinea() {
}

string Aerolinea::getNombre() {
    return this->nombreAerolinea;
}
void Aerolinea::setNombre(string nombre){
    this->nombreAerolinea =nombre;
}

string Aerolinea::toString() {
    stringstream s;
    s << "Nombre: " << this->nombreAerolinea;
    s<< this->vueloData->toString();
    return s.str();
}
