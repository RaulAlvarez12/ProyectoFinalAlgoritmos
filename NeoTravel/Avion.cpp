/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Avion.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:50 PM
 */

#include "Avion.h"

Avion::Avion(string nombreAvion, int cantVuelos, float horasVuelo) {
    this->nombreAvion=nombreAvion;
    this->cantVuelos=cantVuelos;
    this->horasVuelo=horasVuelo;
}


Avion::Avion(const Avion& orig) {
}

Avion::~Avion() {
}

int Avion::getCantVuelos() {
    return this->cantVuelos;
}

void Avion::setCantVuelos(int vuelos) {
    this->cantVuelos=vuelos;
}

string Avion::getNombreAvion() {
    return this->nombreAvion;
}

void Avion::setNombre(string nombre) {
    this->nombreAvion=nombre;
}

float Avion::getHorasVuelo() {
    return this->horasVuelo;
}

void Avion::setHorasVuelo(float horas) {
    this->horasVuelo=horas;
}







