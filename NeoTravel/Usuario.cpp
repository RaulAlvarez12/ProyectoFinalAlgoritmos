/* 
 * File:   Usuario.cpp
 * Author: geraldi
 * 
 * Created on 3 de junio de 2020, 04:49 PM
 */

#include "Usuario.h"

Usuario::Usuario(string nombre, int edad, string genero, int numPasaporte, string nacionalidad, bool permisoIngreso) {
    this->nombre = nombre;
    this->edad = edad;
    this->genero = genero;
    this->numeroPasaporte = numPasaporte;
    this->nacionalidad = nacionalidad;
    this->permisoIngreso = permisoIngreso;
}

Usuario::~Usuario() {
}

string Usuario::getNombre() {
    return this->nombre;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

int Usuario::getEdad() {
    return this->edad;
}

void Usuario::setEdad(int edad) {
    this->edad = edad;
}

string Usuario::getGenero() {
    return this->genero;
}

void Usuario::setGenero(string genero) {
    this->genero = genero;
}

int Usuario::getNumeroPasaporte() {
    return this->numeroPasaporte;
}

void Usuario::setNumeroPasaporte(int numeroPasaporte) {
    this->numeroPasaporte = numeroPasaporte;
}

string Usuario::getNacionalidad() {
    return this->nacionalidad;
}

void Usuario::setNacionalidad(string nacionalidad) {
    this->nacionalidad = nacionalidad;
}

bool Usuario::getPermisoIngreso() {
    return this->permisoIngreso;
}

void Usuario::setPermisoIngreso(bool permiso) {
    this->permisoIngreso = permiso;
}

void Usuario::compruebaPermiso(string ciudadDestino) {
    if (this->nacionalidad.compare("China") == 0 && ciudadDestino.compare("Costa Rica") == 0) this->permisoIngreso = false;
    if (this->nacionalidad.compare("Mexico") == 0 && ciudadDestino.compare("Estados Unidos") == 0) this->permisoIngreso = false;
    if (this->nacionalidad.compare("Ghana") == 0 && ciudadDestino.compare("España") == 0) this->permisoIngreso = false;
    if (this->nacionalidad.compare("Venezuela") == 0 && ciudadDestino.compare("Colombia") == 0) this->permisoIngreso = false;
    if (this->nacionalidad.compare("Irak") == 0 && ciudadDestino.compare("Estados Unidos") == 0) this->permisoIngreso = false;
    if (this->nacionalidad.compare("Paquistan") == 0 && ciudadDestino.compare("Estados Unidos") == 0) this->permisoIngreso = false;
    if (this->nacionalidad.compare("Israel") == 0 && ciudadDestino.compare("Estados Unidos") == 0) this->permisoIngreso = false;
}

string Usuario::toString() {
    stringstream s;
    s << "\nInformacion Usuario\nNombre: " << this->nombre << "\nEdad: " << this->edad << "\nGenero: " << this->genero
            << "\nNumero de pasaporte: " << this->numeroPasaporte << "\nNacionalidad: " << this->nacionalidad;
    return s.str();
}