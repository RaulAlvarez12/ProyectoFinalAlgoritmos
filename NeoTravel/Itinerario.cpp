/* 
 * File:   Itinerario.cpp
 * Author: alsov
 * 
 * Created on 11 de junio de 2020, 01:51 PM
 */

#include "Itinerario.h"

Itinerario::Itinerario() {
    this->colaPrioridad = new Cola();
    colaPrioridad->encolar(new Horario(7,8));
    this->avion = new Avion();
}

Itinerario::Itinerario(Avion* avion, Cola* colaPrioridad) {
    this->colaPrioridad = colaPrioridad;
    this->avion = avion;
}

Itinerario::~Itinerario() {
}

Avion* Itinerario::getAvion() {
    return this->avion;
}

void Itinerario::setAvion(Avion* avion) {
    this->avion = avion;
}

Cola* Itinerario::getColaPrioridad() {
    return this->colaPrioridad;
}

void Itinerario::setColaPrioridad(Cola* cola) {
    this->colaPrioridad = cola;
}

string Itinerario::toString() {
    stringstream s;
    s << " " << this->avion->toString() << this->colaPrioridad->toString();
    return s.str();
}


