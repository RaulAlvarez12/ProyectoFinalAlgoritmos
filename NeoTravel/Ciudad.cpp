
/* 
 * File:   Ciudad.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:50 PM
 */

#include "Ciudad.h"

Ciudad::Ciudad(string nombre) {
    this->nombre=nombre;
}

Ciudad::Ciudad(const Ciudad& orig) {
}

Ciudad::~Ciudad() {
}

string Ciudad::getNombre(){
    return this->nombre;
}

void Ciudad::setNombre(string nombre){
    this->nombre=nombre;
}

string Ciudad::toString(){
    stringstream s;
        s<<"\nNombre de la ciudad: "<<this->nombre;
        return s.str();
}