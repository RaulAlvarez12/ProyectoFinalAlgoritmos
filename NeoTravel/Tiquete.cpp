/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tiquete.cpp
 * Author: geraldi
 * 
 * Created on 11 de junio de 2020, 01:42 PM
 */

#include "Tiquete.h"

Tiquete::Tiquete(Usuario* usuario, Aerolinea* aerolinea, Vuelo* vuelo,Horario* horario) {

    this->usuario = usuario;
    this->aerolinea = aerolinea;
    this->vuelo = vuelo;
    this->horario=horario;
}

void Tiquete::setAerolinea(Aerolinea* Aerolinea) {
    this->aerolinea = Aerolinea;
}

Aerolinea* Tiquete::getAerolinea() {
    return this->aerolinea;
}

void Tiquete::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

Usuario* Tiquete::getUsuario() {
    return this->usuario;
}

void Tiquete::setVuelo(Vuelo* vuelo) {
    this->vuelo = vuelo;
}

Vuelo* Tiquete::getVuelo() {
    return this->vuelo;
}

string Tiquete::toString() {
stringstream s;
    s << "Informacion de compra:\n"
            <<"\n\nVuelo: "<<this->vuelo->getCiudadOrigen()->getNombre()<<" con destino a "<<this->vuelo->getciudadDestino()->getNombre()
            <<"\nHorario: "<<horario->toString()
            << "\n\nINFORMACION PERSONAL:"<<this->usuario->toString();
    return s.str();
}


Tiquete::Tiquete(const Tiquete& orig) {
}

Tiquete::~Tiquete() {
}

