/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Horario.cpp
 * Author: geraldi
 * 
 * Created on 11 de junio de 2020, 02:00 PM
 */

#include "Horario.h"

Horario::Horario(Avion* avion,int espacios) {
    this->avion=avion;
    this->espacios=espacios;
}

Horario::Horario(const Horario& orig) {
}

Horario::~Horario() {
}

Avion* Horario::getAvion() {
    return this->avion;
}

void Horario::setAvion(Avion* avion) {
    this->avion=avion;
}

int Horario::getEspacios() {
    return this->espacios;
}

void Horario::setEspacios(int espacios) {
    this->espacios=espacios;
}


