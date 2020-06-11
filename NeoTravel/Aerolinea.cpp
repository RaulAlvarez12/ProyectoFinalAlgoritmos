/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aerolinea.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:50 PM
 */

#include "Aerolinea.h"

Aerolinea::Aerolinea(string nombre) {
    this->nombreCiudad=nombre;
}
string Aerolinea::getNombre(){
    return this->nombreCiudad;
}
Aerolinea::Aerolinea(const Aerolinea& orig) {
}

Aerolinea::~Aerolinea() {
}

