/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:49 PM
 */

#include "Usuario.h"

Usuario::Usuario(string nombre,int edad,string genero,int numPasaporte, string nacionalidad) {
    
    this->nombre=nombre;
    this->edad=edad;
    this->genero=genero;
    this->numeroPasaporte=numPasaporte;
    this->nacionalidad=nacionalidad;
}

Usuario::Usuario(const Usuario& orig) {
}

Usuario::~Usuario() {
}

string Usuario::getNombre(){
    return this->nombre;
}
void Usuario::setNombre(string nombre){
    this->nombre=nombre;
}
int Usuario::getEdad(){
    return this->edad;
}
void Usuario::setEdad(int edad){
    this->edad=edad;
}
string Usuario::getGenero(){
    return this->genero;
}
void Usuario::setGenero(string genero){
    this->genero=genero;
}
int Usuario::getNumeroPasaporte(){
    return this->numeroPasaporte;
}
void Usuario::setNumeroPasaporte(int numeroPasaporte){
    this->numeroPasaporte=numeroPasaporte;
}
string Usuario::getNacionalidad(){
    return this->nacionalidad;
}
void Usuario::setNacionalidad(string nacionalidad){
    this->nacionalidad=nacionalidad;
}

string Usuario::toString(){
        stringstream s;
        s<<"\nInformacion Usuario\nNombre: "<<this->nombre<<"\nEdad: "<<this->edad<<"\nGenero: "<<this->genero
                <<"\nNumero de pasaporte: "<<this->numeroPasaporte;
        //<<"Nacionalidad: "this->nacionalidad;
        return s.str();
    
}