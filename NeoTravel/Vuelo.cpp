/* 
 * File:   Vuelo.cpp
 * Author: geraldi
 * 
 * Created on 11 de junio de 2020, 01:50 PM
 */

#include "Vuelo.h"

Vuelo::Vuelo(Itinerario* itinerario,Ciudad* ciudadOrigen,Ciudad* ciudadDestino) {
    this->itinerario=itinerario;
    this->ciudadDestino=ciudadDestino;
    this->ciudadOrigen=ciudadOrigen;
}

Vuelo::Vuelo(const Vuelo& orig) {
}

Vuelo::~Vuelo() {
}

Ciudad* Vuelo::getCiudadOrigen() {
    return this->ciudadOrigen;
}

void Vuelo::setCiudadOrigen(Ciudad* ciudadOrigen) {
    this->ciudadOrigen=ciudadOrigen;
}

Itinerario* Vuelo::getItinerario() {
    return this->itinerario;
}

void Vuelo::setItinerario(Itinerario* itinerario) {
    this->itinerario=itinerario;
}

Ciudad* Vuelo::getciudadDestino() {
    return this->ciudadDestino;
    
}

void Vuelo::setciudadDestino(Ciudad* ciudadDestino) {
    this->ciudadDestino=ciudadDestino;
}