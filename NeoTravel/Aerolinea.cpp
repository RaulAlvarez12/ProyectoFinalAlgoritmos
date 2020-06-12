/* 
 * File:   Aerolinea.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:50 PM
 */

#include "Aerolinea.h"

Aerolinea::Aerolinea(string nombre) {
    this->nombreAerolinea=nombre;
}
string Aerolinea::getNombre(){
    return this->nombreAerolinea;
}
Aerolinea::Aerolinea(const Aerolinea& orig) {
}

Aerolinea::~Aerolinea() {
}

