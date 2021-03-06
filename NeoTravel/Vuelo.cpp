/* 
 * File:   Vuelo.cpp
 * Author: geraldi
 * 
 * Created on 11 de junio de 2020, 01:50 PM
 */

#include "Vuelo.h"

Vuelo::Vuelo(Itinerario* itinerario, Ciudad* ciudadOrigen, Ciudad* ciudadDestino) {
    this->itinerario = itinerario;
    this->ciudadDestino = ciudadDestino;
    this->ciudadOrigen = ciudadOrigen;
}

Vuelo::Vuelo() {
    this->itinerario = new Itinerario();
}

Vuelo::~Vuelo() {
}

Ciudad* Vuelo::getCiudadOrigen() {
    return this->ciudadOrigen;
}

void Vuelo::setCiudadOrigen(Ciudad* ciudadOrigen) {
    this->ciudadOrigen = ciudadOrigen;
}

Itinerario* Vuelo::getItinerario() {
    return this->itinerario;
}

void Vuelo::setItinerario(Itinerario* itinerario) {
    this->itinerario = itinerario;
}

Ciudad* Vuelo::getciudadDestino() {
    return this->ciudadDestino;

}

void Vuelo::setciudadDestino(Ciudad* ciudadDestino) {
    this->ciudadDestino = ciudadDestino;
}

string Vuelo::toString() {
    stringstream s;
    s << "Vuelo: " << getCiudadOrigen()->toString() << " a " << getciudadDestino()->toString();
    s << "\nItinerario: " << this->itinerario->toString();
    return s.str();
}//toString

string Vuelo::mostrarVuelosActivos() {
    stringstream s;
    s << "Vuelo: " << getCiudadOrigen()->toString() << " a " << getciudadDestino()->toString() << "\n";
    s <<  this->itinerario->getColaPrioridad()->mostrarVuelosActivos();
    return s.str();
}