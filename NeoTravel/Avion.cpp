/* 
 * File:   Avion.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:50 PM
 */

#include "Avion.h"

Avion::Avion(string nombreAvion, int cantidadEspacios, int cantidadVuelos, int horasVuelo) {
    this->nombreAvion = nombreAvion;
    this->cantidadEspacios = cantidadEspacios;
    this->cantidadVuelos = cantidadVuelos;
    this->horasVuelo = horasVuelo;
}

Avion::Avion() {
    this->nombreAvion = "";
    this->cantidadEspacios = 0;
    this->cantidadVuelos = 0;
    this->horasVuelo = 0;
}

Avion::~Avion() {
}

int Avion::getCantidadVuelos() {
    return this->cantidadVuelos;
}

void Avion::setCantidadVuelos(int vuelos) {
    this->cantidadVuelos = vuelos;
}

string Avion::getNombreAvion() {
    return this->nombreAvion;
}

void Avion::setNombre(string nombre) {
    this->nombreAvion = nombre;
}

int Avion::getHorasVuelo() {
    return this->horasVuelo;
}

void Avion::setHorasVuelo(int horas) {
    this->horasVuelo = horas;
}

int Avion::getCantidadEspacios() {
    return this->cantidadEspacios;
}

void Avion::setCantidadEspacios(int espacios) {
    this->cantidadEspacios = espacios;
}

string Avion::toString() {
    stringstream s;
    s << "Nombre del avion: " << this->nombreAvion << ", cantidad asientos:" << this->cantidadEspacios << ", cantidad vuelos: "
            << this->cantidadVuelos << ", horas de vuelo: " << this->horasVuelo;
    return s.str();
}